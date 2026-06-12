class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedStrs ="";
        for(int i=0;i<strs.size();i++){
            encodedStrs+= to_string(strs[i].size()) + "#" + strs[i];
        }
        return encodedStrs;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        
        int i=0;
        while( i<s.size()){
            string curSize="";
            while(s[i]!='#'){
            curSize+=s[i];
            i++;
            }
            int decodedStrSize = stoi(curSize);
            string decodedStr = "";
            i++;
            for(int j=i;j<i+decodedStrSize;j++)decodedStr+=s[j];
            i+=decodedStrSize;
            strs.push_back(decodedStr);


        }
        return strs;
        
    }
};
