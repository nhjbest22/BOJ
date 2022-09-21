#include <bits/stdc++.h>
using namespace std;

#define visit VISIT
typedef struct 
{
    int x;
    int y;
    int count;
}Pos;

char arr[502][502];
int visit[502][502];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x,y;
    cin>>x>>y;
    queue<Pos> Q;
    int num = 0;
    for (int i=1;i<=x;i++){
        for(int j= 1;j<=y;j++){
            cin>>arr[i][j];
        }
    }
    Q.push({1,1,1}); visit[1][1] = 1;            
    while (!Q.empty()){
        auto P = Q.front(); Q.pop();
        if (P.x == x && P.y == y) {cout<<P.count; break;}
        for (int i= 0; i < 4;i++){
            int nx = P.x + dx[i];
            int ny = P.y + dy[i];
            int nc = P.count+1;
            if (nx < 1 || nx > x || ny < 1 || ny > y) continue;
            if (arr[nx][ny] == '0' || visit[nx][ny] == 1) continue;
            Q.push({nx,ny,nc}); visit[nx][ny] = 1;
        }
    }
    return 0;
}
