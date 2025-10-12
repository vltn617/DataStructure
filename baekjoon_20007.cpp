#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m, x, y;
vector<vector<pair<int, int>>> adj(1001);
int dist[1001];

void input(){
    cin >> n >> m >> x >> y;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
}

void sol(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[y] = 0;
    pq.push({dist[y], y});
    while (!pq.empty()){
        auto[d, cur] = pq.top();
        pq.pop();
        for (pair<int, int> pi : adj[cur]){
            auto[next, cost] = pi;
            if (dist[next] > d + cost){
                dist[next] = d + cost;
                pq.push({dist[next], next});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        pq.push({dist[i], i});
    }
    int ans = 1;
    int temp = x;
    pq.pop(); // pop the start
    while (!pq.empty()){
        auto[d, node] = pq.top();
        if (2 * d > x) {
            ans = -1;
            break;
        }
        if (2 * d <= temp) {
            temp -= 2 * d;
            pq.pop();
        } else {
            temp = x;
            ans ++;
        }
    }
    cout << ans;
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}