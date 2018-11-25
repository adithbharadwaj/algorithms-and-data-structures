#include<stdio.h>

struct stack{

	int top;
	int elements[100];

};

	typedef struct stack stack;
	stack s;

void push(void);

int pop(void);

int stacktop(void);

int main(){

    int n, flag = 1, i, t;

	s.top = -1;

	do{

	printf("enter 1: to push.\nenter 2: to pop\nenter 3: stack top\nenter 0 to exit\n");
	scanf("%d", &n);
    
	switch(n){

       case 1: 
               push();
               break;

       case 2:
               i = pop();
               printf("%d\n", i);
               break;

       case 0:
               flag = 0;
               break;  

       case 3:
               t = stacktop();
               printf("%d\n", t);
               break;             

       default: 
               printf("enter a valid number \n");                

	}

}while(flag);

	return 0;
}

void push(){

	int a;
    
    if(s.top == 99){
    	
    	printf("no more space in the stack \n");
    }

    else{
    	
    	printf("enter the element to be inserted \n");
    	
    	s.top++;
    	
    	scanf("%d", &a);
    	s.elements[s.top] = a; 
    }
}

int pop(){

  if(s.top == -1){
  	
  	  printf("nothing to show \n");
  }

  else{

    return s.elements[s.top--];
    
  }

}

int stacktop(){

   if(s.top == -1){

   	   printf("nothing to show \n");
   }

   else{

   	 return s.elements[s.top];
   }

}