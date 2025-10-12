#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int tc;
    cin >> tc;
    while (tc > 0){
        int n, d, c;
        cin >> n >> d >> c;
        vector <vector<pair<int, int>>> adj(n + 1);
        int dist[10001];
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int  i = 0; i < d; i++){
            int a, b, s;
            cin >> a >> b >> s;
            adj[b].push_back({a, s});
        }
        for (int i = 1; i <= n; i++) dist[i] = INT_MAX;

        dist[c] = 0;
        pq.push({dist[c], c});
        while(!pq.empty()){
            auto[distance, cur] = pq.top();
            pq.pop();
            if (dist[cur] < distance) continue;
            for (pair<int, int> pi : adj[cur]){
                auto[next, cost] = pi;
                if (dist[next] > cost + dist[cur]){
                    dist[next] = cost + dist[cur];
                    pq.push({dist[next], next});
                }
            }
        }
        int cnt = 0;
        int maxTime = -1;
        for (int i = 1; i <= n; i++){
            if (dist[i] != INT_MAX){
                cnt ++;
                if (maxTime < dist[i]){
                    maxTime = dist[i];
                }
            }
        }
        cout << cnt << " " << maxTime << "\n";
        tc--;
    }
}