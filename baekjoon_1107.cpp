#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int target, n;
vector <int> button;
int ans;
void dfs(int cur, int num){
    
    for (int i : button){
        int temp = cur;
        temp *= 10;
        temp += i;
        //cout << temp << endl;     
        ans = min(ans, abs(temp - target) + num + 1);
        if (temp < 10 * target && cur != temp) dfs(temp, num + 1);
    }
}

int main(){
    bool broken[10];
    cin >> target >> n;
    for (int i = 0; i < 10; i++) broken[i] = false;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        broken[temp] = true;
    }
    
    for (int i = 0; i < 10; i++){
        if(!broken[i]) button.push_back(i); 
    }
    ans = abs(target - 100);
    dfs(0, 0);
    cout << ans;
}