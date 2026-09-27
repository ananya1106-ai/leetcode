class Solution {
public:
    struct cmp
    {
        bool operator() (pair <int,char> &a, pair <int,char> &b)
        {
            if(a.first != b.first)
            {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    };
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        int sum =0;
        priority_queue <pair<int,char>, vector<pair<int,char>> ,cmp > pq;
        for(int i=0;i<n;i++)
        {
            pq.push({piles[i] , i});
        }
        while(!pq.empty() && k>0)
        {
            int t= pq.top().first;
            int child= pq.top().second;
            pq.pop();
            t = t-floor(t / 2);
            pq.push({t , child });
            k--;
        }
        while(!pq.empty())
        {
            sum += pq.top().first;
            pq.pop();
        }
        return sum;
    }
};