#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int graph[9][9];
int tempGraph[9][9];
int blank = 0;
vector <pair<int, int>> cctv;
int cctvLen;
int ans = INT_MAX;

void input(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> graph[i][j];
            if (graph[i][j] > 0 && graph[i][j] < 6){
                cctv.push_back({i, j});
            }
        }
    }
    cctvLen = cctv.size();
}

void watch(int xpos, int ypos, int dir){
    if (graph[xpos][ypos] == 6) return;
    tempGraph[xpos][ypos] = -1;
    if (dir == 0){
        if (xpos > 0) watch(xpos - 1, ypos, dir);
        return;
    } else if (dir == 1){
        if (ypos < m - 1) watch(xpos, ypos + 1, dir);
        return;
    } else if (dir == 2){
        if (xpos < n - 1) watch(xpos + 1, ypos, dir);
    } else if (dir == 3){
        if (ypos > 0) watch(xpos, ypos - 1, dir);
    }
}

void draw(int a[][9], int b[][9]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            a[i][j] = b[i][j];
        }
    }
}

void rec(int idx){
    int temp[9][9];
    if (idx == cctvLen) {
        int cnt = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (tempGraph[i][j] == 0) cnt++;
            }
        }
        ans = min(ans, cnt);
        return;
    }
    auto [x, y] = cctv[idx];
    draw(temp, tempGraph);
    if (graph[x][y] == 1){
        for (int i = 0; i < 4; i++){
            watch(x, y, i);
            rec(idx + 1);
            draw(tempGraph, temp);
        }
    } else if (graph[x][y] == 2){
        watch(x, y, 0);
        watch(x, y, 2);
        rec(idx + 1);
        draw(tempGraph, temp);
        watch(x, y, 1);
        watch(x, y, 3);
        rec(idx + 1);
        draw(tempGraph, temp);
    } else if (graph[x][y] == 3){
        for (int i = 0; i < 4; i++){
            watch(x, y, i);
            watch(x, y, (i + 1) % 4);
            rec(idx + 1);
            draw(tempGraph, temp);
        }
    } else if (graph[x][y] == 4){
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                if (i == j) continue;
                watch(x, y, j);
            }
            rec(idx + 1);
            draw(tempGraph, temp);
        }
    } else if (graph[x][y] == 5){
        for (int i = 0; i < 4; i++){
            watch(x, y, i);
        }
        rec(idx + 1);
        draw(tempGraph, temp);
    }
}

void sol(){
    draw(tempGraph, graph);
    rec(0);
    cout << ans;
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}