class Solution {
public:
    void rec(string curr, int open, int close) {
        if (open == 0 && close == 0) {
            res.push_back(curr);
            return;
        }
        
        if (open > 0) rec(curr + "(", open-1, close+1);
        if (close > 0) rec(curr + ")", open, close-1);
    }
    
    vector<string> generateParenthesis(int n) {
        rec("", n, 0);
        return res;
    }
    
private:
    vector<string> res;
};