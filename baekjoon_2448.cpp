#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char graph[5000][10000];

void rec(int xpos, int ypos, int n){
    if (n == 3){
        graph[xpos][ypos] = '*';
        graph[xpos + 1][ypos - 1] = '*';
        graph[xpos + 1][ypos + 1] = '*';
        for (int i = 0; i < 5; i++) graph[xpos + 2][ypos - 2 + i] = '*';
    } else{
        rec(xpos + n/2, ypos - n/2, n/2);
        rec(xpos + n/2, ypos + n/2, n/2);
        rec(xpos, ypos, n/2);
    }
}


int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2 * n - 1; j++) graph[i][j] = ' ';
    }
    rec(0, n-1, n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2*n-1; j++){
            cout << graph[i][j];
        }
        cout << "\n";
    }
}