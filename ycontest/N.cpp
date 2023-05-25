#include <iostream>
#define MAX 102

int a[MAX];

using namespace std;

int leader(int n) {
    while (n != a[n]) n = a[n];
    return n;
}

void un(int x,int y) {
    int x1 = leader(x),y1 = leader(y);
    if (x1 == y1) return;
    a[x1] = y1;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        a[i] =i;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        un(i,x-1);
    }
    int count =0;
    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<" ";
        if(a[i] == i) count++;
    }
    cout<<"\n"<<count;
    return 0;
}
