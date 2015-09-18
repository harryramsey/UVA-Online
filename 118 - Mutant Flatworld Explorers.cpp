#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <memory.h>

using namespace std;

bool scent[55][55];
int x,y;

struct robot{
    char direction;
    int x,y;
    bool lost;
};

void move(robot &r, char command)
{
	if (r.lost) return;
    if (command == 'R'){
        if (r.direction == 'N'){
            r.direction = 'E';
        }
        else if (r.direction == 'E'){
            r.direction = 'S';
        }
        else if (r.direction == 'S'){
            r.direction = 'W';
        }
        else r.direction = 'N';
    }
    else if (command == 'L'){
        if (r.direction == 'N'){
            r.direction = 'W';
        }
        else if (r.direction == 'E'){
            r.direction = 'N';
        }
        else if (r.direction == 'S'){
            r.direction = 'E';
        }
        else r.direction = 'S';
    }
    else{
        if (r.direction == 'N'){
            if (!scent[r.x][r.y] && r.y+1 > y){
                r.lost = true;
                scent[r.x][r.y] = true;
            }
            else if (scent[r.x][r.y] && r.y+1 > y){
            }
            else r.y = r.y+1;

        }
        else if (r.direction == 'E'){
            if (!scent[r.x][r.y] && r.x+1 > x){
                r.lost = true;
                scent[r.x][r.y] = true;
            }
            else if (scent[r.x][r.y] && r.x+1 > x){
            }
            else r.x = r.x+1;
        }
        else if (r.direction == 'S'){
            if (!scent[r.x][r.y] && r.y-1 < 0){
                r.lost = true;
                scent[r.x][r.y] = true;
            }
            else if (scent[r.x][r.y] && r.y-1 < 0){
            }
            else  r.y = r.y-1;
        }
        else{
            if (!scent[r.x][r.y] && r.x-1 < 0){
                r.lost = true;
                scent[r.x][r.y] = true;
            }
            else if (scent[r.x][r.y] && r.x-1 < 0){
            }
            else r.x = r.x-1;
        }
    }
}

int main(void)
{
    int x1,y1;
    string command;
    char dir;
    scanf("%d%d",&x,&y);
    memset(scent,false,sizeof scent);

    while (cin >> x1 >> y1 >> dir){
        cin >> command;
        robot r;
        r.x = x1;
        r.y = y1;
        r.direction = dir;
        r.lost = false;
        for (int i = 0; i < command.size(); i++){
            move(r,command[i]);
        }
        printf("%d %d %c",r.x,r.y,r.direction);
        if (!r.lost) printf("\n");
        else printf(" LOST\n");
    }
    return 0;
}
