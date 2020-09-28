#include <stdio.h>
#include "tokenizer.c"
#include "history.c"

int main(){
  List *history = init_history();
  char choice;
  int input;
  char string[100];
  int x = 0;
  while(x == 0){
  printf("Welcome to Tokenizer...\n");
  printf("______________________________________\n");
  printf("Here are your options\n");
  printf("Press 't' to TOKENIZE\n");
  printf("Press 'h' to VIEW HISTORY\n");
  printf("Press 'i' to VIEW HISTORY AT SPECIFIC ID\n");
  printf("Press '0' to EXIT\n\n");
  scanf("%c", &choice);
  printf("\n\n");

 


    switch(choice){
    case 't':
      printf("Enter string: ");
      fgets(string, 100, stdin);
      char **tokens = tokenize(string);      
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
    case '0':
      printf("EXIT");
      free_history(history);
      x = 1;
      break;
   }

  }
 


}
