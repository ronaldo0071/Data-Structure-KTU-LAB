#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int n=3;
struct student{
char name[20];
int weight;
float height;
};
main()
{
    struct student s[10];
    struct student aux[10];
    FILE *fp;
    int i=0;
    fp=fopen("G:\\Projects\\C\\files\\file1.txt","r");
    if(fp==NULL)
    {
        printf("File cannot open");
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
    fp2=fopen("result2.txt","w");
    if(fp2==NULL)
        printf("Cannot create a new file\n");
    int l,j,k,l1,l2,u2,u1,size;

    size=1;
    while(size<n)
    {

        l1=0;
        k=0;
        while(l1+size<n)
        {
            l2=l1+size;
            u1=l2-1;
            u2=(l2+size-1<n)?l2+size-1:n-1;

            for(i=l1,j=l2;i<=u1&&j<=u2;k++){

                if(s[i].height<=s[j].height){

                        aux[k]=s[i];
                        i++;
                }
                else
                {

                    aux[k]=s[j];
                    j++;
                }
            }
            for(;i<=u1;k++){

                aux[k]=s[i++];}
            for(;j<=u2;k++){
                aux[k]=s[j++];}
            l1=u2+1;
        }
        for(i=l1;k<n;i++)
            aux[k++]=s[i];
        for(i=0;i<n;i++)
            s[i]=aux[i];
        size*=2;
    }
    printf("\nContents of output file :\n");
    for(i=0;i<n;i++)
        printf("%s %.2f %d\n",s[i].name,s[i].height,s[i].weight);
    for(i=0;i<n;i++)
        fprintf(fp2,"%s %.2f %d\n",s[i].name,s[i].height,s[i].weight);
    fclose(fp2);
}
