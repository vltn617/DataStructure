#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
priority_queue<pair<int, int>> pq;
int ans = 0;  
priority_queue<int> pq2;

void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        int d, w;
        cin >> d >> w;
        pq.push({d, w});
    }
}

void sol(){
    int day = pq.top().first;
    while (day > 0){
        while (!pq.empty() && pq.top().first >= day){
            pq2.push(pq.top().second);
            pq.pop();
        }
        day--;
        if (!pq2.empty()){
            ans += pq2.top();
            pq2.pop();
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