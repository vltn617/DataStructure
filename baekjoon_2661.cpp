#include <iostream>
#include <string>

using namespace std;
int n;
string ans; 
bool finish = false;
void isGood(string str){
    if (finish) return;
    int size = str.size();
    for (int i = 1; i <= size/2; i++){
        if (str.substr(size - i, i) == str.substr(size - 2 * i, i)) return;
    }
    if (str.length() == n){
        ans = str;
        finish = true;
    }
    isGood(str + "1");
    isGood(str + "2");
    isGood(str + "3");

}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    isGood("");
    cout << ans;
    
}