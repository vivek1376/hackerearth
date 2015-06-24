#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int T,i,len,carry,ifInc,incPos;
    char N[110],oldCh;

    scanf("%d",&T);

    while(T--)
    {
	scanf("%s",N);

	len=strlen(N);		/* length of string */

	i=len-1,incPos=len,carry=0,ifInc=0;

	while(i>=0)
	{
	    oldCh=N[i];
	    
	    if(carry || !ifInc)
		N[i]++;

	    carry=0;
	    
	    if(N[i]<'3')
		N[i]='3';

	    else if (N[i]=='4')
		N[i]='5';
	    
	    else if (N[i]>'5')
	    {
		N[i]='3';
		carry=1;
	    }

	    
	    if(N[i]>oldCh)
	    {
		incPos=i;
		ifInc=1;
	    }
	    
	    i--;    
	}

	if(carry==1)
	{
	    putchar('3');
	    incPos=-1;
	}

	for(i=incPos+1;i<len;i++)
	    N[i]='3';

	printf("%s\n",N);
    }

    return 0;
}
