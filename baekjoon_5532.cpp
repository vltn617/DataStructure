#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;
    int study = -1;
    if (a % c == 0) study = max(study, a / c);
    else study = max(study, a / c + 1);
    if (b % d == 0) study = max(study, b / d);
    else study = max(study, b / d + 1);
    cout << l - study;
}