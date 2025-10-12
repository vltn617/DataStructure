#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long arr[501];
long long temp[501];
int ans;
int cnt;
long long maxDiff = -1;
void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    ans = n;
    maxDiff = (*max_element(arr, arr + n) - *min_element(arr, arr+n));
}

void dfs(int point, int i, long long diff){
    if (i < 0 || i >= n) return;
    if (i < point){
        if (temp[i] + diff != temp[i + 1]){
            cnt ++;
            temp[i] = temp[i + 1] - diff;
        }
        dfs(point, i - 1, diff);
    }
    else if (point < i){
        if (temp[i - 1] + diff != temp[i]){
            cnt ++;
            temp[i] = temp[i - 1] + diff;
        }
        dfs(point, i + 1, diff);
    }

}

void sol(){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            int diff = arr[j] - arr[i];
            if (diff % (j - i) == 0){
                for (int l = 0; l < n; l++) temp[l] = arr[l];
                diff /= (j - i);

                cnt = 0; 
                dfs(i, i + 1, diff);
                dfs(i, i - 1, diff);
                /*for (int l = 0; l < n; l++) cout << temp[l] << " ";
                cout << cnt << endl;*/
                ans = min(ans, cnt);
            }
        }
    }
    cout << ans;
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}