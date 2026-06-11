class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groupedAnagrams;
        unordered_map<string,vector<string>> anagramsMap;
        for(int i=0;i<strs.size();i++){
            string curStr= strs[i];
            vector<int> c(26);
            for(int j=0;j<curStr.size();j++){
                c[curStr[j]-'a']++;
            }
            string codedStr=to_string(c[0]);
            for(int i=1;i<26;i++){
                codedStr+= ","+to_string(c[i]);
            }
            anagramsMap[codedStr].push_back(strs[i]);
        }
        for(auto anagramPair : anagramsMap){
            groupedAnagrams.push_back(anagramPair.second);
        }
        return groupedAnagrams;
    }
};
