#include <iostream>

using namespace std;

int arr[100001];
int state[100001];

int n, cnt;

void dfs(int x){
    int next = arr[x];
    state[x] = 1;
    if (state[next] == 0) dfs(next);
    else if (state[next] == 1){
        for (int i = next; i != x; i = arr[i]){
            cnt--;
        }
        cnt--;
    }
    state[x] = 2;
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int tc;
    cin >> tc;
    while (tc > 0){
        cin >> n;
        cnt = n;
        for (int i = 1; i <= n; i++){
            cin >> arr[i];
            state[i] = 0;
        }
        for (int i  = 1; i <= n; i++){
            if (state[i] == 0) dfs(i);
        }
        cout << cnt << "\n";
        tc--;
    }
}