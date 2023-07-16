class Trie {
public:

    struct TrieNode
    {
        struct TrieNode * children[26];
        bool isend;
    };

    struct TrieNode* getNode(){
         struct TrieNode* tnode = new TrieNode;
        tnode->isend = false;
        for(int i=0;i<26;i++)
        {
            tnode->children[i] = NULL;
        } 
        return tnode;
    }

    struct TrieNode* head;

    Trie() {
        head = getNode();
    }
    
    void insert(string word) {
        TrieNode* temp = head;
        for(char c : word)
        {
            int index = c - 'a';
            if(temp->children[index] == NULL)
                temp->children[index] = getNode();
            temp = temp->children[index];
        }
        temp->isend = true; 
    }
    
    bool search(string word) {

        TrieNode * temp = head;

        for(char c: word)
        {
            int index = c - 'a';
            if(temp->children[index] == NULL)
                return false;
            temp = temp->children[index];
        }
        return temp->isend;  
    }
    
    bool startsWith(string prefix) {
        
        TrieNode * temp = head;

        for(char c: prefix)
        {
            int index = c - 'a';
            if(temp->children[index] == NULL)
                return false;
            temp = temp->children[index];
        }
        return true;  

        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */