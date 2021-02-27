#include <bits/stdc++.h>
using namespace std;

#define visit VISIT

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int visit[100][100];
int Area[10000];

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);  
    string board[30];
    int N; cin>>N;
    queue<pair<int,int>>Q;
    int ans = -1;
    for (int i= 0; i < N;i++){
        cin>>board[i];
    }
    for (int i =0; i < N;i++){
        for (int j= 0; j< N; j++){
            if(board[i][j] == '1' && visit[i][j] == 0){
                Q.push({i,j}); visit[i][j] = 1; ++ans;
            }
            while (!Q.empty())
            {
                auto pos = Q.front(); Q.pop(); Area[ans]++;
                for (int dir = 0; dir<4;dir++){
                    int nx = pos.first + dx[dir];
                    int ny = pos.second + dy[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (board[nx][ny] == '0'||visit[nx][ny] == 1) continue;
                    Q.push({nx,ny}); visit[nx][ny] = 1;
                }
            }
        }
    }
    sort(Area,Area+ans+1); 
    cout<<ans+1<<'\n';
    for (int i =0;i<ans+1;i++)
        cout<<Area[i]<<'\n'; 
    return 0;
}