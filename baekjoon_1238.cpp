#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m, x;
vector<vector<pair<int, int>>> adj1(1001);
vector<vector<pair<int, int>>> adj2(1001);
int dist1[1001];
int dist2[1001];
int ans = -1;

void input(){
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj1[b].push_back({a, c});
        adj2[a].push_back({b, c});
    }
    for (int i = 1; i <= n; i++) {
        dist1[i] = INT_MAX;
        dist2[i] = INT_MAX;
    }
}

void i_to_x(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    dist1[x] = 0;
    pq.push({dist1[x], x});
    while (!pq.empty()){
        auto[d, cur] = pq.top();
        pq.pop();
        for (pair<int, int> pi : adj1[cur]){
            auto[next, cost] = pi;
            if (dist1[next] > cost + d){
                dist1[next] = cost + d;
                pq.push({dist1[next], next});
            }
        }
    }
}

void x_to_i(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    dist2[x] = 0;
    pq.push({dist2[x], x});
    while (!pq.empty()){
        auto[d, cur] = pq.top();
        pq.pop();
        for (pair<int, int> pi : adj2[cur]){
            auto[next, cost] = pi;
            if (dist2[next] > cost + d){
                dist2[next] = cost + d;
                pq.push({dist2[next], next});
            }
        }
    }
}

void sol(){
    i_to_x();
    x_to_i();
    for (int i = 1; i <= n; i++){
        ans = max(ans, dist1[i] + dist2[i]);
    }
    cout << ans;
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}