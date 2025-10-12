#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;


int n, A, B, C, m;
vector<vector<pair<long long, int>>> adj(500001);
long long ans[100001];
long long dist[100001];

long long MIN(long long a, long long b){
    if (a > b) return b;
    else return a; 
}

void input(){
    cin >> n >> A >> B >> C >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        bool bl = false;
        for (int i = 0; i < adj[a].size(); i++){
            if (adj[a][i].first == b){
                adj[a][i].second = MIN(adj[a][i].second, c);
                break;
            }
        }
        for (int i = 0; i < adj[b].size(); i++){
            if (adj[b][i].first == a){
                adj[b][i].second = MIN(adj[b][i].second, c);
                bl = true;
                break;
            }
        }
        if (bl) continue;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        
    }
}

void dijkstra(int start){
    for (int i = 1; i <= n; i++) dist[i] = LLONG_MAX;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[start] = 0;
    pq.push({dist[start], start});

    while (!pq.empty()){
        auto[d, cur] = pq.top();
        pq.pop();
        for (pair<long long, int> pi : adj[cur]){
            auto[next, cost] = pi;
            if (dist[next] > cost + d){
                dist[next] = cost + d;
                pq.push({dist[next], next});
            }
        }
    }
    long long temp = MIN(dist[A], dist[B]);
    temp = MIN(temp, dist[C]);
}

void sol(){
    for (int i = 1; i <= n; i++) ans[i] = LLONG_MAX;
    dijkstra(A);
    for (int i = 1; i <= n; i++){
        ans[i] = MIN(ans[i], dist[i]);
    }
    dijkstra(B);
    for (int i = 1; i <= n; i++){
        ans[i] = MIN(ans[i], dist[i]);
    }
    dijkstra(C);
    for (int i = 1; i <= n; i++){
        ans[i] = MIN(ans[i], dist[i]);
    }

    int Max = -1;
    int idx = 0;
    for (int i = 1; i <= n; i++){
        if (ans[i] > Max){
            Max = ans[i];
            idx = i;
        }
    }
    cout << idx;
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}