#include <iostream>
using namespace std;

long long n;

bool rec(long long temp){
    if (temp == 1){
        return true;
    } else if (temp % 2 == 0){
        return rec(temp / 2);
    } else return 0;
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n;
    cout << rec(n);
}