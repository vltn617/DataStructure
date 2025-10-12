#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int v, e, start;
vector <vector<pair<int, int>>> edge(20001);
int dist[20001];

void input(){
    cin >> v >> e >> start;
    for (int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
    }
    for (int i = 1; i <= v; i ++) dist[i] = INT_MAX;
}

void sol(){
    input();
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty()){
        int distance = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < distance) continue;
        for (pair<int, int> pi : edge[cur]){
            auto[next, nextDistance] = pi;
            if (dist[next] > dist[cur] + nextDistance){
                dist[next] = dist[cur] + nextDistance;
                pq.push({dist[next], next});
            }
        }
    }
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
    for (int i = 1; i <= v; i++){
        if (dist[i] != INT_MAX) cout << dist[i] <<"\n";
        else cout << "INF\n";
    }
}