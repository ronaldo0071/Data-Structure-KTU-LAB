#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coef,expo;
    struct node* next;
};

struct node* insertpoly(struct node* mypoly,int c,int e);
struct node* append(struct node* mypoly,int c,int e);
struct node* polyaddition(struct node* p1mypoly,struct node* p2mypoly);
void display(struct node* mypoly);

void main()
{
    int a,b,n,i;
    struct node* p1head,* p2head,* p3head;
    p1head=p2head=NULL;

    

    printf("Enter the no of terms of polynomial 1 :\n");
    scanf("%d",&n);
    printf("\nEnter the polynomial:");
    for(i=0;i<n;i++)
    {
        printf("\nEnter the coefficient: ");
        scanf("%d",&a);
         printf("Enter the exponent: ");
        scanf("%d",&b); 
        p1head=insertpoly(p1head,a,b);
    }

    

    printf("\nEnter the no of terms of polynomial 2 :");
    scanf("%d",&n);
    printf("\nEnter the polynomial:");
    for(i=0;i<n;i++)
    {
        printf("\nEnter the coefficient: ");
        scanf("%d",&a);
         printf("Enter the exponent: ");
        scanf("%d",&b);
        p2head=insertpoly(p2head,a,b);
    }

  

    p3head=polyaddition(p1head,p2head);

    

    printf("\nThe polynomial 1 is :\n");
    display(p1head);
    printf("\nThe polynomial 2 is :\n");
    display(p2head);
    printf("\nThe sum of the two polynomials :\n");
    display(p3head);
}

struct node* append(struct node* mypoly,int c,int e)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coef=c;
    newnode->expo=e;
    if(mypoly==NULL)
    {
    newnode->next=NULL;
    return newnode;
    }
    struct node* temp=mypoly;
    while(temp->next!=NULL) 
        temp=temp->next;
    temp->next=newnode;
    newnode->next=NULL;
    return mypoly;
}

struct node* insertpoly(struct node* mypoly,int c,int e)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coef=c;
    newnode->expo=e;
    if(mypoly==NULL){            
        newnode->next=NULL;
        return newnode;
    }
    struct node* prev,* thisone;
    prev=thisone=mypoly;
    while(thisone!=NULL && thisone->expo>e){
        prev=thisone;
        thisone=thisone->next;
    }
    if(thisone==mypoly){            
        newnode->next=thisone;
        return newnode;
    }
    else if(thisone==NULL){        
        prev->next=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=thisone;
        prev->next=newnode;
    }
    return mypoly;
}

struct node* polyaddition(struct node* p1mypoly,struct node* p2mypoly)
{
    struct node* ans=NULL;
    struct node* t1,* t2;
    t1=p1mypoly;
    t2=p2mypoly;
    while(t1!=NULL && t2!=NULL){
        if(t1->expo > t2->expo){
            ans=append(ans,t1->coef,t1->expo);
            t1=t1->next;
        }
        else if(t1->expo < t2->expo){
            ans=append(ans,t2->coef,t2->expo);
            t2=t2->next;
        }
        else{
        if(((t1->coef)+(t2->coef))==0)
            {
            t1=t1->next;
            t2=t2->next;
            }
        else
            {
            ans=append(ans,(t1->coef)+(t2->coef),t1->expo);
            t1=t1->next;
            t2=t2->next;
            }
        }
    }

    while(t1!=NULL){            
        ans=append(ans,t1->coef,t1->expo);
        t1=t1->next;
    }

    while(t2!=NULL){            
        ans=append(ans,t2->coef,t2->expo);
        t2=t2->next;
    }
    return ans;
}

void display(struct node* mypoly)
{
    struct node* temp=mypoly;
    if(temp==NULL){
        printf("\nEmpty\n");
    }
    else{
        while(temp->next!=NULL){
            printf(" (%d)x^%d +",temp->coef,temp->expo);
            temp=temp->next;
        }
       printf(" (%d)x^%d ",temp->coef,temp->expo);
    }
}