#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int in_degree[32001];
vector<vector<int>> edge(32001);

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        in_degree[b]++;
    }
}

void sol(){
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 1; i <= n; i++){
        if (in_degree[i] == 0) pq.push(i);
    }
    while (!pq.empty()){
        int x = pq.top();
        pq.pop();
        cout << x << " ";
        for (int next : edge[x]){
            in_degree[next]--;
            if (in_degree[next] == 0) pq.push(next);
        }
    }
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}