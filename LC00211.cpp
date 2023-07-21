class WordDictionary {
public:
    struct trieNode
    {
        trieNode * value[26];
        bool isend;
    };

    struct trieNode * getnode()
    {
        trieNode * newnode  = new trieNode;
        for(int i=0;i<26;i++)
        {
            newnode->value[i] = NULL;
        }
        newnode->isend = false;
        return newnode;
    }

    trieNode * node;
    WordDictionary() {
        node  = getnode();
    }
    
    void addWord(string word) {
        trieNode * cur = node;
        for(char c: word)
        {
            int i = c - 'a';
            
            if(cur->value[i] != NULL)
            {
                cur = cur->value[i];
            }
            else
            {
                cur->value[i] = getnode();
            }
        }
        cur->isend = true;
    }
    
    bool search(string word) {
        trieNode * cur = node;
        vector<trieNode * > pos;
        pos.push_back(node);
        for(char c : word)
        {

            if(c!= '.')
            {   
                int flag = 0;
                int index = c - 'a';

                for(int i=0;i<pos.size();i++)
                {
                    trieNode * level = pos[i];

                    if(level->value[index] != NULL)
                        {
                            level = level->value[index];
                            pos[i] = level;
                            flag = 1;
                        }
                    else
                        {
                            pos.erase(pos.begin() + i);
                            i--;
                        }
                }
                if(flag == 0)
                    return false;
            }
            else
            {
                for(int i=0;i<pos.size();i++){
                    cur = pos[i];
                    for(int i=0;i<26;i++){
                        if(cur->value[i]!=NULL)
                        {
                            pos.push_back(cur);
                        }
                    }
                    pos.erase(pos.begin()+i);
                    i--;
                }

            }

        }
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */