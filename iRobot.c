#include "iRobot.h"


void explore(void) {
    signed char direction_to_travel = 0;
    int angle_to_turn = 0;

    //set robot starting variables
    unsigned char *current_facing_direction = &local_map[1][1];
    unsigned char robot_x = 0;
    unsigned char robot_y = 1;
    unsigned char goal_x = 0;
    unsigned char goal_y = 3;
    unsigned char goal_number = 0;
    unsigned char *home_goal = &global_map[robot_x][robot_y];
	unsigned char *temp_home_goal = &global_map[goal_x][goal_y];
    *current_facing_direction = 4;
    reset_flag = 1;
    exploring = 1;

	int stepper_pos = 0;
	unsigned char adc_distance = 0;

    char x = 1;
    char y = 0;


	unsigned int exploring_iteration = 0;
    
    while (exploring == 1) {
		_getch();
		printf("exploring_iteration %d\n",exploring_iteration);
		printf("victim count %d\n",victim_count);
		printf("robot x pos %d\n",robot_x);
		printf("robot y pos %d\n",robot_y);
		printf("goal x pos %d\n",goal_x);
		printf("goal y pos %d\n",goal_y);


		stepper_pos = 0;
		x = 1;
    	y = 0;
		adc_distance = 0;
		setupLocalMap();
		switch (exploring_iteration) {
			case 0: 
			    for (char i = 0; i < 8; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
			            case 4: adc_distance = 50; break;
			            case 5: adc_distance = 99; break;
			            case 6: adc_distance = 50; break;
			            case 7: adc_distance = 99; break;
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
				break;
			case 1: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 150; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 2: 
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
				break;
			case 3: 
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
				break;
			case 4: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 150; break;
			            case 1: adc_distance = 100; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 100; break;
			            case 4: adc_distance = 10; break;
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
				break;
			case 5: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 6: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 150; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				cliff_flag = 1;
				update_pos_flag = 1;
				break;
			case 7: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 150; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				temp_global_info_flag = 1;
				break;
			case 8: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 9: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 150; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				victim_found_flag = 1;
				break;
			case 10: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 150; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 11: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 12: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 150; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 13: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 150; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 14: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 15: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 150; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 16: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 150; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 17: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
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
				victim_found_flag = 1;
				break;
			case 18: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 19: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 20: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 21: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 22: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 23: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 24: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				victim_found_flag = 1;
				break;
			case 25: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 26: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 150; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 27: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 28: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 29: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 30: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 31: 
			    for (char i = 0; i < 8; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 150; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
			            case 4: adc_distance = 50; break;
			            case 5: adc_distance = 50; break;
			            case 6: adc_distance = 150; break;
			            case 7: adc_distance = 50; break;
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
				break;
			case 32: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 33: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 150; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 34: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 150; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 35: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 36: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 150; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 37: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 38: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 39: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 40: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 41: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 150; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 42: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
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
				break;
			case 43: 
			    for (char i = 0; i < 5; i++) {
			        switch (stepper_pos) {
			            case 0: adc_distance = 50; break;
			            case 1: adc_distance = 99; break;
			            case 2: adc_distance = 50; break;
			            case 3: adc_distance = 99; break;
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
				break;
		}

	    printf("\n====== LOCAL MAP ======\n");
	    for (char x = 0; x < LOCAL_X; x++) {
	        for (char y = 0; y < LOCAL_Y; y++) {
	            printf("%d, ", local_map[x][y] );
	        }
	        printf("\n");
	    }
        
        if (victim_count == 2 && victim_home_flag == 1) {
			if (robot_x >= 2 || robot_y >= 3) {
				goal_x = 3;
				goal_y = 2;
				temp_home_goal = &global_map[goal_x][goal_y];
			} else {
	            goal_x = 0;
	            goal_y = 1;
			}
			if (temp_home_goal == &global_map[robot_x][robot_y]) {
				goal_x = 0;
				goal_y = 1;
				victim_home_flag = 0;
			}
        }

        //find direction to move next.
        //direction is either 1 (up), 2 (right), 3 (down), 4 (left), or -1 (dead-end)
        direction_to_travel = findPathAStar(robot_x, robot_y, goal_x, goal_y);

		printf("\n====== GLOBAL MAP ======\n");
    		for (char x = 0; x < GLOBAL_X; x++) {
        		for (char y = 0; y < GLOBAL_Y; y++) {
            		printf("%d, ", global_map[x][y] );
        		}
        		printf("\n");
    		}
    	printf("direction to travel = %d \n\n",direction_to_travel);
        
        if (direction_to_travel == 0) {
            angle_to_turn = 0;
            if (goal_number == 0 && victim_count < 2) {
                goal_x = 1;
                goal_y = 3;
                goal_number++;
            } else if (goal_number == 1 && victim_count < 2) {
                goal_x = 3;
                goal_y = 0;
                goal_number++;
            } else if (goal_number == 2 && victim_count < 2) {
                goal_x = 0;
                goal_y = 1;
                goal_number++;
            }
            if (home_goal == &global_map[robot_x][robot_y]) {
                exploring = 0;
            }
        } else if (direction_to_travel == -1) {
            angle_to_turn = 180;
            switch (*current_facing_direction) {
                case 1: direction_to_travel = 3; break;
                case 2: direction_to_travel = 4; break;
                case 3: direction_to_travel = 1; break;
                case 4: direction_to_travel = 2; break;
            }
            global_map[robot_x][robot_y] = DEADEND;
        } else {
            //determine new direction
            angle_to_turn = 90 * (*current_facing_direction - direction_to_travel);
            if (angle_to_turn > 180) {
                angle_to_turn = angle_to_turn - 360;
            } else if (angle_to_turn < -180) {
                angle_to_turn = angle_to_turn + 360;
            }
            reset_flag = 0;
        }

        if (direction_to_travel != 0) {
             *current_facing_direction = direction_to_travel;                   //update facing direction
            switch (*current_facing_direction) {                                //update robot position
                case UP:    robot_x--; break;
                case RIGHT: robot_y++; break;
                case DOWN:  robot_x++; break;
                case LEFT:  robot_y--; break;
            }
        }
        
        if (victim_found_flag == 1) victimCheck(robot_x, robot_y);
        
        if (update_pos_flag == 1) {
            if (cliff_flag == 1)     global_map[robot_x][robot_y] = CLIFF;
            if (bump_flag == 1)      global_map[robot_x][robot_y] = BUMP;
            if (virt_wall_flag == 1) global_map[robot_x][robot_y] = VIRTWALL;
            
            //revert robot position
            switch (*current_facing_direction) {
                case UP:    robot_x++; break;
                case RIGHT: robot_y--; break;
                case DOWN:  robot_x--; break;
                case LEFT:  robot_y++; break;
            }
            cliff_flag = bump_flag = update_pos_flag = 0;
        }
		exploring_iteration++;
    }
}

void victimCheck(unsigned char robot_x, unsigned char robot_y) {
    if (victim_count == 0) {
        victim_one_location = &global_map[robot_x][robot_y];
        victim_count++;
    } else if (victim_count == 1) {
        if (&global_map[robot_x][robot_y] != victim_one_location) {
            victim_two_location = &global_map[robot_x][robot_y];
            victim_count++;
			reset_flag = 1;
			victim_home_flag = 1;
        }
    }
    victim_found_flag = 0;
}

signed char abs_char(signed char a) {
    if(a < 0)
        return -a;
    return a;
}
