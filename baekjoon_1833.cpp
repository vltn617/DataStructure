#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int arr[201][201];
vector<tuple<int, int, int>> edge;
int parent[201];


void input(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        for (int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            edge.push_back({i, j, arr[i][j]});
        }
    }
}

int getParent(int x){
    if (x == parent[x]) return x;
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

bool cmp(const tuple<int, int, int> a, const tuple<int, int, int> b){
    auto[a1, a2, a3] = a;
    auto[b1, b2, b3] = b;
    return a3 < b3;
}

void sol(){
    int C = 0;
    vector<pair<int, int>> M;
    sort(edge.begin(), edge.end(), cmp);
    for (auto[u, v, w] : edge){
        if (w < 0){
            unionParent(u, v);
            C -= w;
        } else if (w == 0) continue;
        else {
            if (isCycle(u, v) == false){  
                M.push_back({min(u, v), max(u, v)});
                C += w;
                unionParent(u, v);
            }
        }
    }
    cout << C << " " << M.size() << "\n";
    for (auto[u, v] : M){
        cout << u << " " << v << "\n";
    }
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}