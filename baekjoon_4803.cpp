#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;



int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int tc = 1;
    int n, m;
    cin >> n >> m;
    while (n != 0){
        vector<vector<int>> edge(n + 1);
        queue <int> q;
        bool bl = true;
        int visited[501];
        int cnt = 0;
        for (int i = 1; i <= n; i++) visited[i] = -1;
        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        for (int i = 1; i <= n; i++){
            bl = true;
            if (visited[i] == -1){
                cnt ++;
                q.push(i);
                visited[i] = 0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for (int i : edge[node]){
                        int newNode = i;
                        if (visited[newNode] != -1 && visited[newNode] != visited[node] - 1){
                            if (bl) cnt --;
                            bl = false;
                        } else if (visited[newNode] == -1){
                            visited[newNode] = visited[node] + 1;
                            q.push(newNode);
                        }
                    }
                } 
            }
            //cout << i << " " << cnt <<endl;
        }
        if (cnt == 0){
            cout << "Case " << tc << ": No trees.\n";
        } else{
            if (cnt == 1) cout << "Case " << tc << ": There is one tree.\n";
            else cout << "Case " << tc << ": A forest of " << cnt << " trees.\n";
        }
        cin >> n >> m;
        tc++;
    }
}

