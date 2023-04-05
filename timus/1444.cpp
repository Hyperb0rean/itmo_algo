#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct point{
    int x,y,i;
};


struct {
    bool operator()(const point& a, const point& b) const {
        return atan2(b.y, b.x) ==  atan2(a.y , a.x)
        ? a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y
        :  atan2(a.y , a.x) < atan2(b.y, b.x);
    }
} myComp;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,x0,y0;
    std::vector<point> v;
    cin>>n;
    cin >> x0>>y0;
    for (int i = 1; i < n; ++i) {
        int x,y;
        cin>>x>>y;
        v.push_back({x-x0,y-y0,i+1});;
    }
    sort(v.begin(),v.end(),myComp);
    int start = 0;
    for(int i = 0;i< n-2;++i){
        if (v[i].x*v[i+1].y - v[i].y*v[i+1].x<=0
            && v[i].x*v[i+1].x + v[i].y*v[i+1].y<0) {
            start=i;
            break;
        }
    }

    cout<<n<<"\n"<<1<<"\n";
    for(int i = 0; i < n-1; i++) cout << (v[(start+i)%(n-1)].i) << "\n";

    return 0;
}
