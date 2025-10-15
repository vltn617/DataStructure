#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n;
char graph[51][51];
int dist[51][51][4];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int startx, starty, endx, endy;

void input(){
    cin >> n;
    startx = -1; 
    starty = -1; 
    endx = -1;
    endy = -1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
           for (int l = 0; l < 4; l++) dist[i][j][l] = INT_MAX;
            if (startx == -1 && graph[i][j] == '#') {
                startx = i;
                starty = j;
            }
            if (startx != -1 && graph[i][j] == '#'){
                endx = i;
                endy = j;
            }
        }
    }
}

void sol(){
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>>pq;
    for (int i = 0; i < 4; i++){
        dist[startx][starty][i] = 0;
        pq.push({dist[startx][starty][i], startx, starty, i});
    }
    while (!pq.empty()){
        auto[d, x, y, direction] = pq.top();
        pq.pop();
        if (graph[x][y] == '!'){
            for (int i = 0; i < 4; i++){
                if (abs(i - direction) == 2) continue; // case that goes back
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (graph[nx][ny] == '*') continue;
                if (i == direction){
                    if (dist[nx][ny][i] >= d) {
                        dist[nx][ny][i] = d;
                        pq.push({dist[nx][ny][i], nx, ny, i});
                    }
                } else{
                    if (dist[nx][ny][i] >= d + 1){
                        dist[nx][ny][i] = d + 1;
                        pq.push({dist[nx][ny][i], nx, ny, i});
                    }
                }
            }
        } else{
            int nx = x + dx[direction];
            int ny = y + dy[direction];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (graph[nx][ny] == '*') continue;
            if (dist[nx][ny][direction] >= d){
                dist[nx][ny][direction] = d;
                pq.push({dist[nx][ny][direction], nx, ny, direction});
            }
        }
    }

    cout << (*min_element(dist[endx][endy], dist[endx][endy] + 4));
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}