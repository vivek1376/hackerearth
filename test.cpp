#include <cstdio>

using namespace std;

int main()
{
	long int N,noOfChar,oldCount,newCount;
    char name[600], *temp, ch, invalidFlag;
    long int charCount[256],i;
    
    scanf("%ld",&N);
    
    while(N--)
    {
    	scanf("%s",name);
    	
    	temp=name, ch='\0';
    	noOfChar=0, oldCount=0, newCount=0, invalidFlag=0;

	/* reset */
	for(i=0;i<256;i++)
	    charCount[i]=0;
	
    	while(*temp && !invalidFlag)
    	{
	    //printf("temp: %c\n",*temp);//d
	    if(*temp!=ch)
	    {
		ch=*temp; //save new character

		if(charCount[(int)ch]!=0)
		    invalidFlag=1;

		charCount[(int)ch]=1;
		
		noOfChar++;
		//newCount++;
    		
		if(newCount!=oldCount && oldCount)
		    invalidFlag=1;
		else
		{
		    oldCount=newCount;
		    newCount=1;
		}
	    }
	    else //same character
		newCount++;
	    
	    if(noOfChar>3)
		invalidFlag=1;
	    
	    temp++;
    	}
    	
    	if(noOfChar!=3)
	    invalidFlag=1;
    		
    	if (invalidFlag==1)
    		printf("Not OK\n");
    	else
    		printf("OK\n");
    }
    return 0;
}

