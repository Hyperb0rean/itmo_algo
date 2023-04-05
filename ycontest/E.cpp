#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n=0,k,input;
    cin>>n>>k;
    vector<int> coord;
    while(n--){
        cin>>input;
        coord.push_back(input);
    }

    int left = 0, right = coord.back() - coord[0] +1;
    while (right - left > 1){
        int mid =( left + right )/2;
        int cows = 1;
        int last = coord[0];
        for(int x : coord) if(x - last >= mid) cows++, last = x;
        if(cows >= k) left = mid;
        else right = mid;
    }
    cout<<left;

    return 0;
}
