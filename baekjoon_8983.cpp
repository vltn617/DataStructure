#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int M, N, L;
vector <int> loc;
vector <pair<int, int>> animals;

void input(){
    cin >> M >> N >> L;
    for (int i = 0; i < M; i++){
        int location;
        cin >> location;
        loc.push_back(location);
    }
    for (int i = 0; i < N; i++){
        int xpos, ypos;
        cin >> xpos >> ypos;
        animals.push_back({xpos, ypos});
    }
}

bool isInRange(const int idx, const pair<int, int> p){
    if (idx < 0 || idx >= M) return false;
    if (abs(loc[idx] - p.first) + p.second <= L){
        return true;
    }
    return false;
}

void sol(){
    input();
    int ans = 0;
    sort(loc.begin(), loc.end());
    for (pair<int, int> p : animals){
        int target = p.first;
        int left = 0; 
        int right = M;
        int mid = 0;
        while (left <= right){
            mid = (left + right) / 2;
            if (target < loc[mid]){
                right = mid - 1;
            } else if (target > loc[mid]) {
                left = mid + 1;
            } else break;
        }
        if (isInRange(mid - 1, p) || isInRange(mid, p) || isInRange(mid + 1, p)){
            ans++;
        }
    }
    cout << ans;
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
}