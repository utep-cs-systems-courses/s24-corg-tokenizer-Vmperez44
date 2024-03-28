#include <stdio.h>
#include "tokenizer.h"

int space_char(char c){
  return (c == ' ' || c== '\t') && c!= '0';
  
}

int non_space_char(char c){
  return (c!=' ' || c!='\t') && c!='0';
  
}

char *token_start(char *str){

  int count = 0;
  while(space_char(str[count])){
    if(str[count] == '\0'){
      return NULL;
    }
    count++;
  }
  return str+count;

}

char *token_terminator(char *token){
 
  while(*token != '\0'){
    token++;
  }
  return token;
  
}

int count_tokens(char *str){

  int count = 0;
  while(*str != '\0'){
    str = token_start(str);

    str = token_terminator(str);

    count++;
  }
  return count;

}

char *copy_str(char inStr, short len){

  char *copy = malloc((len+1) * sizeof(char));

  for (int i = 0; i<len; i++){
    copy[i] = inStr[i];
  }
  copy[i] = '\0';
  return copy;

}

char **tokenize(char* str){

  int count = count_tokens(str);
  char **tokens = malloc(sizeof(char *) * (count +1));
  char *token = str;
  for (int i = 0; i<count; i++){
    char* start = token_start(token);
    char* end = token_terminator(token);
    int length =  end-start;
    tokens[i] = copy_str(start, length);

  }

  tokens[count] = '\0';
  
  return tokens;
}

void print_tokens(char **tokens){

  int i = 0;
  while(tokens[i]!= NULL){
    printf("\n Tokens[%d] : %s\n", i, tokens[i]);
    i++;
  }

}

void free_tokens(char tokens){

  int i =0;
  while(tokens[i]){
    free(tokens[i]);
    i++;
  }
}
