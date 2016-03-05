#include <cstdio>
#include <cstring>
#include <cstdlib>
//#include <unordered_map>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int N,Q,K,i,j;
    unsigned long long int T,totalT=0;
    
    vector<unsigned long long int>qTime,accTime;

    scanf("%d %d",&N,&Q);

    for(i=0;i<N;i++)
    {
	scanf("%lld",&T);
	qTime.push_back(T);
    }

    sort(qTime.begin(), qTime.end(),greater<long long int>());

    for(i=0;i<N;i++)
	scanf("%lld",&T);

    //fflush(stdin);

    /* calc acc time */
    for(vector<long long int>::size_type ix=0; ix!=qTime.size(); ++ix)
    {
	totalT+=qTime[ix];
	accTime.push_back(totalT);
    }
    
    /* answer */
    for(i=0;i<Q;i++)
    {
	scanf("%d",&K);
	printf("%lld\n",accTime[K-1]);
    }

    return 0;
}

    
    
