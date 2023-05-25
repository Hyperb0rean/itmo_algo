#include <iostream>
#include <queue>
#include <set>
#include <list>
#include <unordered_map>

using namespace std;
const int INF = 1000000;

struct vertex{
    int g;
    int h;
    int id;
};
bool operator< (const vertex &v1, const vertex &v2){return v1.g+v1.h > v2.g+v2.h;}

int heuristic(int x,int y,int dx,int dy){
    return abs(dx-x)+abs(dy-y);
}

int main() {
    int n, m, x, y, dx, dy;
    cin >> n >> m >> x >> y >> dx >> dy;
    string grid[n];
    for (int i = 0; i < n; i++) cin >> grid[i];

    int start = (x - 1) * m + (y - 1);
    int finish = (dx - 1) * m + (dy - 1);
    priority_queue<vertex> queue;
    queue.push({0, heuristic(x,y,dx,dy),start});
    vertex visited[n*m];
    for (int i = 0; i < n*m; i++) visited[i] = {-1, -1};

    while (!queue.empty()){
        auto curr = queue.top();
        queue.pop();
        if (curr.id == finish) break;

        std::unordered_map<char,int> chars = {{'.',1},{'#',INF},{'W',2}};

        multiset<vertex> vertices;
        int i = curr.id / m;
        int j = curr.id % m;
        if (j + 1 < m)
            vertices.insert({chars[grid[i][j + 1]], heuristic(i, j + 1, dx, dy), curr.id + 1});
        if (j - 1 >= 0)
            vertices.insert({chars[grid[i][j - 1]], heuristic(i, j - 1, dx, dy), curr.id - 1});
        if (i + 1 < n)
            vertices.insert({chars[grid[i + 1][j]], heuristic(i + 1, j, dx, dy), curr.id + m});
        if (i - 1 >= 0)
            vertices.insert({chars[grid[i - 1][j]], heuristic(i - 1, j, dx, dy), curr.id - m});

        for (auto next : vertices){
            int new_g = curr.g + next.g >= INF ? INF : curr.g + next.g;
            if (visited[next.id].g == -1 || visited[next.id].g > new_g){
                queue.push({new_g,next.h, next.id});
                visited[next.id].g = new_g;
                visited[next.id].h = next.h;
                visited[next.id].id = curr.id;
            }
        }
    }

    std::unordered_map<int,char> direction_names = {
            {1,'E'}, {m,'S'}, {-1,'W'}, {-m,'N'},
    };

    if (visited[finish].g >= INF) visited[finish].g = -1;
    cout << visited[finish].g << "\n";
    if (visited[finish].g == -1) return 0;
    list<char> result;
    int curr = finish;
    while (curr != start){
        result.push_front(direction_names[(curr - visited[curr].id)]);
        curr = visited[curr].id;
    }
    for (char i : result) cout << i;
    return 0;
}