#ifndef EXPLORE_H
#define	EXPLORE_H

#include "main.h"

#define     ROBOT       100
#define     GOAL        200
#define     WALL        255
#define     DEADEND     254
#define     CLIFF       253
#define     BUMP        252
#define     VIRTWALL    251

#define     GLOBAL_X        4
#define     GLOBAL_Y        5
#define     LOCAL_X         3
#define     LOCAL_Y         3

#define     CLOSED_SET_SIZE 20
#define     OPEN_SET_SIZE   20

#define     TURN_AROUND     -1
#define     STOP            0
#define     UP              1
#define     RIGHT           2
#define     DOWN            3
#define     LEFT            4

void setupExplore(void);
void setupLocalMap(void);
signed char findPathAStar(char, char, char, char);
void writeLocalMap(unsigned char, char, char);

unsigned char global_map[GLOBAL_X][GLOBAL_Y];
unsigned char local_map[LOCAL_X][LOCAL_Y];
volatile char temp_global_info_flag;

#endif	/* EXPLORE_H */
