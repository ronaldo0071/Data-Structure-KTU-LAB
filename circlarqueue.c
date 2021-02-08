#include <stdio.h>
#include <stdlib.h>
int a[20],front=-1,rear=-1;
void display(int n)
{
    printf("\nCircular Queue\n");
  int j=front;
    while(j<rear)
    {
        printf("%i ",a[j]);
        j=(j+1)%n;
    }
    
}
void push(int n)
{
    int j;
    printf("\nEnter the element to insert\n");
    if(rear==-1)
    {
        front=rear=0;
        scanf("%i",&a[rear]);
        return;
    }
    else
    {
    if((rear+1)%n==front)
    {
        printf("Queue is full\n");
        return;
    }
    rear=(rear+1)%n;

    scanf("%i",&a[rear]);
    }
    printf("Sucessfully pushed\n");
    
}
void pop(int n)
{
    int j;
    if(front==rear)
    {
        printf("Queue is empty\n");
        return;
    }
    front=(front+1)%n;
    printf("Sucessfully popped\n");
   
    
}
main()
{
    int n,o;
    printf("Enter the size of circular queue\n");
    scanf("%i",&n);
    while(1)
    {
        printf("\nMENU\n");
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
    scanf("%i",&o);
    switch(o)
    {
        case 1:push(n);
                break;
        case 2: pop(n);
                break;
        case 3: display(n);
                break;
        case 4: exit(0);
                break;
        default: printf("Enter correct option\n");
    }
    }
}
