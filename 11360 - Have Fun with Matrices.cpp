#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <stdlib.h>

void print_vector(std::vector<std::vector<int> > &v)
{
	for (int i = 0; i < v.size(); i++){
		for (int j = 0; j < v[i].size(); j++){
			std::printf("%d",v[i][j]);
		}
		std::printf("\n");
	}
}


std::vector <std::vector<int> > transpose(std::vector <std::vector<int> > &v){
	int N = v.size();
	std::vector<std::vector<int> > t(N, std::vector<int>(N));

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			t[i][j] = v[j][i];
		}
	}
	return t;
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

void increment(std::vector <std::vector<int> > &v){
	int N = v.size();

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			v[i][j] = (v[i][j]+1)%10;
		}
	}
}

void decrement(std::vector <std::vector<int> > &v){
	int N = v.size();

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			v[i][j] = (v[i][j]-1);
			if (v[i][j] < 0){
				v[i][j] += 10;
			}
		}
	}
}

void row(std::vector <std::vector<int> > &v, int x, int y)
{
	int N = v.size();

	for (int i = 0; i < N; i++){
		int temp = v[x][i];
		v[x][i] = v[y][i];
		v[y][i] = temp;
	}
}

void col(std::vector <std::vector<int> > &v, int x, int y)
{
	int N = v.size();

	for (int i = 0; i < N; i++){
		int temp = v[i][x];
		v[i][x] = v[i][y];
		v[i][y] = temp;
	}
}



int main(void)
{
	int nCases,nCommands, N, x,y;
	std::string str, val, command;

	std::cin >> nCases;

	for (int i = 0; i < nCases; i++){
		std::cin >> N;
		std::vector <std::vector<char> > v(N,std::vector<char>(N));

		for (int j = 0; j < N; j++){
			std::cin >> str;
			for (int k = 0; k < N; k++){
				v[j][k] = str[k];
			}
		}
		std::vector <std::vector<int> > t = toInteger(v);
		std::cin >> nCommands;

		for (int j = 0; j < nCommands; j++){
			std::cin >> command;
			if (command == "transpose"){
				t = transpose(t);
			}
			else if (command == "inc"){
				increment(t);
			}
			else if (command == "dec"){
				decrement(t);
			}
			else{
				std::cin >> x >> y;
				if (command == "row"){
					row(t,x-1,y-1);
				}
				else col(t,x-1,y-1);
			}
		}
		std::printf("Case #%d\n",i+1);
		print_vector(t);
		std::printf("\n");
	}
    return 0;
}
