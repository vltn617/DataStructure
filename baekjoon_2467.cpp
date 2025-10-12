#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
vector <int> v;

void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
}

void sol(){
    input();
    pair<int, int> ans;
    int min = INT_MAX;
    for (int i = 0; i < n; i++){
        int left = 0;
        int right = n;
        int mid = left;
        int target = (-1) * v[i];
        while (left <= right){
            mid = (left + right) / 2;
            if (target < v[mid]){
                right = mid - 1;
            } else if (target > v[mid]) {
                left = mid + 1;
            } else break;
        }
       // cout << mid << " ";
        if (mid < n && abs(v[i] + v[mid]) < min){
            if (mid == i) continue;
            min = abs(v[i] + v[mid]);
            ans = {v[i], v[mid]};
        }if (mid >= 1 && abs(v[i] + v[mid - 1]) < min){
            if (mid - 1 == i) continue;
            min = abs(v[i] + v[mid - 1]);
            ans = {v[i], v[mid - 1]};
        }

    }
    cout << std::min(ans.first, ans.second) << " " << max(ans.first, ans.second);
}
int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
    return 0;
}