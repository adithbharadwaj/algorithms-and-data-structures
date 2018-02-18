#include<stdio.h>


void towers(int n, char from, char to, char aux);

int main(){

    int n;
    printf("Enter the number of pegs\n");
    scanf("%d", &n);
    towers(n, 'A', 'C', 'B');

	return 0;
}

void towers(int n, char from, char to, char aux){

   
   if(n == 1){
   	  printf("peg 1 moved from %c to %c\n", from, to); 
   	  return;
   } 
   
   towers(n - 1, from, aux, to);
   printf("peg %d moved from %c to %c\n", n, from, to);
   towers(n - 1, aux, to, from); 

}