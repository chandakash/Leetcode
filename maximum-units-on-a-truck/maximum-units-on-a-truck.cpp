class Solution {
public:
    bool static comp(vector<int> a, vector<int> b)
    {
        if(a[1]>b[1])
            return true;
    return false;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int units = 0;
        for(auto x : boxTypes)
        {
            if(truckSize < x[0])
            {
                return units+truckSize*x[1];
            }
            else
            {
                units+=x[0]*x[1];
                truckSize-=x[0];
            }
        }
    return units;
        // int i = 0;
//         int c = boxTypes[0].size();
//         int r = boxTypes.size();
        
//         for(int i = 0; i<r && truckSize>0; i++)
//         {
//             int d = boxTypes[i][0]/truckSize;
//             int r = boxTypes[i][0]%truckSize;
            
//             if(d>=1)
//             {
//                 if(r==0)
//                 {
//                     truckSize-=truckSize;
//                     units+=boxTypes[i][1]*truckSize;
//                 }
//                 else
//                 {
//                     truckSize-=r;
//                     units+=boxTypes[i][1]*r;
//                 }
//             }
//             else
//             {
//                 truckSize-=r;
//                 units+=boxTypes[i][1]*r;
//             } 
//         }
                     
//         return units;  
    }
};