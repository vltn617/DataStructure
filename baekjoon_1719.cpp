#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj(201);
pair<int, int> dist[201];
int ans[201][201];

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
}

void dijksta(const int start){
    for (int i = 1; i <= n; i++) {
        dist[i].first = INT_MAX;
        dist[i].second = -1;
    }
    dist[start].first = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (pair<int, int> pi : adj[start]){
        auto[next, cost] = pi;
        dist[next].first = cost;
        dist[next].second = next;
        pq.push({dist[next].first, next});
        
    }
    while (!pq.empty()){
        auto[d, cur] = pq.top();
        pq.pop();
        for (pair<int, int> pi : adj[cur]){
            auto[next, cost] = pi;
            if (dist[next].first > d + cost){
                dist[next].first = d + cost;
                dist[next].second = dist[cur].second;
                pq.push({dist[next].first, next});
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (i == start) continue;
        else ans[start][i] = dist[i].second;
    }
}

void sol(){
    for (int i = 1; i <= n; i++){
        dijksta(i);
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j){
                cout << "- ";
                continue;
            }
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}