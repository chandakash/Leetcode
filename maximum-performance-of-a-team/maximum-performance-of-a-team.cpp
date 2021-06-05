class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> p;
        for(int i=0;i<speed.size();i++)
        {
            p.push_back({efficiency[i],speed[i]});
        }
        
        sort(p.rbegin(),p.rend());// to sort in decreasing order acc to efficiency.
        
        long speedSum = 0;
        long res = 0;
        
        priority_queue<int, vector<int>, greater<int>> minh;
        
        for(auto it : p)
        {
            speedSum += it.second;
            minh.push(it.second);
            if(minh.size()>k)
            {
                speedSum -= minh.top();
                minh.pop();
            }
        res = max(res, speedSum*it.first);
        }
    return res%(int)(1e9+7);
    }
};