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


  // Print statistics function call:
  print_statistics(test, SIZE);

  //Print array data from function call:
  print_array(test, SIZE);

  return; // main() return
}



/* ------------------------------------------------
FUNCTION: print_statistics() 
------------------------------------------------ */
void print_statistics(unsigned char array_data[], int array_size) {
  // add statistics functions here...
  int min = find_minimum(array_data, array_size);
  int max = find_maximum(array_data, array_size);
  int mean = find_mean(array_data, array_size);
  int median = find_median(array_data, array_size);

  // add all the print statements here...
  printf("\n---DATA STATISTICS---\n");
  printf("Min: %d\n", min);
  printf("Max: %d\n", max);
  printf("Mean: %d\n", mean);
  printf("Median: %d\n", median);
  printf("---END DATA STATISTICS---\n");

  return; //print_statisics()
}


/* ------------------------------------------------
FUNCTION: print_array() 
------------------------------------------------ */
void print_array(unsigned char array_data[], int array_size) {
  printf("\n---ARRAY DATA---\n");
  for (int i = 0; i < array_size; i++) {
    printf("test[%d]: %d\n", i, array_data[i]);
  }
  printf("---END ARRAY DATA---\n");
  return; //print_array()
}


/* ------------------------------------------------
FUNCTION: find_median()
------------------------------------------------ */
int find_median(unsigned char array_data[], int array_size) {
  int median = 0;
  int i = 0;

  sort_array(array_data, array_size);

  if (SIZE % 2 == 0) {  //Check if array_size is even
    i = SIZE / 2;
  }
  else {    // Else, array_size is odd
    i = ((SIZE / 2) + 0.5);
  }
  return array_data[i]; //Get value at that index
}


/* ------------------------------------------------
FUNCTION: find_mean(), for unsorted array data  
------------------------------------------------ */
float find_mean(unsigned char array_data[], int array_size) {
  int sum = 0;
  for (int i = 0; i < array_size; i++) {
    sum += array_data[i];
  }
  return sum/array_size;  
}


/* ------------------------------------------------
FUNCTION: find_maximum(), for unsorted array data
------------------------------------------------ */
int find_maximum(unsigned char array_data[], int array_size) {
  int max = array_data[0];
  for (int i = 0; i < array_size; i++) {
    if (array_data[i] > max) {
      max = array_data[i];
    }
  }
  return max;
}


/* ------------------------------------------------
FUNCTION: find_minimum(), for unsorted array data
------------------------------------------------ */
int find_minimum(unsigned char array_data[], int array_size) {
  int min = array_data[0];
  for (int i = 0; i < array_size; i++) {
    if (array_data[i] < min) {
      min = array_data[i];
    }
  }
  return min;
}

/* ------------------------------------------------
FUNCTION: sort_array(): sorts in place
------------------------------------------------ */
void sort_array(unsigned char array_data[], int array_size) {
  int i,j;
  for (int i = 0; i < array_size; i++) {    //Main loop
		for (int j = 0; j < array_size; j++) {  //Loop to get second value
			if (array_data[j] < array_data[i]) {  //Compare values
				int tmp = array_data[i];            //
				array_data[i] = array_data[j];      //Swap value locations
				array_data[j] = tmp;                //
			}
		}
	}
  return;
}


