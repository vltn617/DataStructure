#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[20001];
bool visited[20001];
int cnt;

void input(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
}

void dfs(int xpos){
    if (visited[xpos] == true) return;
    visited[xpos] = true;
    cnt++;
    dfs(arr[xpos]);
}

long long int lcm(long long int a, long long int b) {
    return (a * b) / __gcd(a, b);
}

void sol(){
    input();
    vector <int> v;
    for (int i = 1; i <= n; i++){
        if (visited[i] == false){
            cnt = 0;
            dfs(i);
            v.push_back(cnt);
        }
    }
    int ans = 1;
    for (int i : v){
        ans = lcm(ans, i);
    }
    cout << ans << "\n";
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
}