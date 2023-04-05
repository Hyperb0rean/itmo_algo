#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>


using namespace std;

struct val_dep{
    int value;
    uint depth;
};


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    std::unordered_map<string,std::stack<val_dep>> m;
    std::stack<std::unordered_set<string>> changed;
    changed.emplace(0);
    uint depth = 0;
    string input;

    while (cin>>input){
        if(input == "{"){
            depth++;
            changed.emplace(0);
        }
        else if(input == "}")
        {
            depth--;
            for( const string& k : changed.top()){
                if(!m[k].empty() && m[k].top().depth>depth) m[k].pop();
            }
            changed.top().clear();
            changed.pop();
        } else if(!input.empty()){

            string lhs = input.substr(0, input.find('='));
            string rhs = input.substr(input.find('=') + 1, input.length());

            if (m[lhs].empty()) m[lhs].push({0,depth});

            if (isdigit(rhs[0]) || rhs[0] == '-') {
                if (m[lhs].top().depth >= depth) m[lhs].top() = {stoi(rhs),depth};
                else m[lhs].push({stoi(rhs),depth});
            } else {
                if (m[rhs].empty())  m[rhs].push({0,depth});
                cout << m[rhs].top().value<<"\n";
                if (m[lhs].top().depth >= depth) m[lhs].top() = {m[rhs].top().value,depth};
                else m[lhs].push({m[rhs].top().value,depth});
            }
            changed.top().insert(lhs);
        }
    }

    return 0;
}
