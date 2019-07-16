
// min heap inplementation using arrays without using dynamic resizing. also added heapsort.

#include<stdio.h>
#include<stdlib.h>

#define maxsize 100

int size = 0;
int items[maxsize];

// helper methods

int getLeftIndex(int index){ 
	return (2*index + 1); 
}
int getRightIndex(int index){ 
	return (2*index + 2); 
}
int getParentIndex(int index){
 return (index - 1)/2; 
}

int hasLeftChild(int index){
	if((2*index + 1) < size){
		return 1;
	}
	return 0;
}
int hasRightChild(int index){
	if((2*index + 2) < size){
		return 1;
	}
	return 0;
}
int hasParent(int index){
	if((index - 1)/2 >= 0){
		return 1;
	}
	return 0;
}
void swap(int *a, int *b){

  int temp = *a;
  *a = *b;
  *b = temp;

}

// actual heap methods 

int getMin(){
	return items[0];
}

// adding new item to the heap at the last and then heapifying it upwards

void heapifyUp(){

   int index = size - 1;

   while(hasParent(index) && items[getParentIndex(index)] > items[index]){
       swap(&items[getParentIndex(index)], &items[index]);   
       index = getParentIndex(index);
   }

}

void heapifyDown(){

   int index = 0, minIndex;

   while(hasLeftChild(index)){
        minIndex = getLeftIndex(index);

   	    if(items[minIndex] > items[getRightIndex(index)]){
   	    	minIndex = getRightIndex(index);
   	    }

   	    if(items[index] < items[minIndex]){
   	    	break;
   	    }
   	    else{
   	    	swap(&items[index], &items[minIndex]);
   	    }

   	    index = minIndex;
   }

}

int add(int item){
   
   items[size] = item;
   size++;
   heapifyUp(); 

}


// delete min element and return it

int extractMin(){

  if(size == 0){
  	return -1;
  }
  
  int temp = items[0];

  items[0] = items[size - 1];
  size--;
  heapifyDown();

  return temp;
}

int main(){

   int n, el;

   printf("Enter the size of the array: \n");
   scanf("%d", &n);
     
   printf("Enter the elements\n");  
   
   for (int i = 0; i < n; i++) {
   	   
   	   scanf("%d", &el);
   	   add(el);

   }

   printf("\n");

   // heapsort

   printf("The sorted elements are: \n");

   while(1){
     
     int a = extractMin();
     if(a == -1){
     	break;
     }
     else{
     	printf("%d\n", a);
     }

   }

     
	return 0;
}