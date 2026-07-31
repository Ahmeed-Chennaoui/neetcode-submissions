class Solution {
   public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        dfs(0, 0, n, "");
        return res;
    }
    void dfs(int open, int curOpen, int n, string cur) {
        if (cur.size() == 2 * n) {
            res.push_back(cur);
            return;
        }
        if (open < n) dfs(open + 1, curOpen + 1, n, cur + "(");
        if (curOpen > 0) dfs(open, curOpen - 1, n, cur + ")");
    }
};
