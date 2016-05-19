#include "iRobot.h"

void explore(void) {
    char direction_to_travel = 0;
    int robot_x;
    int robot_y;
    char goal_x = 0;
    char goal_y = 3;

    printf( "legend:\n"
            "robot = 100\n"
            "goal = 200\n" 
            "direction 1 = UP\n"
            "direction 2 = RIGHT\n"
            "direction 3 = DOWN\n"
            "direction 4 = LEFT\n"
            "direction -1 = deadend turn around cunt\n");
    
    //==============================================================
    //==============================================================
    //==============================================================test code 1
    printf("\n============ STEP 1 ============\n");
    unsigned char adc_distance = 0;
    char x = 1;
    char y = 0;
    int stepper_pos = 0;

    robot_x = 0;
    robot_y = 1;
    
    setupLocalMap();
    for (char i = 0; i < 8; i++) {
        switch (stepper_pos) {
            case 0: adc_distance = 50; break;
            case 1: adc_distance = 100; break;
            case 2: adc_distance = 150; break;
            case 3: adc_distance = 100; break;
            case 4: adc_distance = 50; break;
            case 5: adc_distance = 100; break;
            case 6: adc_distance = 50; break;
            case 7: adc_distance = 100; break;
        }

        writeLocalMap(adc_distance, x, y);
                
        switch (stepper_pos) {
            case 0: x--; stepper_pos++; break;
            case 1: y++; stepper_pos++; break;
            case 2: y++; stepper_pos++; break;
            case 3: x++; stepper_pos++; break;
            case 4: x++; stepper_pos++; break;
            case 5: y--; stepper_pos++; break;
            case 6: y--; stepper_pos++; break;
            case 7: x--; stepper_pos++; break;
        }
    }

    //set robot position to centre array cell
    writeLocalMap(LEFT,1,1);

    printf("\n====== LOCAL MAP ======\n");
    for (char x = 0; x < LOCAL_X; x++) {
        for (char y = 0; y < LOCAL_Y; y++) {
            printf("%d, ", local_map[x][y] );
        }
        printf("\n");
    }

    direction_to_travel = findPathAStar(robot_x, robot_y, goal_x, goal_y);

    printf("\n====== GLOBAL MAP ======\n");
    for (char x = 0; x < GLOBAL_X; x++) {
        for (char y = 0; y < GLOBAL_Y; y++) {
            printf("%d, ", global_map[x][y] );
        }
        printf("\n");
    }
    printf("direction to travel = %d \n\n",direction_to_travel);

    //==============================================================
    //==============================================================
    //==============================================================test code 2
    printf("\n============ STEP 2 ============\n");
    adc_distance = 0;
    x = 1;
    y = 0;
    stepper_pos = 0;

    robot_x = 0;
    robot_y = 0;
    
    setupLocalMap();
    for (char i = 0; i < 5; i++) {
        switch (stepper_pos) {
            case 0: adc_distance = 150; break;
            case 1: adc_distance = 100; break;
            case 2: adc_distance = 50; break;
            case 3: adc_distance = 100; break;
            case 4: adc_distance = 50; break;
        }

        writeLocalMap(adc_distance, x, y);
                
        switch (stepper_pos) {
            case 0: x--; stepper_pos++; break;
            case 1: y++; stepper_pos++; break;
            case 2: y++; stepper_pos++; break;
            case 3: x++; stepper_pos++; break;
            case 4: x++; stepper_pos++; break;
        }
    }

    //set robot position to centre array cell
    writeLocalMap(LEFT,1,1);

    printf("\n====== LOCAL MAP ======\n");
    for (char x = 0; x < LOCAL_X; x++) {
        for (char y = 0; y < LOCAL_Y; y++) {
            printf("%d, ", local_map[x][y] );
        }
        printf("\n");
    }

    direction_to_travel = findPathAStar(robot_x, robot_y, goal_x, goal_y);

    printf("\n====== GLOBAL MAP ======\n");
    for (char x = 0; x < GLOBAL_X; x++) {
        for (char y = 0; y < GLOBAL_Y; y++) {
            printf("%d, ", global_map[x][y] );
        }
        printf("\n");
    }
    printf("direction to travel = %d \n\n",direction_to_travel);

    //==============================================================
    //==============================================================
    //==============================================================test code 3
    printf("\n============ STEP 3 ============\n");
    adc_distance = 0;
    x = 1;
    y = 0;
    stepper_pos = 0;

    robot_x = 1;
    robot_y = 0;
    
    setupLocalMap();
    for (char i = 0; i < 5; i++) {
        switch (stepper_pos) {
            case 0: adc_distance = 150; break;
            case 1: adc_distance = 100; break;
            case 2: adc_distance = 50; break;
            case 3: adc_distance = 100; break;
            case 4: adc_distance = 50; break;
        }

        writeLocalMap(adc_distance, x, y);
                
        switch (stepper_pos) {
            case 0: x--; stepper_pos++; break;
            case 1: y++; stepper_pos++; break;
            case 2: y++; stepper_pos++; break;
            case 3: x++; stepper_pos++; break;
            case 4: x++; stepper_pos++; break;
        }
    }

    //set robot position to centre array cell
    writeLocalMap(DOWN,1,1);

    printf("\n====== LOCAL MAP ======\n");
    for (char x = 0; x < LOCAL_X; x++) {
        for (char y = 0; y < LOCAL_Y; y++) {
            printf("%d, ", local_map[x][y] );
        }
        printf("\n");
    }

    direction_to_travel = findPathAStar(robot_x, robot_y, goal_x, goal_y);

    printf("\n====== GLOBAL MAP ======\n");
    for (char x = 0; x < GLOBAL_X; x++) {
        for (char y = 0; y < GLOBAL_Y; y++) {
            printf("%d, ", global_map[x][y] );
        }
        printf("\n");
    }
    printf("direction to travel = %d \n\n",direction_to_travel);

    //==============================================================
    //==============================================================
    //==============================================================test code 4
    printf("\n============ STEP 4 ============\n");
    adc_distance = 0;
    x = 1;
    y = 0;
    stepper_pos = 0;

    robot_x = 1;
    robot_y = 1;
    
    setupLocalMap();
    for (char i = 0; i < 5; i++) {
        switch (stepper_pos) {
            case 0: adc_distance = 50; break;
            case 1: adc_distance = 100; break;
            case 2: adc_distance = 150; break;
            case 3: adc_distance = 100; break;
            case 4: adc_distance = 50; break;
        }

        writeLocalMap(adc_distance, x, y);
                
        switch (stepper_pos) {
            case 0: x--; stepper_pos++; break;
            case 1: y++; stepper_pos++; break;
            case 2: y++; stepper_pos++; break;
            case 3: x++; stepper_pos++; break;
            case 4: x++; stepper_pos++; break;
        }
    }

    //set robot position to centre array cell
    writeLocalMap(RIGHT,1,1);

    printf("\n====== LOCAL MAP ======\n");
    for (char x = 0; x < LOCAL_X; x++) {
        for (char y = 0; y < LOCAL_Y; y++) {
            printf("%d, ", local_map[x][y] );
        }
        printf("\n");
    }

    direction_to_travel = findPathAStar(robot_x, robot_y, goal_x, goal_y);

    printf("\n====== GLOBAL MAP ======\n");
    for (char x = 0; x < GLOBAL_X; x++) {
        for (char y = 0; y < GLOBAL_Y; y++) {
            printf("%d, ", global_map[x][y] );
        }
        printf("\n");
    }
    printf("direction to travel = %d \n\n",direction_to_travel);


    //==============================================================
    //==============================================================
    //==============================================================test code 5
    printf("\n============ STEP 5 ============\n");
    adc_distance = 0;
    x = 1;
    y = 0;
    stepper_pos = 0;

    robot_x = 1;
    robot_y = 2;
    
    setupLocalMap();
    for (char i = 0; i < 5; i++) {
        switch (stepper_pos) {
            case 0: adc_distance = 150; break;
            case 1: adc_distance = 100; break;
            case 2: adc_distance = 150; break;
            case 3: adc_distance = 100; break;
            case 4: adc_distance = 150; break;
        }

        writeLocalMap(adc_distance, x, y);
                
        switch (stepper_pos) {
            case 0: x--; stepper_pos++; break;
            case 1: y++; stepper_pos++; break;
            case 2: y++; stepper_pos++; break;
            case 3: x++; stepper_pos++; break;
            case 4: x++; stepper_pos++; break;
        }
    }

    //set robot position to centre array cell
    writeLocalMap(RIGHT,1,1);

    printf("\n====== LOCAL MAP ======\n");
    for (char x = 0; x < LOCAL_X; x++) {
        for (char y = 0; y < LOCAL_Y; y++) {
            printf("%d, ", local_map[x][y] );
        }
        printf("\n");
    }

    direction_to_travel = findPathAStar(robot_x, robot_y, goal_x, goal_y);

    printf("\n====== GLOBAL MAP ======\n");
    for (char x = 0; x < GLOBAL_X; x++) {
        for (char y = 0; y < GLOBAL_Y; y++) {
            printf("%d, ", global_map[x][y] );
        }
        printf("\n");
    }
    printf("direction to travel = %d \n\n",direction_to_travel);

    //==============================================================
    //==============================================================
    //==============================================================test code 5
    printf("\n============ STEP 5 ============\n");
    adc_distance = 0;
    x = 1;
    y = 0;
    stepper_pos = 0;

    robot_x = 0;
    robot_y = 2;
    
    setupLocalMap();
    for (char i = 0; i < 5; i++) {
        switch (stepper_pos) {
            case 0: adc_distance = 50; break;
            case 1: adc_distance = 100; break;
            case 2: adc_distance = 50; break;
            case 3: adc_distance = 100; break;
            case 4: adc_distance = 50; break;
        }

        writeLocalMap(adc_distance, x, y);
                
        switch (stepper_pos) {
            case 0: x--; stepper_pos++; break;
            case 1: y++; stepper_pos++; break;
            case 2: y++; stepper_pos++; break;
            case 3: x++; stepper_pos++; break;
            case 4: x++; stepper_pos++; break;
        }
    }

    //set robot position to centre array cell
    writeLocalMap(UP,1,1);

    printf("\n====== LOCAL MAP ======\n");
    for (char x = 0; x < LOCAL_X; x++) {
        for (char y = 0; y < LOCAL_Y; y++) {
            printf("%d, ", local_map[x][y] );
        }
        printf("\n");
    }

    direction_to_travel = findPathAStar(robot_x, robot_y, goal_x, goal_y);

    printf("\n====== GLOBAL MAP ======\n");
    for (char x = 0; x < GLOBAL_X; x++) {
        for (char y = 0; y < GLOBAL_Y; y++) {
            printf("%d, ", global_map[x][y] );
        }
        printf("\n");
    }
    printf("direction to travel = %d \n\n",direction_to_travel);

}

int abs(int a) {
    if(a < 0)
        return -a;
    return a;
}
