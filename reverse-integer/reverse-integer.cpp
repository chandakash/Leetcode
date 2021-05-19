class Solution {
public:
    int reverse(int x) {
        int r = 0;
        long long int num=0;
        while(x!=0)
        {
            r = x%10;
            num = num*10+r;
            x=x/10;
        }
        if(num<INT_MIN || num>INT_MAX)
            return 0;
        else 
            return num;
    }
};