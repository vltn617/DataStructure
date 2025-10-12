#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector <vector<int>> heavier (100);
vector <vector<int>> lighter (100);
int cntHeavy[100];
int cntLight[100];
bool visited[100];


void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        heavier[b].push_back(a);
        lighter[a].push_back(b);
    }
}
void initVisited(){
    for (int i = 0; i <= n; i++){
        visited[i] = false;
    }
}

void dfsHeavy(int node, int curr){
    if (visited[curr] == false){
        visited[curr] = true;
        if (node != curr) cntHeavy[node]++;
        for (int marble : heavier[curr]){
            dfsHeavy(node, marble);
        }
    }
    
}
void dfsLight(int node, int curr){
    if (visited[curr] == false){
        visited[curr] = true;
        if (node != curr) cntLight[node]++;
        for (int marble : lighter[curr]){
            dfsLight(node, marble);
        }
    }
}

int solve(){
    int ans = 0;
    for (int i = 1; i <= n; i++){
        initVisited();
        dfsHeavy(i, i);
        initVisited();
        dfsLight(i, i);
    }
    int half = n / 2;
    for (int i = 1; i <= n; i++){
        if (cntHeavy[i] > half || cntLight[i] > half) ans++;
    }
    return ans;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    cout << solve();
}