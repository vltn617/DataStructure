#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

long long canDrive;
int charger;
long long distances[101];
long long tm[102];
vector <pair <long long, long long>> visited (102, {-1, -1});

void input(){
    cin >> canDrive >> charger;
    for (int i = 0; i < charger + 1; i++){
        cin >> distances[i];
    }
    for (int i = 1; i <= charger; i++){
        cin >> tm[i];
    }
}

int bfs(){
    queue <pair<int, long long>> q;  //current location and time
    q.push({0, 0});
    visited[0].first = 0; // tm
    visited[0].second = 0; // prefer node
    while (!q.empty()){
        auto[loc, time] = q.front();
        q.pop();
        long long fuel = canDrive;
        int distance = 0;
        if (loc > charger + 1) continue;
        for (int i = loc; i < charger + 1; i++){
            distance += distances[i];
            if (fuel >= distance && (visited[i+1].first == -1 || visited[i + 1].first > time + tm[i+1])){
                q.push({i + 1, time + tm[i+1]});
                visited[i+1].first = time + tm[i + 1];
                visited[i+1].second = loc;
            }
        }
    }
    for (int i = 0; i < charger+ 2; i++){
        //cout << i << " "<< visited[i].first <<" " << visited[i].second << endl;
    }
    return visited[charger + 1].first;
}


int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    cout << bfs() <<'\n';
    priority_queue<int, vector<int>, greater<int>> pq;
    int k = charger + 1;
    while (visited[k].second != 0){
        pq.push(visited[k].second);
        k = visited[k].second;
    }

    cout << (int)pq.size() << "\n";
    while (!pq.empty()){
        cout << pq.top() <<" ";
        pq.pop();
    }
}