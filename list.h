int str_compare(char str1[], char str2[]){
  int i = 0;
  int count = 0;

  while( (str1[i] != '\0') || (str2[i] != '\0') ){
    if(str1[i]==str2[i]){
      count++;
    }
    i++;
  }
  if(i==count){
    if((str1[i] == '\0') && (str2[i] == '\0') ){
      return 1;
    }
  }
  return 0;
}

void new_item(struct items **node, char name[]){
  struct items *new = (struct items*) malloc(sizeof(struct items));
  strcpy(new->item,name);
  new->next = *node;

  *node = new;
}

void show_items(struct items *node){
  do{
    printf("%s\n",node->item);
    node = node->next;
  }while(node!=NULL);
  printf("b\n");
}
/* in process
void delete_item(struct items **node, char name[]){
  struct items *aux = *node;

  if(str_compare(((*node)->item), name)==1){
    *node = (*node)->next;
    free(aux);
  }

  while((*node)->next != NULL){
    if(str_compare(((*node)->next->item), name)==1){
      aux = (*node)->next;
      (*node)->next = (*node)->next->next;
      free(aux);
    }
  }
}
*/