

// bruteforce approach.
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
//         int n = gas.size();
        
//         for(int i=0;i<n;i++)
//         {
//             int tank = 0, steps = 0, j = i;
//             while(steps<n)
//             {
//                 tank += (gas[j%n] - cost[j%n]);
//                 if(tank<0)
//                     break;
//                 j++;
//                 steps++;
//             }
//         if(steps==n && tank>=0)
//         return i;
//         }
//    return -1;
//     }
// };

// best approach O(n)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int tank =0;
        int total=0;
        int start_idx=0;
        
        for(int i=0;i<n;i++)
        {
            total+=gas[i]-cost[i];
            tank +=gas[i]-cost[i]; 
            
            if(tank<0)
            {
                start_idx = i+1;
                tank=0;
            }
        }
   return (total>=0) ? start_idx : -1;
    }
};

// wrong approach
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
//         int n = gas.size();
//         vector<int> greed(n);
//         for(int i=0;i<gas.size();i++)
//         {
//             greed[i] = gas[i]/cost[i];
//         }
        
//         int min_idx = 0;
//         int max_greed=greed[0];
//         for(int i=1;i<n;i++)
//         {
//             if(max_greed<greed[i])
//             {
//                 max_greed = greed[i];
//                 min_idx = i;
//             }
//         }
        
//         int tank=0;
//         for(int i=min_idx;i<n;i++)
//         {
//             tank += (gas[i]-cost[i]);
//         }
//         for(int i=0;i<min_idx;i++)
//         {
//             tank += (gas[i]-cost[i]);
//         }
        
//     if(tank>=0)
//         return min_idx;
//     else
//         return -1;
//     }
// };