#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
int graph[51][51];
vector<tuple<int, int, int>> edge;
int sum = 0;
int parent[51];
void input(){
    cin >> n; 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            char a;
            cin >> a;
            if (a == '0') graph[i][j] = 0;
            else if (a >= 97) graph[i][j] = a - 96;
            else graph[i][j] = a - 38;
            sum += graph[i][j];
            edge.push_back({i, j, graph[i][j]});
        }
    }
}
bool cmp (const tuple<int, int, int> a, const tuple<int, int, int> b){
    auto[a1, a2, a3] = a;
    auto[b1, b2, b3] = b;
    return a3 < b3;
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

void sol(){
    for (int i = 1; i <= n; i++) parent[i] = i;
    sort(edge.begin(), edge.end(), cmp);
    int need = 0;
    for (auto[x, y, c] : edge){
        if (isCycle(x, y) == false && c != 0){
            need += c;
            unionParent(x, y);
        }
    }
    for (int i = 1; i <= n; i++){
        if (getParent(i) != 1){
            cout << "-1";
            return;
        }
    }
    cout << sum - need;
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}