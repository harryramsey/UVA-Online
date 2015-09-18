#include <cstdio>

long long factorial[13];

void generateFactorial()
{
    factorial[1] = 1;
    for (long long i = 2; i < 13; i++){
        factorial[i] = i*factorial[i-1];
    }
}

int derangement(int n)
{
    double derangement = 1.0;

    for (int i = 1; i <= n; i++){
        if (i % 2 == 1){
            derangement -= 1.0/factorial[i];
        }
        else derangement += 1.0/factorial[i];
    }
    derangement *= factorial[n];
    derangement += 0.5;
    return (int) derangement;
}

int main()
{
    generateFactorial();
    int N, cases;
    std::scanf("%d",&cases);

    for (int i = 0; i < cases; i++){
        scanf("%d",&N);
        std::printf("%d/%lld\n",derangement(N), factorial[N]);
    }
}
