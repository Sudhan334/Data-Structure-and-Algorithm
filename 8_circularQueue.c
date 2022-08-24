#include <stdio.h>
#include <stdlib.h>
struct CircularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct CircularQueue *q)
{
    if ((q->r+1)%q->size==q->f)
    {
        return 1;
    }
    else{
        return 0;
    }
} 
int isEmpty(struct CircularQueue *q)
{
    if (q->r==q->f)
    { 
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct CircularQueue *q,int value)
{
    if (isFull(q))
    {
          printf("The queue is Overflow!\n");
    }
    else
    {
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=value;
    }
     
}
int dequeue(struct CircularQueue *q)
{
    int a;
    if (isEmpty(q))
    {
        printf("The queue is underflow!");
    }
    else
    {
        q->f= (q->f+1)%q->size; 
       a=q->arr[q->f];
    }
       return a;
    
}

void display(struct CircularQueue *q)
{
    for (int i = 0; i <= q->r; i++)
    {
      printf("The value at index %d of queue is %d",i,q->arr[i]);  
      printf("\n");
    }
    
}
int main(){
     struct CircularQueue q;
     q.size= 3;
     q.f=q.r=0;
     q.arr= (int*) malloc(q.size*sizeof(int));
      enqueue(&q,3); 
      enqueue(&q,4);
        printf("Dequeing element %d\n",dequeue(&q));       
        printf("Dequeing element %d\n",dequeue(&q));       
        // printf("Dequeing element %d\n",dequeue(&q));      
      enqueue(&q,6);
      enqueue(&q,7);
      enqueue(&q,8);
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