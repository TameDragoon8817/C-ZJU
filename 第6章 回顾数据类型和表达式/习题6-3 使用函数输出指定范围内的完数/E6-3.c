int factorsum( int number ){
	int i=0,ret = 0;
	if(number==1){
		return number;
	}
	for(i=1; i<number; i++){
		if(number%i == 0){
			ret += i;
		}
	}
	if(ret == number){
		return ret;
	}
	else
		return 0;
 
}

void PrintPN( int m, int n ){
	
	int i,j;
	int count = 0;
	for(i=m; i<=n; i++ ) {
		if(factorsum(i)!=0){
			int ret = 0;	
			count++;
			printf("%d = ",i);
			if(i==1){
				printf("%d",i);
			}
			
			for(j=1; j<i; j++){
				
				if(i%j == 0){
					printf("%d",j);
					ret += j;
					if(ret != i){
						printf(" + ");
				    }					
				}
			}
			printf("\n");	
		}
	}
	if(count==0){
		printf("No perfect number");
	} 	
 
}