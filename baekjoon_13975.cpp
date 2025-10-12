#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc > 0){
        long long ans = 0;
        int k;
        cin >> k;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0 ; i < k; i++){
            long long a;
            cin >> a;
            pq.push(a);
        }
        while (pq.size() != 1){
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            pq.push(first + second);
            ans += (first + second);
        }
        cout << ans << "\n";
        tc--;
    }
}