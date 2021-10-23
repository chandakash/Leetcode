class Solution {
public:
    void dfs(int oldcolor,int newcolor,int x,int y,vector<vector<int>>&img,vector<vector<int>>&vis,int n,int m)
    {
        if(x<0 or y<0 or x>=n or y>=m)
            return;
        if(vis[x][y] or img[x][y]!=oldcolor)
            return;
        vis[x][y]=1;
        img[x][y]=newcolor;
        dfs(oldcolor,newcolor,x+1,y,img,vis,n,m);
        dfs(oldcolor,newcolor,x-1,y,img,vis,n,m);
        dfs(oldcolor,newcolor,x,y-1,img,vis,n,m);
        dfs(oldcolor,newcolor,x,y+1,img,vis,n,m);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int x=image.size();
        int y=image[0].size();
        vector<vector<int>>vis(x,vector<int>(y,0));
        int oldcolor=image[sr][sc];
        dfs(oldcolor,newColor,sr,sc,image,vis,x,y);
        return image;
    }
};