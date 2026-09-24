class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long first = nums[0];
        long sec = LONG_MIN;
        long third= LONG_MIN;
        for(int i=1;i<n;i++)
        {
            // Duplicate hai toh ignore
            if(nums[i] == first || nums[i] == sec || nums[i] == third)
                continue;

            if(nums[i] > first)
            {              
                third = sec;
                sec = first;
                first = nums[i];
            }
            else if(nums[i] > sec)
            {
                third = sec;
                sec = nums[i];
            }
            else if(nums[i] > third)
            {
                third = nums[i];
            }
        }
        // Agar 3 distinct numbers nahi mile
        if(third == LONG_MIN)
            return first;
        return third;
    }
};