#include <iostream>
#include <string>

using namespace std;

int main(){
    int i = 1;
    while (true){
        
        int a, b;
        string oper;
        cin >> a >> oper >> b;
        if (oper == "E") break;
        cout << "Case " << i <<": ";
        if (oper == ">") {
            if (a > b) cout << "true";
            else cout << "false";
            cout << "\n";
        }
        else if (oper == ">="){
            if (a >= b) cout << "true";
            else cout << "false";
            cout << "\n";
        }
        else if (oper == "<"){
            if (a < b) cout << "true";
            else cout << "false";
            cout << "\n";
        }
        else if (oper == "<="){
            if (a <= b) cout << "true";
            else cout << "false";
            cout << "\n";
        }
        else if (oper == "=="){
            if (a == b) cout << "true";
            else cout << "false";
            cout << "\n";
        }
        else if (oper == "!="){
            if (a != b) cout << "true";
            else cout << "false";
            cout << "\n";
        } 
        i++;
    }
}