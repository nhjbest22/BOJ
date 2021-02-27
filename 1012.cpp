#include <bits/stdc++.h>

using namespace std;

#define visit VISIT

int visit[100][100];
int board[100][100];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    int Tx, Ty;
    cin>>T;
    while(T--){
        queue <pair<int,int>>Q;
        int x,y,TN;
        cin>>x>>y>>TN;
        while(TN--){
            cin>>Tx>>Ty; board[Tx][Ty]=1;
        }
        int ans = 0;
        for (int i =0;i<x;i++){
            for (int j=0;j<y;j++){
                if(board[i][j] == 1 && visit[i][j] != 1){
                    Q.push({i,j}); visit[i][j] = 1;
                    ans++;
                }
                while (!Q.empty()){
                    auto pos = Q.front(); Q.pop(); 
                    for (int dir =0;dir<4;dir++){
                        int nx = pos.first + dx[dir];
                        int ny = pos.second + dy[dir];
                        if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
                        if (visit[nx][ny] == 1 || board[nx][ny] != 1) continue;
                        Q.push({nx,ny}); visit[nx][ny] = 1;
                    }
                }
            }
        }
        for (int i =0; i < x; i++){
            fill(board[i],board[i]+y,0);
            fill(visit[i],visit[i]+y,0);
        }
        cout<<ans<<'\n';
    }
    return 0;
}