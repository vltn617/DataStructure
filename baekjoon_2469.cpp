#include <iostream>
#include <string>
#include <vector>

using namespace std;

int k, n;
vector <string> edge;
char start[26];
char obj[26];

void input(){
    cin >> k >> n;
    for (int i = 0; i < k; i++){
        cin >> obj[i];
        start[i] = i + 65;
    }
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        edge.push_back(s);
    }
}

void swap(char arr[], string trunk){
    for (int i = 0; i < k-1; i++){
        if (trunk[i] == '-'){
            char temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
}

void sol(){
    input();
    int idx = 0;
    while (edge[idx][0] != '?'){
        swap(start, edge[idx]);
        idx++;
    }
    idx = n - 1;
    while (edge[idx][0] != '?'){
        swap(obj, edge[idx]);
        idx--;
    }
    string ans = "";
    bool chg = false;
    for (int i = 0; i < k - 1; i++){
        if (chg) {
            ans += '*';
            chg = false;
            continue;
        }
        if (start[i] == obj[i]) ans += '*';
        else if ((start[i] == obj[i+1]) && (obj[i] == start[i+1])){
            ans += '-';
            chg = true;
        } else {
            ans = "";
            for (int i = 0; i < k - 1; i++) ans += 'x';
            break;
        } 
    }
    cout << ans;
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
}