#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>


using namespace std;

int n, m, t, start;
vector<int> og;
vector <vector<int>> graph(51);
vector <vector<int>> party(51);
bool visited[51];
void input(){
    cin >> n >> m >> t;
    for (int i = 0; i < t; i++){
        int temp;
        cin >> temp;
        og.push_back(temp);
        visited[temp] = true;
    }
    for (int i = 1; i <= m; i++){
        int p;
        cin >> p;
        for (int j = 0; j < p; j++){
            int k;
            cin >> k;
            party[i].push_back(k);
            if (j > 0) {
                graph[party[i][j - 1]].push_back(k);
                graph[k].push_back(party[i][j - 1]);
            }
        }
    }
}

void dfs(int num){
    visited[num] = true;
    for (int i : graph[num]){
        if (!visited[i]) dfs(i);
    }
}

void sol(){
    input();
    if (t == 0) {
        cout << m;
        return; 
    }
    for (int i : og){
        dfs(i);
    }
    int cnt = 0;
    for (int j = 1; j <= m; j++){
        bool canLie = true;
        for (int i : party[j]){
            if (visited[i]){
                canLie = false;
            }
        }
        if (canLie) {
           // cout << j << endl;
            cnt++;
        }
    }
    cout << cnt;
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
}