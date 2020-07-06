int prime( int p )
{	
	int i ;
	if(p<=1){
		return 0;	
	}else if (p==2){
		return 1;
	}else{
		for(i=2;i<=p/2;i++){
			if(p%i==0){
				return 0;
			} else if(i>p/2){
				return 1;	
			}
		}
	}
	return 1;
}
 
void Goldbach( int n ){
	int a;
	int count=0;
	for(a=2; a<=n;a++){	
		if(prime(a)==1&&prime(n-a)==1){
			count++;
			if(count==1){
				printf("%d=%d+%d",n,a,n-a);
			}
		}
	}
} 