#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int r, c;
char graph[51][51];
int floud[51][51];
int route[51][51];
int startx, starty, targetx, targety;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void input(){
    cin >> r >> c;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> graph[i][j];
            if (graph[i][j] == 'D'){
                targetx = i;
                targety = j;
            } else if (graph[i][j] == 'S'){
                startx = i;
                starty = j;
            }
        }
    }
}

void water(){
    queue <pair<int, int>> q;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            floud[i][j] = -1;
            if (graph[i][j] == '*'){
                q.push({i, j});
                floud[i][j] = 0;
            }
        }
    }
    while (!q.empty()){
        auto[xpos, ypos] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = xpos + dx[i];
            int ny = ypos + dy[i];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c){
                if (graph[nx][ny] != 'D' && graph[nx][ny] != 'X'){
                    if (floud[nx][ny] == -1){
                        floud[nx][ny] = floud[xpos][ypos] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    /*for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << floud[i][j] << " ";
        }
        cout << endl;
    }*/
}
void hedgehog(){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            route[i][j] = -1;
        }
    }
    queue<pair<int, int>> q;
    q.push({startx, starty});
    route[startx][starty] = 0;
    while (!q.empty()){
        auto[xpos, ypos] =  q.front();
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = xpos + dx[i];
            int ny = ypos + dy[i];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c){
                if (graph[nx][ny] != 'X' && (floud[nx][ny] > route[xpos][ypos] + 1 || graph[nx][ny] == 'D' || floud[nx][ny] == -1) && route[nx][ny] == -1){
                    route[nx][ny] = route[xpos][ypos] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    /*for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << route[i][j] << " ";
        }
        cout << endl;
    }*/
}
int main(){
    input();
    water();
    hedgehog();
    if (route[targetx][targety] != -1) cout << route[targetx][targety];
    else cout << "KAKTUS";
}