class Solution {
public:
    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int sum=0,coeff=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            coeff+=(i+1)*arr[i];
        }
        // cout<<coeff<<" "<<sum<<"\n";
        int ans=coeff;
        for(int i=0;i<arr.size();i++){
            ans=max(ans,coeff=coeff-sum);
            
            sum-=arr[i];
        }
        return ans;
    }
};