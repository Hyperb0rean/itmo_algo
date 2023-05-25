#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;



void dfs (int v, vector<vector<int>>& D, vector<bool>& used,int x) {
    used[v] = true;
    for (int i = 0; i < D.size(); ++i)
        if(!used[i] &&  D[v][i]<=x) dfs(i,D,used,x);

}
void dfs_t (int v, vector<vector<int>>& D, vector<bool>& used,int x) {
    used[v] = true;
    for (int i = 0; i < D.size(); ++i)
        if(!used[i] &&  D[i][v]<=x) dfs_t(i,D,used,x);

}

bool check(int x, vector<vector<int>>& D) {

        vector<bool> used(D.size(), false);

        dfs(0,D,used,x);

        for (int j = 0; j < D.size(); ++j)
            if(!used[j]) return false;
        vector<bool> used_t(D.size(), false);

        dfs_t(0,D,used_t,x);
        for (int j = 0; j < D.size(); ++j)
            if(!used_t[j]) return false;
    return true;
}



int main(){
    int n,max;
    cin>>n;
    vector <vector<int> > D(n, vector<int>(n, 0));
    for(auto &line: D){
        for(auto &cell: line){
            cin>>cell;
            max = std::max(cell,max);
        }
    }

    int left = -1;
    int right =  max + 1;
    while (right - left>1) {
        int mid = (left + right) / 2;
        if (check(mid,D)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout<< right;
    return 0;

}


//4
//0 10 12 16
//11 0 8 19
//15 16 0 22
//13 10 17 0


