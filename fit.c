#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert(struct node **start){
    struct node *temp, *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the size\n");
    scanf("%i", &newnode->data);
    newnode->next = NULL;
    if((*start) == NULL){
        *start = newnode;
    }
    else{
        temp = *start;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}



void first(struct node **start){
    struct node *temp = *start, *tempp;
    int a;
    if (*start == NULL)
    {
        printf("OVER\n");
        return;
    }
    printf("\nEnter the size to allocate\n");
    scanf("%i", &a);
    while (temp!=NULL && temp->data < a)
    {
        temp = temp->next;
    }
    if (temp!=NULL)
    {
        temp->data = temp->data - a;
        if (temp->data == 0)
        {
            tempp = *start;
            if (temp  == *start)
            {
                tempp = tempp->next;
                *start = tempp;
                return;
            }
            while (tempp->next != temp)
            {
                tempp = tempp->next;
            }
            tempp->next = temp->next;
            free(temp);
        }
    }
    else
    {
        printf("Not enough space\n");
        return;
    }
}

void best(struct node **start){
    int a;
    struct node *tempp, *temp = *start;
    if (*start == NULL)
    {
        printf("OVER\n");
        return;
    }
    printf("\nEnter the size to allocate\n");
    scanf("%i", &a);
    while (temp->next!=NULL && temp->data < a)
    {
        temp = temp->next;
    }
    tempp = temp;
    temp = temp->next;
    while (temp!=NULL)
    {
        while (temp->next!=NULL && temp->data < a)
        {
            temp = temp->next;
        }
        if (tempp->data > temp->data && temp->data >= a)
        {
            tempp = temp;
        }
        temp = temp->next;
    }
    if (tempp->data >= a)
    {
        tempp->data = tempp->data - a;
        if (tempp->data == 0)
        {
            temp = *start;
            if (tempp  == *start)
            {
                temp = temp->next;
                *start = temp;
                return;
            }
            while (temp->next != tempp)
            {
                temp = temp->next;
            }
            temp->next = tempp->next;
            free(tempp);
        }
    }
    else
    {
        printf("Not enough space\n"); 
        return;   
    }
}

void worst(struct node **start){
    int a;
    struct node *tempp = *start, *temp = *start;
    if (*start == NULL)
    {
        printf("OVER\n");
        return;
    }
    printf("\nEnter the size to allocate\n");
    scanf("%i", &a);
    while (temp!=NULL)
    {
        while (temp->next!=NULL && temp->data < a)
        {
            temp = temp->next;
        }
        if (tempp->data < temp->data && temp->data >= a)
        {
            tempp = temp;
        }
        temp = temp->next;
    }
    if (tempp->data >= a)
    {
        tempp->data = tempp->data - a;
        if (tempp->data == 0)
        {
            temp = *start;
            if (tempp  == *start)
            {
                temp = temp->next;
                *start = temp;
                return;
            }
            while (temp->next != tempp)
            {
                temp = temp->next;
            }

            temp->next = tempp->next;
            free(tempp);
        }
    }
    else
    {
        printf("Not enough space\n"); 
        return;   
    }
}

void display(struct node *start){
    struct node *temp1;
    temp1 = start;
    while (temp1 != NULL)
    {
        printf("%i  ", temp1->data);
        temp1 = temp1->next;
    }
}

main(){
    struct node *head = NULL, *temp1;
    int n, q, choice;
    printf("Enter the no of location\n");
    scanf("%i", &n);
    for(int i = 0;i < n;i++){
        insert(&head);
    }
    display(head);
    while(1){
        printf("\nMENU\n");
        printf("1.First\n2.Best\n3.Worst\n4.Exit\n");
        scanf("%i", &choice);
        switch(choice){
            case 1:
                first(&head);
                display(head);
                break;
            case 2:
                best(&head);
                display(head);
                break;
            case 3:
                worst(&head);
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Enter valid choice");
        }
    }
}