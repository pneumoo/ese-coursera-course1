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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);


/**
 * @brief Moves bytes from one location to another
 * 
 * This function takes two byte pointers (one source and one destination) 
 * and a length of bytes to move from the source location to the destination.
 * The behavior should handle overlap of source and destination. 
 * Copy should occur, with no data corruption. All operations need to be 
 * performed using pointer arithmetic, not array indexing
 *
 * @param uint8_t src Pointer to the source memory byte
 * @param uint8_t dst Pointer to destination memory byte
 * @param size_t length The length of bytes to move
 *
 * @return uint8_t dst, Returns the pointer of the destination
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);


/**
 * @brief Copies bytes from one location to another
 * 
 * This function takes two byte pointers (one source and one destination) 
 * and a length of bytes to copy from the source location to the destination.
 * The behavior is undefined if there is overlap of source and destination. 
 * Copy should still occur, but will likely corrupt your data. All operations
 * need to be performed using pointer arithmetic, not array indexing.
 *
 * @param uint8_t src Pointer to the source memory byte
 * @param uint8_t dst Pointer to destination memory byte
 * @param size_t length The length of bytes to copy
 *
 * @return uint8_t dst, Returns the pointer of the destination
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);


/**
 * @brief Sets bytes at mem location to a value
 * 
 * This should take a pointer to a source memory location, a length in bytes 
 * and set all locations of that memory to a given value.
 * You should NOT reuse the set_all() function.
 *
 * @param uint8_t src Pointer to the source memory byte
 * @param size_t length The length of bytes
 * @param uint8_t value The bytes will be set to this value
 *
 * @return uint8_t src, Returns the pointer of the source
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);


/**
 * @brief Sets all bytes to zero 
 * 
 * This should take a pointer to a source memory location, a length in bytes 
 * and set all locations of that memory to zero. 
 * You should NOT reuse the set_all() function.
 *
 * @param uint8_t src Pointer to the source memory byte
 * @param size_t length The length of bytes
 *
 * @return uint8_t src, Returns the pointer of the source
 */
uint8_t * my_memzero(uint8_t * src, size_t length);


/**
 * @brief Reverses the order of a section of memory
 * 
 * This should take a pointer to a memory location and a length in 
 * bytes and reverse the order of all of the bytes.
 * All operations need to be performed using pointer arithmetic, not array indexing
 *
 * @param uint8_t src Pointer to the source memory byte
 * @param size_t length The length of bytes
 *
 * @return uint8_t src, Returns the pointer of the source
 */
uint8_t * my_reverse(uint8_t * src, size_t length);


/**
 * @brief Allocates words in dynamic memory
 * 
 * This should take number of words to allocate in dynamic memory
 * All operations need to be performed using pointer arithmetic, not array indexing
 * Should return a pointer to memory if successful, or a Null Pointer if not successful
 *
 * @param length The length of words
 *
 * @return int32_t ptr, Mem location if successful, Null if not successful. 
 */
int32_t * reserve_words(size_t length);


/**
 * @brief Frees words in memory
 * 
 * Should free a dynamic memory allocation by providing the pointer src to the function
 * All operations need to be performed using pointer arithmetic, not array indexing
 *
 * @param length The length of words
 *
 * @return void 
 */
void free_words(void * src);  // passed type needs to be void for some reason...?




#endif /* __MEMORY_H__ */
