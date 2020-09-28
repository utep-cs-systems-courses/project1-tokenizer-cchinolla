#include <stdio.h>
#include "tokenizer.c"
#include "history.c"

int main(){
  List *history = init_history();
  char choice[100];
  int input;
  char string[100];
  int x = 0;
  
  printf("Welcome to Tokenizer...\n");
  printf("______________________________________\n");
  printf("Here are your options\n");
  while(x == 0)
    {
      printf("Press 't' to TOKENIZE\n");
      printf("Press 'h' to VIEW HISTORY\n");
      printf("Press 'i' to VIEW HISTORY AT SPECIFIC ID\n");
      printf("Press '0' to EXIT\n\n");
      fgets(choice, 100, stdin);
      printf("\n\n");

 


      switch(choice[0]){
      case 't':
	printf("Enter string: ");
	fgets(string, 100, stdin);
	char **tokens = tokenize(string);      
	print_tokens(tokens);
	add_history(history,string);
	free_tokens(tokens);
	break;
      case 'h':
	printf("_________________________________\n");
	printf("Displaying History\n");
	print_history(history);
	break;
      case 'i':
	printf("Enter specific id: ");
	scanf("%d", &input);
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
