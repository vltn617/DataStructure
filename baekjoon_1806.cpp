#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int n, s;
vector <int> v;

void input(){
    cin >> n >> s;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
}

void sol(){
    input();
    int arr[n + 1];
    arr[0] = 0;
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++){
        arr[i] = arr[i - 1] + v[i - 1];
    }
    int start = 0;

    for (start = 1; start <= n; start++){
        int left = start;
        int right = n;
        int mid = (left + right) / 2;
        int target = arr[start] + s - v[start - 1];
        while (left < right){
            if(arr[mid] < target){
                left = mid + 1;
            } else {
                right = mid;
            }
            mid = (left + right) / 2;
        }
        //cout << mid <<" " << start << endl;
        if (arr[mid] - arr[start - 1] < s){
            continue;
        } else {
            ans = min(ans, mid - start + 1);
        }
        
    }
    if (ans == INT_MAX) {
        cout << "0";
        return;
    } else cout << ans;  
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
}