#include<stdio.h>

void tuple(int sp[50][50], int t[50][3], int r, int c){
    int i, j;
    t[0][0] = r;
    t[0][1] = c;
    int count = 0, l = 1;
    for (i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if (sp[i][j] != 0)
            {
                t[l][0] = i;
                t[l][1] = j;
                t[l][2] = sp[i][j];
                l++;
                count++;
            }
        }
    }
    t[0][2] = count;
}

void transpose(int t1[50][3], int tran[50][3]){
    int i, j, k = 1;
    tran[0][0] = t1[0][1];
    tran[0][1] = t1[0][0];
    tran[0][2] = t1[0][2];
    for ( i = 0; i < t1[0][1]; i++)
    {
        for (j = 1; i <= t1[0][2]; j++)
        {
            if (t1[j][1] == i)
            {
                tran[k][0] = t1[j][1];
                tran[k][1] = t1[j][0];
                tran[k][2] = t1[j][2];
                k++;
            }
            
        }
        
    }

    for ( i = 0; i <= tran[0][2]; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%i ", tran[i][j]);
        }   
        printf("\n");
    }
    
}

main(){
    int sp1[50][50], t1[50][3], tr1[50][3], r1, c1, i, j;
    printf("Enter the number of rows and column of 1\n");
    scanf("%i %i", &r1, &c1);
    printf("Enter the elements\n");
    for ( i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%i", &sp1[i][j]);
        }   
    }
    tuple(sp1, t1, r1, c1);
    transpose(t1, tr1);
}