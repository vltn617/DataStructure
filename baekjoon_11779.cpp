#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>

using namespace std;

int n, m, start, destination;
vector<vector<pair<int, int>>> adj(1001);
pair<long long, int> dist[1001];
bool bl[1001][1001];

void input(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dist[i].first = INT_MAX;
        dist[i].second = -1;
    }
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if (bl[a][b]){
            for (int i = 0; i < adj[a].size(); i++){
                if (adj[a][i].first == b){
                    adj[a][i].second = min (adj[a][i].second, c);
                    break;
                }
            }
        }
        else {
            bl[a][b] = true;
            adj[a].push_back({b, c});
        }
    }
    cin >> start >> destination;
}

void sol(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start].first = 0;
    pq.push({dist[start].first, start});
    while (!pq.empty()){
        auto[d, cur] = pq.top();
        pq.pop();
        for (pair<int, int> pi : adj[cur]){
            auto[next, cost] = pi;
            if (dist[next].first > d + cost){
                dist[next].first = d + cost;
                dist[next].second = cur;
                pq.push({dist[next].first, next});
            }
        }
    }
    stack <int> st;
    int cur = destination;
    while (dist[cur].second != -1){
        st.push(cur);
        cur = dist[cur].second;
    }
    st.push(start);
    cout << dist[destination].first << "\n";
    cout << st.size() << "\n";
    while (!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}