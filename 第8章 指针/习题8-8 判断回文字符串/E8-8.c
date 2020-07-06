    bool palindrome( char *s )
    {
    	int i,n;
    	n=strlen(s);
    	if(n%2)
    	{
    		for(i=0;i<(n-1)/2;i++)
    		{
    			if(s[i]==s[n-1-i])
    			continue;
    			else
    			return false;
    		}
    	}
    	else
    	{
    		for(i=0;i<n/2;i++)
    		{
    			if(s[i]==s[n-1-i])
    			continue;
    			else
    			return false;
    		}
    	}
    	return true;
    }