#include <iostream>
#include <cstdio>
#include <math.h>

long long table[25][150] = {0};

void genTable()
{
    for (int i = 0; i < 6; i++){
        table[0][i] = 1;
    }

    int iterations = 0;
    for (int i = 0; i < 24; i++ ){
        iterations += 6;
        for (int j = 0; j < iterations; j++){
            for (int k = 1; k <= 6; k++){
                table[i+1][j+k] += table[i][j];
            }
        }
    }
}

long long gcd(long long a, long long b)
{
    while (b != 0){
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(void)
{
    int n, x;
    genTable();

    while (std::scanf("%d%d",&n,&x) == 2){
        if (n == 0 && x == 0) break;
        long long soltn = 0;

        for (int j = x-1; j < 150; j++){
            soltn += table[n-1][j];
        }

        long long possibleRolls = pow(6,n);
        long long GCD = (long) gcd(soltn,possibleRolls);

        if (soltn/GCD == 0){
            std::printf("0\n");
        }
        else  if (soltn/GCD == 1 && possibleRolls/GCD == 1){
            std::printf("1\n");
        }
        else printf("%lld/%lld\n", soltn/GCD, possibleRolls/GCD);
    }

    return 0;
}

