// Brian Weinstein
// June 15th 2021
// data.c
//
// This file does basic memory manipulations

#include "data.h"
#include "memory.h"

// Character array for ASCII values up to base 16
char hex [] = { '0', '1', '2', '3', '4', '5', \
  '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) 
{
  int r; // placeholder for remainder
  int negflag = 0;
  int length = 0; // keeps track of length of ascii
	uint8_t * temp_ptr = ptr; // to remember beginning of memory location


  if(data<0)
  {
    data = -data; //make number positive for math to work
    negflag = 1;
  }

  while(data != 0)
  {
    r = data % base;	//get remainder of division by 'base'
    data = data / base; //set num equal to the quotient
    *ptr++ = hex[r]; // put hex val in that location
    length++;
  }

  if(negflag == 1) 
  {
    *ptr = '-'; //adds negative sign and leave ptr there
    length++;
  }
  else 
  {
    ptr--; //corrects ptr location to last value
  }

  // reverse everything so that it's in teh correct order for later
  my_reverse(temp_ptr, length);
	
	length = length + 1; // to account for '\0' terminator
		
	return length; //Length of converted data (ASCII)
}





int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) 
{
  int negflag = 0;	//flag for neg numbers
	int32_t sum = 0; //for summing up the base conversion
	
	if(*ptr == '-')	//check for negative
	{
		negflag = 1;	
		digits--;			//decrement the digit count
		ptr++;				//move pointer past the '-'
	}

	for(int i = digits-2; i >=0; i--) // loop through remaining ascii characters
	{
		sum += getval(*ptr, hex) * power(base, i);
		ptr++;
	}
	
	if(negflag == 1)
	{
		sum = -sum;
	}


	return sum; //Converted 32-bit signed integer
}




// add helper func to get index of hex[]
int getval(char c, char * chararray)
{
	for(int i=0; i<16; i++)
	{
		if(chararray[i] == c)
		{		
			return i;			
		}	
	}
	printf("ERROR - VALUE NOT FOUND. RETURNING 0");
	return 0;
}


// add exponent helper function
int power(uint32_t base, int exp) 
	{
  int i, result = 1;
  for (i = 0; i < exp; i++)
		{
			result *= base;
		}
  return result;
}


