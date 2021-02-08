#include<stdio.h>
#include<stdlib.h>
struct pqueuee
{
    int data;
    int prio;
};
struct pqueuee pqueue[20],temp;
int front=-1,rear=-1;
void push(int n)
{
    int i;
    if(rear==-1)
    {
        printf("Enter the element and priority\n");
        front=rear=0;
        scanf("%i %i",&pqueue[rear].data,&pqueue[rear].prio);
    }
    else
    {

    if(rear+1>=n)
    {
        printf("Queue is overflow\n");
        return;
    }
    rear++;
    printf("Enter the element and priority\n");
    scanf("%i %i",&pqueue[rear].data,&pqueue[rear].prio);
    for(i=rear;i>front;i--)
    {
        if(pqueue[i].prio>pqueue[i-1].prio)
        {
            temp=pqueue[i];
            pqueue[i]=pqueue[i-1];
            pqueue[i-1]=temp;
        }
    }
    }
    printf("After pushing Queue is\n");
    for(i=front;i<=rear;i++)
    {
        printf("Element: %i\t",pqueue[i].data);
        printf("Priority: %i ",pqueue[i].prio);
        printf("\n");
    }
    printf("\n");
}
void pop(int n)
{
    int i;
    if(front==-1)
        {
        printf("Queue is empty\n");
        return;
        }
    printf("Deleted element is %i\n",pqueue[front].data);
    if(front==rear)
    {
        front=rear=-1;
        printf("After popping Queue is empty\n");
        return;

    }
    ++front;
    printf("After popping Queue is\n");
    for(i=front;i<=rear;i++)
    {
        printf("Element: %i\t",pqueue[i].data);
        printf("Priority: %i ",pqueue[i].prio);
        printf("\n");
    }
    printf("\n");
}
main()
{
    int n,o;
    printf("Enter the size of priority queue\n");
    scanf("%i",&n);
    while(1)
    {
        printf("Options\n");
    printf("1.Push\n2.Pop\n3.Exit\nSelect an option\n");
    scanf("%i",&o);
    switch(o)
    {
        case 1:push(n);
                break;
        case 2: pop(n);
                break;
        case 3: exit(0);
                break;
        default: printf("Enter correct option\n");
    }
    }
}
