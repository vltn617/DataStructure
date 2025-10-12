#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;
int w, h;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int excape[1001][1001];
char graph[1001][1001];

int fire[1001][1001];
void drawGraph(){
    queue <pair<int, int>> q;
    for(int i = 0; i < h; i ++){
        for (int j = 0; j < w; j++){
            if (graph[i][j] == '*'){
                fire[i][j] = 0;
                q.push({i, j});
            }
            else fire[i][j] = -1;
        }
    }

    while (!q.empty()){
        auto[x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w){
                if (fire[nx][ny] == -1 && graph[nx][ny] != '#'){
                    fire[nx][ny] = fire[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int tc;
    cin >> tc;
    while (tc > 0){
        int ans = INT_MAX;
        queue <tuple<int, int, int>> q;
        cin >> w >> h;
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++) {
                excape[i][j] = -1;
            }
        }
        
        int startx, starty;
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                cin >> graph[i][j];
                if (graph[i][j] == '@'){
                    startx = i;
                    starty = j;
                }
            }
        }
        excape[startx][starty] = 0;
        q.push({startx, starty, 0});
        drawGraph();
        int curTime = 0;
        while (!q.empty()){
            auto[xpos, ypos, tm] = q.front();
            q.pop();
            if (xpos == 0 || xpos == h - 1 || ypos == 0 || ypos == w -1) {
                ans = min(ans, tm + 1);
                break;
            }
            for (int i = 0; i < 4; i++){
                int nx = xpos + dx[i];
                int ny = ypos + dy[i];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w){
                    if (graph[nx][ny] == '.' && excape[nx][ny] == -1){
                        if (fire[nx][ny] > tm + 1 || fire[nx][ny] == -1){
                            excape[nx][ny] = tm + 1;
                            q.push({nx, ny, tm + 1});
                        }
                    }
                }
            }
        }
        if (ans != INT_MAX) cout << ans << "\n";
        else cout << "IMPOSSIBLE\n";
        tc--;
    }
}