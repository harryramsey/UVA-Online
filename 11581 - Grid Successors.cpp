#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

void print_vector(std::vector <std::vector<int> > &v)
{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            std::printf("%d",v[i][j]);
        }
        std::printf("\n");
    }
}

std::vector <std::vector<int> > toInteger(std::vector <std::vector<char> > &v)
{
    int N = v.size();
    std::vector <std::vector<int> > t(N,std::vector<int>(N));

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            t[i][j] = v[i][j]-48;
        }
    }
    return t;
}

std::vector <std::vector<int> > func(std::vector <std::vector<int> > &v)
{
    std::vector<std::vector<int> > t(3,std::vector<int>(3));

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            int sum = 0;
            if (i+1 < 3){
                sum  = (sum + v[i+1][j])%2;
            }
            if (i-1 >= 0){
                sum = (sum + v[i-1][j])%2;
            }
            if (j+1 < 3){
                sum = (sum + v[i][j+1])%2;

            }
            if (j-1 >= 0){
                sum = (sum + v[i][j-1])%2;
            }
            t[i][j] = sum;
        }
    }
    return t;
}

bool isZero(std::vector <std::vector<int> > v)
{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (v[i][j] != 0){
                return false;
            }
        }
    }
    return true;
}

int main(void)
{
    std::string line;
    int N;
    std::vector<std::vector<char> > v(3,std::vector<char>(3));
    std::cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < 3; j++){
            std::cin >> line;
            for (int k = 0; k < 3; k++){
                v[j][k] = line[k];
            }
        }
        std::vector<std::vector<int> > t = toInteger(v);

        if (isZero(t)){
            std::printf("-1\n");
        }

        else{
            int count = 0;
            while (true){
                t = func(t);
                if (isZero(t)){
                    break;
                }
                count++;
            }
            std::printf("%d\n", count);
        }
    }
    return 0;
}
