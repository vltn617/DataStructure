#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> edge(1001);
int dist[1001];
int in_degree[1001];

void input(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int s, t, c;
        cin >> s >> t >> c;
        edge[s].push_back({t, c});
        in_degree[t]++;
    }
}

int dijkstra(int start){
    for (int i = 1; i <= n; i++)  dist[i] = -1;
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({dist[start], start});
    while (!pq.empty()){
        auto[d, x] = pq.top();
        pq.pop();
        for (auto [next, cost] : edge[x]){
            if (dist[next] < d + cost){
                dist[next] = d + cost;
                pq.push({dist[next], next});
            }
        }
    }
    return *max_element(dist + 1, dist + 1 + n); 
}

void sol(){
    int ans = -1;
    for (int i = 1; i <= n; i++){
        if (in_degree[i] == 0)
            ans = max(ans, dijkstra(i));
    }
    cout << ans;
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}