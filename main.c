#include "main.h"

//calls all other module setup functions
void setup(void) {
    setupExplore();
}

//main program. starts by calling setup, then loops with pushbutton flag checks and displaying adc distance continuously
int main(void) {
    setup();
	explore();
}
