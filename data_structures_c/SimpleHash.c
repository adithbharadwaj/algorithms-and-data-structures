
// super simple hash table with no collision resolution;
// hash set contains only keys whereas hashmap contains ket and value pairs where each key is mapped to a value. there can only be one key,
// but multiple values are possible! 

#include<stdio.h>


int a[10];

int hash(int key);
int find(int key);

int main(){

   int n, i, k;
 
   printf("Enter the no of values: \n");
   scanf("%d", &n);                  
   
   printf("Enter the values\n"); 
   for (int i = 0; i < n; ++i){
    	
    	scanf("%d", &k);
    	a[hash(k)] = k;
    } 

    while(1){

    	printf("Enter the value to be searched: \n");
    	scanf("%d", &k);
     
    	if(find(k)){
    		printf("Found\n");
    	} 
    	else{
    		printf("not found\n");
   	    }
   
   }
   
   return 0;

}

int hash(int key){

   return (key % 10);

}

int find(int key){

   if(a[hash(key)] == key){
   	return 1;
   }  

   return 0;

}



