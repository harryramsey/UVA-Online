#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>

using namespace std;

string pieces[500];
bool used[500];
int numPieces;
string soltn;
int numSoltns;


void solve(int targetLength, string target, int numUsed)
{
    if (numUsed == numPieces && numSoltns == 0){
        soltn = target;
        numSoltns++;
        return;
    }
    if (numSoltns > 0) return;

    for (int i = 0; i < numPieces; i++){
        if (!used[i]){
            used[i] = true;
            int size = pieces[i].size();

            for (int j = i+1; j < numPieces; j++){
            	if (!used[j] && size+pieces[j].size() == targetLength){
                    if (numUsed == 0){
                        used[j] = true;
                        solve(targetLength,pieces[i]+pieces[j],numUsed+2);
                        solve(targetLength,pieces[j]+pieces[i],numUsed+2);
                        used[j] = false;
                    }
                    else{
                        used[j] = true;
                        if (pieces[i]+pieces[j] == target){
                            solve(targetLength,target,numUsed+2);
                        }
                        else if (pieces[j] + pieces[i] == target){
                            solve(targetLength,target,numUsed+2);
                        }
                        used[j] = false;
                    }
            	}
            }
            if (used[i]){
            	used[i] = false;
              	return;
            }
        }
    }


}

int main(void)
{
    bool printed = false;
    int smallest, largest;
    string str;
    getline(cin,str);
    int N = atoi(str.c_str());
    getline(cin,str);

    for (int i = 0; i < N; i++){
    	if (printed){
            printf("\n");
    	}
    	else printed = true;

        numPieces = 0;
        numSoltns = 0;
        smallest = 10000;
        largest = -100000;
        soltn = "";
        while (getline(cin,str)){
            if (str == "") break;
            pieces[numPieces++] = str;
            int size = str.size();
            if (size < smallest) smallest = size;
            if (size > largest) largest = size;
        }
        memset(used,false,sizeof used);
        solve(largest+smallest,"",0);
        printf("%s\n",soltn.c_str());
    }
    return 0;
}

