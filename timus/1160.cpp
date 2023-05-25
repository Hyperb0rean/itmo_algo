#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p (1000);

int dsu_get (int v) {
    return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void dsu_unite (int a, int b) {
    a = dsu_get (a);
    b = dsu_get (b);
    if (a != b)
        p[a] = b;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,max =0;
    cin >> n >> m;

    vector < pair < int, pair<int,int> > > g (m);

    for (int i = 0; i < m; ++i) {
        cin>>g[i].second.first>>g[i].second.second>>g[i].first;
    }

    int cost = 0;
    vector < pair<int,int> > res;

    sort (g.begin(), g.end());
    p.resize (n);
    for (int i=0; i<n; ++i)
        p[i] = i;
    for (int i=0; i<m; ++i) {
        int a = g[i].second.first,  b = g[i].second.second,  l = g[i].first;
        if (dsu_get(a) != dsu_get(b)) {
            cost += l;
            max = std::max(max,l);
            res.push_back (g[i].second);
            dsu_unite (a, b);
        }
    }

    cout<<max<<"\n";
    cout<<res.size()<<"\n";
    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i].first << " "<< res[i].second<<"\n";
    }

    return 0;
}
