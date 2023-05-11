#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k,n;
    std::vector<int> c;
    cin>>k>>n;
    for (int i = 0; i < k; ++i) {
        int x;
        cin>>x;
        c.push_back(x);
    }
    sort(c.begin(),c.end());
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += c[i%k];
    }
    cout<<sum;
    return 0;
}
