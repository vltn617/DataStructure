#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int button[61][6];
int tc;
vector <int> v;

int dt[5] {60, 10, -10, 1, -1};
bool visited[61];
int m = 60;
queue <int> q;

void input(){
    cin >> tc;
    for (int i = 0; i < tc; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 1; i <= 60; i++) button[i][0] = 80;
}

void bfs(int time){
    for (int i = 0; i < 5; i++){
        int nt = time + dt[i];
        if (nt > m || nt < 0) continue;
        else if (button[nt][0] > button[time][0] + 1){
            for (int j = 0; j < 6; j++){
                button[nt][j] = button[time][j];
            }
            button[nt][0]++;
            button[nt][i + 1]++;
            visited[nt] = true;
            q.push(nt);
        }
        else if (button[nt][0] == button[time][0] + 1){
            for (int j = 1; j <= 5; j++){
                if (button[nt][j] < button[time][j]){
                    for (int l = 0; l < 6; l++){
                        button[nt][l] = button[time][l];
                    }
                    button[nt][0]++;
                    button[nt][i + 1]++;
                    visited[nt] = true;
                    q.push(nt);
                }   
            }
        }
    }
}

void sol(){
    input();
    q.push(0);
    visited[0] = 0;
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        bfs(a);
    }
    for (int i : v){
        int temp = i;
        int R = temp % 60;
        int Q = temp / 60;
        cout << Q + button[R][1] << " ";
        for (int j = 2; j <= 5; j++){
            cout << button[R][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
}