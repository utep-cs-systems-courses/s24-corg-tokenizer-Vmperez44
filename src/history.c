
#include <stdio.h>
#include <stdlib.h>
#include "history.h"




/* Initialize the linked list to keep the history. */

List* init_history(){

  List *token_history;
  token_history = malloc(sizeof(List));
  return token_history;
  
}



/* Add a history item to the end of the list.

   List* list - the linked list

   char* str - the string to store

*/

void add_history(List *list, char *str){

  Item *new_item = (Item*) malloc(sizeof(Item));
  int string_length = 0;
  while(str[string_length] != '\0'){
    string_length++;
  }
  new_item->str = copy_str(str, string_length);

  if(list->root ==NULL){
    list->root = new_item;
    new_item->id-1;
  }
  
  else{
    Item *temp_item = list->root;
    while(temp_item->next != NULL){
      new_item->id += 1;
      temp_item = temp_item->next;
    }
    temp_item->next=new_item;
    new_item->id += 1;
  }
  
}



/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char *get_history(List *list, int id){

  Item * curr_item = list->root;
  while(curr_item != 0){
    if(curr_item->id == id){
      return curr_item->str;
    }
    
    curr_item = curr_item->next;
  }
  
  return "No history";

}




/*Print the entire contents of the list. */
void print_history(List *list){

  if(list == NULL || list->root ==NULL){
    printf("No history to print");
    return;
  }
  Item *temp = list->root;
  while(temp != NULL){
    printf("[%d] %s\n", temp->id, temp->str);
    temp = temp->next;
  }

}



/*Free the history list and the strings it references. */

void free_history(List *list){

  Item *current = list->root;
  while(current != NULL){
    Item *prev = current;
    free(current->str);
    current = prev->next;
    free(prev);
  }

  free(list);

}


