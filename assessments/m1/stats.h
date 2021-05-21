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
 * @file stats.h
 * @brief Header file for a simple application that performs statistical analytics on a dataset. 
 *
 *  print_statistics()
 *  print_array()
 *  find_median()
 *  find_mean()
 *  find_maximum()
 *  find_minimum()
 *  sort_array()
 *
 * @author Brian Weinstein
 * @date May 19, 2021
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param array_data is a 1D array of data
 *
 * @return no return, only print statements
 */
void print_statistics(unsigned char array_data[], int array_size);


/**
 * @brief Given an array of data and a length, prints the array to the screen
 * 
 * @param array_data is a 1D array of data
 * @param array_size size of array_data
 *
 * @return no return, only print statements
 */
void print_array(unsigned char array_data[], int array_size);


/**
 * @brief Given an array of data and a length, returns the median value
 *
 * @param array_data is a 1D array of data
 * @param array_size size of array_data
 *
 * @return no return, only print statements
 */
int find_median(unsigned char array_data[], int array_size);


/**
 * @brief Given an array of data and a length, returns the mean
 *
 * @param array_data is a 1D array of data
 * @param array_size size of array_data
 *
 * @return no return, only print statements
 */
int find_mean(unsigned char array_data[], int array_size); 


/**
 * @brief Given an array of data and a length, returns the maximum
 *
 * @param array_data is a 1D array of data
 * @param array_size size of array_data
 *
 * @return no return, only print statements
 */
int find_maximum(unsigned char array_data[], int array_size); 


/**
 * @brief Given an array of data and a length, returns the minimum
 *
 * @param array_data is a 1D array of data
 * @param array_size size of array_data
 *
 * @return no return, only print statements
 */
int find_minimum(unsigned char array_data[], int array_size); 


/**
 * @brief Given an array of data and a length, sorts the array from largest to smallest. 
 * 
 * (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value.
 * 
 * @param array_data is a 1D array of data
 * @param array_size size of array_data
 *
 * @return no return, only print statements
 */
void sort_array(unsigned char array_data[], int array_size); 


#endif /* __STATS_H__ */