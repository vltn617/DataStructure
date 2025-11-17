#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n, m;
vector <tuple<int, int, int>> adj;
int ans = 0;
int parent[100001];

bool cmp (const tuple<int, int, int> a, const tuple<int, int, int> b){
    auto[a1, a2, a3] = a;
    auto[b1, b2, b3] = b;
    return a3 < b3;
}

int getParent(int x){
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
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

void input(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj.push_back({a, b, c});
    }
    sort(adj.begin(), adj.end(), cmp);
}


void sol(){
    for (tuple<int, int, int> ti : adj){
        auto[a, b, c] = ti; 
        if (isCycle(a, b) == false){
            ans += c;
            unionParent(a, b);
        }
    }
    cout << ans;
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}