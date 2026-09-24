class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int m = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int r = nums[i];
            int sum = 0;
            if(nums[i] < 10 && nums[i] == i)
            {
                m = min(i,m);
            }
            else
            {
                while(r>0)
                {
                    int d = r%10;
                    sum += d;
                    r = r/10;
                }
            }
            if(sum == i)
            {
                m = min(i,m);
            }
        }
        if(m == INT_MAX)
            return -1;
        return m;
    }
};