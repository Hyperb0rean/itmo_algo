#include <iostream>



using namespace std;

class node{
public:
    node* prev;
    node* next;
    int val;
    node(node* p, node* n, int v){
        prev = p;
        next =n;
        val = v;
    }
};

class mylovelylist{
public:
    node* head;
    node* back;
    node* middle;
    int size = 0;
    void push_back(int val){
        node* new_node = new node(back, nullptr,val);
        if(back) back->next = new_node;
        else {
            head = new_node;
            middle = head;
        }
        if(size%2==0 && middle->next) middle = middle->next;
        back = new_node;
        size++;
    }
    void pop_front(){
        if(!head || !head->next) {
            head = nullptr;
            middle = nullptr;
            back = nullptr;
            size =0;
        }
        else{
            if(size%2==0 && middle->next) middle = middle->next;
            if(head->next) {
                head->next->prev = nullptr;
            }
            head = head->next;
            size--;
        }
    }
    void push_middle(int val){
        if(!middle){
            middle = new node(back, head,val);
            back = middle;
            head = middle;

        } else{
            node* new_node = new node(middle->prev, middle->next,val);
            if(middle->next) middle->next->prev = new_node;
            else back = new_node;
            middle->next = new_node;
            if(size%2==0 && middle->next) middle = middle->next;
        }
        size++;
    }
    mylovelylist(){
        back= nullptr;
        head= nullptr;
        middle = nullptr;
        size = 0;
    }
};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    mylovelylist list;


    int n;
    cin>>n;
    for (int i = 0; i <= n; ++i) {
       string s;
       getline(cin,s);
       if(s[0] == '-'){
           cout<<list.head->val<<"\n";
           list.pop_front();
       }
       if(s[0] == '+') list.push_back(stoi(s.substr(2,s.length()-2)));
       if(s[0] == '*') list.push_middle(stoi(s.substr(2,s.length()-2)));

    }

    return 0;
}




//8
//* 1
//-
//* 2
//* 3
//* 4
//-
//-
//-
