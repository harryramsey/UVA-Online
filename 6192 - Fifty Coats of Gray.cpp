#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>
#include <queue>

using namespace std;

int main(void)
{
	int n,w,l,h,paintArea,m, dw,dh;
	while (scanf("%d%d%d%d%d%d",&n,&w,&l,&h,&paintArea,&m) == 6){
		if (n == 0 && w == 0 && l == 0 && h == 0 && paintArea == 0 && m == 0) break;

		int apartmentArea = (l*h)+(l*h)+(w*h)+(w*h)+(l*w);
		for (int i = 0; i < m; i++){
			scanf("%d%d",&dw,&dh);
			apartmentArea -= dh*dw;
		}
		int totalArea = apartmentArea*n;
		double cans = (double)totalArea/paintArea;
		printf("%.lf\n",ceil(cans));
	}
    return 0;
}
