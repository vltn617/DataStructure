#include <iostream>
#include <vector>

using namespace std;

vector <vector<int>> v;
int n;
int visited[101];
int cnt = 0;
bool isStable = true;
int num = 0;

void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        vector <int> temp (n);
        visited[i] = -1;
        for (int j = 0; j < n; j++){
            cin >> temp[j];
        }
        v.push_back(temp);
    }
}

void dfs(int who){
    if (visited[who] == -1) visited[who] = cnt; 
    num++;
    for (int i = 0; i < n; i++){
        if (who == i) continue;
        if (v[who][i] == 0){
            if (visited[i] == -1){
                dfs(i);
            } else if (visited[i] != -1 && visited[i] != cnt){
                isStable = false;
                return;
            }
        }
    }
}
void solve(){
    for (int i = 0; i < n; i++){
        if (visited[i] == -1){
            cnt++;
            num = 0;
            dfs(i);
            if (num == 1) isStable = false;
        }
    }
    //for (int i = 0; i < n; i++) cout << i << "  "<< visited[i] << "\n ";
    if (!isStable) cout << 0;
    else {
        cout << cnt << "\n";
        for (int i = 0; i < n; i++){
            if (visited[i] == -2) continue;
            int temp = visited[i];
            for (int i = 0; i < n; i++){
                if (visited[i] == temp){
                    visited[i] = -2;
                    cout << i + 1 << " ";
                }
            }
            cout << "\n";            
        }
    }

}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    solve();
}