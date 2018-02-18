
// without tail node

#include<stdio.h>
#include<stdlib.h>

struct LinkedList{
	
  int data;
	struct LinkedList *next;
	
};

typedef struct LinkedList node;

void InsertFront(node *list, int n);
void display(node *head);
void InsertBack(node *list, int n);
int PopFront(node *list);
int PopBack(node *list);
void InsertAfter(node *list, int key, int n);
void DeleteAfter(node *n, int key);

int main(){

    int op, n, flag = 1, pop, key;
    
    node *head = (node *) malloc(sizeof(node));
    node *new; 

    head->data = 0;
    head->next = NULL;
    
    while(flag){

       printf("\n");

       printf("1 ----- > insert front\n2 ----- > display elements\n3 ---- > insert last\n");
       printf("4 ---- > pop front\n5 ---- > pop Back\n6 ---- > insert after an element\n7 ---- > delete after\n8 ----- > exit\n");
       
       printf("\n");

       scanf("%d", &op);

       switch(op){

          case 1: printf("Enter the number to be added\n");
                  scanf("%d", &n);
                  InsertFront(head, n);
                  break;

          case 2: printf("The elements are: \n");
                  display(head->next);
                  printf("\n");
                  break;

          case 3: printf("Enter the element to be added last: \n");
                  scanf("%d", &n);
                  InsertBack(head, n);
                  break;
          
          case 4: pop = PopFront(head);
                  if(pop == -1){
                    printf("empty list\n");
                    break;
                  }
                  printf("The front element is %d\n", pop);
                  break;      

          case 5: pop = PopBack(head);
                  if(pop == -1){
                    printf("empty list \n");
                    break;
                  } 
                  printf("The last element is %d\n", pop);
                  break; 

          case 6: printf("Enter the key after which the element is to be inserted \n");
                  scanf("%d", &key);
                  printf("Enter the element to be inserted\n");
                  scanf("%d", &n);
                  InsertAfter(head, key, n);
                  break; 

          case 7: printf("Enter the key after which the element is to be deleted \n");
                  scanf("%d", &key);
                  DeleteAfter(head, key);   
                  break;   

          case 8: flag = 0;
                  break; 

       }

    }

	return 0;
}

void InsertFront(node *list, int n){

	    node *newNode;
     	newNode = (node *)malloc(sizeof(node));
    	
      if(list->next == NULL){
         newNode->next = NULL;
    	   newNode->data = n;
         list->next = newNode;
         return;
      }
      
      newNode->next = list->next;
      newNode->data = n;
      list->next = newNode;

}

void display(node *head){

     if(head == NULL){
       printf("Empty list\n");
       return;
     }

     if(head->next == NULL){
     	printf("%d", head->data);
     }
     else{
     	while(head != NULL){
     		printf("%d ", head->data);
     		head = head->next;
     	}
     }
  
}

void InsertBack(node *list, int n){
 
    node *q;

    while(list != NULL){
         q = list;
         list = list->next;
    }

    node *last = (node *) malloc(sizeof(node));
    q->next = last;
    last->data = n;
    last->next = NULL; 

}

int PopFront(node *head){

    if(head->next == NULL){
       return -1;
    }

    int n = head->next->data;
    free(head->next);
    head->next = head->next->next;    

    return n;
}

int PopBack(node *list){

    int n;
    node *q;

    if(list->next == NULL){
      return -1;
    }

    while(list->next != NULL){
        q = list; 
        list = list->next;
    } 
    
    n = list->data;
    q->next = NULL;
    free(list); 

    return n;

}

void InsertAfter(node *head, int key, int n){
   
    node *newNode;
   
    if(head->next == NULL){
       InsertFront(head, n);
       return;
    }   

    head = head->next;

    while(head->data != key){
      head = head->next;
    }

    newNode = (node *)malloc(sizeof(node));
    newNode->next = head->next ;
    newNode->data = n;
    head->next = newNode;

}

void DeleteAfter(node *list, int key){

    if(list->next == NULL || list->next->next == NULL){
      
      printf("Nothing to delete\n");
      return; 
    } 

    else{

      list = list->next;

      while(list->data != key){
         list = list->next;  
      }
    
      free(list->next);
      list->next = list->next->next;    
    
    }
}


