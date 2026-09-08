class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_set<int> st;
        unordered_set<int> ans;
        for(int i=0;i<n;i++)
        {
            st.insert(nums1[i]);
        }
        for(int i=0;i<m;i++)
        {
            if(st.find(nums2[i]) != st.end())
            ans.insert(nums2[i]);
        }
       return vector<int>(ans.begin(), ans.end());
    }
};