class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groupedAnagrams;
        unordered_map<string,vector<string>> anagramsMap;
        for(int i=0;i<strs.size();i++){
            string curStr= strs[i];
            sort(curStr.begin(),curStr.end());
            anagramsMap[curStr].push_back(strs[i]);
        }
        for(auto anagramPair : anagramsMap){
            groupedAnagrams.push_back(anagramPair.second);
        }
        return groupedAnagrams;
    }
};
