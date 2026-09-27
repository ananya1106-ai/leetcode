class Solution {
public:
    class Node {
      public:
    int value;
    int row;
    int col;
    Node(int v, int i, int j)
    {
        value=v;
        row=i;
        col=j;
    }
};
struct cmp {
    bool operator()(const Node &a, const Node &b) {
        return a.value > b.value;   // min heap
    }
};
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        priority_queue<Node, vector<Node>, cmp> pq;
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> res;
        for(int j=0;j<n;j++)
        {
            pq.push({nums1[j]+nums2[0], j,0});
        }
        while(!pq.empty() && k>0)
        {
            Node n = pq.top();
            pq.pop();
            int v = n.value;
            int row = n.row;
            int col = n.col;
            res.push_back({nums1[row], nums2[col]});
            k--;
            if(col+1 < m)
            {
                pq.push({nums1[row] + nums2[col+1], row, col+1});
            }
        }
        return res;
    }
};