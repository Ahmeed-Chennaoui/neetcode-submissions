class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x=0,y=matrix.size();
        while(x<y){
            int m= x + (y-x)/2;
            if(matrix[m][0]<=target)x=m+1;
            else y=m;
        }
        if (x == 0) return false;
        int l=0,r=matrix[x-1].size()-1;
        while(l<=r){
            int m = l +(r-l)/2;
            if(matrix[x-1][m]==target)return true;
            else if(matrix[x-1][m]>target)r=m-1;
            else l=m+1;
        }
        return false;

    }
};
