
// best case = o(n), when the array is already sorted. worst case = average case = o(n^2)

#include<stdio.h>

void insertionSort(int a[], int n);

int main(){

   int i, n;
   int a[100] = {0};
   
   printf("Enter no. of the elements: \n");	
   scanf("%d", &n);

   printf("Enter the elements: \n");

   for (int i = 0; i < n; ++i){
   	  
   	  scanf("%d", &a[i]);
   }
   
   insertionSort(a, n);

   return 0;

}

void insertionSort(int a[], int n){

   for (int i = 1; i < n; ++i) {
   	  
   	  int j = i - 1;
   	  int key = a[i];

   	  while(j >= 0 && a[j] > key){
         
         a[j + 1] = a[j];
         j--; 

   	  }

   	  a[j + 1] = key;

   }

   for (int i = 0; i < n; ++i){
   	    
   	    printf("%d ", a[i]);

   }
   
   printf("\n");

}