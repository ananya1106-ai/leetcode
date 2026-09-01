class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0,high=n-1;
        int first =-1,last=-1;

        //first occurence
        while(low<=high)
        {
            int guess= (low+high)/2;
            if(nums[guess] == target)
            {
                first= guess;
                high = guess-1;

            }
            else if(nums[guess] < target)
            {
                low= guess+1;
            }
            else{
                high = guess-1;
            }
        }

        // last occurence
        low=0,high=n-1;
        while(low<=high)
        {
            int guess= (low+high)/2;
            if(nums[guess] == target)
            {
                last= guess;
                low = guess+1;

            }
            else if(nums[guess] < target)
            {
                low= guess+1;
            }
            else{
                high = guess-1;
            }
        }
        return {first,last};
    }
};