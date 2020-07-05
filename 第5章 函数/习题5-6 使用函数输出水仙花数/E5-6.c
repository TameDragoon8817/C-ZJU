int narcissistic( int number ){
	int i,n=0,sum=0,cnt=0;  
    n = number;  
    while(n){    
        cnt++;  
        n/=10;  
    }  
  
    n = number;  
    while(n){
		i=n%10;
        sum += (int)pow(i, cnt);
        n/=10; 
    }  
  
    if(sum == number)  
        return 1;  
    else  
        return 0;  
 
}
 
void PrintN( int m, int n ){  
  
    int i;  
  
    for(i=m+1;i<n;i++)  
        if(narcissistic(i))  
            printf("%d\n", i);  
}  