#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj(10001);
int start, destination;
int weight[10001];
bool bl[10001][10001];

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if (bl[a][b]){
            for (int i = 0; i < adj[a].size(); i++){
                if (adj[a][i].first == b){
                    adj[a][i].second = max(adj[a][i].second, c);
                    break;
                }
            }
            for (int i = 0; i < adj[b].size(); i++){
                if (adj[b][i].first == a){
                    adj[b][i].second = max(adj[b][i].second, c);
                    break;
                }
            }
        } else{
            bl[a][b] = true;
            bl[b][a] = true;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
    }
    cin >> start >> destination;
    for (int i = 1; i <= n; i++) weight[i] = -1;
}

void sol(){
    weight[start] = INT_MAX;
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
    pq.push({weight[start], start});
    while (!pq.empty()){
        auto[w, cur] = pq.top();
        pq.pop();
        for (pair<int, int> pi : adj[cur]){ 
            auto[next, margin] = pi;
            if (weight[next] < min(margin, w)){
                weight[next] = min(margin, w);
                pq.push({weight[next], next});
            }
        }
    }
    cout << weight[destination];
}   

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}