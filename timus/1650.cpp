#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct City
{
    long long money;
    int days;
    std::string name;
} cities[100000];

struct Person
{
    std::string name;
    long long money;
    City* location;
} persons[10000];

std::unordered_map<std::string, Person*> personMap;
std::map<std::string, City*> cityMap;
std::set<std::pair<long long, City*>,std::greater<>> cityHeap;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, c = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::string name, location; long long money;
        std::cin >> name >> location >> money;
        personMap[name] = &persons[i];
        if(!cityMap[location]) cityMap[location] = &cities[c++];
        persons[i].location = cityMap[location];
        persons[i].money = money;
        cityMap[location]->name = location;
        cityMap[location]->money += money;
    }
    for(const auto& i : cityMap)
        cityHeap.insert( { i.second->money, i.second } );
    std::cin >> m >> k;
    int prevday = 0, day;
    std::string name, place;
    while(true)
    {
        bool finished = (!(std::cin >> day >> name >> place));
        finished = (name == "finish");
        if(finished) day = m;
        if(day != prevday)
        {
            auto it2 = cityHeap.begin();
            auto it = it2++;
            if(it2 == cityHeap.end() || it->first > it2->first)
                it->second->days += day-prevday;
        }
        if(finished) break;
        if(!cityMap[place])
        {
            cityMap[place] = &cities[c++];
            cityMap[place]->name = place;
        }

        cityHeap.erase( { personMap[name]->location->money, personMap[name]->location } );
        personMap[name]->location->money -= personMap[name]->money;
        cityHeap.insert( { personMap[name]->location->money, personMap[name]->location } );
        cityHeap.erase( { cityMap[place]->money, cityMap[place] } );
        cityMap[place]->money += personMap[name]->money;
        cityHeap.insert( { cityMap[place]->money, cityMap[place] } );
        personMap[name]->location = cityMap[place];
        prevday = day;
    }
    std::vector<std::pair<std::string, int>> output;
    for(auto& item : cityHeap)
        if(item.second->days)
            output.emplace_back(item.second->name, item.second->days);
    std::sort(output.begin(), output.end());
    for(auto& item : output) std::cout << item.first << " " << item.second << "\n";

    return 0;
}
