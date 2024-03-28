#include <stdio.h>
#include "tokenizer.h"

int space_char(char c){
  return (c == ' ' || c== '\t') && c!= '0';
  
}

int non_space_char(char c){
  return (c!=' ' || c!='/t') && c!='0';
  
}

char *token_start(char *str){
  char *start = NULL;
  if(str!= NULL){
    start = str;
  }
  
  while (*start != ' ' && *start != '\0'){
    start++;
  }
  if (*start== '\0') {
    return 0;
  }else{
    *start = '\0';
    start++;
    return start;
  }
  
}

char *token_terminator(char *token){
  while(*token!= '\0'){
    token++;
  }
  return token;
  
}

int count_tokens(char *str){
  

}

char *copy_str(char inStr, short len){


}

char **tokenize(char* str){


}

void print_tokens(char **tokens){


}

void free_tokens(char tokens){


}
