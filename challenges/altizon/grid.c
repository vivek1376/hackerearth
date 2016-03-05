#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>

#define N_SIZE_MAX 1001

int isCube(unsigned long long int c);
    
int main()
{
    int N, K, i, j, m;
    unsigned long long int totalSum = 0, oldSum = 0, cubeCount=0;

    scanf ("%d %d", &N, &K);

    //unsigned long int grid[1001][1001];
    /* allocate 2D array */
    unsigned long int **grid = (unsigned long int **) malloc (N_SIZE_MAX * sizeof (unsigned long int *));

    for (i = 0; i < N_SIZE_MAX; i++)
        grid[i] = (unsigned long int *) malloc (N_SIZE_MAX * sizeof (unsigned long int));

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf ("%lu", &grid[i][j]);

    printf ("%lu K:%d\n", grid[2][1],K); //d

    totalSum=0;
    
    /* intial sum */
    for (i = 0; i < K; i++)
        for (j = 0; j < K; j++)
	{
            totalSum += grid[i][j];
	    printf("ts: %ld\n",totalSum);//d
	}

//    printf("sum: %llu\n",totalSum);//d
    
//    if(isCube(totalSum))
//	cubeCount++;
    
    oldSum=totalSum;		/* save the sum of (0,0) K-matrix */
    
    /* start from (0,0) */
    for (i = 0, j = 0; i < (N - K + 1); i++)
    {
        if (i > 0)
        {			/* calculate new row[0] value 
				   of K-matrix sum */
	    totalSum=oldSum;
	    
	    /* calculate by subtract and add */
            for (m = 0; m < K; m++)
            {
                totalSum -= grid[i - 1][m];
                totalSum += grid[i + K - 1][m];
            }

	    oldSum=totalSum;
        }
	printf("sum: %llu\n",totalSum);//d
	/* check if cube */
        if (isCube (totalSum))
            cubeCount++;

        for (j = 0; j < (N - K); j++)
        {
            /* subtract line and add */
            for (m = 0; m < K; m++)
            {
                totalSum -= grid[i + m][j];
                totalSum += grid[i + m][j + K];
            }
	    printf("sum: %llu\n",totalSum);//d
            /* check */
            if (isCube (totalSum))
                cubeCount++;
        }
    }

    printf("cubeCount: %llu\n",cubeCount);//d
    return 0;
}

int isCube(unsigned long long int c)
{
    unsigned long long int root=llroundl(cbrtl((long double)c));

    if(c==root*root*root)
	return 1;
    else
	return 0;
}
