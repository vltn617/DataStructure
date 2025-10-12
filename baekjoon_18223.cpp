#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int v, e, p;
vector <vector<pair<int, int>>> adj(5001);
int dist[5001];
void input(){
    cin >> v >> e >> p;
    for (int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
}

void dijkstra(int start){
    for (int i = 1; i <= v; i++) dist[i] = INT_MAX;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({dist[start], start});
    while (!pq.empty()){
        auto[d, cur] = pq.top();
        pq.pop();
        for (pair <int, int> pi : adj[cur]){
            auto[next, cost] = pi;
            if (dist[next] > d + cost){
                dist[next] = d + cost;
                pq.push({dist[next], next});
            }
        }
    }
}

void sol(){
    dijkstra(1);
    int route = dist[v];
    dijkstra(p);
    int p_to_1 = dist[1];
    int p_to_v = dist[v];
    if (route == p_to_1 + p_to_v){
        cout << "SAVE HIM";
    } else cout << "GOOD BYE";
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}