#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main(){

  List *history = init_history();
  int x = 0;
  printf("Welcome to Tokenizer...\n");
  printf("______________________________________\n");
  printf("Here are your options\n");
  printf("Press 't' to TOKENIZE\n");
  printf("Press 'h' to VIEW HISTORY\n");
  printf("Press 'i' to VIEW HISTORY AT SPECIFIC ID\n");
  printf("Press '0' to EXIT");
  scanf("%c", &choice);
  printf("\n\n");

  while(x == 0){

    switch(choice){
    case 't':
      printf("Enter string: ");
      scanf("%s", &string);
      char **tokens = tokenize(string);
      printf("\n");
      print_tokens(tokens);
      add_history(history,string);
      free_tokens(tokens);
      char *firstWord = word_start(string);
      int wordTotal = count_words(string);
      printf("\n");
      printf("First word of string: %c\n",firstWord); 
      printf("Total number of words: %d\n",wordTotal);
      break;
    case 'h':
      printf("_________________________________\n");
      printf("Displaying History\n");
      print_history(history);
      break;
    case 'i':
      printf("Enter specific id: ");
      scanf("%d",&input);
      char **token = tokenize(get_history(history, input));
      print_tokens(token);
      free_tokens(token);
      break;
   }

  }
 


}
