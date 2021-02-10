#include <stdio.h>
int t1[20][3],t2[20][3],ad[30][3],tr1[20][3],tr2[20][3];
void tupleform(int s1[20][20],int r1,int c1,int s2[20][20],int r2,int c2)
{
    int i,j,l,n;
    t1[0][0]=r1;
    t1[0][1]=c1;
    l=0,n=1;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            if(s1[i][j]!=0)
            {
                t1[n][0]=i;
                t1[n][1]=j;
                t1[n][2]=s1[i][j];
                l++,n++;
            }
        }
    }
    t1[0][2]=l;
    printf("\n\nTuple Form of first Matrix\n");
    for(i=0;i<=t1[0][2];i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%i ",t1[i][j]);
        }
        printf("\n");
    }
    l=0,n=1;
    t2[0][0]=r2;
    t2[0][1]=c2;
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            if(s2[i][j]!=0)
            {
                t2[n][0]=i;
                t2[n][1]=j;
                t2[n][2]=s2[i][j];
                l++,n++;
            }
        }
    }
    t2[0][2]=l;
    printf("Tuple Form of second Matrix\n");
    for(i=0;i<=t2[0][2];i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%i ",t2[i][j]);
        }
        printf("\n");
    }
}
void transform(int t1[20][3],int t2[20][3])
{
    int i,j,l=1;
    tr1[0][0]=t1[0][1];
    tr1[0][1]=t1[0][0];
    tr1[0][2]=t1[0][2];
    for(i=0;i<t1[0][1];i++)
    {
        for(j=1;j<=t1[0][2];j++)
        {
            if(t1[j][1]==i)
            {
                tr1[l][0]=t1[j][1];
                tr1[l][1]=t1[j][0];
                tr1[l][2]=t1[j][2];
                l++;
            }
        }
    }
    printf("\nTranspose of first Matrix in tuple form\n");
    for(i=0;i<=tr1[0][2];i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%i ",tr1[i][j]);
        }
        printf("\n");
    }
    l=1;
    tr2[0][0]=t2[0][1];
    tr2[0][1]=t2[0][0];
    tr2[0][2]=t2[0][2];
    for(i=0;i<t2[0][1];i++)
    {
        for(j=1;j<=t2[0][2];j++)
        {
            if(t2[j][1]==i)
            {
                tr2[l][0]=t2[j][1];
                tr2[l][1]=t2[j][0];
                tr2[l][2]=t2[j][2];
                l++;
            }
        }
    }
    printf("Transpose of second Matrix in tuple form\n");
    for(i=0;i<=tr2[0][2];i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%i ",tr2[i][j]);
        }
        printf("\n");
    }
}
void add(int t1[20][3],int t2[20][3])
{
    int r1,r2,i=1,j=1,k=1,m;
    r1=t1[0][2];
    r2=t2[0][2];
    if(t1[0][0]==t2[0][0]&&t1[0][1]==t2[0][1])
    {
        ad[0][0]=t1[0][0];
        ad[0][1]=t1[0][1];
        while(i<=r1&&j<=r2)
        {
            if(t1[i][0]==t2[j][0])
            {
                if(t1[i][1]==t2[j][1])
                {
                    if((t1[i][2]+t2[j][2])!=0)
                    {
                        ad[k][2]=t1[i][2]+t2[j][2];
                        ad[k][1]=t1[i][1];
                        ad[k][0]=t1[i][0];
                        k++;
                    }
                    i++,j++;
                }
               else if(t1[i][1]<t2[j][1])
               {
                    ad[k][0]=t1[i][0];
                    ad[k][1]=t1[i][1];
                    ad[k][2]=t1[i][2];
                    i++;k++;
               }
               else if(t1[i][1]>t2[j][1])
               {
                    ad[k][0]=t2[j][0];
                    ad[k][1]=t2[j][1];
                    ad[k][2]=t2[j][2];
                    j++;
                    k++;
               }
            }
            else if(t1[i][0]<t2[j][0])
            {
                    ad[k][0]=t1[i][0];
                    ad[k][1]=t1[i][1];
                    ad[k][2]=t1[i][2];
                    i++;k++;
            }
            else if(t1[i][0]>t2[j][0])
            {
                    ad[k][0]=t2[j][0];
                    ad[k][1]=t2[j][1];
                    ad[k][2]=t2[j][2];
                    j++;k++;
            }
        }
        if(i<=r1)
        {
            for(m=i;m<=r1;m++)
            {
                    ad[k][1]=t1[m][1];
                    ad[k][0]=t1[m][0];
                    ad[k][2]=t1[m][2];
                    k++;
            }
        }
        if(j<=r2)
        {
            for(m=j;m<=r2;m++)
            {
                    ad[k][1]=t2[m][1];
                    ad[k][0]=t2[m][0];
                    ad[k][2]=t2[m][2];
                    k++;
            }
        }
        ad[0][2]=k-1;
        printf("\nSum of Matrix 1 and Matrix 2\n");
        for(i=0;i<=ad[0][2];i++)
        {
            for(j=0;j<3;j++)
            {
                printf("%i ",ad[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nCannot add these 2 Matrices\n");
    }
}
main()
{
    int a[20][20],b[20][20];
    int i,j,m1,m2,n1,n2;
    printf("Enter the order of first Matrix\n");
    scanf("%i %i",&m1,&n1);
    printf("Enter the elements of Matrix\n");
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
            scanf("%i",&a[i][j]);
        }
    }
    printf("Enter the order of second Matrix\n");
    scanf("%i %i",&m2,&n2);
    printf("Enter the elements of second Matrix\n");
    for(i=0;i<m2;i++)
    {
        for(j=0;j<n2;j++)
        {
            scanf("%i",&b[i][j]);
        }
    }
    tupleform(a,m1,n1,b,m2,n2);
    transform(t1,t2);
    add(t1,t2);
}
