#include <bits/stdc++.h>
#define visit VISIT

using namespace std;
int dx [6] = {-1,0,1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int visit[40][40][40];
int dist[40][40][40];

int main (){
    string board[40][40];
    queue<pair<pair<int,int>,int>> S;
    int z,x,y;
    int result;
    bool Isfind = false;
    while(1){
        cin>>z>>x>>y;
        if (x == 0 && y == 0 && z ==0) return 0;
        for (int i = 0 ; i< z; i++){
            for (int j= 0;j<x;j++){
                cin>>board[i][j];
            }
        }
        for (int i = 0 ; i< z; i++){
            for (int j= 0;j<x;j++){
                for (int k=  0; k < y;k++){
                    if (board[i][j][k] == 'S'){
                        S.push({{i,j},k}); visit[i][j][k] = 1;
                    }
                }
            }
        }
        
        int count = 1;
        while(!S.empty() && !Isfind){
            auto pos = S.front(); S.pop();
            for (int dir = 0;dir<6;dir++){
                int nidz = pos.first.first + dz[dir];
                int nidx = pos.first.second + dx[dir];
                int nidy = pos.second + dy[dir];
                if (nidz < 0 || nidz >= z || nidx <0 || nidx >= x || nidy <0|| nidy >= y) continue;
                if (board[nidz][nidx][nidy] == '#'|| visit[nidz][nidx][nidy]) continue;
                if (board[nidz][nidx][nidy] == 'E'){
                    result = dist[pos.first.first][pos.first.second][pos.second]+1; Isfind = true; break;
                }
                S.push({{nidz,nidx},nidy}); visit[nidz][nidx][nidy] = 1; dist[nidz][nidx][nidy] = dist[pos.first.first][pos.first.second][pos.second]+1;
            }
        }
        if (Isfind){
            cout<<"Escaped in "<<result<<"minute(s).\n";
        }
        else{
            cout<<"Trapped!\n";
        }
        while(!S.empty()){S.pop();}
        for (int i = 0 ; i< 40; i++){
            for (int j= 0;j<40;j++){
                for (int k=  0; k < 40;k++){
                    visit[i][j][k] = 0; dist[i][j][k] = 0;
                }
            }
        }
        Isfind = false;
    }
    return 0;
}