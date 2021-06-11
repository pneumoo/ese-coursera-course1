/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file main.c
 * @brief Main entry point to the final assessment
 *
 * Your main function will be very simple. You will just need to call a function 
 * that is defined in the course1.c source file. However, you need to use a 
 * compile time switch to wrap this function to call. This way we can have a simple 
 * main() function that can switch which course deliverable we wish to call by 
 * specifying the -DCOURSE1 compile time switch.
 *
 * @author Brian Weinstein
 * @date June 10, 2021
 */



#ifdef COURSE1
void main() {
 	course1();
	return 0;
}
#endif

