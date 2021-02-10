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

void multi(int t1[50][3], int t2[50][3]){
    int res[50][3], t3[50][3], i, j = 1, k, l=1, m=1, n = 1;
    // transpose(t2, t3);
    if (t1[0][1] != t2[0][0])
    {
        printf("Cant multiply");
        return;
    }
    res[0][0] = t1[0][0];
    res[0][1] = t2[0][1];
    /multiply/
    for ( i = 0; i < t1[0][1]; i++)
    {
        for (j = 1; j <= t1[0][2]; j++)
        {
            for (k = 1; k <= t2[0][2]; k++)
            {
                if (t1[j][1] == i && t2[k][0] == i)
                {
                    res[l][0] = t1[j][0];
                    res[l][1] = t2[k][1];
                    res[l][2] = t1[j][2]*t2[k][2];
                    l++;
                }   
            }
        }
    }
    res[0][2] = l-1;
    t3[0][0] = res[0][0];
    t3[0][1] = res[0][1];
    t3[0][2] = res[0][2];
    /Sorting/
    for (i = 0; i < res[0][0]; i++)
    {
        for (k = 0; k < res[0][1]; k++)
        {
            for (j = 1; j <= res[0][2]; j++)
            {
                if (res[j][0] == i)
                {
                    if (res[j][1] == k)
                    {
                        t3[m][0] = res[j][0];
                        t3[m][1] = res[j][1];
                        t3[m][2] = res[j][2];
                        m++;
                    }
                }   
            }
        }
    }
    /adding like terms/
    i = 1;
    while(i <= t3[0][2])
    {
        if (t3[i][0] == t3[i+1][0] && t3[i][1] == t3[i+1][1])
        {
            t3[i][2] += t3[i+1][2];
            for (j = i+1; j <= t3[0][2]; j++)
            {
                t3[j][0] = t3[j+1][0];
                t3[j][1] = t3[j+1][1];
                t3[j][2] = t3[j+1][2];   
                printf("%i\n", t3[0][2]);                                                                                          
            }
            i = 1;
            t3[0][2]--;
        }
        else
            i++;
    }

    printf("Resultant\n");
    for ( i = 0; i <= t3[0][2]; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%i ", t3[i][j]);
        }   
        printf("\n");
    }
}

main(){
    int sp1[50][50], sp2[50][50], t1[50][3], t2[50][3], tr1[50][3], r1, c1, r2, c2, i, j;
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
    printf("Enter the number of rows and column of 2\n");
    scanf("%i %i", &r2, &c2);
    printf("Enter the elements\n");
    for ( i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            scanf("%i", &sp2[i][j]);
        }   
    }
    tuple(sp1, t1, r1, c1);
    tuple(sp2, t2, r2, c2);
    printf("first\n");
    for ( i = 0; i <= t1[0][2]; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%i ", t1[i][j]);
        }   
        printf("\n");
    }
    printf("second\n");
    for ( i = 0; i <= t2[0][2]; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%i ", t2[i][j]);
        }   
        printf("\n");
    }
    // transpose(t1, tr1);
    multi(t1, t2);
}