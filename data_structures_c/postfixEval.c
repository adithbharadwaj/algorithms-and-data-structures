#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct stack{

	int top;
	int elements[100];

};

	typedef struct stack stack;
	stack s;

void push(int a);
int pop(void);

int evaluate(char c[], int length){

   int op1, op2, result, i = 0;

   while(c[i] != '\0'){

      if(isdigit(c[i])){
      	push(c[i] - '0');
      }
      else{
         op2 = pop();
         op1 = pop();

         if(c[i] == '+'){
            result = op1 + op2; 
         }
         if(c[i] == '-'){
         	result = op1 - op2;
         }
         if(c[i] == '*'){
         	result = op2 * op1;
         }
         if(c[i] == '/' && op2 != 0){
         	result = op1/op2;
         }

         push(result);

      }
         i++;

   }

       return pop();

}

int main(){
    
    int n;
    char c[10];

    s.top = -1;

    printf("Enter the expression \n");
    scanf("%s", c);

    printf("%d\n", evaluate(c, strlen(c)));


	return 0;
}

void push(int a){

    if(s.top == 99){
    	
    	printf("no more space in the stack \n");
    }
    else{
    	
    	s.top++;
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

