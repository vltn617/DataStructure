#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <vector <int>> dices;

void input(){
    cin >> n;
    for (int  i = 0; i < n; i++){
        vector <int> temp (6);
        for (int j = 0; j < 6; j++){
            cin >> temp[j];
        }
        dices.push_back(temp);
    }
}

int findOpposite(int idx){
    if (idx == 0) return 5;
    else if (idx == 1) return 3;
    else if (idx == 2) return 4;
    else if (idx == 3) return 1;
    else if (idx == 4) return 2;
    else {
        return 0;
    } 
}

int solve(){
    int ans = -1;
    for (int i = 0; i < 6; i++){
        int down = dices[0][i];
        int idx = -1;
        for (int l = 0; l < 6; l++){
            if (dices[0][l] == down){
                idx = findOpposite(l);
                break;
            }
        }
        int up = dices[0][idx];
        int sum = 0;
        int M = 0;
        for (int k = 0; k < 6; k++){
            if (dices[0][k] == up || dices[0][k] == down) continue;
            else M = max(M, dices[0][k]);
        }
        sum += M;

        for (int j = 1; j < n; j++){
            down = up;
            for (int l = 0; l < 6; l++){
                if (dices[j][l] == down){
                idx = findOpposite(l);            
                break;
                }
            }
            up = dices[j][idx];
            M = 0;
            for (int k = 0; k < 6; k++){
                if (dices[j][k] == up || dices[j][k] == down) continue;
                else M = max(M, dices[j][k]);
            }
            sum += M;
        }
        ans = max(sum, ans);
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