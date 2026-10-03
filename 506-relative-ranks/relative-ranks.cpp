class Solution {
public:
    struct cmp
    {
        bool operator() (pair<int,int> &a,pair<int,int> &b)
        {
            if(a.first != b.first)
            {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    };
    vector<string> findRelativeRanks(vector<int>& score) {

        int n = score.size();
        priority_queue <pair<int,int>, vector<pair<int,int>> ,cmp > pq;
        vector<string> res(n);
        for(int i=0;i<n;i++)
        {
            pq.push({score[i], i});
        }
        int count = 1;
        while(!pq.empty())
        {
            pair<int,int> p = pq.top();
            int idx = p.second;
            pq.pop();

            if(count == 1)
            res[idx] = "Gold Medal";
            else if(count == 2)
            res[idx] = "Silver Medal";
            else if(count == 3)
            res[idx]= "Bronze Medal";
            else
            res[idx] = to_string(count);
            count++;
        }
        return res;
    }
};