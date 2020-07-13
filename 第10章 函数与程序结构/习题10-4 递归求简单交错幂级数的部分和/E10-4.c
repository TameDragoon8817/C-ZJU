#include<math.h>
double fn( double x, int n ){
	double f;
		
	if(n==1){
		f=x;	
	}else{
		f=pow(-1,n-1)*pow(x,n)+fn(x,n-1);
	}
	
	return f;
}