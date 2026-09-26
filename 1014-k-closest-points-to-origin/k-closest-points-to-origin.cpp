class Solution {
public:
    struct cmp
        {
            bool operator()(pair<int,int>&a , pair<int,int>&b)
            {
                if(a.first!=b.first)
                {
                    return a.first<b.first;
                }
                return a.second<b.second;
            }
        };
    int fun(vector<int>arr)
    {
        int n = arr.size();
        long long ans = (1ll*arr[0]*arr[0])+(1ll*arr[1]*arr[1]);
        return (ans);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        int m = points[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        for(int i=0;i<n;i++)
        {
                int dist = fun(points[i]);
                pair<int,int>p = {dist , i};
                if(pq.size()<k)
                {
                    pq.push(p);
                }
                else
                {
                    pq.push(p);
                    pq.pop();
                }
        }
        vector<vector<int>>ans;
        while(!pq.empty())
        {
          int index = pq.top().second;
          pq.pop();
          ans.push_back(points[index]);
        }
       return ans;
    }
};