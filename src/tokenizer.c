#ifndef _TOKENIZER_
#define _TOKENIZER_
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#define true 1
#define false 0


/*Return true (non-zero)  if c is a whitespace character ('\t' or ' ').
  Zero terminators are not printable (therefore false) */
int space_char(char c){
  if(c == ' ' || c == '\t'|| c == '\n'){
    return true;
  }
  else{
       return false;
       }
}  
 

/* Return true (non-zero) if c is a non-whitespace character (not tab or space).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c){
  if(c == '\t' || c == ' ' || c == '\n'){
    return false;
  }
  else{
    return true;
  }
}
/*Returns a pointer to the first character of the next space-separated word in
  zero-terminated str. Return a sero pointer if str does not contain any words. */
  char  *word_start(char *str){
    //while there's a space at the beg of str, keep moving on
    int i =0;
    while(!non_space_char(str[i])){
	i++;
      }
      //if not then return the pointer of the 1st character
      return &str[i];
  }


/*Returns a pointer terminator char following *word*/
    char *word_terminator(char *word){
      while(!space_char(*word)){
	word ++;
      }
      //
	return word;
      }

/*Counts the number of words in the string argument. */
      int count_words(char *str){
	int i = 0;
	int count = 0;
	int count2 = 0;
	while(*str){
	  if(*str == '\t' || *str == ' ' || *str == '\n'){
	    count2 = 0;
	  }else if(count2 == 0){
	    count2 = 1;
	    count++;
	  }
	  str++;
	}
	return count;
      }

/*Returns a freshly allocated new zero-terminated string
  containing <len> chars from <inStr> */
      char *copy_str(char *inStr, short len){
	char *outStr = malloc((len + 1) * sizeof(char));
	int i = 0;
 
	while(i<=len){
	  outStr[i] = inStr[i];
	  i++;
	}
	return outStr;
      }

/*Returns a freshly allocated zero-terminated vector of freshly
  allocated space-separated tokens from zero-terminated str.*/
      char **tokenize(char* str){
	int totalNumWords = count_words(str);
	char **tokens = malloc((totalNumWords+1) * sizeof(char *));
	char *startWord = word_start(str);
	char *wordTerm = word_terminator(str);
	int i;
	for(i =0; i<totalNumWords; i++){
	  tokens[i] = copy_str(startWord, wordTerm-startWord);
	  startWord = word_start(wordTerm);
	  wordTerm = word_terminator(startWord);
	}
	tokens[i] = NULL;
	return tokens;
      }
    


/*Prints all tokens. */
 void print_tokens(char **tokens){
   int i =0;
   while(tokens[i] != NULL){
     printf("%s\n", tokens[i]);
     i++;
   }
 }


/* Frees all tokens and the vector coontaining themxxx. */
 void free_tokens(char **tokens){
   int i = 0;
   while(tokens[i] != NULL){
     free(tokens[i]);
     i++;
   }
   free(tokens);
 }


#endif
