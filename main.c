#include <stdio.h>

/*
 large number formats
----------------------

numbers are saved as an array of 1024 chars.
each char represents one digit, and must be between 0 and base-1 (inclusive)

the last digit (num[1023]) will be the least significant

therefore, the array
 char num[1024] = {...}

will represent the number
 sum {i = 0->1023} (num[1023-i] * base^i)

*/


/* 
converts large number (saved as described at top of file) to string

reads number from 'num'
outputs number to 'str'
(base is not needed for conversion)
*/
void to_string(char num[1024], char str[1025]){
	/* saves whether a non-zero digit was encountered */
	char non_zero = 0;
	/* index for num */
	int i;
	/* index for str */
	int j;
	/* list of digits */
	char digits[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	
	
	for(i=0,j=0;i<1024; i++){
		/* this condition will remove all zeros at the begining of the number */
		if(non_zero ||  num[i]){
			/* write digit */
			str[j] = digits[(int) num[i]];
			/* non zero digit encountered */
			non_zero = 1;
			/* go to next string position */
			j++;
		}
	}
	
	/* if all digits encountered were zero, insert 0 */
	if(! non_zero){
		str[j] = digits[0];
		j++;
	}
	/* insert null character at end of string */
	str[j] = '\0';
}

/*
implements division of large number by small number


num: the list of digits of input number (see large number format at top of file)
out: list of digits of output number (out <- num/div)
div: number to divide by
base: base in which large numbers are saved

returns: the remainder.

NOTE: function would still work if num and out are the same variable, num would be overwritten.
*/
int divmod(char num[1024], char out[1024], int div, int base){
	/* the value of all digits read from 'num'
	   minus those writen to 'out' */
	int collected = 0;
	/* loop index */
	int i;
	
	for(i = 0; i<1024; i++){
		/* insert next digit to 'collected' */
		collected *= base;
		collected += num[i];
		
		/* calculate and write next output digit */
		out[i] = collected / div;
		
		/* decrease the writen digit from collected */
		collected %= div;
	}
	
	/* the remainder remains in collected */
	return collected;
}

int main(){
	return 0;
}