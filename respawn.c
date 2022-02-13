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
int get_data(struct items **all, struct items **alive, struct items **dead){

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
    new_item(&(*alive), name);
  }

  fscanf(arq,"%d\n",&structs_Num);
  for(int i = 0; i < structs_Num; i++){
    fscanf(arq,"%[^\n]\n",&name);
    new_item(&(*dead), name);
  }
  fclose(arq);

  return cash;
}

void update_data(int wallet, struct items *all, struct items *alive, struct items *dead){
  int size = size_list(all);

  FILE *arq = fopen("data.txt","w");
  fprintf(arq,"%d\n",wallet);

  fprintf(arq,"%d\n", size);
  for(int i = 0; i < size; i++){
    fprintf(arq,"%s\n",all->item);
    all = all->next;
  }

  size = size_list(alive);
  fprintf(arq,"%d\n", size);
  for(int i = 0; i < size; i++){
    fprintf(arq,"%s\n",alive->item);
    alive = alive->next;
  }

  size = size_list(dead);
  fprintf(arq,"%d\n", size);
  for(int i = 0; i < size; i++){
    fprintf(arq,"%s\n",dead->item);
    dead = dead->next;
  }

  fclose(arq);
}

int main(){
  FILE *arq = fopen("data.txt","a");
  fclose(arq);

  struct items *all = NULL;
  struct items *alive = NULL;
  struct items *dead = NULL;

  int wallet = get_data(&all, &alive, &dead);
  int order;
  int stop = 1;
  while(stop){
    printf("Your wallet: %d\n\n",wallet);
    printf("ALL YOU ITENS:\n");
    show_items(all);
    printf("Opitions:\n");
    printf("0 - Left\n");
    printf("1 - Add or remove money\n");
    printf("2 - add a item in your list\n");
    printf("3 - remove a item in your list\n: ");
    scanf("%d",&order);
    if(order == 1){
      printf("What is the value?\n");
      int val;
      scanf("%d",&val);
      wallet += val;
      update_data(wallet,all,alive,dead);
    }else{
      if(order == 2){
        printf("What is the item?\n");
        char nam[50];
        scanf("%s",&nam);
        new_item(&all,nam);
        new_item(&alive,nam);
        update_data(wallet,all,alive,dead);
      } else{
          if(order == 3){
            printf("What is the item?\n");
            char nam[50];
            scanf("%s",&nam);
            delete_item(&alive,nam);
            new_item(&dead, nam);
            update_data(wallet,all,alive,dead);
          }else if(order == 0) stop = 0;
        }
      }
    system("clear"); // linux
    // system("cls") // windows
  }

  printf("THE END\n");
}
