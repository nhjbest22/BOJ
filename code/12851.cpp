#include <bits/stdc++.h>
using namespace std;

#define visit VISIT

int visit[100002];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>>Q;
    int x,y, count,ans = 0;
    bool Isfind = false;
    cin>>x>>y;
    Q.push({x,0}); visit[x] = 0;
    if (x == y){cout<<"0\n1"; return 0;} // x == y 이면 bfs에 넣기 전에 답을 내고 끝내기
    if (x > y){cout<<x-y<<'\n'<<1; return 0;} // x > y 이면 뒤로 1칸씩만 움직일 수 있음
    while(!Q.empty()){
        auto pos = Q.front(); Q.pop();
        for (int nidx : {pos.first-1, pos.first+1, pos.first*2}){
            if (nidx == y){
                if (!Isfind) {
                    Isfind = true; cout<<pos.second+1<<'\n';
                    count = pos.second+1; ans++; continue;
                }
                if (Isfind && pos.second+1 == count){ans++; continue;} 
            }
            if (Isfind && pos.second+1 != count) {cout<<ans; return 0;}
            if (nidx < 0 || nidx > 100000 || (visit[nidx] != 0 && pos.second+1 > visit[nidx])) continue; // 32: 범위 밖이거나 이미 방문해봤다면 방문 count 를 비교해서 continue
            if (!visit[nidx]) visit[nidx] = pos.second+1; // 방문 안해봤으면 최소 방문횟수 입력
            Q.push({nidx, pos.second+1}); 
        }
    }
    return 0;
}