#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int arr[100001];
bool bl[100001];
long long ans = 0;

void sol(){
    cin >> n;
    int left = 0;
    int right = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    while (left < n){
        if (right == n){
            ans += (right - left);
            left ++;
        } else if (bl[arr[right]] == false){
            bl[arr[right]] = true;
            right ++;
        } else if (bl[arr[right]] == true){
            bl[arr[left]] = false;
            ans += (right - left);
            left++;
        }
        //cout << left << " " << right << " " << ans <<endl;
    }
    cout << ans;
}


int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
}