#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int n, m;
vector<vector<string>> edge(51);
string king;
unordered_map<string, int> in_degree;
unordered_map<string, vector<string>> familyTree;
unordered_map<string, long long> score;
vector<string> candidate;
void input(){
    cin >> n >> m >> king;
    for (int i = 0; i < n; i++){
        string a, b, c;
        cin >> a >> b >> c;
        in_degree[a] = 0;
        in_degree[b] = 0;
        in_degree[c] = 0;
        familyTree[b].push_back(a);
        familyTree[c].push_back(a);
    }
    for (int i  = 0; i < m; i++){
        string s;
        cin >> s;
        candidate.push_back(s);
    }
    for (const auto[parent, kids]: familyTree){   
        for (string name : kids){
            in_degree[name]++;
        }
    }
}

void sol(){
    score[king] = LLONG_MAX;
    queue<string> q;
    for (const auto[p, i] : in_degree){
        if (i == 0) q.push(p);
    }
    while (!q.empty()){
        string p = q.front();
        q.pop();
        for (string kid : familyTree[p]){
            score[kid] += (score[p]/2);
            in_degree[kid]--;
            if (in_degree[kid] == 0){
                q.push(kid);
            }
        }
    }
    long long Max = -1;
    string ans;
    for (string p : candidate){
        if (Max < score[p]){
            Max = score[p];
            ans = p;
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