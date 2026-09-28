class Solution {
public:
    struct cmp {
        bool operator () (pair <int,int> &a , pair <int,int> &b)
        {
            if(a.first != b.first)
            {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(); //rows
        int m = mat[0].size(); //cols
        vector<int> ans;
        priority_queue <pair<int,int > , vector<pair<int,int >> , cmp> pq;

        for(int i=0;i<n;i++)
        {
            int count = 0;
            for(int j=0;j<m;j++)
            {
                
                if(mat[i][j] == 1)
                count++;
            }
            pq.push({count,i});
        }
        while(!pq.empty())
        {
            if(pq.size() > k)
            pq.pop();
            else
            {
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};