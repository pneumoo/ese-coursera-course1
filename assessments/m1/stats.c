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

//---------TESTING-------------
  //find_mean() and print
  int mean = find_mean(test, SIZE);
  printf("Mean: %f\n", mean); //TODO: this seems to FLOOR avg value... why? 

  // find_maximum() on unsorted data
  int max = find_maximum(test, SIZE);
  printf("Maximum value: %d\n", max);

  // find_minimum() on unsorted data
  int min = find_minimum(test, SIZE);
  printf("Minimum value: %d\n", min);
//---------/TESTING/------------

  return; // main() return
}

/* ------------------------------------------------
FUNCTION: print_statistics() 
------------------------------------------------ */
void print_statistics(unsigned char array_data[], int array_size) {
  // add statistics functions here...
  int min = find_minimum(array_data, array_size);
  int max = find_maximum(array_data, array_size);
  float mean = find_mean(array_data, array_size);
  float median = 0.0; //TODO: add the find_median() call here when that function is complete

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
  //use sort function here
  //then do median math
  //return median

/* ------------------------------------------------
FUNCTION: find_mean()  
------------------------------------------------ */
int find_mean(unsigned char array_data[], int array_size) {
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
FUNCTION: sort_array()
------------------------------------------------ */
