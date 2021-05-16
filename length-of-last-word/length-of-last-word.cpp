class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int len=0;
        int count =0;
        int n = s.size();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ')
                len= (++count);
            else
                count=0;
        }
        
    return len;
    }
};