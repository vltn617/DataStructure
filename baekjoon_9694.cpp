#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++){
        int n, m;
        pair<int, int> dist[21];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<vector<pair<int, int>>> edge(21);
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            int a, b, c;
            cin >> a >> b >> c;
            edge[a].push_back({b, c});
            edge[b].push_back({a, c});
        }
        for (int i = 0; i < m; i++) dist[i].first = INT_MAX;
        dist[0] = {0, 0};
        pq.push({dist[0].first, 0});
        while (!pq.empty()){
            auto[d, cur] = pq.top();
            pq.pop();
            for (pair<int, int> pi : edge[cur]){
                auto[next, cost] = pi;
                if (dist[next].first > d + cost){
                    dist[next].first = d + cost;
                    dist[next].second = cur;
                    pq.push({dist[next].first, next});
                }
            }
        }
        if (dist[m-1].first == INT_MAX){
            cout << "Case #" << t << ": -1\n";
            continue;
        }
        int cur = m - 1;
        stack <int> st;
        while (cur != 0){
            st.push(cur);
            cur = dist[cur].second;
        }
        st.push(0);


        cout << "Case #" << t << ": ";
        while (!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
        cout << "\n";
    }
}