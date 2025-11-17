#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int n, m;
vector <tuple<int, int, int>> edge(1001);
int parent[1001];
int dist[1001];

void input(){
    cin >> n >> m;
    for (int i = 0; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
}

int getParent(int x){
    if (x == parent[x]) return x;
    else return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool isCycle(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if (a == b) return true;
    else return false;
}

int MST(int hill){
    for (int i = 0; i <= n; i++) parent[i] = i;
    int cnt = 0;
    for (auto[u, v, w] : edge){
        if (w != hill) continue;
        if (isCycle(u, v)) continue;
        else{
            unionParent(u, v);
            cnt++;
        }
    }
    return cnt;
}

void sol(){
    int a = MST(0);
    int b = n - MST(1);
    cout << (a + b) * (a - b);
}


int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}