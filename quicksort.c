#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int n=3;
struct student{
char name[20];
int weight;
float height;
};

void inchange(struct student kkk[], int h,int k)
{
    struct student temp;
    temp=kkk[h];
    kkk[h]=kkk[k];
    kkk[k]=temp;
}
void sort(struct student kk[],int le,int rig)
{

    int i,j;
    char piv[30];
    if(le<rig)
    {

        i=le;
        j=rig+1;
        strcpy(piv,kk[le].name);
        do{

            do{i++;}while(strcmp(kk[i].name,piv) <0);
            do{j--;}while(strcmp(kk[j].name,piv)>0);
            if(i<j)
                inchange(kk,i,j);

        }while(i<j);
        inchange(kk,le,j);
        sort(kk,le,j-1);
        sort(kk,j+1,rig);

    }
}
main()
{
    struct student s[10];
    FILE *fp;
    int i=0;
    fp=fopen("G:\\Projects\\C\\files\\file1.txt","r");
    if(fp==NULL)
    {
        printf("Cannot open file");
        exit(0);
    }
    printf("Contents of input file :\n");
    char b[10];
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %f %d",&s[i].name,&b,&s[i].height,&s[i].weight);
        strcat(s[i].name," ");
        strcat(s[i].name,b);
        printf("%s %.2f %d\n",s[i].name,s[i].height,s[i].weight);
        i++;
    }
    n=i;
    fclose(fp);
    FILE *fp2;
    fp2=fopen("result1.txt","w");
    if(fp2==NULL)
        printf("Cannot create a new file\n");
    sort(s,0,n-1);
    printf("\nContents of output file :\n");
    for(i=0;i<n;i++)
        printf("%s %.2f %d\n",s[i].name,s[i].height,s[i].weight);
    for(i=0;i<n;i++)
        fprintf(fp2,"%s %.2f %d\n",s[i].name,s[i].height,s[i].weight);
    fclose(fp2);
}