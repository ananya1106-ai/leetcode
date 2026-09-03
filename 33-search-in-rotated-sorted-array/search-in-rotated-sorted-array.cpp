class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n= nums.size();
        int low= 0,high=n-1;
        //min
        while(low <= high)
        {
            int guess= (low+high)/2;

            if(nums[guess] == target)
            return guess;

            //PART 1
            if(nums[guess] > nums[n-1])
            {
                if(nums[guess] < target)
                low= guess+1;
                else
                {
                    if(nums[0] > target)
                    {
                        low= guess+1; //right
                    }
                    else
                    {
                        high= guess-1; //left
                    }
                }
            }
            
            //PART 2
            else
            {
                if(nums[guess] > target)
                high= guess-1;
                else
                {
                    if(nums[n-1] < target)
                    {
                         high= guess-1; //left
                    }
                    else
                    {
                        low= guess+1; //right
                    }
                }
            }
        }
    return -1;
    }
};