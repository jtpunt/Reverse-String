#include <stdio.h>
#include <string.h>
int main(){
	char myStr[] = "Reverse, this string\n";
	int i, j, lastIdx = strlen(myStr) - 2;
	printf("%zu\n", strlen(myStr));
	for(i = strlen(myStr) - 1; i >= 0; i--){
		if(myStr[i] == '\n'){ // skip the newline character
			printf("Newline char found at: %d\n", i);
		}else{ // valid characters should follow
			if(myStr[i] == ' '){
				printf("Space char found at: %d\n", i);
				// the word we wish to extract is 1 index after the space
				for(j = i + 1; j <= lastIdx; j++){
					printf("%c", myStr[j]);
				}
				// if there's a comma, it'll be before the space
				if(myStr[i - 1] == ','){
					printf("%c\n", myStr[i - 1]);
					lastIdx = i - 2;
				}else{
					lastIdx = i - 1;
				}
				printf("\n");
				// printf("%c - %d\n", myStr[i], i);
			}else if(i == 0){
				printf("Space char found at: %d\n", i);
				for(j = i; j <= lastIdx; j++){
					printf("%c", myStr[j]);
				}
				printf("\n");
				lastIdx = i - 1;
				// printf("%c - %d\n", myStr[i], i);
			}else{
				printf("%c - %d\n", myStr[i], i);
			}
		}
	}
	printf("\n");
}