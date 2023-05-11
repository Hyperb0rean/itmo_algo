#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    std::vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }
    double sum = 0;
    double prob_pair = 2./(n*(n-1));
    double prob_num = 1./36;
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            for (int k = 0; k < 6; ++k) {
                for (int l = 0; l < 6; ++l) {
                    sum+=prob_pair*prob_num*min(v[i][k],v[j][l])*min(v[i][k],v[j][l])*min(v[i][k],v[j][l]);
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
