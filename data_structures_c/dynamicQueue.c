
// queue of variable size

#include<stdio.h>
#include<stdlib.h>

struct queue{
	
	int *elements;
	int front, rear;

};

int size;

int isFull(struct queue *q){

     if((q->front == q->rear + 1) || (q->front == 0 && q->rear == size - 1)){
         return 1;  
    } 

    return 0;

}

int isEmpty(struct queue *q){
     
    if(q->front == -1){
    	return 1;
    }   

    return 0; 
}


int dequeue(struct queue *q){ 
 
    int element;

    if(isEmpty(q)){
    	
    	return -1;
    }
    
    else{
        
        element = q->elements[q->front];
        
        if(q->front == q->rear){
             q->front = q->rear = -1;  
        }

        else{
        	q->front = (q->front + 1)%size;        
        }
    
    }

    return (element);    

}

void enqueue(struct queue *q, int element){

    if(isFull(q)){

        printf("\n");
    	printf("Queue is full\n");
    	return;
    }

    if(q->front == -1){
    	q->front = 0;
    }

    q->rear = (q->rear + 1)%size;
    q->elements[q->rear] = element;

}

void display(struct queue *q){
    
    printf("\nthe elements are \n");

 
    for (int i = q->front; i <= q->rear; i++){
        
         printf("%d\n", q->elements[i]);
    }

    printf("\n");

}

int main(){

    int flag = 1, c, el, first;

    struct queue *q;
    q = (struct queue *) malloc(sizeof(struct queue));

    printf("Enter the size of the queue: \n");
    scanf("%d", &size);

    printf("\n");

    q->elements = (int *) malloc(size*sizeof(int));
   
    q->front = -1;
    q->rear = -1;

    while(flag){

        printf("1 ->  enqueue\n\n");
        printf("2 ->  dequeue\n\n");
        printf("3 ->  display\n\n");
        printf("4 ->  exit\n\n");

        printf("Enter your choice\n");
        scanf("%d", &c);

        if(c == 1){
        	printf("Enter the element\n");
        	scanf("%d", &el);

        	enqueue(q, el);
        }

        else if(c == 2){	
             first = dequeue(q);
             
             if(first == -1){
                printf("Queue is Empty\n");   
             }
             else{
                printf("The dequeued element is %d\n", first);
        
            }
        }

        else if(c == 3){
             
             display(q); 
        }

        else if(c == 4){
            flag = 0;
        }

    }


	return 0;
}