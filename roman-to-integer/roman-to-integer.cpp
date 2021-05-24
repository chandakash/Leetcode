class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m;
        int n = s.length();
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int sum = m[s[n-1]];
        int j = n-1;
        int i = j-1;
        for(i,j; j>=1; j--,i--){
            if(m[s[j]]>m[s[i]]){
                sum=sum-m[s[i]];
            }
            if(m[s[j]]<=m[s[i]]){
                sum=sum+m[s[i]];
            }
        }
        
        return sum;
    }
};