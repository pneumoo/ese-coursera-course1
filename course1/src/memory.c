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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}


void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}


char get_value(char * ptr, unsigned int index){
  return ptr[index];
}


void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}


void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}


uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {
	/*For case of data overlap, copy data backwards*/
	if(src < dst && dst <= (src + length)) {
		unsigned int i;
		for (i = 0; i < length; i + sizeof(length)) {
			*(dst+length - i) = *(src+length - i);
		}
	}
	/* Otherwise, we can use just regular copy */
	else{
		my_memcopy(src, dst, length);
	}
	return dst;
}


uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
	unsigned int i;
	/*Moves src+i byte to dst+i byte until all have been moved*/
	/*Data corruption may occur if (src < dst <= src+length) */
	for (i = 0; i < length; i + sizeof(length)) {
		*(dst + i) = *(src + i);
	}
	return dst;
}


uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
	size_t i;
	for (i = 0; i < length; i++) {
		*(src++) = value;
	}
	return src;
}


uint8_t * my_memzero(uint8_t * src, size_t length) {
	// Just use my_memset with zero setting. Already returns src pointer.
	return my_memset(src, length, 0);
}


uint8_t * my_reverse(uint8_t * src, size_t length) 
{
  int a, b;                     			//variables to store swap values

  for(int i=0; i<length/2; i++) 
  {
    a = *(src+i);               			//a gets value from dereferenced arr ptr (increments up)
    b = *(src + (length-i-1));        //b decrements. -1 due to length->index difference
    
    *(src+i) = b;
    *(src + (length-i-1)) = a;        //swap the values    
  }

	return src;  
} 


int32_t * reserve_words(size_t length) 
{
	int32_t * p = malloc(length * sizeof(int32_t));
	
	// malloc may not be able to service this request...
	//... so it's good practice to check for NULL pointer 
	if (p == NULL) 
	{
  	fprintf(stderr, "malloc failed\n");
  	return -1;
  }
  
  else 
  {
		return p;
	}
} 


void free_words(int32_t * src) 
{
	free(src);
	return 0;
}








