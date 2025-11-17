#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int tc = 3;
    while (tc > 0){
        int n;
        cin >> n;
        long long sum = 0;
        for (int i = 0; i < n; i++){
            long long temp;
            cin >> temp;
            sum += temp;
        }
        if (sum > 0) cout << "+\n";
        else if (sum == 0) cout << "0\n";
        else cout << "-\n";
        tc--;
    }
}