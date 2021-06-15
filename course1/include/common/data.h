// Brian Weinstein
// June 15th 2021
// data.h
//
// basic memory manipulations

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef __DATA_H__
#define __DATA_H__

#define BASE_16 (16)
#define BASE_15 (15)
#define BASE_14 (14)
#define BASE_13 (13)
#define BASE_12 (12)
#define BASE_11 (11)
#define BASE_10 (10)
#define BASE_9 (9)
#define BASE_8 (8)
#define BASE_7 (7)
#define BASE_6 (6)
#define BASE_5 (5)
#define BASE_4 (4)
#define BASE_3 (3)
#define BASE_2 (2)

/**
 * @brief Integer-to-ASCII conversion
 * 
 * Integer-to-ASCII needs to convert data from a standard integer type into an ASCII string.
 * All operations need to be performed using pointer arithmetic, not array indexing
 * The number you wish to convert is passed in as a signed 32-bit integer.
 * You should be able to support bases 2 to 16 by specifying the integer value 
 * of the base you wish to convert to (base).
 * Copy the converted character string to the uint8_t* pointer passed in as a parameter (ptr)
 * The signed 32-bit number will have a maximum string size (Hint: Think base 2).
 * You must place a null terminator at the end of the converted c-string
 * Function should return the length of the converted data (including a negative sign). 
 * Example my_itoa(ptr, 1234, 10) should return an ASCII string length of 5 
 * This function needs to handle signed data.
 * You may not use any string functions or libraries
 * 
 * @param int32_t data Data to be converted to ASCII
 * @param uint8_t ptr Pointer data where data is manipulated in memory
 * @param uint32_2 base Base number system of Data to be converted
 *
 * @return uint8_t strlen String length of converted data (including negative sign)
 *
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

	

/**
 * @brief ASCII-to-Integer converter
 * 
 * ASCII-to-Integer needs to convert data back from an ASCII represented 
 * string into an integer type.
 * All operations need to be performed using pointer arithmetic, not array indexing
 * The character string to convert is passed in as a uint8_t * pointer (ptr).
 * The number of digits in your character set is passed in as a uint8_t integer (digits).
 * You should be able to support bases 2 to 16.
 * The converted 32-bit signed integer should be returned.
 * This function needs to handle signed data.
 * You may not use any string functions or libraries
 * 
 * @param uint8_t ptr Pointer to the character string to be converted
 * @param int32_t digits Number of characters in character set
 * @param uint32_2 base Base number system of Data to be converted
 *
 * @return int32_t val The converted 32-bit signed integer  
 *
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);


/*get value from char array helper function*/
int getval(char c, char * chararray);


/*exponent helper function*/
int power(uint32_t base, int exp);


#endif /* __DATA_H__ */
