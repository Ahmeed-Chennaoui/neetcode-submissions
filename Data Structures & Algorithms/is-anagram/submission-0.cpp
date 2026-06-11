class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> occurrences;
        for(int i=0;i<s.size();i++)occurrences[s[i]]++;
        for(int j=0;j<t.size();j++){
            occurrences[t[j]]--;
            if(occurrences[t[j]]==0){
                occurrences.erase(t[j]);
            }
        }
        return occurrences.size()==0;
    }
};
