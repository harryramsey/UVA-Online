#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double max = 2147483647;

void classify(char first[], char operand[], char second[])
{
	double a,b,result;
	sscanf(first, "%lf", &a);
	sscanf(second, "%lf", &b);

	if (operand[0] == '+'){
		result = a+b;
	}
	else{
		result = a*b;
	}
	if (a > max) printf("first number too big\n");
	if (b > max) printf("second number too big\n");
	if (result > max) printf("result too big\n");
}

int main()
{
	char a[300], operand[300], b[300];

	while(scanf("%s%s%s", a,operand,b) == 3){
		printf("%s %s %s\n", a, operand, b);
		classify(a,operand,b);
	}
	return 0;
}


