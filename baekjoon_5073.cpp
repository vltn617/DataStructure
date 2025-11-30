#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int a, b, c;
    while (true){
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;
        int arr[3] = {a, b, c};
        sort (arr, arr + 3);
        if (a == b && b == c) cout << "Equilateral\n";
        else if (arr[2] >= arr[1] + arr[0]) cout << "Invalid\n";
        else if (a == b || b == c || a == c) cout << "Isosceles\n";
        else cout << "Scalene\n";
    }
}