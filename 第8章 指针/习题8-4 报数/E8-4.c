void CountOff( int n, int m, int out[] ){
	int i=0,j=0,k=0,cnt=0,a[MAXN];
 
	for(i=0;i<n;i++)
		a[i] = i+1;
 
	i=0;
	while(cnt < n){
		if(a[i]!=0)
			k++;
		if(k==m){
			j++;
			out[i]=j;
			k=0;
			cnt++;
			a[i]=0;
		}
 
		i++;
		if(i==n)
			i=0;
	}
}