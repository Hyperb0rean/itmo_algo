#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class compare
{
public:
    bool operator() (const std::pair<int, int>& a, const std::pair<int, int>& b)
    {
        return (a.first == b.first) ? (a.second > b.second) : a.first < b.first;
    }
};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    std::priority_queue<pair<int,int>,vector<pair<int,int>>,compare> priorityQueue;
    int k;
    cin>>k;
    for (int i = 1; i <= k; ++i) {
        int x;
        cin>>x;
        priorityQueue.emplace(x,i);
    }
    while(!priorityQueue.empty()){
        pair<int,int> top = priorityQueue.top();
        priorityQueue.pop();
        cout<<top.second<<" ";
        if(!priorityQueue.empty()){
            pair<int,int> top2 = priorityQueue.top();
            priorityQueue.pop();
            cout<<top2.second<<" ";
            if(top2.first > 1) priorityQueue.emplace(top2.first-1,top2.second);
        }
        if(top.first > 1) priorityQueue.emplace(top.first-1,top.second);
    }

    return 0;
}
