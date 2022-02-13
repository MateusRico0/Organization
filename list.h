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
  if(node != NULL){
    do{
      printf("%s\n",node->item);
      node = node->next;
    }while(node!=NULL);
  }else{
    printf("Empty\n");
  }
}


struct items *search_node(struct items *node, char name[]){
    while(node!=NULL){
      if(str_compare((node->item), name) == 1){
        return node;
      }
      node = node->next;
    }
}

void delete_item(struct items **node, char name[]){
  struct items *result = search_node(*node, name);
  struct items *aux = *node;

  if(*node == result){
    *node = result->next;
    free(result);
  }else{
    while((aux != result) && (aux != NULL)){
      if(aux->next == result){
        aux->next = result->next;
        free(result);
      }
      aux = aux->next;
    }
  }
}

int size_list(struct items *node){
  int count = 0;
  while(node != NULL){
    count++;
    node = node->next;
  }

  return count;
}
