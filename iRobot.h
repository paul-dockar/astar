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
#define     RIGHT_WHEEL_FAST     200         //right wheel speed in mm/s. right wheel slightly faster than left wheel, so compensate
#define     LEFT_WHEEL_FAST      200         //left wheel speed in mm/s
#define     RIGHT_WHEEL_SLOW     50          //right wheel speed in mm/s. right wheel slightly faster than left wheel, so compensate
#define     LEFT_WHEEL_SLOW      50         //left wheel speed in mm/s

//IROBOT MANEUVERS
#define     SHARP_RIGHT()       drive(-80,LEFT_WHEEL_FAST);
#define     SHARP_LEFT()        drive(RIGHT_WHEEL_FAST,-80);
#define     SHARP_RIGHT2()      drive(-90,LEFT_WHEEL_FAST);
#define     SHARP_LEFT2()       drive(RIGHT_WHEEL_FAST,-90);
#define     SLOW_RIGHT()        drive(150,LEFT_WHEEL_FAST);
#define     SLOW_LEFT()         drive(RIGHT_WHEEL_FAST,150);

#define     SPIN_RIGHT_F()        drive(-RIGHT_WHEEL_FAST,LEFT_WHEEL_FAST);
#define     SPIN_LEFT_F()         drive(RIGHT_WHEEL_FAST,-LEFT_WHEEL_FAST);
#define     SPIN_RIGHT_S()        drive(-RIGHT_WHEEL_SLOW,LEFT_WHEEL_FAST);
#define     SPIN_LEFT_S()         drive(RIGHT_WHEEL_SLOW,-LEFT_WHEEL_FAST);

#define     DRIVE_STRAIGHT_F()  drive(RIGHT_WHEEL_FAST,LEFT_WHEEL_FAST);
#define     DRIVE_STRAIGHT_S()  drive(RIGHT_WHEEL_SLOW,LEFT_WHEEL_SLOW);
#define     DRIVE_BACKWARD()    drive(-RIGHT_WHEEL_FAST,-LEFT_WHEEL_FAST);
#define     DRIVE_STOP()        drive(0,0); __delay_ms(800);

void explore(void);
int abs(int a);


#endif	/* IROBOT_H */
