#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->r==q->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
} 
int isEmpty(struct queue *q)
{
    if (q->r==q->f)
    { 
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue *q,int value)
{
    if (isFull(q))
    {
          printf("The queue is Overflow!\n");
    }
    else
    {
        (q->r)++;
        q->arr[q->r]=value;
    }
     
}
int dequeue(struct queue *q)
{
    int a=-1;
    if (isEmpty(q))
    {
        printf("The queue is underflow!");
    }
    else
    {
        q->f++; 
       a=q->arr[q->f];
    }
       return a;
    
}

void display(struct queue *q)
{
    for (int i = 0; i <= q->r; i++)
    {
      printf("The value at index %d of queue is %d",i,q->arr[i]);  
      printf("\n");
    }
    
}
int main(){
     struct queue q;
     q.size= 3;
     q.f=q.r=-1;
     q.arr= (int*) malloc(q.size*sizeof(int));
      enqueue(&q,3); 
      enqueue(&q,4);
      enqueue(&q,5);
    //   enqueue(&q,6);
        printf("Dequeing element %d\n",dequeue(&q));       
        printf("Dequeing element %d\n",dequeue(&q));       
        printf("Dequeing element %d\n",dequeue(&q));      
        display(&q); 
        if (isEmpty(&q))
        {
            printf("Queue is empty\n");
        }
        if (isFull(&q))
        {
            printf("Queue is Full\n");
        }
        
    return 0;
}