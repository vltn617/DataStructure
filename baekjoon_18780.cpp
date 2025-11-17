#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, c;
vector<vector<pair<int, int>>> edge(100001);
int tm[100001];
int in_degree[100001];

void input(){
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        tm[i] = a;
    }
    for (int i = 0; i < c; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        in_degree[b]++;
    }
}

void sol(){
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (in_degree[i] == 0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int x = q.front();
        q.pop();
        for (auto[next, cost] : edge[x]){
            tm[next] = max(tm[next], cost + tm[x]);
            in_degree[next]--;
            if (in_degree[next] == 0){
                q.push(next);
            }
        }
 
    }
    for (int i = 1; i <= n; i++) cout << tm[i] << "\n";
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}