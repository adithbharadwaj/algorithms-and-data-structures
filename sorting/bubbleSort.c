
// best case - o(n), when the array is already sorted || worst case - o(n^2) = average case

#include<stdio.h>

void bubbleSort(int a[], int n);

int main(){

   int i, n;
   int a[100] = {0};
   
   printf("Enter no. of the elements: \n");	
   scanf("%d", &n);

   printf("Enter the elements: \n");

   for (int i = 0; i < n; ++i){
   	  
   	  scanf("%d", &a[i]);
   }
   
   bubbleSort(a, n);

   return 0;

}

// optimized bubble sort to run in o(n) - best case by breaking out of the outer loop if no swaps are made in the inner loop

void bubbleSort(int a[], int n){

   int flag = 1;

   for (int i = 0; i < n - 1; i++){
      for (int j = 0; j < n - i - 1; j++){
          
          if(a[j] > a[j + 1]){
             int temp = a[j];
             a[j] = a[j + 1];
             a[j + 1] = temp;
             flag = 0;   
          }

      }

      // if no comparions are made in the inner loop, then the array is already sorted. so we break.

      if(flag){
         break;
      }
   }

   for (int i = 0; i < n; ++i)
   {
      printf("%d ", a[i]);
   }

   printf("\n");

}