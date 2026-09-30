class Solution {
public:
    void sub(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &res)
{
    if(i== nums.size())
    {
        res.push_back({ans});
        return;
    }

    ans.push_back(nums[i]);
    sub(nums,ans,i+1,res);
    ans.pop_back();
    sub(nums,ans,i+1,res);
}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        sub(nums,ans,0,res);
        return res;
    }
};