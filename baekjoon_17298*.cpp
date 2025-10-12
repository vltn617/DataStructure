#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n;
vector <int> v;
stack <int> st;
void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
}

void sol(){
    input();
    vector <int> ans(n);
    for (int i = n - 1; i >= 0; i--){
        while (!st.empty()){
            if (st.top() > v[i]){
                ans[i] = st.top();
                break;
            } else st.pop();
        }
        if (st.empty()) ans[i] = -1;
        st.push(v[i]);
    }
    for (int i : ans){
        cout << i << " ";
    }
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
}
