#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; 
int output[31];
int ans[31];

void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> output[i];
    }
}

void sol(){
    input();
    int offset = 0;
    for (int i = 0; i < n; i++){
        ans[offset] = output[i];
        offset = (offset + output[i]) % n;
        while (i != n -1 && ans[offset] != 0){
            offset = (offset + 1) % n;
        }
    }
    cout << n << '\n';
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
}