#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int n, m, t;
vector<vector<pair<int, int>>> adj(301);
vector<pair<int, int>> tc;
bool bl[301][301];
int dist[301][301];
set <int> st;

void input(){
    cin >> n >> m >> t;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if (bl[a][b]){
            for (int j = 0; j < adj[a].size(); j++){
                if (adj[a][j].first == b){
                    adj[a][j].second = min(adj[a][j].second, c);
                    break;
                }
            }
        } else {
            bl[a][b] = true;
            adj[a].push_back({b, c});
        }
    }
    for (int i = 0; i < t; i++){
        int a, b;
        cin >> a >> b;
        tc.push_back({a, b});
        st.insert(a);
    }
}

void sol(){
    for (int i : st){
        for (int j = 1; j <= n; j++){
           dist[i][j] = INT_MAX;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[i][i] = 0;
        pq.push({dist[i][i], i});
        while (!pq.empty()){
            auto[d, cur] = pq.top();
            pq.pop();
            for (pair<int, int> pi : adj[cur]){
                auto[next, cost] = pi;
                if (dist[i][next] > max(cost, d)){
                    dist[i][next] = max(cost, d);
                    pq.push({dist[i][next], next});
                }
            }
        }
    }
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
    for (pair<int, int> pi : tc){
        auto[start, end] = pi;
        if (dist[start][end] == INT_MAX) cout <<"-1\n";
        else cout << dist[start][end] << "\n";
    }
}
