int CountDigit( int number, int digit ) {
	int a[10] = {0};
	
	if (number == 0)	return 1;
	if (number < 0)	number = -number;
	while (number) {
		a[number % 10]++;
		number /= 10;
	}
	
	return a[digit];
}