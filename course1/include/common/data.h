/* DATA.H PLACE HOLDER 

data.c/data.h Requirements

This file should do some very basic data manipulation.*/

#ifndef __DATA_H__
#define __DATA_H__


int BASE_16 = 16;
int BASE_15 = 15;
int BASE_14 = 14;
int BASE_13 = 13;
int BASE_12 = 12;
int BASE_11 = 11;
int BASE_10 = 10;
int BASE_9 = 9;
int BASE_8 = 8;
int BASE_7 = 7;
int BASE_6 = 6;
int BASE_5 = 5;
int BASE_4 = 4;
int BASE_3 = 3;
int BASE_2 = 2;

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



#endif /* __DATA_H__ */
