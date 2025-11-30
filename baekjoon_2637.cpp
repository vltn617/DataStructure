#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> edge(101);
int in_degree[101];
int need[101];
int basic[101];

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        in_degree[b]++;
        basic[a]++;
    }
}

void sol(){
    queue<int> q;
    vector <int> v;
    for (int i = 1; i <= n; i++){
        if (basic[i] == 0){
            v.push_back(i);
        }
    }
    q.push(n);
    need[n] = 1;
    while (!q.empty()){
        int x = q.front();
        q.pop();
        for (auto[next, c] : edge[x]){
            need[next] += (c * need[x]);
            if (--in_degree[next] == 0){
                q.push(next);
            }
        }
    }
    for (int x : v){
        cout << x << " " << need[x] << "\n";
    }
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}