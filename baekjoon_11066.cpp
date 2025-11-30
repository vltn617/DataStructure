#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int tc;
    cin >> tc;
    while (tc--){
        int k, arr[501], dp[501][501], sum[501];
        cin >> k;
        sum[0] = 0;
        for (int i = 1; i <= k; i++){
            cin >> arr[i];
            sum[i] = sum[i - 1] + arr[i];
        }    
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                if (i == j) dp[i][j] = 0;
                else dp[i][j] = INT_MAX;
            }
        }
        for (int i = 1; i < k; i++){
            for (int j = 1; i + j <= k; j++){
                for (int s = j; s < i + j; s++){
                    dp[j][j + i] = min(dp[j][j + i], dp[j][s] + dp[s + 1][i + j] + sum[i + j] - sum[j - 1]);
                }
            }
        }
        cout << dp[1][k] << "\n";
    }
}