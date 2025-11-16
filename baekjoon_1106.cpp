#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int c, n;
vector<pair<int, int>> v;
int dp[1001];

void input(){
    cin >> c >> n;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    for (int i = 1; i <= 1000; i++) dp[i] = 100011;
}

void sol(){
    for (pair<int, int> pi : v){
        for (int i = 1; i <= c; i++){
            int temp = max(i - pi.second, 0);
            dp[i] = min(dp[i], dp[temp] + pi.first);
        }
        //for (int i = 0; i <=c ; i++) cout << i << ": " << dp[i] << "\n";
    }
    cout << dp[c];
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}