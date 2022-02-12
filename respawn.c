#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

struct items{
  char item[50];
  struct items *next;
};

#include "list.h"

void Upper(struct items **str){
  for(int i = 0; i < 50; i++){
    if((*str)->item[i] > 96  && (*str)->item[i] < 123)
      (*str)->item[i] -= 32;
  }
}

/**
* 1st line: Cash
* 2nd line: N of all elements
* Next lines: N elements
* N+1: N of elements that the person have
* ...
*/
int get_data(struct items **all, struct items **live, struct items **dead){

  int cash;
  int structs_Num;
  char name[50];

  FILE *arq = fopen("data.txt","r");
  fscanf(arq,"%d\n",&cash);

  fscanf(arq,"%d\n",&structs_Num); // Number of structs that will be read
  for(int i = 0; i < structs_Num; i++){
    fscanf(arq,"%[^\n]\n",&name);
    new_item(&(*all), name);
  }

  fscanf(arq,"%d\n",&structs_Num);
  for(int i = 0; i < structs_Num; i++){
    fscanf(arq,"%[^\n]\n",&name);
    new_item(&(*live), name);
  }

  fscanf(arq,"%d\n",&structs_Num);
  for(int i = 0; i < structs_Num; i++){
    fscanf(arq,"%[^\n]\n",&name);
    new_item(&(*dead), name);
  }
  fclose(arq);

  return cash;
}

void update_data(int wallet){
  FILE *arq = fopen("data.txt","w");
  fprintf(arq,"%d\n",wallet);
  fclose(arq);
}

int main(){
  FILE *arq = fopen("data.txt","a");
  fclose(arq);

  struct items *all = NULL;
  struct items *live = NULL;
  struct items *dead = NULL;

  int wallet = get_data(&all, &live, &dead);
}
