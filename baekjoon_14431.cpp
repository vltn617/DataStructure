#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

int startx, starty, endx, endy, n;
vector<pair<int, int>> pos;
int dist[4002];
vector<vector<pair<int, int>>> edge(4002);
bool isPrime[10001];
bool visited[10001];

void input(){
    cin >> startx >> starty >> endx >> endy >> n;
    pos.push_back({startx, starty});
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        pos.push_back({x, y});
        dist[i] = INT_MAX;
    }
    pos.push_back({endx, endy});
}

void prime(){
    for (int i = 2; i <= 10000; i++) isPrime[i] = true;
    for (int i = 2; i <= 100; i++){
        if (isPrime[i] == true){
            for (int j = i * i; j <= 10000; j += i){
                isPrime[j] =false;
            }
        }
    }
}

void sol(){
    prime();
    for (int i = 0; i <= n+1; i++){
        for (int j = i + 1; j <= n+1; j++){
            int distance = (pos[i].first - pos[j].first) * (pos[i].first - pos[j].first) + (pos[i].second - pos[j].second) * (pos[i].second - pos[j].second);
            distance = (int) sqrt(distance);
            if (isPrime[distance]){
                edge[i].push_back({j, distance});
                edge[j].push_back({i, distance});
            }
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[0] = 0;
    dist[n + 1] = INT_MAX;
    pq.push({dist[0], 0});
    while (!pq.empty()){
        auto[d, cur] = pq.top();
        pq.pop();
        for (auto[next, cost] : edge[cur]){
            if (dist[next] > cost + d){
                dist[next] = cost + d;
                pq.push({dist[next], next});
            }
        }
    }
    if (dist[n + 1] == INT_MAX) cout << "-1";
    else cout << dist[n + 1];
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}