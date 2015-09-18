#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

void knuth_perm(std::string base, std::string perm, int level)
{
    if (level == base.length()){
        std::printf("%s\n",perm.c_str());
        return;
    }
    for (int i = 0; i <= level; i++){
        knuth_perm(base, perm.substr(0,i)+base[level]+perm.substr(i,level-i),level+1);
    }
}

int main(void)
{
    std::string str;
    bool printed = false;
    while(getline(std::cin,str)){
    	if (printed)std::printf("\n");
    	else printed = true;
    	knuth_perm(str,"", 0);
    }
    return 0;
}

