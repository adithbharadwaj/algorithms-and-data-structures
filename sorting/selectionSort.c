
// best case = worst case = avg case = o(n^2);

#include<stdio.h>

void selectionSort(int a[], int n);

int main(){

   int i, n;
   int a[100] = {0};
   
   printf("Enter no. of the elements: \n");	
   scanf("%d", &n);

   printf("Enter the elements: \n");

   for (int i = 0; i < n; ++i){
   	  
   	  scanf("%d", &a[i]);
   }
   
   selectionSort(a, n);

   return 0;

}

void selectionSort(int a[], int n){

     for (int i = 0; i < n - 1; ++i){
        
        int min = i;

        for (int j = i + 1; j < n; ++j){
             
            if(a[j] < a[min]){
               min = j;
            } 

        }

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;

     }

   for (int i = 0; i < n; ++i){

      printf("%d ", a[i]);
   }

   printf("\n");
   

}