#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define true 1
#define false 0
int casenum = 1;

int circularnums[448];

void genNums()
{
	int i, pos = 0;
	for (i = 10; i < 10000000; i++){
		if (isCircular(i)){
			circularnums[pos++] = i;
		}
	}
}

int isCircular(int n)
{
	int count = 0, i = 0, k = 0;
	char str[10];
	sprintf(str,"%d", n);
	int N = getLength(str);
	int landings[N];

	for (k = 0; k < N; k++){
		landings[k] = false;
	}

	while (landings[i] == false){
		landings[i] = true;
		int currDigit = str[i]-48;
		i = (i+currDigit)%N;
		count++;
	}
	if (count == N && i == 0){
		if (countChars(str,N) == false){
			return false;
		}
		return true;
	}
	return false;
}

int countChars(char str[], int N)
{
	int i, pos;
	int chars[10];

	for (i = 0; i < 10; i++){
		chars[i] = 0;
	}
	for (i = 0; i < N; i++){
		pos = str[i]-48;
		chars[pos]++;
		if (chars[pos] > 1){
			return false;
		}
	}
	return true;
}

int getLength(char str[])
{
	int length = 0, i = 0;
	while (str[i] != '\0'){
		length++;
		i++;
	}
	return length;
}

int binarySearch(int x, int v[], int n)
{
	int mid;
	int lo = 0;
	int hi = n-1;

	while (lo <= hi){
		mid = (hi+lo)/2;
		if (x < v[mid]){
			hi = mid - 1;
		}
		else if (x > v[mid]){
			lo = mid + 1;
		}
		else return v[mid]; /*found it*/
	}
	if (v[mid] < x){
		return v[mid+1];
	}
	else return v[mid];
}

int main()
{
	int x;

	genNums();
	while (scanf("%d", &x) == 1){
		if (x == 0) break;
		printf("Case %d: %d\n", casenum, binarySearch(x,circularnums,448));
		casenum++;
	}
	return 0;
}

