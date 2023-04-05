#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>


using namespace std;

string s;

struct unit{
    char letter;
    int weight;
};

struct {
    bool operator()(const unit a, const unit& b) const {
        return a.weight == b.weight ? a.letter<b.letter : a.weight<b.weight;
    }
} myComp;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    cin>>s;
    std::unordered_map<char,int> weights;
    for (int i = 0; i < 26; ++i) {
        int x;
        cin>>x;
        weights[alphabet[i]] = x;
    }
    std::vector<unit> letters;
    std::map<char,int> count_taken;
    std::map<char,int> count_all;
    for (char & i : s) count_all[i]++;
    string result;
    for (char & i : s) {
        if(count_all[i]>1
           &&  count_taken[i]<2) {
            letters.push_back({i,weights[i]}) ;
            count_taken[i]++;
        }
        else result+=i;
    }
    sort(letters.begin(),letters.end(),myComp);


    for (int j=0; result.length()!=s.length(); j+=2) {
        result = letters[j].letter+result;
        result =result+ letters[j+1].letter;
    }
    cout<<result;
    return 0;
}



