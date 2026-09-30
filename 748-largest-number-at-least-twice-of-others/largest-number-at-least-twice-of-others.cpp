class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int m = nums[0];
        int count = 0;
        int idx = 0;

        for(int i=1;i<n;i++)
        {
            if(m < nums[i])
            {
                m = nums[i];
                idx = i;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]*2 > m && nums[i] != m)
            count++;
            else
            continue;
        }
        if(count > 0)
        return -1;
        return idx;
    }
};