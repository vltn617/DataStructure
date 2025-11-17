#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    double arr[5] = {350.34, 230.9, 190.55, 125.3, 180.9};
    while (tc > 0){
        double sum = 0;
        for (int i = 0; i < 5; i++){
            int n;
            cin >> n;
            sum += arr[i] * n;
        }
        printf("$%.2lf\n", sum);
        tc--;
    }
}