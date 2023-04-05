#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char input;
    stack<char> s;
    stack<int> l,u;
    vector<int> v;
    int lows = 0, ups = 0;
    while(cin.get(input))
    {
        if (input == '\n') break;
        if(isupper(input))  ups++,v.push_back(0),u.push(ups);
        else lows++,l.push(lows);
        if(!s.empty() && _toupper(input) == _toupper(s.top()) && input!=s.top()){
            s.pop();
            v.at(u.top()-1) = l.top();
            l.pop();
            u.pop();

        } else {
            s.push(input);
        }
    }
    if(!s.empty()) cout << "Impossible";
    else {
        cout << "Possible\n";

        for (int x: v) {
            cout << x << " ";
        }
    }

    return 0;
}
