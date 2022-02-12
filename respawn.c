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

int get_data(){
  int cash;
  int structs_Num;
  FILE *arq = fopen("data.txt","r");
  fscanf(arq,"%d\n",&cash);
//  fscanf(arq,"%d\n",&structs_Num);


  fclose(arq);

  return cash;
}

int main(){
  FILE *arq = fopen("data.txt","a");
  fclose(arq);

  struct items *all = NULL;
  struct items *exist = NULL;
  struct items *voided = NULL;

  int wallet = get_data();

}
