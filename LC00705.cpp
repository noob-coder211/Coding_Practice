/*
problem: https://leetcode.com/problems/design-hashset/description/
time complexity: o(n)
space complexity: o(n)

*/

class MyHashSet {
public:
    vector<int> h;  
    MyHashSet() {
         h.clear();
    }
    
    void add(int key) {
        cout<<h.size()<<endl;
        h.push_back(key); 
    }
    
    void remove(int key) {
        if(contains(key))
        {
           // h.erase(remove(h.begin(), h.end(), key), h.end());
           h.erase(std::remove(h.begin(), h.end(), key), h.end());
        }   
    }
    
    bool contains(int key) {
        for(int i=0;i<h.size();i++)
        {
            if(h[i] == key)
                return true;
        }
        return false;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */