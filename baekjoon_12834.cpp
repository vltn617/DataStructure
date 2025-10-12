#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, v, e, A, B;
vector <int> home;
vector <vector<pair<int, int>>> adj(1001);
int dist[1001];

void input(){
    cin >> n >> v >> e >> A >> B;
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        home.push_back(a);
    }
    for (int i = 1; i <= e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
}

void dijksta(int start){
    for (int i = 1; i <= v; i++) dist[i] = INT_MAX;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({dist[start], start});
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
}

void sol(){
    long long ans = 0;
    dijksta(A);
    for (int i : home){
        if (dist[i] != INT_MAX) ans += dist[i];
        else ans += -1;
    }
    dijksta(B);
    for (int i : home){
        if (dist[i] != INT_MAX) ans += dist[i];
        else ans += -1;
    }
    cout << ans;
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}
