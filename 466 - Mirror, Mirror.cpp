#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>


bool equals(std::vector<std::vector<char> > &v, std::vector<std::vector<char> > &t)
{
	int N = v.size();

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (v[i][j] != t[i][j]){
				return false;
			}
		}
	}
	return true;
}

std::vector<std::vector<char> > transpose(std::vector<std::vector<char> > &v)
{
	int N = v.size();
	std::vector<std::vector<char> > t (N,std::vector<char>(N));

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
                    t[i][j] = v[j][i];
		}
	}
	return t;
}

void rotate90(std::vector<std::vector<char> > &v)
{
	std::vector<std::vector<char> > t = transpose(v);

	int N = v.size();
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			v[i][j] = t[i][N-1-j];
		}
	}
}

void flipVertical(std::vector<std::vector<char> > &v)
{
	int N = v.size();
	std::vector<std::vector<char> > t = v;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			t[i][j] = v[i][j];
		}
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			v[i][j] = t[N-1-i][j];
		}
	}
}

int main(void)
{
	int setNum = 1;
	std::string str;
	std::string val;

	while (std::getline(std::cin,val)){
		int N = atoi(val.c_str());
		bool solved = false;
		std::vector < std::vector<char> > v (N, std::vector<char>(N));
	    std::vector < std::vector<char> > t (N, std::vector<char>(N));

	    for (int i = 0; i < N; i++){
	    	std::getline(std::cin,str);
	        for (int j = 0; j < (2*N)+1; j++){
	            if (j < N){
	            	v[i][j] = str[j];
	            }
	            else if (j!= N){
	            	t[i][j-N-1] = str[j];
	            }
	        }
	    }

	    if (equals(v,t)){
	    	std::printf("Pattern %d was preserved.\n",setNum);
	    }
	    else {
	    	for (int i = 0; i < 3; i++){
	    		rotate90(v);
	    		if (i == 0 && equals(v,t)){
	    			std::printf("Pattern %d was rotated 90 degrees.\n",setNum);
	    			solved = true;
	    			break;
	    		}
	    		else if (i == 1 && equals(v,t)){
	    			std::printf("Pattern %d was rotated 180 degrees.\n",setNum);
	    			solved = true;
	    			break;
	    		}
	    		else if (i == 2 && equals(v,t)){
	    			std::printf("Pattern %d was rotated 270 degrees.\n",setNum);
	    			solved = true;
	    			break;
	    		}
	    	}
	    	if (!solved){
	    		rotate90(v);
	    		flipVertical(v);

	    		if (equals(v,t)){
	    			std::printf("Pattern %d was reflected vertically.\n",setNum);
	    			solved = true;
	    		}
	    		else if (!solved){
	    			for (int i = 0; i < 3; i++){
	    				rotate90(v);
	    				if (i == 0 && equals(v,t)){
	    					std::printf("Pattern %d was reflected vertically and rotated 90 degrees.\n",setNum);
	    					solved = true;
	    					break;
	    				}
						else if (i == 1 && equals(v,t)){
							std::printf("Pattern %d was reflected vertically and rotated 180 degrees.\n",setNum);
							solved = true;
							break;
						}
						else if (i == 2 && equals(v,t)){
							std::printf("Pattern %d was reflected vertically and rotated 270 degrees.\n",setNum);
							solved = true;
							break;
						}
	    			}
	    		}
	    		if (!solved){
	    			std::printf("Pattern %d was improperly transformed.\n",setNum);
	    		}
	    	}
	    }
	    setNum++;
	}
    return 0;
}
