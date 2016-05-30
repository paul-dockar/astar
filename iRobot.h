#ifndef IROBOT_H
#define	IROBOT_H

#include "main.h"

//OPCODES
#define     START               128			//Create start command
#define     FULL                132			//Create full control command
#define     DRIVE               145			//Create Drive Direct command
#define     BUTTONS             18			//state of the create push buttons
#define     LEDS                139			//control the state of the create leds
#define     IRBYTE              17			//IR byte recieved by create
#define     SONG_PLAYING        37			//indicates if a song is currently being played
#define     PLAY_SONG           141			//play a song (0 - 15)
#define     SONG                140			//define a song
#define     SENSORS             142         //Create sensor command

//SENSOR PACKET_ID's for OPCODE 142
#define     DISTANCE            19          //distance in mm
#define     ANGLE               20          //angle in degrees
#define     VOLTAGE             22          //voltage in mV
#define     BATTERY_CHARGE      25          //battery current charge in mAh
#define     BATTERY_CAPACITY    26          //battery capacity in mAh
#define     BUMP_SENSOR          7
#define     VIRTWALL_SENSOR     13

//IROBOT WHEEL SPEED DEFINES
#define     RIGHT_WHEEL_FAST     300         //right wheel speed in mm/s. right wheel slightly faster than left wheel, so compensate
#define     LEFT_WHEEL_FAST      300         //left wheel speed in mm/s
#define     RIGHT_WHEEL_SLOW     100         //right wheel speed in mm/s. right wheel slightly faster than left wheel, so compensate
#define     LEFT_WHEEL_SLOW      100         //left wheel speed in mm/s


int total_distance_travel;                      //Global variable which holds the total distance travelled, allowing to write to the LCD from any function.
char reset_flag;
char exploring;
char move_stepper;
char slow_flag;
char victim_found_flag;
unsigned char *victim_one_location;
unsigned char *victim_two_location;
unsigned char victim_count;
int total_distance_travel;

volatile char cliff_flag;
volatile char bump_flag;
volatile char virt_wall_flag;
volatile char update_pos_flag;

void explore(void);
void victimCheck(unsigned char robot_x, unsigned char robot_y);

signed char abs_char(signed char a);

#endif	/* IROBOT_H */
