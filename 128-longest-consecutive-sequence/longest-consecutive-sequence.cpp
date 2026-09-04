class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count=1,ans=1;
        int n= nums.size();
        if(nums.empty())
        return 0;
        for(int i=1;i<n;i++)
        {
            if(nums[i] == nums[i-1]+1)
            count++;
            else if(nums[i] == nums[i-1])
{
    continue;
}
            else{
            count=1;
        }
        ans =max(count,ans);
        }
        return ans;
    }
};