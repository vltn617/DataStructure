#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n;
int graph[21][21];
int startx, starty;
int shark = 2;
int cnt = 0;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int ans = 0;
int visited[21][21];


void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
            if (graph[i][j] == 9){
                startx = i;
                starty = j;
                graph[i][j] = 0;
            }
            visited[i][j] = -1;
        }
    }
}
void sol() {
    while (true) {
        for (int i = 0; i < n; ++i)
            fill(visited[i], visited[i] + n, -1);
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, startx, starty});
        visited[startx][starty] = 0;

        bool found = false;

        while (!pq.empty()) {
            auto [tm, x, y] = pq.top(); pq.pop();

            if (graph[x][y] != 0 && graph[x][y] < shark) {
                graph[x][y] = 0;
                cnt++;
                if (cnt == shark) {
                    shark++;
                    cnt = 0;
                }
                ans += tm;
                startx = x;
                starty = y;
                found = true;
                break;
            }

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (visited[nx][ny] != -1) continue;
                if (graph[nx][ny] > shark) continue;

                visited[nx][ny] = tm + 1;
                pq.push({tm + 1, nx, ny});
            }
        }

        if (!found) break; 
    }

    cout << ans;
}


int main(){
    cin.tie(nullptr);  cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}
