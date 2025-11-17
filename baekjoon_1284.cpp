#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    while(true){
        string s;
        cin >> s;
        if (s == "0") break;
        int ans = 0;
        for (char c : s){
            if (c == '0') ans += 4;
            else if (c == '1') ans += 2;
            else ans += 3;
        }
        ans += ((int)s.length() + 1);
        cout << ans << "\n";
    }
}