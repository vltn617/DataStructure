#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool visited[100001][2];
int graph[100001][2];
int n;
int loc1, loc2;
vector <vector <pair <int, int>>> edge(100001);
vector <pair <int, int>> neighbor;

void dfs(int loc, int idx){
    visited[loc][idx] = true;
    for (pair<int, int> p : edge[loc]){
        auto[end, price] = p;
        if (visited[end][idx] == false){
            graph[end][idx] = graph[loc][idx] + price;
            dfs(end, idx);
        }
    }
}

void sol(){
    cin >> n >> loc1 >> loc2;
    for (int i = 0; i < n - 1; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
        neighbor.push_back({a, b});
    }
    for (int i = 1; i <= n; i++){ // visited initialize
        visited[n][0] = false;
        visited[n][1] = false;
    }
    dfs(loc1, 0);
    dfs(loc2, 1);

    int ans = INT_MAX;
    for (pair <int, int> p : neighbor){
        auto[a, b] = p;
        if (ans > graph[a][0] + graph[b][1]){
            ans = graph[a][0] + graph[b][1];
        }
        if (ans > graph[a][1] + graph[b][0]){
            ans = graph[a][1] + graph[b][0];
        }
    }
    for (int i = 1; i <= n; i++){
        if (ans > graph[i][0] + graph[i][1]) ans = graph[i][0] + graph[i][1];
    }
    cout << ans;
}


int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
}