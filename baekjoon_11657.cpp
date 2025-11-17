#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
vector<tuple<int, int, int>> edge;
long long dist[501];

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    for (int i = 1; i <= n; i++) dist[i] = 1e9;
}

bool bellmanFord(){
    dist[1] = 0;
    for (int i = 1 ; i <= n; i++){
        for (auto[u, v, w] : edge){
            if (dist[u] == 1e9) continue;
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                if (i == n) return true;
            }
        }
    }
    return false;
}

void sol(){
    if (bellmanFord()){
        cout << -1;
        return;
    }
    for (int i = 2; i <= n; i++){
        if (dist[i] == 1e9) cout << "-1\n";
        else cout << dist[i] << "\n";
    }
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}