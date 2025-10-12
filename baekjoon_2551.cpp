#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int n;
vector <int> v;

void solve(){
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
        sum += a;
    }
    sort(v.begin(), v.end());
    cout << v[(n-1)/2] <<" ";
    int avg = sum / n;
    long long temp = 0;
    for (int i = 0; i < n; i++){
        temp += (2*v[i] - 2*avg -1);
    }
    if (temp > 0) avg ++;
    

    cout << avg << endl;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    solve();
}