#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct {
    bool operator()(const string& a, const string& b) const {
        return a+b > b+a;
    }
} myComp;



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input;
    vector<string> words;

    while(cin>>input)
    {
        //if(input == "d") break;
      words.push_back(input);

    }

    sort(words.begin(),words.end(),myComp);
    for(const string& s: words){
        cout<<s<<" ";
    }

    return 0;
}
