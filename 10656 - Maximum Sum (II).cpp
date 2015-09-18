#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>

int main(void)
{
  int N;
  int arr[10005];
  int last = 0;

  while (scanf("%d",&N) == 1){
    if (N == 0) break;

    for (int i = 0; i < N; i++){
      scanf("%d",&arr[i]);
      if (arr[i] !=  0) last = i;
    }

    for (int i = 0; i <= last; i++){
      if (i == last) printf("%d\n",arr[i]);
      else if (arr[i] != 0) printf("%d ",arr[i]);
    }

    for (int i = 0; i < N; i++){
      arr[i] = 0;
    }
    last = 0;
  }
    return 0;
}


