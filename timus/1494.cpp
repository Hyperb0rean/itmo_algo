#include <iostream>
#include <array>
#include <unordered_set>
#include <set>
#include <stack>

using namespace std;


std::array<int,100000> a;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    stack <int> st;
    int p = 0;
    for(int i =1;i<=n;i++){
        st.push(i);
        while(!st.empty() && a[p]==st.top()){
            p++;
            st.pop();
        }
    }
    while(p < n){
        if (a[p]==st.top()){
            p++;
            st.pop();
        }else{
            break;
        }
    }

    if(st.empty()) cout<<"Not a proof";
    else cout<<"Cheater";


    return 0;
}
