#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <int> honey;
long long sum;

void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        honey.push_back(a);
        sum += a;
    }
}

long long sol(){
    long long ans = -1;
    long long tempSum;
    long long firstCase;
    //case 1:  a1 and a2 are the locs of bees
    tempSum = sum;
    tempSum -= honey[0]; 
    tempSum -= honey[1];
    if (ans < 2 * tempSum){
        ans = 2 * tempSum;
    }
    firstCase = 2 * tempSum;
    // case 4: 
    int temp = 0;
    for (int i = 2; i < n; i++){
        temp += honey[i];
        temp += honey[i];
        if (temp < honey[1]){
            tempSum = firstCase - (temp - honey[1]);
            if (ans < tempSum){
                ans = tempSum;
            }
        }
        temp -= honey[i];
    }
    //case 2:  a_n-1 and a_n-2 are the locs of bees
    int secondCase;
    tempSum = sum;
    tempSum -= (honey[n-1] + honey[n-2]);
    if (ans < 2 * tempSum){
        ans = 2 * tempSum;
    }
    secondCase = tempSum * 2;
    //case 5;
    temp = 0;
    for (int i = n-3; i >= 0; i--){
        temp += honey[i];
        temp += honey[i];
        if (temp < honey[n-2]){
            tempSum = secondCase - (temp - honey[n-2]);
            if (ans < tempSum){
                ans = tempSum;
            }
        }
        temp -= honey[i];
    }
    //case 3: a_1 and a_n are the locs of bees
    tempSum = sum;
    tempSum -= (honey[n-1] + honey[0]);
    long long k = *max_element(honey.begin() + 1, honey.end() - 1);
    tempSum += k;
    if (ans < tempSum){
        ans = tempSum;
    }
    

    return ans;
}
int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    cout << sol();
}