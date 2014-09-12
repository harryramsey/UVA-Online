#include <stdio.h>
#include <math.h>

#define infinity 2147000
#define true 1
#define false 0

typedef struct{
	double m;
	double b;
	int x;
	int isVertical;
	int isHorizontal;
}line;

line create_line(double x1, double y1, double x2, double y2)
{
	line line;
	line.x = x1;
	if (x2-x1 == 0){
		line.m = infinity;
		line.b = infinity;
		line.isVertical = true;
		line.isHorizontal = false;
		line.x = x1;
	}
	else if (y2-y1 == 0){
		line.m = 0;
		line.b = y1;
		line.isHorizontal = true;
		line.isVertical = false;
	}
	else{
		line.m = (y2-y1)/(x2-x1);
		line.b = y2-(x2*line.m);
		line.isHorizontal = false;
		line.isVertical = false;
	}
	return line;
}

void line_intersection(line l1, line l2)
{
	double m,b,x,y;
	if (l1.isVertical && l2.isVertical){
		if (l1.x == l2.x){
			printf("LINE\n");
		}
		else printf("NONE\n");
	}
	else if (l1.isHorizontal && l2.isHorizontal){
		if (l1.b == l2.b){
			printf("LINE\n");
		}
		else printf("NONE\n");
	}
	else if (l1.m == l2.m){
		if (l1.b == l2.b){
			printf("LINE\n");
		}
		else printf("NONE\n");
	}
	else if (l1.isVertical){
		x = l1.x;
		y = l2.m*x + l2.b;
		printf("POINT %.2lf %.2lf\n",x,y);
	}
	else if (l2.isVertical){
		x = l2.x;
		y = l1.m*x + l1.b;
		printf("POINT %.2lf %.2lf\n",x,y);
	}
	else{
		m = l1.m-l2.m;
		b = l2.b-l1.b;
		x = b/m;
		y = l1.m*x + l1.b;
		printf("POINT %.2lf %.2lf\n",x,y);
	}
}

int main()
{
	int i,N;
	double x1,x2,x3,x4,y1,y2,y3,y4;
	scanf("%d",&N);
	printf("INTERSECTING LINES OUTPUT\n");
	for (i = 0; i < N; i++){
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		line l1 = create_line(x1,y1,x2,y2);
		line l2 = create_line(x3,y3,x4,y4);
		line_intersection(l1,l2);
	}
	printf("END OF OUTPUT\n");
	return 0;
}

