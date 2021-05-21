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
 * @file stats.c
 * @brief A simple application that performs statistical analytics on a dataset. 
 *
 * Functions like min, max, average, and others are performed and printed. 
 *
 * @author Brian Weinstein
 * @date May 19, 2021
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  int sum = 0;
  float avg = 0.0;

  /* Statistics and Printing Functions Go Here */
  printf("Hello Stats.c!!!!!!\n");


/*   Print array data
  for (int i = 0; i < SIZE; i++){
    printf("test[%d]: %d\n", i, test[i]);
  } */

  //Print array data from function call:
  print_array(test, SIZE);

  //Print 

  // SUM FUNCTION
  for (int i = 0; i < SIZE; i++){
    sum += *(test+i);
  }
  printf("Sum: %d\n", sum);
  // AVERAGE FUNCTION
  avg = sum/SIZE;
  printf("Avg: %f\n", avg); //TODO: this seems to FLOOR avg value... why? 

  //testing find_mean()
  int mean = find_mean(test, SIZE);
  printf("Mean: %f\n", mean); //TODO: this seems to FLOOR avg value... why? 

}

/* ------------------------------------------------
FUNCTION: print_statistics() 
------------------------------------------------ */
void print_statistics(unsigned char array_data[]) {
  // add statistics functions here...
  // add all the print statements here...
  return;
}


/* ------------------------------------------------
FUNCTION: print_array() 
------------------------------------------------ */
void print_array(unsigned char array_data[], int array_size) {
  for (int i = 0; i < array_size; i++) {
    printf("test[%d]: %d\n", i, array_data[i]);
  }
  return;
}


/* ------------------------------------------------
FUNCTION: find_median()
------------------------------------------------ */


/* ------------------------------------------------
FUNCTION: find_mean()  
------------------------------------------------ */
int find_mean(unsigned char array_data[], int array_size) {
  //intialize & declare local variables
  int sum = 0;

  // loop through array_data[] and sum all values
  for (int i = 0; i < array_size; i++) {
    sum += array_data[i];
  }
  // Get mean and return mean
  return sum/array_size;
}

/* ------------------------------------------------
FUNCTION: find_maximum() 
------------------------------------------------ */


/* ------------------------------------------------
FUNCTION: find_minimum()
------------------------------------------------ */


/* ------------------------------------------------
FUNCTION: sort_array()
------------------------------------------------ */