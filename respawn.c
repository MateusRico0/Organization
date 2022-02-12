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

int main(){
  struct items *all = NULL;
  struct items *exist = NULL;
  struct items *voided = NULL;

  new_item(&all,"Opaa...\n");
  new_item(&all,"Alo\n");
  new_item(&all,"Alguem?\n");
  new_item(&all,"OI show\n");
  show_items(all);
  delete_item(&all,"Alguem?\n");
  show_items(all);
}
