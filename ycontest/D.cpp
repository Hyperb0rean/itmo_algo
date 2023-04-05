#include <iostream>

using namespace std;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,c,d,k;
    cin>>a>>b>>c>>d>>k;
    if(a == a*b -c) cout << a;
    else if(k>d) cout << ((a*b-c > a) ? d : 0);
    else {
        int res = a;
        for (int i = 0; i < k; ++i) {
            res = max(min(res*b -c,d),0);
        }
        cout<<res;
    }
    return 0;
}
