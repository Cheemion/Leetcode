#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using std::vector;
using std::unordered_map;
using std::list;
struct Node {
    Node(int k = 0, int v = 0) : key(k), val(v) {}
    int key;
    int val;
};

class Solution {
private:
    std::list<Node> L;
    std::unordered_map<int,std::list<Node>::iterator> H;
    int cap;
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LRU(vector<vector<int>>& operators, int k) {
        cap = k;
        vector<int> result;
        for(auto& input: operators){
            if(input[0] == 1) { //set
                set(input[1], input[2]);
            } else { // get
                result.push_back(get(input[1]));
            }
        }
        return result;
    }

    int remove(std::list<Node>::iterator& ite) {
        int key = ite->key;
        int val = ite->val;
        L.erase(ite);
        H.erase(key);
        return val;
    }
        
    void add(int key, int val) {
        L.push_front(Node(key,val));
        H[key] = L.begin();
        if(L.size() > cap) {
            auto last = L.end();
            --last;
            remove(last);
        }
    }

    void set(int x, int y) {
       auto ite = H.find(x);
       if(ite != H.end()) {
           remove(ite->second);
       } 
       add(x, y);
    }

    int get (int x) {
        int val = 0;
        auto ite = H.find(x);
        if(ite != H.end()) {
            val = remove(ite->second);
            add(x, val);
            return val;
        }
        return -1;
    }
};

int main(int, char**) {
    list<int> ints;
    ints.push_back(1);
    ints.push_back(2);



    std::unordered_map<int, std::string> map;
    map.insert(std::pair<int, std::string>(000, "student zero"));
    map.insert(std::pair<int, std::string>(001, "student one"));
    map.insert(std::pair<int, std::string>(000, "student zero again"));
    map[123] = "123";
    map[123] = "1234";
    std::cout << map.begin()->first << std::endl;
    std::cout << map.begin()->second << std::endl;
    std::cout << "Hello, world!\n";
    return 0;
}