class Solution {
public:
    struct cmp{
        bool operator() (pair<int,int> &a , pair<int,int> &b )
        {
            if(a.first != b.first)
            return a.first > b.first; //min
            return a.second > b.second;
        }
    };
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long cost = 0;
        priority_queue <pair<int,int>  , vector<pair<int,int>> , cmp > left;
        priority_queue <pair<int,int>  , vector<pair<int,int>> , cmp > right;
        int l=0,r=n-1;
        for(int i=0;i<candidates && l<=r ;i++)
        {
            left.push({costs[l] , l});
            l++;
        }
        for(int i=0;i<candidates && l<=r ;i++)
        {
            right.push({costs[r] , r});
            r--;
        }
        while(k--)
        {
            if(right.empty() || (!left.empty()) && left.top().first <= right.top().first)
            {
                pair<int,int> p = left.top();
                left.pop();
                cost += p.first;
                if(l<=r)
                {
                    left.push({costs[l],l});
                    l++;
                }
            }
            else
            {
                pair<int,int> p2 = right.top();
                right.pop();
                cost += p2.first;
                 if(l <= r) {
                    right.push({costs[r], r});
                    r--;
                }
            }
        }
        return cost;
    }
};