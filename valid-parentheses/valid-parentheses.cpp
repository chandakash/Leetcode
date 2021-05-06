class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        
        for(char ch : s)
        {
            if(ch == '(' || ch == '{' || ch == '[')
                S.push(ch);
            else
            {
                if(!S.empty())
                {
                    char x = S.top();
                    S.pop();
                if( (ch == ')' && x == '(') || (ch == '}' && x=='{') || ( ch == ']' && x == '['))
                    continue;
                else
                    return false;    
                }
                else
                    return false;
                
            }
        }
    if(S.empty())
       return true;
    else
        return false;
    }
};