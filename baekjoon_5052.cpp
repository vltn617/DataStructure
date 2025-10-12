#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

bool cmp(const string a, const string b){
    if (a.length() < b.length()){
        return true;
    } else return false;
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t > 0){
        int n;
        cin >> n;
        bool isAns = true;
        vector<string> v(n);
        unordered_set <string> us;
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end(), cmp);
        int len = v[0].length();
        for (string str : v){
            for (int i = len; i < str.length() + 1; i++){
                string newString = str.substr(0, i);
                if (us.find(newString) != us.end()){
                    isAns = false;
                }
            }
            if (isAns){
                us.insert(str);
            }
        }
        if (isAns) cout<< "YES\n";
        else cout << "NO\n";


        t--; 
    }
}