/* https://www.hackerearth.com/real-image-backend-hiring-challenge/algorithm/non-decreasing-sequence-4/ */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T, N, L, i, j, k, sCount = 0;
    //  long int s1,s2,s3,num;

    scanf ("%d", &T);
    long int *arr = (long int *) malloc (1000001 * sizeof (long int));
    long int *nonDecArr = (long int *) malloc (1000001 * sizeof (long int));

    for (i = 0; i < T; i++)
    {   /* process each test case in
        for loop */
        scanf ("%d", &N);

//	s1=s2=s3=1000009;
//	sCount=0;
        for (j = 0; j < N; j++)
            scanf ("%ld", &arr[j]);

        scanf ("%d", &L);
        for (j = 0; j < L; j++)
            nonDecArr[j] = 1000009;

        for (j = 0; j < N; j++)
            for (k = 0; k < L; k++)
            {
                if (arr[j] == nonDecArr[k])
                    break;
                if (arr[j] < nonDecArr[k])
                {
                    nonDecArr[k] = arr[j];
                    break;
                }
            }
        if (nonDecArr[L - 1] != 1000009)
            printf ("%ld\n", nonDecArr[L - 1]);
        else
            printf ("-1\n");
    }

    return 0;
}
