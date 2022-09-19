#include <bits/stdc++.h>
using namespace std;

#define visit VISIT

int arr[1002][1002];
int visit[502][502];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int>> Q;
    int dist[1002][1002];
    int M = -1;
    int x,y;
    cin>>y>>x;
    for (int i=0;i<x;i++){
        for(int j = 0;j<y;j++)
            cin>>arr[i][j];
    }
    for (int i =0;i<x;i++)
        fill(dist[i],dist[i]+y,-1);
    for (int i=0;i<x;i++){
        for(int j = 0;j<y;j++){
            if (arr[i][j] == 1){
                dist[i][j] =0; Q.push({i,j});
            }
        }
    }
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for (int i =0; i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= x || ny < 0|| ny >= y) continue;
            if (dist[nx][ny] != -1 || arr[nx][ny] != 0) continue;
            dist[nx][ny] = dist[cur.first][cur.second] +1; arr[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
    for (int i=0;i<x;i++){
        for(int j = 0;j<y;j++){
            if (arr[i][j] == 0){
                cout<<-1; return 0;
            }
            if (dist[i][j] != -1)
                M= max(M,dist[i][j]);
        }
    }
    cout<<M;
    return 0;
}