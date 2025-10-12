#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int len = s.length();
    int front = len % 3;
    string ans = "";
    int digit = 1;
    int num = 0;
    for (int i = front - 1; i >= 0; i--){
        if (s[i] == '1') num += digit;
        digit *= 2; 
    }
    if (num != 0) ans += (char) num + 48;
    for (int i = front; i < len; i += 3){
        num = 0;
        digit = 1;
        for (int j = i + 2; j >= i; j--){
            if (s[j] == '1') num += digit;
            digit *= 2;
        }
        ans += (char) num + 48;
    }
    if (ans == ""){
        cout << 0;
        return 0;
    }
    cout << ans;
}