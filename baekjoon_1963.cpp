#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool primeNum[10001];
int tc;

void setPrimeNum(){
    for (int i = 1; i < 10000; i++) primeNum[i] = true;
    for (int i = 2; i < 10000; i++){
        if (primeNum[i]){
            for (int j = i * i; j < 10000; j += i){
                primeNum[j] = false;
            }
        }
    }
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    setPrimeNum();
    cin >> tc;
    while (tc > 0){
        int start, end;
        cin >> start >> end;
        queue <int> q;
        q.push(start);
        int visited[10001];
        for (int i = 0; i < 10001; i++) visited[i] = -1;
        visited[start] = 0;
        while (!q.empty()){
            int x = q.front();
            q.pop();
            if (x == end) break;
            string stringx = to_string(x);
            for (int i = 0; i < 4; i++){
                for (int j = 0; j < 10; j++){
                    string temp = stringx;
                    char num = j + 48;
                    if (i == 0 && num == '0') continue;
                    temp[i] = num;
                    int nx = stoi(temp);
                    if (primeNum[nx] && visited[nx] == -1){
                        visited[nx] = visited[x] + 1;
                        q.push(nx);
                    }
                }
            }

        }
        if (visited[end] == -1) cout << "IMPOSSIBLE\n";
        else cout << visited[end] << "\n";
        tc--;
    }
}