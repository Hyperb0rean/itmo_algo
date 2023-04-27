#include <iostream>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
#include <list>


using namespace std;

const int maxp = 500000;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,p,actions = 0;

    std::unordered_set<int> onfloor;
    std::priority_queue<pair<int,int>,vector<pair<int,int>>, std::less<>> cars_heap;

    cin>>n>>k>>p;

    int input[p];
    list<int> nodes[n];

    for (int i = 0; i < p; ++i) {
        cin>>input[i];
        nodes[--input[i]].push_back(i);
    }

    for (int i = 0; i < p; ++i) {
        nodes[input[i]].pop_front();
        if(onfloor.find(input[i]) == onfloor.end()){
            actions++;
            cout<<i<<" down "<<input[i]+1<<" ";
            if(onfloor.size() >= k){
                cout<<"up "<< cars_heap.top().second +1;
                onfloor.erase(cars_heap.top().second);
                cars_heap.pop();
            }
            onfloor.insert(input[i]);
            cout<<"\n";
        }
        int priority = nodes[input[i]].empty() ? maxp : nodes[input[i]].front();
        cars_heap.emplace(priority,input[i]);
    }
    cout<<actions;
    return 0;
}
