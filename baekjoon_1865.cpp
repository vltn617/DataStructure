#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

<<<<<<< HEAD
int main(){
    int tc;
    cin >> tc;
    vector<string> ans;
    while (tc > 0){
        int n, m, w;
        cin >> n >> m >> w;
        vector<tuple<int, int, int>> edge;
        int dist[501];
        for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
        for (int i = 0; i < m; i++){
            int s, e, t;
            cin >> s >> e >> t;
            edge.push_back({s, e, t});
        }
        for (int i = 0; i < w; i++){
            int s, e, t;
            cin >> s >> e >> t;
            edge.push_back({s, e, -t});
        }
        for (int i = 1; i <= n; i++){
            
        }
        tc--;
=======
int n, m, w;
long long dist[501];
vector<tuple<int, int, int>> edge;

bool bellmanFord(){
    for (int i = 1; i <= n; i++){
        for (auto[s, e, t] : edge){
            if (dist[e] > dist[s] + t){
                dist[e] = dist[s] + t;
                if (i == n) return true;
            }
        }
    }
    return false;
}


int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int tc;
    cin >> tc;
    while (tc--){       
        cin >> n >> m >> w;

        for (int i = 1; i <= n; i++){
            dist[i] = INT_MAX;
        } 
        edge.clear();
        for (int i = 0; i < m; i++){
            int u, v, c;
            cin >> u >> v >> c;
            edge.push_back({u, v, c});
            edge.push_back({v, u, c});
        }
        for (int i = 0; i < w; i++){
            int u, v, c;
            cin >> u >> v >> c;
            edge.push_back({u, v, -c});
        }

        bool bl = false;       
        dist[1] = 0;
        bl = bellmanFord();
        cout << ((bl) ? "YES\n" : "NO\n");
>>>>>>> 9f4d4251b3e8a741fdf3a05835abddb2c03ce7ec
    }
}