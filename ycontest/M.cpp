#include <unordered_map>
#include <utility>
#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>


const int INF = 1000000000;



struct Node
{
    uint g,h;
    std::pair<int,int> coordinates;
    std::string result;

    explicit Node(std::pair<int,int> coord,std::string r);
};

Node::Node(std::pair<int,int> c, std::string r)
{
    coordinates = c;
    g = h = 0;
    result = std::move(r);
}



std::vector<std::pair<int,int>> direction = {
        { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 },
};

std::vector<char> direction_names = {
        'E', 'S', 'W', 'N',
};

auto cmp = [](Node* a, Node* b) { return a->g==b->g ? a->h<=b->h : a->g<=b->g; };
auto cmp2 = [](Node* a, Node* b) { return a->g+a->h<=b->g +b->h; };


struct hashFunction
{
    size_t operator()(const std::pair<int,int> &x) const
    {
        return x.first ^ x.second;
    }
};

void AStar(std::pair<int,int> start, std::pair<int,int> finish, std::vector<std::vector<int>>& table, int n, int m, std::string* result, int* sum){
    Node* current = nullptr;
    std::set<Node*, decltype(cmp2)> open(cmp2);
    //auto comp = [](std::pair<int,int> a, std::pair<int,int> b) { return a.first==b.first ? a.second<b.second : a.first<b.first; };
    std::unordered_set<std::pair<int,int>,hashFunction> closed;
    std::unordered_map<std::pair<int,int>,Node*,hashFunction> open_lookup;
    open.insert(new Node(start,""));
    open_lookup.insert(std::make_pair(start,*open.begin()));
    while(!open.empty())
    {
        auto current_it = open.begin();
        current = *current_it;
        if (current->coordinates == finish) {
            *sum = current->g;
            *result= current->result;
            break;
        }
        closed.insert(current->coordinates);
        open.erase(current_it);
        open_lookup.erase(current->coordinates);


        for (int i = 0; i < 4; ++i) {
            std::pair<int,int> next = std::make_pair(current->coordinates.first + direction[i].first,current->coordinates.second + direction[i].second);
            if(next.first < 0 || next.second < 0 || next.first >= n || next.second >= m || closed.find(next) != closed.end()) continue ;

            Node *successor = open_lookup.find(next) != open_lookup.end()
                    ? open_lookup.find(next)->second : nullptr;
            if (successor == nullptr) {
                successor = new Node(next,current->result +direction_names[i]);
                successor->g = current->g + table[next.first][next.second] >= INF ? INF :current->g + table[next.first][next.second];
                successor->h = 0*(abs((finish.first - successor->coordinates.first))+
                                abs((finish.second - successor->coordinates.second)));
            }
            else if (current->g + table[next.first][next.second] < successor->g) {
                open.erase(successor);
                successor->result = current->result +  direction_names[i];
                successor->g = current->g + table[next.first][next.second] >= INF ? INF :current->g + table[next.first][next.second];
            }
            open.insert(successor);
        }
        delete current;
    }
}


int main() {

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);


    int n,m;
    int x,y,dx,dy;
    std::cin>>n>>m>>x>>y>>dx>>dy;
    std::vector<std::vector<int>> table(n,std::vector<int> (m,0));


    std::unordered_map<char,int> chars = {{'.',1},{'#',INF},{'W',2}};

    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin>>s;
        for (int j = 0; j < m; ++j) {
            table[i][j] = chars[s[j]];
        }
    }

    int sum =0;
    std::string result;
    AStar({--x,--y},{--dx,--dy}, table, n,m, &result, &sum);

    if(sum >= INF) std::cout<<-1;
    else std::cout<<sum<<"\n"<<result;
    return 0;
}

