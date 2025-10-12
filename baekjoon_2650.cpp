#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n;
int MAX = 51;
int order[4] = {0, 2, 3, 1};
int ans = 0;
int cross[51] = {0,};
vector <pair <int, int>> v;
int convert(int a, int b){
    if (a == 2 || a == 3) b = MAX - b;
    a = order[a - 1] * MAX;
    return a + b;
}

void input(){
    cin >> n;
    for (int i = 0; i < n/2 ; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int p = convert(a, b);
        int q = convert(c, d);
        v.push_back({min(p, q), max(p, q)});
    }
}

void solve(){
    for (int i = 0; i < v.size(); i++){
        auto [a, b] = v[i];
        for (int j = 0; j < v.size(); j++){
            if (i == j) continue;
            auto[c, d] = v[j];
            if (a < c && c < b && b < d){
                ans ++;
                cross[i]++;
                cross[j]++;
            }
        }
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    cout << ans << '\n';
    cout << *max_element(cross, cross+51);
}