#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;


string letter;
string bridge[2];
int dp[2][101][21];
int ans = 0;

void input(){
    cin >> letter >> bridge[0] >> bridge[1];
}

int solve(){
    int bridgeLen = bridge[0].length();
    int letterLen = letter.length();
    for (int i = 0; i < bridgeLen; i++) {
        if (letter[0] == bridge[0][i]) dp[0][i][0]++;
        if (letter[0] == bridge[1][i]) dp[1][i][0]++;
    }
    for (int i = 0; i < bridgeLen; i++){
        for (int j = 1; j < letterLen; j++){
            if (bridge[0][i] == letter[j]){
                for (int k = 0; k < i; k++){
                    dp[0][i][j] += dp[1][k][j-1];
                }
            }
            if (bridge[1][i] == letter[j]){
                for (int k = 0; k < i; k++){
                    dp[1][i][j] += dp[0][k][j-1];
                }
            }
        }
    }
    for (int i = 0; i < bridgeLen; i++){
        ans += dp[0][i][letterLen-1];
        ans += dp[1][i][letterLen-1];
    }
    return ans;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    cout << solve();
}

