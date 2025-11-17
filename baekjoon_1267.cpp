#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> call;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        call.push_back(a);
    }   
    int A = 0, B = 0;
    for (int x : call){
        A += (x / 30 + 1) * 10;
        B += (x / 60 + 1) * 15;
    }
    if (A < B) cout << "Y " << A;
    else if (A == B) cout << "Y M " << A;
    else cout << "M " << B;
}