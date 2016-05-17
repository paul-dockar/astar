#include "explore.h"

unsigned char *closed_set [CLOSED_SET_SIZE];
unsigned char *open_set [OPEN_SET_SIZE];
unsigned char ignore = 0;

struct NEIGHBOUR {
    unsigned char *up;
    unsigned char *right;
    unsigned char *down;
    unsigned char *left;
} neighbour;

//declare local functions
void initialisePointersNULL(unsigned char *array[], char size);
void removeFromOpenSet(unsigned char *item_to_remove);
void pushToClosedSet(unsigned char *current_open_set);
void rearrangeOpenSet(void);
unsigned char *getNeighbourNodes(unsigned char *current_node, unsigned char neighbour_node);
unsigned char checkNeighbour(unsigned char *neighbour, unsigned char *goal, unsigned char *robot, char goal_x, char goal_y);

void setupExplore(void) {
    setupGlobalMap();
    setupLocalMap();
}

void setupGlobalMap(void) {
    for (char x = 0; x < GLOBAL_X; x++) {
        for (char y = 0; y < GLOBAL_Y; y++) {
            global_map [x][y] = 0;
        }
    }

    //output array
    for (char x = 0; x < GLOBAL_X; x++) {
        for (char y = 0; y < GLOBAL_Y; y++) {
            global_map [x][y] = 0;

            printf("%d, ", global_map[x][y] );
        }
        printf("\n");
    }
	printf("setupGlobalMap done\n\n");

    //output array addresses
    for (char x = 0; x < GLOBAL_X; x++) {
        for (char y = 0; y < GLOBAL_Y; y++) {
            global_map [x][y] = 0;

            printf("Address of global_map[%d][%d] = %X\n", x, y, &global_map[x][y] );
        }
        printf("\n");
    }
}

void setupLocalMap(void) {
    for (char x = 0; x < LOCAL_X; x++) {
        for (char y = 0; y < LOCAL_Y; y++) {
            local_map [x][y] = 0;
        }
    }

    //output array
    for (char x = 0; x < LOCAL_X; x++) {
        for (char y = 0; y < LOCAL_Y; y++) {
            local_map [x][y] = 0;

            printf("%d, ", local_map[x][y] );
        }
        printf("\n");
    }
    printf("setupLocalMap done\n\n");
}

void writeGlobalMap(unsigned char value, char x, char y) {
    global_map [x][y] = value;

    printf("global_map[%d][%d] = %d\n", x,y, global_map[x][y] );
}

void writeLocalMap(unsigned int adc_distance, char x, char y) {
    local_map [x][y] = adc_distance;
}

char findPathAStar(char robot_x, char robot_y, char goal_x, char goal_y) {
    unsigned char *current_open_set = 0;
    unsigned char *goal_position = &global_map[goal_x][goal_y];
    unsigned char *robot_position = &global_map[robot_x][robot_y];
    
    //setup robot/goal position, clear open and closed sets, clear global map
    setupGlobalMap();
    initialisePointersNULL(closed_set, CLOSED_SET_SIZE);
    initialisePointersNULL(open_set, OPEN_SET_SIZE);

    writeGlobalMap(ROBOT, robot_x, robot_y);
    writeGlobalMap(GOAL, goal_x, goal_y);

    open_set[0] = robot_position;                       //put starting node on open set list
    
    printf("open_set[0] = %x\n", open_set[0]);

    while (*open_set [0] != 0) {
        printf("\n\n\ninside while loop\n\n\n");
        unsigned char smallest_open_set = MAX;
        
        printf("find the node with the least f on the open list\n");

        //find node with least f on the open list
        for (char i = 0; i < OPEN_SET_SIZE; i++) {
            if (open_set [i] != 0 && smallest_open_set > *open_set [i]) {
                smallest_open_set = *open_set [i];
                current_open_set = open_set [i];
            }
            printf("current open set = %x \n",current_open_set);
            printf("i = %d, current smallest open set = %d \n",i,smallest_open_set);
        }
        
        //remove the chosen one from the open list
        removeFromOpenSet(current_open_set);
        
        //generate 4 neighbours from current node
        neighbour.up    = getNeighbourNodes(current_open_set, UP);
        neighbour.right = getNeighbourNodes(current_open_set, RIGHT);
        neighbour.down  = getNeighbourNodes(current_open_set, DOWN);
        neighbour.left  = getNeighbourNodes(current_open_set, LEFT);

        printf("up node = %x\n",neighbour.up);
        printf("right node = %x\n",neighbour.right);
        printf("down node = %x\n",neighbour.down);
        printf("left node = %x\n",neighbour.left);
        
        //for each neighbour; write f value to global map
        *neighbour.up       = checkNeighbour(neighbour.up, goal_position, robot_position, goal_x, goal_y);
        *neighbour.right    = checkNeighbour(neighbour.right, goal_position, robot_position, goal_x, goal_y);
        *neighbour.down     = checkNeighbour(neighbour.down, goal_position, robot_position, goal_x, goal_y);
        *neighbour.left     = checkNeighbour(neighbour.left, goal_position, robot_position, goal_x, goal_y);

        if (*neighbour.up       == GOAL) return UP;
        if (*neighbour.right    == GOAL) return RIGHT;
        if (*neighbour.down     == GOAL) return DOWN;
        if (*neighbour.left     == GOAL) return LEFT;

        for (char x = 0; x != GLOBAL_X; x++) {
            for (char y = 0; y != GLOBAL_Y; y++) {
                printf("%d, ", global_map[x][y] );
            }
            printf("\n");
        }

        //put current_open_set onto closed set
        pushToClosedSet(current_open_set);
        
        //print open set
        for (char i = 0; i < OPEN_SET_SIZE; i++) {
            printf("\n open_set[%d + 1] == %p \n",i,open_set[i]);
        }

        //print closed set
        for (char i = 0; i < CLOSED_SET_SIZE; i++) {
            printf("\n closed_set[%d] == %p \n",i,closed_set[i]);
        }
    }
    
    
    
    return 0;
}

