#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1024

int main(void) {
	int baseA=0, baseB=0, i, scanCheck=0, input_size=0, decimal_sum=0;
	char input[MAX_SIZE], output[MAX_SIZE];
	char c;
	printf("Please enter the number's base:\n");
	fflush(stdout);
	scanCheck=scanf("%d",&baseA);
	if(scanCheck==0){
		printf("An error occurred!\n");
		fflush(stdout);
		return 0;
	}
	if(baseA<2 || baseA>16){
		printf("Invalid input base\n");
		fflush(stdout);
		return 0;
	}
	printf("Please enter the desired base:\n");
	fflush(stdout);
	scanCheck=scanf("%d",&baseB);
	if(scanCheck==0){
		printf("An error occurred!\n");
		fflush(stdout);
		return 0;
	}
	if(baseB<2 || baseB>16){
		printf("Invalid desired base\n");
		fflush(stdout);
		return 0;
	}
	printf("Please enter a number in base %d:\n",baseA);
	fflush(stdout);
	scanf("%s", input);
	while(input[input_size]!='\0'){
		c=input[input_size];
		if('0'<=c && c<='9' && c<baseA+'0'){
			input[input_size++]=c-'0';
		}
		else if('a'<=c && c<='a'+(baseA-10)){
			input[input_size++]=c-'a'+10;
		}
		else if('A'<=c && c<='A'+(baseA-10)){
			input[input_size++]=c-'A'+10;
		}
		else{
			printf("Invalid number!\n");
			fflush(stdout);
			return 0;
		}
	}
	/*converting to decimal:*/
	for(i=0,decimal_sum=0;i<input_size;i++){
		decimal_sum=(decimal_sum*baseA)+input[i];
	}
	/*converting to baseB:*/
	i=MAX_SIZE-1;
	output[i--]='\0';
	for(;i>=0 && decimal_sum>0;i--){
		if(decimal_sum%baseB<10){
			output[i]=decimal_sum%baseB+'0';
		}
		else output[i]=decimal_sum%baseB-10+'A';
		decimal_sum/=baseB;
	}
	printf("The result is : %s\n",output+i+1);
	fflush(stdout);

	return 0;
}
