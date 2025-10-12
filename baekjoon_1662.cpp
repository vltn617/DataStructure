#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

string str;



int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> str;
    int len = str.length();
    stack <int> st;
    int ans = 0;
    for (int i = 0; i < len; i++){
        if (i < len - 1 && str[i + 1] == '('){
            st.push(str[i] - 48);
        } else if (str[i] == '('){
            st.push(-1);
        } else if (str[i] == ')'){
            int temp = 0;
            while(st.top() != -1){
                temp += st.top();
                st.pop();
            }
            st.pop();
            temp *= st.top();
            st.pop();
            st.push(temp);
        } else {
            st.push(1);
        }
    }
    while (!st.empty()){
        ans += st.top();
        st.pop();
    }
    cout << ans;
}