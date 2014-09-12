#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double fun(double p, double q, double r, double s, double t, double u, double x)
{
		return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

void secant(double pcoeff, double q, double r, double s, double t, double u){
		double tol =  0.00000001;
		double p = 0, q0 = 0, q1 = 0, p0 = 0, p1 = 1;


		if (fun(pcoeff,q,r,s,t,u,0) * fun(pcoeff,q,r,s,t,u,1) > 0){
			printf("No solution\n");
		}
		else if (pcoeff == 0.0 && q == 0.0 && r == 0.0 && s == 0.0 && s == 0.0 && t == 0.0 && u == 0.0){
			printf("0.0000\n");
		}
		else {
			while (1){
				q0 = fun(pcoeff,q,r,s,t,u,p0);
				q1 = fun(pcoeff,q,r,s,t,u,p1);
				p = p1-q1*(p1-p0)/(q1-q0);
				if (fabs(p-p1) < tol){
					printf("%.4lf\n",p);
					break;
				}
				p0 = p1;
				q0 = q1;
				p1 = p;
				q1 = fun(pcoeff,q,r,s,t,u,p1);
			}
		}
	}


int main()
{
	double p,q,r,s,t,u;

	while(scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) == 6){
		secant(p,q,r,s,t,u);

	}

	return 0;
}


