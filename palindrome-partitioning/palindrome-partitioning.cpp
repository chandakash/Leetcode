class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        
        helper(s,0,res,path);
        return res;
    }
    
    void helper(string s, int idx, vector<vector<string>> &res, vector<string> &path)
    {
        if(idx == s.size())
        {
            res.push_back(path);
            return;
        }
        
        for(int i=idx; i<s.size();i++)
        {
            if(isPalindrome(s,idx,i))
            {
                path.push_back(s.substr(idx,i-idx+1));
                helper(s,i+1,res,path);
                path.pop_back();
            }
        }
            
    }
    
    bool isPalindrome(string s, int start, int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
                return false;
        }
    return true;
    }
};