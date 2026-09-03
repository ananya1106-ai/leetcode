class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low= 0,high=n-1,res=-1;
        //min
        while(low <= high)
        {
            int guess= (low+high)/2;
            if(nums[guess] > nums[n-1])
            low= guess+1;
            else
            {
                res= guess;
                high= guess-1;
            }
        }
        // first half
        int mn =  res;
        low= 0 , high = mn-1;
        while(low <= high)
        {
            int mid= (low+high)/2;
            if(nums[mid] == target)
            return mid;
            else if(nums[mid] > target)
            high = mid-1;
            else
            low= mid+1;
        }

        // second half
        low= mn , high = n-1;
        while(low <= high)
        {
            int mid= (low+high)/2;
            if(nums[mid] == target)
            return mid;
            else if(nums[mid] > target)
            high = mid-1;
            else
            low= mid+1;
        }
        return -1;

    }
};