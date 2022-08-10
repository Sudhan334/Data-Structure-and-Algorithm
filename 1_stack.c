#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int stack[100];
int i,n,choice,j,top=-1;
void push();
int pop();
void display();
void main()
{
  
  up:
        printf("Choose options:\n 1.Push 2.Pop 3.Display 4.Exit\n");
        scanf("%d",&choice);

    
        switch(choice)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("exiting.....");
            break;
            default:
            printf("Invalid Option!");
        }
    goto up;
}
 void push()
 {
     if (top==4)
     {
         printf("Stack Overflow!\n");
     }
     else{
         printf("Enter the number you want to push into the stack.\n");
         int x;
         scanf("%d",&x);
         top++;
         stack[top]=x;
         printf("%d is pushed into stack!\n",stack[top]);

     }
 }
 int pop()
 {
     if (top==-1)
     {
         printf("Stack underflow!\n");
     }
     else{
         int val;
        
         val=stack[top];
         top--;
         printf("%d is poped from stack!\n",val);
 return val; 
     }
   
 }
 void display()
 {
         printf("After push and pop operation data in the stack are:\n");

     for ( i = 0; i < top; i++)
     {
         printf("%d",stack[i]);
     }
     
 }

