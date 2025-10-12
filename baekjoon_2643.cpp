#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <pair<int, int>> v;
int dp[1001];

bool cmp(const pair<int , int>& a, const pair<int, int>& b){
    if (a.first < b.first) return true;
    else if (a.first == b.first) return a.second < b.second;
    else return false;
}

void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        v.push_back({0,0});
        dp[i] = 1;
        int a, b;
        cin >> a >> b;
        v[i].first = max(a, b);
        v[i].second = min(a, b);
    }
    sort(v.begin(), v.end(), cmp);
}

int solve(){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (v[i].first <= v[j].second || (v[i].first <= v[j].first && v[i].second <= v[j].second)){
                if (dp[i] + 1 > dp[j]) dp[j] = dp[i] + 1;
            }
        }
    }
    //for (int i = 0; i < n; i++) cout << dp[i] << endl;
    return *max_element(dp, dp + n);
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    cout << solve();
}