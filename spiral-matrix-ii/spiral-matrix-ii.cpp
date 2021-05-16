class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int l=0,r=n-1;// left and right
        int t=0,b=n-1;// top and down
        int d = 0 ;// direction
        vector<vector<int>> res(n,vector<int>(n));
        int num = 1;
        while(l<=r && t<=b)
        {
            if(d==0)
            {
                for(int i=l;i<=r;i++)
                {
                    res[t][i]=num;
                    num++;
                }
                d=1;
                t++;
            }
            else if(d==1)
            {
                for(int i=t;i<=b;i++)
                {
                    res[i][r]=num;
                    num++;
                }
            d=2;r--;
            }
            else if(d==2)
            {
                for(int i=r;i>=l;i--)
                {
                    res[b][i]=num;
                    num++;
                }
            d=3;b--;
            }
            else if(d==3)
            {
                for(int i=b;i>=t;i--)
                {
                    res[i][l]=num;
                    num++;
                }
            d=0;l++;
            }
        }
    return res;
    }
};