#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;
long long l;
int n, k;

unordered_set <long long> us;
priority_queue <int, vector<int>, greater<int>> pq;
queue <pair <long long, int>> q;
void input(){
    cin >> l >> n >> k;
    for (int i = 0; i < n; i++){
        long long a;
        cin >> a;
        q.push({a, 0});
    }
}

void sol(){
    while (pq.size() < k){
        auto[loc, darkness] = q.front();
        q.pop();
        if (loc < 0  || loc > l) continue;
        if (us.find(loc) == us.end()){ // non visited
            us.insert(loc);
            pq.push(darkness);
            q.push({loc - 1, darkness + 1});
            q.push({loc + 1, darkness + 1});
        }
    }
    while (!pq.empty()){
        cout << pq.top() << '\n';
        pq.pop();
    }
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}

