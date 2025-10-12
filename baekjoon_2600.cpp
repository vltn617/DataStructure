#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int marble[3];
vector <pair <int, int>> tc(5);
int dp[501][501]; // 0 : unvisited, 1 : lose, 2 : win

void input(){
    for (int i = 0; i < 3; i++) cin >> marble[i];
    for (int i = 0; i < 5; i++) cin >> tc[i].first >> tc[i].second;
}

int isWin(int p, int q){
    if (dp[p][q] > 0) return dp[p][q];
    for (int i = 0; i < 3; i++){
        int res1, res2;
        if (p >= marble[i]) res1 = isWin(p - marble[i], q);
        if (q >= marble[i]) res2 = isWin(p, q - marble[i]);
        if (res1 == 1 || res2 == 1){
            dp[p][q] = 2;
            dp[q][p] = 2;
            return 2;
        }
    }
    dp[q][p] = 1;
    dp[p][q] = 1;
    return 1;
}

void sol(){
    dp[0][0] = 1;
    for (pair<int, int> p : tc){
        auto[case1, case2] = p;
        cout <<(char) (67 - isWin(case1, case2)) << endl;
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}

