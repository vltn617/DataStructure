#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

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
    }
}