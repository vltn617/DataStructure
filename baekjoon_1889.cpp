#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

int n;
int in_degree[200001];
int edge[200001][2];
bool Included[200001];
bool visited[200001];

void input(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        Included[i] = true;
        int a, b;
        cin >> a >> b;
        edge[i][0] = a;
        edge[i][1] = b;
        in_degree[a]++;
        in_degree[b]++;
    }
}

void sol(){
    int exclude = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (in_degree[i] < 2){
            q.push(i);
        }
    }
    while (!q.empty()){
        int x = q.front();
        q.pop();
        if (visited[x] == true) continue;
        visited[x] = true;
        exclude++;
        Included[x] = false;
        for (int next : edge[x]){
            in_degree[next]--;
            if (in_degree[next] < 2){
                q.push(next);
            }
        }
    }
    cout << n - exclude << "\n";
    for (int i = 1; i <= n; i++){
        if (Included[i]) cout << i << " ";
    }
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}