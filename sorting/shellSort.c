
// best case - o(nlogn) || worst case and average case - depends on the span. generally o(n*(logn)^2) or o(n^2);

#include<stdio.h>

void shellSort(int a[], int n);

int main(){

   int i, n;
   int a[100] = {0};
   
   printf("Enter no. of the elements: \n");	
   scanf("%d", &n);

   printf("Enter the elements: \n");

   for (int i = 0; i < n; ++i){
   	  
   	  scanf("%d", &a[i]);
   }
   
   shellSort(a, n);

   return 0;

}


void shellSort(int a[], int n){

   // i = span.

   for (int i = n/2; i > 0; i /= 2){

       for (int j = i; j < n; j++){
  
         int temp = a[j];  
  
         for (int k = j - i; k >= 0 && temp < a[k]; k -= i){
             a[k + i] = a[k]

          } 

          a[k + i] = temp;

       }

   }
    

}
