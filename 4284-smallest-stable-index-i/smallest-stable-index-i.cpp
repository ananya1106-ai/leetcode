class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n= nums.size();
        int great =nums[0];
        
        for(int i=0;i<n;i++)
        {
            int low =nums[i];
            for(int j=0;j<=i;j++)
            {
                great = max(nums[j],great);
            }
            for(int k=i ; k< n;k++)
                {
                    low = min (nums[k], low);
                }
               if(great - low <= k)
                return i;
        }
        return -1;
    }
};