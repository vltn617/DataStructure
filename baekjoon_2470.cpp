#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int arr[100001];
pair<int, int> ans;
int _min = INT_MAX;

void input(){
    cin >> n; 
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

bool cmp(const int a, const int b) {
    return a < b;
}

void renewal(int idx, int mid){
    if (mid >= n || mid < 0) return;
    if (mid == idx) return;
    int mix = abs(arr[idx] + arr[mid]);
    if (mix < _min){
        _min = mix;
        ans = {arr[idx], arr[mid]};
    }
}

void sol(){
    input();
    for (int i = 0; i < n; i++){
        int target = (-1) * arr[i];
        int left = 0; 
        int right = n;
        int mid = 0;
    
        while (left <= right){
            mid = (left + right) / 2;
            if (arr[mid] < target){
                left = mid + 1;
            } else if (arr[mid] > target){
                right = mid - 1;
            } else break;
        } 
        renewal(i, mid);
        renewal(i, mid - 1);
        renewal(i, mid + 1);
    }
    cout << min(ans.first, ans.second) << " " << max(ans.first, ans.second);
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
}