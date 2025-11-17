#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int num;
    cin >> num;
    int n; cin >> n;
    for (int i = 0; i < n ; i++){
        char a; int k;
        cin >> a >> k;
    
        (a == '+') ? num += k : num -= k;
    }
    cout << num;
}