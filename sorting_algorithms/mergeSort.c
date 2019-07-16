
// best case = worst case = avg case = o(nlogn); 

#include<stdio.h>

void mergeSort(int a[], int l, int h);
void merge(int a[], int l, int m, int h);
void print(int a[], int n);

int main(){

   int i, n;
   int a[100] = {0};
   
   printf("Enter no. of the elements: \n");	
   scanf("%d", &n);

   printf("Enter the elements: \n");

   for (int i = 0; i < n; ++i){
   	  
   	  scanf("%d", &a[i]);
   }
   
   mergeSort(a, 0, n - 1); 
   print(a, n);

   return 0;

}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int h){
   
   int mid;

   if(l < h){

       mid = (l + h)/2;
        
       mergeSort(a, l, mid); 
       mergeSort(a, mid + 1, h);
       merge(a, l, mid, h);

   }

}

void print(int a[], int n){

   for (int i = 0; i < n; ++i) {
      printf("%d ", a[i]);
   }

   printf("\n");

}