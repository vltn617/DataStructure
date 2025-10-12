#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m; 
vector <vector<pair<int, int>>> edge(501);
pair<int, int> visited[501];
bool isLock;

void input(){
    cin >> n >> m;
    for (int i = 0 ; i < m; i++){
        int a, b, c;
        bool bl = true;
        cin >> a >> b >> c;
        for (int j = 0; j < edge[a].size(); j++){
            auto[end, price] = edge[a][j];
            if (end == b){
                if (c < price){
                    edge[a][j].second = c;
                }
                bl = false;
            }
        }
        if (bl) edge[a].push_back({b, c});
    }
    for (int i = 0; i < 501; i++) visited[i].first = INT_MIN;
}


void dfs(int start){
    for (pair<int, int> pi : edge[start]){
        auto[end, price] = pi;
        if (visited[start].first + price < 0){
            if (visited[end].second == start) isLock = true;
            else {
                visited[end].first = visited[start].first + price;
                visited[end].second = start;
                dfs(end);
            }
        } else if (visited[end].first == INT_MIN) {
            visited[end].first = visited[start].first + price;
            visited[end].second = start;
            dfs(end);
        } else if (visited[end].first > visited[start].first + price){
            visited[end].first = visited[start].first + price;
            visited[end].second = start;
            dfs(end);
        } 
    }
}
void sol(){
    input();
    visited[1].first = 0;
    visited[1].second = 1;
    dfs(1);
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
    if (isLock) {cout << -1; return 0;}
        
    for (int i = 2; i <= n; i++){
        if(visited[i].first != INT_MIN) cout << visited[i].first << "\n";
        else cout << -1 << "\n";
    }
}
