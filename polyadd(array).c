#include <stdio.h>
struct poly
{
    int coe;
    int exp;
}a[100],temp1,temp2;
main()
{
    int i,n,m,x,y,k,j,l;
    printf("Enter the number of terms in 1st polynomial\n");
    scanf("%i",&m);
    printf("Enter coefficients and exponents of 1st polynomial\n");
    for(i=0;i<m;i++)
    {
        scanf("%i %i",&a[i].coe,&a[i].exp);
    }
    for ( i = 0; i < m-1; i++)
    {
        for ( k = 0; k < m-i-1; k++)
        {
        
             if (a[k].exp<a[k+1].exp)
            {
                temp1=a[k];
                a[k]=a[k+1];
                a[k+1]=temp1;
            }

        }
        
    }
    
    printf("Enter the number of terms in 2nd polynomial\n");
    scanf("%i",&n);
    printf("Enter coefficients and exponents of 2nd polynomial\n");
    for(i=m;i<m+n;i++)
    {
        scanf("%i %i",&a[i].coe,&a[i].exp);
    }
    for ( j = m; j < m+n; j++)
    {
        for ( l = m; l < m+n; l++)
        {
        
             if (a[l].exp<a[l+1].exp)
            {
                temp2=a[l];
                a[l]=a[l+1];
                a[l+1]=temp2;
            }

        }
        
    }
    x=0;
    y=m;
    i=m+n;
    while(x<m && y<m+n)
    {
        if(a[x].exp==a[y].exp)
        {
            if(a[x].coe+a[y].coe!=0)
            {
                a[i].coe=a[x].coe+a[y].coe;
                a[i].exp=a[x].exp;
                ++i;
            }
            ++x,++y;

        }
        else if(a[x].exp>a[y].exp)
        {
            a[i].coe=a[x].coe;
            a[i].exp=a[x].exp;
            ++x,++i;
        }
        else
        {
            a[i].coe=a[y].coe;
            a[i].exp=a[y].exp;
            ++i,++y;
        }
    }
    while(x<m)
    {
        a[i].coe=a[x].coe;
        a[i].exp=a[x].exp;
        ++x,++i;
    }
    while(y<m+n)
    {
        a[i].coe=a[y].coe;
        a[i].exp=a[y].exp;
        ++i,++y;
    }
    for(int j=0;j<i;j++)
    {
        if(j==0)
        {
            printf("\n First polynomial:\n");
            printf(" %ix^%i",a[j].coe,a[j].exp);
            continue;
        }
        if(j==m)
        {
            printf("\n second polynomial:\n");
            printf(" %ix^%i",a[j].coe,a[j].exp);
            continue;
        }
        if(j==m+n)
        {
            printf("\n Resultant polynomial:\n");
            printf(" %ix^%i",a[j].coe,a[j].exp);
            continue;
        }
     a[j].coe>0 ?  printf(" +%ix^%i",a[j].coe,a[j].exp):printf(" %ix^%i",a[j].coe,a[j].exp);

    }

}
