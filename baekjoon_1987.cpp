#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int r, c;
char graph[21][21];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = -1;
unordered_set <char> us;
bool visited[26];

void input(){
    cin >> r >> c;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++) cin >> graph[i][j];
    }
}

void dfs(int xpos, int ypos, int cnt){
    ans = max(ans, cnt);
    for (int i = 0; i < 4; i++){
        int nx = xpos + dx[i];
        int ny = ypos + dy[i];
        if (nx >= 0 && nx < r && ny >= 0 && ny < c){
            if (visited[graph[nx][ny] - 65] == false){
                visited[graph[nx][ny] - 65] = true;
                dfs(nx, ny, cnt + 1);
                visited[graph[nx][ny] - 65] = false;
            }
            
        }
    }
}


void sol(){
    input();
    visited[graph[0][0] - 65] = true;
    dfs(0, 0, 1);
    cout << ans;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
}