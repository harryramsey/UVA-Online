#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>

int numStations;
double capacity;
double mpg;
double originCost;
double dist;
double loc[55];
double cost[55];
double minCost;

void solve(double gallons, double spent, int level)
{
    if (level == numStations+1){
        if (spent < minCost) minCost = spent;
        return;
    }
    if (spent > minCost) return;

    double toNext = loc[level+1]-loc[level];
    if (gallons < toNext/mpg){
        solve(capacity-toNext/mpg,spent+2.00+(cost[level]*(capacity-gallons)),level+1);
    }
    else if (gallons < capacity/2){
        solve(capacity-toNext/mpg,spent+2.00+(cost[level]*(capacity-gallons)),level+1);
        solve(gallons-toNext/mpg, spent, level+1);
    }
    else solve(gallons-toNext/mpg, spent, level+1);
}

int main(void)
{
    int it = 1;
    while (std::scanf("%lf",&dist) == 1){
    	if (dist < 0) break;

        std::scanf("%lf%lf%lf%d", &capacity,&mpg, &originCost, &numStations);
        for (int i = 1; i <= numStations; i++){
            std::scanf("%lf%lf",&loc[i],&cost[i]);
        }
        for (int i = 1; i <= numStations; i++){
            cost[i] /= 100.0;
        }
        loc[0] = 0;
        cost[0] = originCost;
        loc[numStations+1] = dist;
        cost[numStations+1] = 0;
        minCost = 10000000000;

        solve(capacity,originCost,0);
        std::printf("Data Set #%d\n",it++);
        std::printf("minimum cost = $%.2lf\n",minCost);
    }
    return 0;
}
