#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
typedef struct tree node;
node *r=NULL,*sel=NULL;
void create()
{
    printf("Enter the data\n");
    int n,found=0;
    node *trep,*trap;
    trep=r;
    trap=NULL;
    scanf("%i",&n);
    while(trep!=NULL&&found==0)
    {
        if(n<trep->data)
        {
            trap=trep;
            trep=trep->left;
        }
        else if(n>trep->data)
        {
            trap=trep;
            trep=trep->right;
        }
        else
        {
            ++found;
        }
    }
    if(found==0)
    {
      trep=(node *)malloc(sizeof(node));
      trep->data=n;
      trep->left=NULL;
      trep->right=NULL;
      if(r==NULL)
      {
          r=trep;
      }
      else if(trap->data>n)
      {
          trap->left=trep;
      }
      else if(trap->data<n)
      {
          trap->right=trep;
      }
    }
    else
    {
        printf("Already exists\n");
    }

}
node * inorder(node *l,int item)
{
    if(l!=NULL)
    {
      inorder(l->left,item);
      if(l->data==item)
      {
         return l;
      }
      inorder(l->right,item);
    }
}
void inord(node *l)
{
    if(l!=NULL)
    {
      inord(l->left);
      printf("%i ",l->data);
      inord(l->right);
    }
}
void preorder(node *l)
{
    if(l!=NULL)
    {
      printf("%i ",l->data);
      preorder(l->left);
      preorder(l->right);
    }
}
void postorder(node *l)
{
    if(l!=NULL)
    {
      postorder(l->left);
      postorder(l->right);
      printf("%i ",l->data);
    }
}
node* min(node *curr)
{
    while(curr->left!=NULL)
      {
           curr=curr->left;
      }
    return curr;
}
node* del(node *root,int data)
{
    if(root==NULL)
        return root;
    else if(data< root->data)
        root->left=del(root->left,data);
    else if(data> root->data)
        root->right=del(root->right,data);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            root=NULL;

        }
        else if(root->left==NULL)
        {
            node *ff=root;
            root=root->right;
            free(ff);

        }
        else if(root->right==NULL)
        {
            node *ff=root;
            root=root->left;
            free(ff);

        }
        else
        {
            node *succ=min(root->right);
            root->data=succ->data;
            root->right=del(root->right,succ->data);
        }
    }
    return root;
}
main()
{
    int op;
    while(1){
    printf("\nOptions\n1.Insert a new node\n2.Inorder traversal.\n3.Preorder traversal.\n4.Postorder traversal.\n5.Delete a node.\n6. Exit");
    printf("\nEnter a option\n");
    scanf("%i",&op);
    int hhh;
    switch(op)
    {
        case 1:create();
                break;
        case 2: printf("\n Inorder traversal is\n");
                inord(r);
                break;
        case 4:printf("\n postorder traversal is\n");
                postorder(r);
                break;
        case 3:printf("\n preorder traversal is\n");
                preorder(r);
                break;
        case 5: printf("Enter element to delete\n");
                scanf("%i",&hhh);
                del(r,hhh);
                break;
        case 6: exit(0);
        default: printf("Enter correct option\n");
    }
    }
}
