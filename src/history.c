#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>
#include "history.h" 

/*Initialize the linked list to keep the history. */
List  *init_history(){
  List *list = malloc(sizeof(List));
  list->root = malloc(sizeof(Item));
  return list;
}

/*Add a history item to the end of the list.
List* list- the linked list
char* str- the string to store
*/
void add_history(List *list, char *str){
  int count = 1;
  Item *temp = list-> root;

  while(temp->next != NULL){
    count++;
    temp = temp->next;
  }
  temp->next = malloc(sizeof(Item));
  temp->id = count;
  temp->str = str;
  
  
}
/*Retrieve the string stored in the node where Item->id == id.
List* list - the linked list
int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item *curr = list->root;
  while(curr != NULL){
    if(curr->id == id){
      return curr->str;
    }
    curr = curr->next;
}
  return NULL;
}
/*Print the entire contents of the list*/
void print_history(List *list){
  Item *temp = list->root;

  while(temp != NULL){
    printf("id:%d str:%s\n", temp->id, temp->str);
    temp = temp->next;
  }
}
/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *curr = list->root;
  while(curr != NULL){
    free(curr->str);
    free(curr);
    curr = curr->next;
  }
  free(list);
}
