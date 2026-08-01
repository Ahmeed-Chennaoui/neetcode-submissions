class TrieNode {
   public:
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};
class PrefixTree {
   public:
    TrieNode* root;
    PrefixTree() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        TrieNode* cur = root;
        for(auto c : word){
            if(cur->children.find(c)==cur->children.end())return false;
            cur=cur->children[c];
        }
        return cur->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(auto c : prefix){
            if(cur->children.find(c)==cur->children.end())return false;
            cur=cur->children[c];
        }
        return true;
    }
};
