class Solution {
public:
    int rows,cols;
    
    void islandsAndTreasure(vector<vector<int>>& grid) {
        rows=grid.size(),cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0)bfs(grid,i,j);
            }
        }
        

    }
    void bfs(vector<vector<int>>& grid,int r,int c){
        vector<vector<bool>> visit(rows,vector<bool>(cols,false));
        queue<vector<int>> q;
        q.push({r,c});
        int depth=0;
        while(!q.empty()){
            
            int size = q.size();
            for(int i=0;i<size;i++){
                int x=q.front()[0],y=q.front()[1];
                q.pop();
                if(x<0||x>=rows||y<0||y>=cols)continue;
                if(visit[x][y])continue;
                visit[x][y]=true;
                if(grid[x][y]>0)grid[x][y]=min(grid[x][y],depth);
                if(grid[x][y]>-1){
                    q.push({x+1,y});
                    q.push({x-1,y});
                    q.push({x,y+1});
                    q.push({x,y-1});
                }
            }
            depth++;
        }


    }
};
