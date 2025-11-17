#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int n, m, p, x, z;
vector<vector<pair<int, int>>> edge(100001);
vector<int> stop;
long long ans = LLONG_MAX;
long long dist[100001];
long long dist1[100001];

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    cin >> x >> z >> p;
    for (int i = 0; i < p; i++){
        int a;
        cin >> a;
        stop.push_back(a);
    }
}

void sol(){
    for (int i = 1; i <= n; i++) dist[i] = LLONG_MAX;
    int start = x;
    dist[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({dist[start], start});
    while (!pq.empty()){
        auto[d, cur] = pq.top();
        pq.pop();
        if (d > dist[cur]) continue;
        for (auto[next, cost] : edge[cur]){
            if (dist[next] > cost + d){
                dist[next] = cost + d;
                pq.push({dist[next], next});
            }
        }
    }

    for (int i = 1; i <= n; i++) dist1[i] = LLONG_MAX;
    start = z;
    dist1[start] = 0;
    pq.push({dist1[start], start});
    while (!pq.empty()){
        auto[d, cur] = pq.top();
        pq.pop();
        if (d > dist[cur]) continue;
        for (auto[next, cost] : edge[cur]){
            if (dist1[next] > cost + d){
                dist1[next] = cost + d;
                pq.push({dist1[next], next});
            }
        }
    }

    for (int p : stop){
        if (dist[p] == LLONG_MAX || dist1[p] == LLONG_MAX) continue;
        if (ans > dist[p] + dist1[p]){
            ans = dist[p] + dist1[p];
        }
    }
    cout << (ans == LLONG_MAX ? -1 : ans);
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}