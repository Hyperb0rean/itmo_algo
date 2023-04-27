#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;

    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        a.push_back(x);
    }

    int len = (int)sqrt(n +.0) +1;

    vector<int> b (len,INFINITY);
    for (int i=0; i<n; ++i)
        b[i / len] = std::min(a[i], b[i/len]);

    for (int l=0, r=k-1;r<n;++r,++l) {
        int min = INFINITY;
        for (int i=l; i<=r; ) {
            if (i % len == 0 && i + len - 1 <= r) {
                // если i указывает на начало блока, целиком лежащего в [l;r]
                min = std::min(min, b[i / len]);
                i += len;
            } else {
                min = std::min(min, a[i]);
                ++i;
            }
        }
        cout<<min<<" ";
    }

    return 0;
}

