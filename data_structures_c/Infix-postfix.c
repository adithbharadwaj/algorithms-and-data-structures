#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct stack{

	int top;
	char elements[100];
};

	typedef struct stack stack;
	stack s;

void push(char a);
int pop(void);
int prec(char ch);
void convert(char c[]);

char peek(){

    return s.elements[s.top];
}

int isEmpty(){

    return s.top == -1 ;
}

int main(){
    
    int n;
    char c[10];

    s.top = -1;

    printf("Enter the expression \n");
    scanf("%s", c);

    convert(c); 

	return 0;
}

void push(char a){

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
int prec(char ch){

    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 	
    case '^':
        return 3;
    }

    return 0;
}

void convert(char c[]){

    int i = 0; 

    while(c[i] != '\0'){

       if(isdigit(c[i])){
       	 printf("%c", c[i]); 
       }
       else if(c[i] == '('){
       	 push(c[i]);
       }
       else if(c[i] == ')'){

       	  while(!isEmpty() && peek() != '('){
       	  	printf("%c", pop());
       	  }

       	  pop();

       }
       else{

          while(!isEmpty() && ( prec(c[i]) <= prec(s.elements[s.top]) ) ){
          	printf("%c", pop()); 
          } 

          push(c[i]);

       }

       i++;

    }

    while(!isEmpty()){
    	printf("%c", pop());
    }

}
