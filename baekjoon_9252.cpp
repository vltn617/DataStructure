#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
string dp[1001][1001];
int dp2[1001][1001];

int main(){
    string a, b;
    cin >> a >> b;
    a = "0" + a;
    b = "0" + b;
    int n = a.length();
    int m = b.length();
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if (i == 0 || j == 0) {
                dp[i][j] = "";
                continue;
            }
            if (a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + a[i];
                dp2[i][j] = dp2[i-1][j-1] + 1;
            } else {
                if (dp[i-1][j].length() >= dp[i][j-1].length()){
                    dp[i][j] = dp[i - 1][j];
                } else dp[i][j] = dp[i][j - 1];
                dp2[i][j] = max(dp2[i-1][j], dp2[i][j-1]);
            }
        }
    }
    /*for(int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << dp2[i][j] << "   ";
        }
        cout << endl;
    }*/
   cout << dp2[n][m];
}