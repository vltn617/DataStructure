#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N;
int mp, mf, ms, mv;
int nutrients[15][5];

int price = INT_MAX;
vector <int> composition;

void input(){
    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < N; i++){
        for (int  j = 0; j < 5; j++){
            cin >> nutrients[i][j];
        }
    }
}

bool chkNutrients(vector <int> v){
    int p, f, s, vitamin;
    p = f = s = vitamin = 0;
    for (int i: v){
        p += nutrients[i][0];
        f += nutrients[i][1];
        s += nutrients[i][2];
        vitamin += nutrients[i][3];
    }
    if (p >= mp && f >= mf && s >= ms && vitamin >= mv){
        return true;
    }
    return false;
}

void include_or_exclude(int idx, vector <int> v, int p){
    if (idx == N) return;
    //exclude
    include_or_exclude(idx + 1, v, p);
    //include
    v.push_back(idx);
    p += nutrients[idx][4];
    if (chkNutrients(v)){
        if (price > p){
            price = p;
            composition = v;
        } else if (price == p){
            sort(composition.begin(), composition.end());
            sort(v.begin(), v.end());
            int len = min(v.size(), composition.size());
            int i;
            for (i = 0; i < len; i++){
                if (composition[i] > v[i]){
                    composition = v;
                    break;
                } else continue;
            }    
            if (i == len && v.size() < composition.size()) {
                composition = v;
            }        
        }
        return;
    }
    include_or_exclude(idx + 1, v, p);
}

void sol(){
    input();
    vector <int> v;
    int p = 0;
    include_or_exclude(0, v, p);
    if (composition.empty()) {
        cout << -1;
        return;
    }
    cout << price << "\n";
    sort(composition.begin(), composition.end());
    for (int i : composition){
        cout << i + 1 << " ";
    }
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
}