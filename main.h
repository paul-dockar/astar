#ifndef MAIN_H
#define	MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "explore.h"
#include "iRobot.h"

void setup(void);                       //calls all other module setup functions
int main(void);                        //main program. starts by calling setup, then loops with pushbutton flag checks and displaying adc distance continuously

#endif	/* MAIN_H */
