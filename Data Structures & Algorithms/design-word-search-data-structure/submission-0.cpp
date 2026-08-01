class TrieNode {
   public:
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};
class WordDictionary {
   public:
    TrieNode* root;
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isEnd = true;
    }

    bool search(string word) { return dfs(word, 0, root); }

    bool dfs(string word, int i, TrieNode* cur) {
        if (i == word.size()) return cur->isEnd;
        if (word[i] != '.' && cur->children.find(word[i]) == cur->children.end()) return false;
        if (word[i] != '.') return dfs(word, i + 1, cur->children[word[i]]);
        bool res = false;
        for (const auto& child : cur->children) {
            res = res || dfs(word, i + 1, child.second);
        }
        return res;
    }
};
