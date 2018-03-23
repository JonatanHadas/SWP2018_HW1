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
implements division of large number by small number


num: the list of digits of input number (see large number format in begining of file)
out: list of digits of output number (out <- num/div)
div: number to divide by
base: base in which large numbers are saved

returns: the remainder.


*/
int divmod(char num[1024], char out[1024], int div, int base){
	/* the value of all digits read from 'num'
	   minus those writen to 'out'
	*/
	int collected = 0;
	/* loop index
	*/
	int i;
	
	for(i = 0; i<1024; i++){
		/* insert next digit to 'collected'
		*/
		collected *= base;
		collected += num[i];
		
		/* calculate and write next output digit
		*/
		out[i] = collected / div;
		
		/* decrease the writen digit from collected
		*/
		collected %= div;
	}
	
	/* the remainder remains in collected
	*/
	return collected;
}

int main(){
	return 0;
}