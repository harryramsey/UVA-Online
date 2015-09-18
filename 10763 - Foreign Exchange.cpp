#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>
#include <queue>
#include <map>

using namespace std;

#define INF 1000000000

int start[500000+10];
int dest[500000+10];

int main(void)
{
	int n;
    while (scanf("%d",&n)){
        if (n == 0) break;

        for (int i = 0; i < n; i++){
        	scanf("%d%d",&start[i],&dest[i]);
        }
        sort(start,start+n);
        sort(dest,dest+n);
        bool soltn = true;
        for (int i = 0; i < n; i++){
        	if (start[i] != dest[i]){
        		soltn = false;
        		break;
        	}
        }
        if (soltn) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

