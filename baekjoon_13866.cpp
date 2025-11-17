#include <iostream>
#include <queue>

using namespace std;

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    priority_queue<int> pq;
    for (int i = 0; i < 4; i++){
        int temp;
        cin >> temp;
        pq.push(temp);
    }
    int a, b;
    a = b = 0;
    a += pq.top(); pq.pop();
    b += pq.top(); pq.pop();
    b += pq.top(); pq.pop();
    a += pq.top();
    cout << abs(a - b);
}