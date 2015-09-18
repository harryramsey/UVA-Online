#include <iostream>
#include <cstdio>
#include <vector>

bool checkParity(std::vector <std::vector<int> > &v)
{
    int N = v.size();

    for (int i = 0; i < N; i++){
        int sum = 0;
        for (int j = 0; j < N; j++){
            sum += v[i][j];
        }
        if (sum % 2 != 0){
            return false;
        }
    }

    for (int i = 0; i < N; i++){
        int sum = 0;
        for (int j = 0; j < N; j++){
            sum += v[j][i];
        }
        if (sum % 2 != 0){
            return false;
        }
    }
    return true;
}

std::vector<std::vector<int> > findErrors(std::vector<std::vector<int> > &v)
{
    int N = v.size();
    std::vector<std::vector<int> > t(2,std::vector<int>(0));

    for (int i = 0; i < N; i++){
        int sum = 0;
        for (int j = 0; j < N; j++){
            sum += v[i][j];
        }
        if (sum % 2 != 0){
            t[0].push_back(i);
        }
    }

    for (int i = 0; i < N; i++){
        int sum = 0;
        for (int j = 0; j < N; j++){
            sum += v[j][i];
        }
        if (sum % 2 != 0){
            t[1].push_back(i);
        }
    }
    return t;
}

bool tweak(std::vector<std::vector<int> > v, int x, int y){
	v[x][y] = (v[x][y]+1)%2;
	if (checkParity(v)){
       	return true;
	}
	return false;
}

int main(void)
{
    int N, bit;

    while (std::scanf("%d",&N) == 1){
        if (N == 0) break;

        std::vector <std::vector<int> > v(N, std::vector<int>(N));
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                std::scanf("%d",&bit);
                v[i][j] = bit;
            }
        }
        std::vector<std::vector<int> > errors = findErrors(v);
        int m = errors[0].size();
        int n = errors[1].size();

        if (n == 0 && m == 0){
            std::printf("OK\n");
        }
        else if (n == 1 && n == 1 && tweak(v,errors[0][0],errors[1][0])){
        	std::printf("Change bit (%d,%d)\n",errors[0][0]+1,errors[1][0]+1);
        }

        else{
        	std::printf("Corrupt\n");
        }
    }
    return 0;
}
