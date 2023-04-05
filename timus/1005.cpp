#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,min = INT32_MAX;
    cin>> n;
    vector<bool> mask(n,0);
    vector<int> values;

    for (int i = 0; i < n; ++i) {
        int input =0;
        cin>>input;
        values.push_back(input);
    }

    for(int i = 0; i < 1<<(n-1) ; ++i)
    {
        int sum1 = 0,sum2 = 0;
        int j = i;
        for (int k = 0; k < n/2; ++k) {
            if(j%2) sum1+=values[k];
            else sum2+=values[k];
            j/=2;
        }
        min = std::min(abs(sum2-sum1),min);
    }
    cout<<min;
    return 0;
}
