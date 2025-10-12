#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, c;
vector <int> weight;

void input(){
    cin >> n >> k >> c;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        weight.push_back(a);
    }
    sort(weight.begin(), weight.end());
}

void sol(){
    input();
    vector <long long> accumulate;
    for (int i = 0; i < n; i++){
        long long s = 0;
        if (i < n - k){
            for (int j = i; j < i + k; j++){
                s += weight[j];
            }
        } else {
            for (int j = n - k; j < n; j++){
                s += weight[j];
            }
        }
        accumulate.push_back(s);
    }
    long long bag = 0;
    long long rest = 0;
    int idx = 0;
    for (int x = 1; x <= c; x++){
        rest = x - bag;
        if (idx >= n - k){
            cout << accumulate[idx] << "\n";
            continue;
        }
        while (rest >= weight[idx]){
            bag += weight[idx];
            rest = x - bag;
            idx++;
        }
        cout << accumulate[idx] << "\n";
    }
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
}