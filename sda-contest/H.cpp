#include <iostream>
using namespace std;

int a[1000000];
int d[1000000];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    int c = 0;
    for (int i = n - 1; i >= 0; --i) {
        int a_temp = a[i] + c;
        c-= d[i];
        c+= a[i]>0;
        d[i - a[i]]++;
        a[i] = a_temp;
    }

    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<" ";
    }
}