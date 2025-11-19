#include <iostream>

using namespace std;
int n, m;
int A[101][101];

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int temp;
            cin >> temp;
            cout << A[i][j] + temp << " ";
        }
        cout << "\n";
    }

}