#include <iostream>
#include <map>
#include <vector>


using namespace std;

std::map<int,int> blocks_start_end;
std::multimap<int,int> blocks_size_start;

void remove_by_size(const map<int, int>::iterator& it){
    auto it_sizes = blocks_size_start.find(it->second-it->first);
    while (it_sizes->second != it->first) it_sizes++;
    blocks_size_start.erase(it_sizes);
    blocks_start_end.erase(it);
}
void remove(const multimap<int, int>::iterator& it){
    blocks_start_end.erase(it->second);
    blocks_size_start.erase(it);
}

void insert(const pair<int, int>& pair){
    blocks_start_end.insert(pair);
    blocks_size_start.insert({pair.second-pair.first, pair.first});
}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    n++;
    std::vector<pair<int,int>> query_table(m,{0,0});
    insert({1,n});
    for (int i = 0; i < m; ++i) {
        int query;
        cin>>query;
        if(query<0){
            query*=-1;
            query--;
            if(query_table[query].first<0) continue;
            int old_start = query_table[query].first;
            int old_size = query_table[query].second;
            int old_end = old_start + old_size;


            auto after_block = blocks_start_end.lower_bound(old_end);
            auto before_block = (after_block==blocks_start_end.begin()) ? blocks_start_end.end() : prev(after_block);

            if(after_block!=blocks_start_end.end() && after_block->first ==old_end){
                if(before_block!=blocks_start_end.end() && before_block->second ==old_start){
                    int new_start = before_block->first;
                    int new_end = after_block->second;
                    remove_by_size(before_block);
                    remove_by_size(after_block);
                    insert({new_start,new_end});
                } else{
                    int new_end = after_block->second;
                    remove_by_size(after_block);
                    insert({old_start,new_end});
                }
            }
            else{
                if(before_block!=blocks_start_end.end() && before_block->second ==old_start){
                    int new_start = before_block->first;
                    remove_by_size(before_block);
                    insert({new_start,old_end});
                } else insert({old_start,old_end});
            }



        } else{
            auto it = blocks_size_start.lower_bound(query);
            if(it == blocks_size_start.end()){
                query_table[i] = make_pair(-1,query);
                cout<<-1<<"\n";
            }
            else {
                cout<<it->second<<"\n";
                int new_start = it->second + query;
                int new_end =  it->first + it->second;
                query_table[i] = make_pair(it->second, query);
                remove(it);
                insert({new_start,new_end});
            }
        }
    }


    return 0;
}
//   -------///-------- ////// ----- --------- ///////////