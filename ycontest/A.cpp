#include <iostream>

using namespace std;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int lmax = 1;
    int rmax = 1;
    int l = 1;
    int r = 1;
    int prev = 0;
    int count = 0;
    int n,t;

    cin>>n;
    while(n--){
        cin>>t;
        if(t == prev){
            count++;
            if(count>=3) {

                lmax = (rmax - lmax) >= (r - l) ? lmax : l;
                rmax = (rmax - lmax) >= (r - l) ? rmax : r;

                l = r - 1;
                count--;

            }
        }
        else{
            prev = t;
            count = 1;
        }
        r++;
    }


    lmax = (rmax-lmax)>=(r-l) ? lmax : l;
    rmax = (rmax-lmax)>=(r-l) ? rmax : r;

    cout<<lmax<<" "<<rmax-1;
    return 0;
}
