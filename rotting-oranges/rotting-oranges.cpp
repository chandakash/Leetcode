class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int fresh = 0, time = 0;
        queue<pair<int,int>> res;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==2)
                    res.push({i,j});
                else if(grid[i][j]==1)
                        fresh++;
            }
        }
        
        while(!res.empty())
        {
            int num = res.size();
            for(int i=0;i<num;i++)
            {
                int x = res.front().first, y = res.front().second;
                res.pop();
                
                if(x>0 && grid[x-1][y]==1){ grid[x-1][y] = 2; fresh--; res.push({x-1,y});}
                if(y>0 && grid[x][y-1]==1){ grid[x][y-1] = 2; fresh--; res.push({x,y-1});}
                if(x<r-1 && grid[x+1][y]==1){ grid[x+1][y] = 2; fresh--; res.push({x+1,y});}
                if(y<c-1 && grid[x][y+1]==1){ grid[x][y+1] = 2; fresh--; res.push({x,y+1});}
            }
            if(!res.empty()) time++;
        }
    return fresh==0 ? time : -1;
    }
};