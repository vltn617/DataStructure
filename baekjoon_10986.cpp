#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
long long arr[1000001];
long long r[1001];
long long sum = 0;
long long ans = 0; 

void input(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
        int temp = sum % m;
        r[temp]++;
    }
    r[0]++;
}

void sol(){
    for (int i = 0; i < m; i++){
        ans += (r[i] * (r[i] - 1)) / 2;
    }
    cout << ans;
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}
