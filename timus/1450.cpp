#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, start, finish;
    cin >> n >> m;

    vector<vector<int> > edges(m, vector<int>(3));
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        edges[i][0]--;
        edges[i][1]--;
        edges[i][2] *= -1;
    }
    cin >> start >> finish;
    const int INF = 1;
    vector<int> d(n, 1);

    d[--start] = 0;
    for (int i = 0; i < n - 1; ++i){
        for (int j = 0; j < m; ++j){
            if (d[edges[j][0]] < 1) {
                d[edges[j][1]] = min(d[edges[j][1]], d[edges[j][0]] + edges[j][2]);
            }
        }
    }
    if(d[--finish] == 1) {
        cout<<"No solution";
        return 0;
    }
    cout<<-d[finish];

    return 0;
}
