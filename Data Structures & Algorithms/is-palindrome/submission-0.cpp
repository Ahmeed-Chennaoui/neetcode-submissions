class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string purgedS="";
        for(int i=0;i<n;i++){
            if(isalnum(static_cast<unsigned char>(s[i])))purgedS+=tolower(s[i]);
        }
        cout<<purgedS;
        for(int i=0;i<purgedS.size()/2;i++){
            if(purgedS[i]!=purgedS[purgedS.size()-1-i])return false;
        }
        return true;
    }
};
