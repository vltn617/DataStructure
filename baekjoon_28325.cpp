#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
long long arr[250001];
long long ans = 0;
vector <int> v;

void input(){
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> arr[i];
        ans += arr[i];
        if (arr[i] > 0){
            v.push_back(i);
        }
    }
}

void sol(){
    input();
    int sz = v.size();
    if (sz == 0) {
        ans = (n / 2);
        if (n == 1) ans = 1;
    }
    else {
        int rooms = v[0] - 1;
        rooms += (n - v[sz - 1]);
        ans += ((rooms + 1) / 2);
        for (int i = 0; i < sz - 1; i++){
            rooms = v[i + 1] - v[i];
            ans += (rooms / 2);
        }
    }
    cout << ans;
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    sol();
}