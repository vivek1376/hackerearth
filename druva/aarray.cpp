#include <cstdio>
#include <cstring>
#include <cstdlib>
//#include <unordered_map>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int T,N,K,i,j,m,n,X;

    long int A,arr[11][17],Q1=0,Q2=0,minL=0,maxL=100;
    long long int Q=0,Qmin=LLONG_MAX,Qmax=0;
    double Qd;
    scanf("%d",&T);

    while(T--)
    {
	scanf("%d %d",&N,&K);

	for(i=0;i<K;i++)
	{
	    for(j=0;j<N;j++)
		scanf("%d",&arr[i][j]);
	}

	for(i=0;i<N;i++)
	    for(j=i;j<N;j++)
	    {
		Q=0;
		X=j-i+1;
		for(m=i;m<=j;m++)
		{
		    Q1=0;
		    for(n=0;n<K;n++)
		    {
			Q1+=arr[n][m];
			
		    }

		    Q=Q*Q1;
		    Q=Q%1000000007;
		    Q=Q/X;
		}
		if(Q<=Qmin && X>minL)
		{
		    Qmin=Q;
		    minL=X;
		}

		if(Q>=Qmax && X<maxL)
		{
		    Qmax=Q;
		    maxL=X;
		}		
	    }

	printf("%lld %d\n",Qmin^Qmax,minL^maxL);
	
    }

    return 0;
}
