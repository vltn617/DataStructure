#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int score[6][3];
int isAble = 0;
vector <pair<int ,int>> p;
vector <int> answer;
void dfs(int gameIndex, int tempscore[][3]){
    if (gameIndex == 15) {
        isAble = 1;
    }
    auto [t1, t2] = p[gameIndex];
    //case1 t1 win
    if (tempscore[t1][0] > 0 && tempscore[t2][2] > 0){
        tempscore[t1][0]--;
        tempscore[t2][2]--;
        dfs(gameIndex+1, tempscore);
        tempscore[t1][0]++;
        tempscore[t2][2]++;
    }
    // case2 draw
    if (tempscore[t1][1] > 0 && tempscore[t2][1] > 0){
        tempscore[t1][1]--;
        tempscore[t2][1]--;
        dfs(gameIndex+1, tempscore);
        tempscore[t1][1]++;
        tempscore[t2][1]++;
    }

    //case3 t2 win
    if (tempscore[t1][2] > 0 && tempscore[t2][0] > 0){
        tempscore[t1][2]--;
        tempscore[t2][0]--;
        dfs(gameIndex+1, tempscore);
        tempscore[t1][2]++;
        tempscore[t2][0]++;
    }
}

void solve(){
    for (int i = 0; i < 6; i++){
        for (int j = i + 1; j < 6; j++){
            p.push_back({i, j});
        }
    }
    for (int tc = 0; tc < 4; tc++){
        isAble = 0;
        for (int i = 0; i < 6; i++){
            int sum = 0;
            for (int j = 0; j < 3; j++){
                cin >> score[i][j];
                sum += score[i][j];
            }
            if (sum != 5) {
                isAble = -1;
            }
        }
        if (isAble == -1) {
            answer.push_back(0);
            continue;
        }
        dfs(0, score);
        answer.push_back(isAble);
    }
    for (int i : answer){
        cout << i << " ";
    }
}

int main(){
    solve();
}
