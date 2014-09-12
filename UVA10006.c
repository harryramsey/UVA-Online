#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0

bool is_Prime[65001];

void test_carmichael(int n)
{
	int a, ans = 1;
	if (is_Prime[n]){
		printf("%d is normal.\n", n);
	}
	else{
		for (a = 2; a < n; a++){
			if (modular_pow(a,n,n) != a){
				ans = -1;
				break;
			}
		}
		if (ans > 0 && is_Prime[n] == false) printf("The number %d is a Carmichael number.\n", n);
		else printf("%d is normal.\n", n);
	}
}

int modular_pow(unsigned int base, unsigned int exponent, unsigned int modulus)
{
	unsigned int result = 1;
	base = base % modulus;
	while (exponent > 0){
		if (exponent % 2 == 1){
			result = (result * base) % modulus;
		}
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}

void primeGen(int N){
	int i,j;
	
	for (i = 2; i <= N; i++){
		is_Prime[i] = true;
	}

	for (i= 2; i*i <= N; i++){
		if (is_Prime[i] == true){
			for (j = i; i*j <= N; j++){
				is_Prime[i*j] = false;
			}
		}
	}
}

int main()
{
	int n;

	primeGen(65000);
	while (scanf("%d", &n) == 1){
		if (n == 0) break;
		test_carmichael(n);
	}
	return 0;
}


