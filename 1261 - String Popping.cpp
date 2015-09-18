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

map<string,bool> mymap;
int soltns;

void pop_string(string str)
{
    if (str == ""){
        soltns++;
        return;
    }
    if (soltns > 0) return;

    bool prevFound = mymap.find(str)->second;
    if (prevFound) return;

    mymap[str] = true;
    for (int i = 0; i < str.size(); i++){
        for (int j = i+1; j < str.size(); j++){
            if (str[i] != str[j]) break;
            else{
                pop_string(str.substr(0,i)+str.substr(j+1));
            }
        }
    }
}

int main(void)
{
    int n;
    string str;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> str;
        mymap.clear();
        soltns = 0;
        pop_string(str);
        if (soltns > 0) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
