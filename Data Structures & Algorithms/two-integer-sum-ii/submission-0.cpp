class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;
        while(l<r){
            int cur= numbers[l]+numbers[r];
            if (target<cur)r--;
            else if (target>cur)l++;
            else return {l+1,r+1};
        }
        return {};
    }
};
