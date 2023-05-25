
#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

int main() {


    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<vector < int> > g(n);
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin>>x>>y;
        g[--x].push_back(--y);
        g[y].push_back(x);

    }

    vector<char> part (g.size(), -1);
    bool result = true;
    vector<int> q (g.size());
    for (int st=0; st<g.size(); ++st)
        if (part[st] == -1) {
            int h=0, t=0;
            q[t++] = st;
            part[st] = 0;
            while (h<t) {
                int v = q[h++];
                for (size_t i=0; i<g[v].size(); ++i) {
                    int to = g[v][i];
                    if (part[to] == -1)
                        part[to] = !part[v],  q[t++] = to;
                    else
                        result &= part[to] != part[v];
                }
            }
        }

    cout<< (result ? "YES" : "NO");

    return 0;
}