#include <bits/stdc++.h>
using namespace std;

#define visit VISIT
#define FOR(n) for(int i = 0; i < n; i++)


int visit[302][302];

int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};


int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue <pair<int,int>>Q;  
    int TN; cin>>TN;
    int N,x,y,Tx,Ty;
    while (TN--)
    {
        cin>>N;
        cin>>x>>y;
        cin>>Tx>>Ty;
        Q.push({x,y}); visit[x][y] =1;
        while(!Q.empty()){
            auto pos = Q.front(); Q.pop();
            if (pos.first == Tx && pos.second == Ty){cout<<visit[pos.first][pos.second]-1<<'\n'; break;}
            for (int dir = 0; dir<8;dir++){
                int nx = pos.first + dx[dir];
                int ny = pos.second + dy[dir];
                if (nx < 0 || nx >= N|| ny < 0 || ny >= N) continue;
                if (visit[nx][ny] != 0) continue;
                Q.push({nx,ny}); visit[nx][ny] = visit[pos.first][pos.second]+1;
            }
        }
        while(!Q.empty()) Q.pop();
        for (int i =0; i < N; i++){
            fill(visit[i], visit[i] + N+1,0);
        }
    }
    return 0;
}