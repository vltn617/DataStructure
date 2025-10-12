#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[6] = {0, 1, 1, 1, 2, 2};
int M;

void sol(){
    cin >> M;
    if (M == 1) {
        cout << "1 1";
        return;
    }
    int n = M / 6;
    cout << 2*n + arr[M % 6] <<" ";
    int i = 2;
    int cnt = 0;
    while (M % 4 == 0){
        M /= 4;
        cnt ++;
    }
    while (M != 1){
        if (M % i == 0){
            M /= i;
            cnt ++;
        }
        else i++;
    }
    cout << cnt;
}
int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
}
