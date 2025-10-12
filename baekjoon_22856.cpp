#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <vector<int>> tree(100001);
bool visited[100001];
int cnt = -1;

void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        int node, kid1, kid2;
        cin >> node >> kid1 >> kid2;
        tree[node].push_back(kid1);
        tree[node].push_back(kid2);
    }
}

void inorder(int cur, bool bl){
    if (cur == -1) return;
    int left = tree[cur][0];
    int right = tree[cur][1];

    cnt++;
    inorder(left, 0);
    if (bl) {
        inorder(right, 1);
    } else {
        cnt++;
        inorder(right, 0);
    }
}

void sol(){
    input();
    inorder(1, true);
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
    cout << cnt;
}