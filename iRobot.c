#include "iRobot.h"

void explore(void) {
    char direction_to_travel = 0;
    int robot_x;
    int robot_y;
    char goal_x = 0;
    char goal_y = 3;
    
    printf("\n\n\n");
    for (char x = 0; x < GLOBAL_X; x++) {
        for (char y = 0; y < GLOBAL_Y; y++) {
            printf("%d, ", global_map[x][y] );
        }
        printf("\n");
    }

    printf("goal is hardcoded to 0,3\n\n");

    printf("enter in robot x value position between 0 and 3:\n");
    scanf("%d", &robot_x);
    while (robot_x > 3 || robot_x < 0) {
        printf("\n\nyou are a shitcunt try again\n");
        printf("enter in robot x value position between 0 and 3:\n");
        scanf("%d", &robot_x);
    }

    printf("enter in robot y value position between 0 and 4:\n");
    scanf("%d", &robot_y);
    while (robot_y > 4 || robot_y < 0) {
        printf("\n\nyou are a shitcunt try again\n");
        printf("enter in robot y value position between 0 and 4:\n");
        scanf("%d", &robot_y);
    }

    direction_to_travel = findPathAStar(robot_x, robot_y, goal_x, goal_y);

    printf("\n\n\n\n A* RESULTS: \n"
            "direction to travel = %d \n\n",direction_to_travel);

    for (char x = 0; x < GLOBAL_X; x++) {
        for (char y = 0; y < GLOBAL_Y; y++) {
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
