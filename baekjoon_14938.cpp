#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m, r;
int items[101];
vector <vector<pair<int, int>>> adj(101);

void input(){
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) cin >> items[i];
    for (int i = 0; i < r; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
}

void sol(){
    int ans = -1;
    for (int i = 1; i <= n; i++){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int dist[101];
        for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
        dist[i] = 0;
        pq.push({i, 0});
        while (!pq.empty()){
            auto[cur, d] = pq.top();
            pq.pop();
            for (pair <int, int> pi : adj[cur]){
                auto[next, cost] = pi;
                if (dist[next] > d + cost){
                    dist[next] = d + cost;
                    pq.push({next, dist[next]});
                }
            }
        }
        int temp = 0;
        for (int i = 1; i <= n; i++){
            if (dist[i] <= m){
                temp += items[i];
            }
        }
        ans = max(ans, temp);
    }
    cout << ans;
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}