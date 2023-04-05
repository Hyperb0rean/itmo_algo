#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct {
    bool operator()(const int & a, const int& b) const {
        return a>b;
    }
} myComp;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k,sum=0;
    std::vector<int> v;
    cin>>n>>k;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end(),myComp);
    for (int i = 1; i <= n; ++i) {
        sum+= (i%k) !=0 ? v[i-1] : 0;
    }
    cout<<sum;
    return 0;
}

