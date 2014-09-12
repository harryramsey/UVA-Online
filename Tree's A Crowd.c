#include <stdio.h>
#include <math.h>

typedef struct{
	int x,y,z;
}point;

void shortest_distance(point points[], int N)
{
	int histogram[10],i,j,currdist,smallestdist;
	for (i = 0; i < 10; i++){
		histogram[i] = 0;
	}
	for (i = 0; i < N;i++){
		smallestdist = 2147000000;
		for (j = 0; j < N; j++){
			if (i != j){
				currdist = (int)distance(points[i],points[j]);
				if (currdist < smallestdist){
					smallestdist = currdist;
				}
			}
		}
		if (smallestdist < 10){
			histogram[smallestdist]++;
		}
	}

	for (i = 0; i < 10; i++){
		printf("%4d",histogram[i]);
	}
	printf("\n");
}

int distance(point a, point b)
{
	int dist = sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2));
	return dist;
}

int main()
{
	int a,b,c,i;
	point points[6000];
	i = 0;
	while (scanf("%d%d%d",&a,&b,&c) == 3){
		if (a == 0 && b == 0 && c == 0){
			break;
		}
		point p = {a,b,c};
		points[i++] = p;
	}
	shortest_distance(points,i);
	return 0;
}