void initialisePointersNULL(unsigned char *array[], char size) {
    for (char i = 0; i < size; i++) {
        array[i] = 0;

        printf("array[%d] = %x\n", i, array[i]);
    }
	printf("initialised open and closed sets done\n\n");
}

void removeFromOpenSet(unsigned char *item_to_remove) {
    for (char i = 0; i < OPEN_SET_SIZE; i++) {
        printf("before remove %p\n",open_set[i]);

        if (open_set [i] == item_to_remove) {
            open_set [i] = 0;
            printf("removing %x from open set\n",item_to_remove);
        }

        printf("after remove %p\n",open_set[i]);
    }
}

void pushToClosedSet(unsigned char *current_open_set){
    for (char i = 0; i < CLOSED_SET_SIZE; i++) {
        if (closed_set[i] == current_open_set) {
            break;
        } else if (closed_set[i] == 0) {
            closed_set[i] = current_open_set;
            break;
        }
    }
}

void pushToOpenSet(unsigned char *current_neighbour){
    for (char i = 0; i < OPEN_SET_SIZE; i++) {
        if (open_set[i] == current_neighbour) {
            break;
        } else if (open_set[i] == 0) {
            open_set[i] = current_neighbour;
            break;
        }
    }
}

unsigned char *getNeighbourNodes(unsigned char *current_node, unsigned char neighbour_direction) {
    for (char x = 0; x != GLOBAL_X; x++) {
        for (char y = 0; y != GLOBAL_Y; y++) {
            if (current_node == &global_map[x][y]) {
                if (x == 0 && neighbour_direction == UP)    return &ignore;
                if (x == 4 && neighbour_direction == DOWN)  return &ignore;
                if (y == 0 && neighbour_direction == LEFT)  return &ignore;
                if (y == 5 && neighbour_direction == RIGHT) return &ignore;

                switch (neighbour_direction) {
                    case 1: x--; return (&global_map[x][y]);
                    case 2: y++; return (&global_map[x][y]);
                    case 3: x++; return (&global_map[x][y]);
                    case 4: y--; return (&global_map[x][y]);
                }
            }
        }
    }
    return &ignore;
}

unsigned char checkNeighbour(unsigned char *neighbour, unsigned char *goal, unsigned char *robot, char goal_x, char goal_y) {
    char distance=0;
    char distance_x=0;
    char distance_y=0;
    char pos_x=0;
    char pos_y=0;

    if (neighbour == &ignore) return MAX;
    if (neighbour == goal) return GOAL;
    if (neighbour == robot) return ROBOT;
    
    for (char x = 0; x != GLOBAL_X; x++) {
        for (char y = 0; y != GLOBAL_Y; y++) {
            if (neighbour == &global_map[x][y]) {
                pos_x = x;
                pos_y = y;
                break;
            }
        }
    }

    distance_x = pos_x - goal_x;
    distance_y = pos_y - goal_y;
    distance = abs(distance_x) + abs(distance_y);

    

    //if a node with same position as successor is in the OPEN list, skip it
    for (char i = 0; i < OPEN_SET_SIZE; i++) {
        if (neighbour == open_set[i]) {
            printf("\n=============================test========================\n");
            printf("neighbour on open set = %p\n",neighbour);
            return distance;
        }
    }
    //if a node with same position as successor is in the CLOSE list, skip it
    for (char i = 0; i < CLOSED_SET_SIZE; i++) {
        if (neighbour == closed_set[i]) {
            printf("\n=============================test========================\n");
            printf("neighbour on closed_set = %p\n",neighbour);
            return distance;
        }
    }
    //otherwise add node to open list
    pushToOpenSet(neighbour);

    return distance;
}
