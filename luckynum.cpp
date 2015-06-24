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

//	printf("%s: ",N);//d
	len=strlen(N);		/* length of string */

	i=len-1,incPos=len,carry=0,ifInc=0;

	while(i>=0)
	{
//	    printf("\n\ni: %d  carry: %d  ifInc:%d\n",i,carry,ifInc);//d
//	    printf("New: %s\n",New);//d
	    oldCh=N[i];
	    
	    if(carry || !ifInc)
		N[i]++;

	    carry=0;
	    
	    if(N[i]<'3')
	    {
//		printf("s3\n");//d
		N[i]='3';
//		ifInc=1;
//		incPos=i;
	    }
	    else if (N[i]=='4')
	    {
//		printf("ff\n");//d
		N[i]='5';
		//	ifInc=1;
		//	incPos=i;
	    }
	    else if (N[i]>'5')
	    {
//		printf("*\n");//d
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
//	    printf("@@\n");//d
	    putchar('3');
	    incPos=-1;
	}

	for(i=incPos+1;i<len;i++)
	    N[i]='3';

	printf("%s\n",N);
    }

    return 0;
}

	
	
