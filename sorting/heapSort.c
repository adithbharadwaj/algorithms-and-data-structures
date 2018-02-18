
// max heap inplementation using arrays without using dynamic resizing.

// best case = worst case = avg case = o(nlogn);

#include<stdio.h>
#include<stdlib.h>

#define maxsize 100


// helper methods

void swap(int *a, int *b){

  int temp = *a;
  *a = *b;
  *b = temp;

}


void heapify(int a[], int n, int i){

   int max = i;
   int l = 2 * i + 1; 
   int r = 2 * i + 2;

   if(l < n && a[l] > a[max]){
    max = l;
   }
   if(r < n && a[r] > a[max]){
    max = r;
   }
 
   if(max != i){
    swap(&a[i], &a[max]);
    heapify(a, n, max);
   }
   
   
}


// delete min element and return it

int heapSort(int a[], int n){

for (int i = n/2 - 1; i >= 0; i--){

   heapify(a, n, i);

}

for (int i = n - 1; i >= 0; i--){

   swap(&a[0], &a[i]);

   heapify(a, i, 0);

}
  
   
  for (int i = 0; i < n; ++i){

    printf("%d\n", a[i]);

  }

}

int main(){

   int n, el;
   int a[10];

   printf("Enter the size of the array: \n");
   scanf("%d", &n);
     
   printf("Enter the elements\n");  
   
   for (int i = 0; i < n; i++) {
   	   
   	   scanf("%d", &a[i]);

   }

   printf("\n");

   // heapsort

   printf("The sorted elements are: \n");

   heapSort(a, n);  

	return 0;
}