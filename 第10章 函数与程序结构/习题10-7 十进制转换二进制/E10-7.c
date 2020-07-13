void dectobin( int n ) {
	if ( n / 2 > 0 ) 
		dectobin( n / 2 );
	printf("%d", n % 2);
}