#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* extractWord(char* myStr, int begIdx, int endIdx){
	int i, j = 0;
	char* word = malloc(sizeof(char) * endIdx - begIdx);
	memset(word, '\0', sizeof(word));
	for(i = begIdx; i <= endIdx; i++){
		word[j++] = myStr[i];
	}
	return word;
}
int main(){
	char myStr[] = "Reverse, this is a string\n";
	char reverseStr[strlen(myStr)];
	char *myWord = NULL;
	int i, j, lastIdx = strlen(myStr) - 2;
	memset(reverseStr, '\0', sizeof(reverseStr));
	printf("%zu\n", strlen(myStr));
	for(i = strlen(myStr) - 1; i >= 0; i--){
		if(myStr[i] != '\n'){ // skip the newline character
			if(myStr[i] == ' '){ // are we at a space char?
				// the word we wish to extract is 1 index after the space
				myWord = extractWord(myStr, i + 1, lastIdx);
				strcat(reverseStr, myWord);
				free(myWord);
				if(myStr[i - 1] == ','){ // if there's a comma, it'll be before the space
					strcat(reverseStr, ","); // add the comma after our previously extracted word
					lastIdx = i - 2; // skip the idx [i - 1], since it have already handled the comma
				}else{
					lastIdx = i - 1; // update lastIdx so we can extract the next word
				}
				strcat(reverseStr, " "); // add the space after the word we just extracted
			}else if(i == 0){ // are we at the beginning of our string?
				myWord = extractWord(myStr, i, lastIdx);
				strcat(reverseStr, myWord);
				free(myWord);
				lastIdx = i - 1;
			}else{ // every other character is handled here
				printf("%c - %d\n", myStr[i], i);
			}
		}
	}
	printf("%s\n", reverseStr);
}