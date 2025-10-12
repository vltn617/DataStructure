#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int money, k;
vector <pair<int, int>> coins;
int dp[10001];

void input(){
    cin >> money >> k;
    for (int i = 0; i < k; i++){
        int value, count;
        cin >> value >> count;
        coins.push_back({value, count});
    }
}

void solve(){
    dp[0] = 1;
    for (int i = 0; i < k; i++){
        auto[value, cnt] = coins[i];
        for (int j = money; j >= 0; j--){
            for (int l = 1; l <= cnt; l++){
                if (j - value * l >= 0){
                    dp[j] += dp[j - value * l];
                }
            }
        }
    }
     
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    cout << dp[money];
}