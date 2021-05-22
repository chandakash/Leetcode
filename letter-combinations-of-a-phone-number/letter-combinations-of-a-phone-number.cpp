class Solution {
     vector<string> m;
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        if(digits.size()==0)
            return res;
        
        m = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s;
        dfs(s,digits,0,res);
    return res;
    }
    
    void dfs(string &s, string digits, int pos, vector<string> &res)
    {
        if(pos == digits.size())
        {
            res.push_back(s);
            return;
        }
        
        for(char ch : m[digits[pos]-'0'])
        {
            s+=ch;
            dfs(s,digits,pos+1,res);
            s.pop_back();
        }
    }
};