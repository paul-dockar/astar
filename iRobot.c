#include "iRobot.h"

void explore(void) {
    char direction_to_travel = 0;
    char robot_x = 0;
    char robot_y = 1;
    char goal_x = 0;
    char goal_y = 3;
    
    direction_to_travel = findPathAStar(robot_x, robot_y, goal_x, goal_y);

    printf("\n\n\n\n A* RESULTS: \n"
            "direction to travel = %d \n\n",direction_to_travel);

    for (char x = 0; x != GLOBAL_X; x++) {
        for (char y = 0; y != GLOBAL_Y; y++) {
            printf("%d, ", global_map[x][y] );
        }
        printf("\n");
    }
}

int abs(int a) {
    if(a < 0)
        return -a;
    return a;
}
