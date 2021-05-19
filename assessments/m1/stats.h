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
 * 
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
 * @param p pointer to data array
 *
 * @return no return, only print statements
 */
void print_statistics(char p)


/**
 * @brief Given an array of data and a length, prints the array to the screen
 * 
 * @param p pointer to data array
 * @param size size of data array
 *
 * @return no return, only print statements
 */
void print_array(char p, int size) 


/**
 * @brief Given an array of data and a length, returns the median value
 *
 * @param p pointer to data array
 * @param size size of data array
 *
 * @return no return, only print statements
 */
int median find_median(char p, int size) 


/**
 * @brief Given an array of data and a length, returns the mean
 *
 * @param p pointer to data array
 * @param size size of data array
 *
 * @return no return, only print statements
 */
int mean find_mean(char p, int size) 


/**
 * @brief Given an array of data and a length, returns the maximum
 *
 * @param p pointer to data array
 * @param size size of data array
 *
 * @return no return, only print statements
 */
int max find_maximum(char p, int size) 


/**
 * @brief Given an array of data and a length, returns the minimum
 *
 * @param p pointer to data array
 * @param size size of data array
 *
 * @return no return, only print statements
 */
int min find_minimum(char p, int size) 


/**
 * @brief Given an array of data and a length, sorts the array from largest to smallest. 
 * 
 * (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value.
 * 
 * @param p pointer to data array
 * @param size size of data array
 *
 * @return no return, only print statements
 */
void sort_array(char p, int size) 


#endif /* __STATS_H__ */