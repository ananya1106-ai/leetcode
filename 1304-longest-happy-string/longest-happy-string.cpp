class Solution {
public:
    struct cmp
    {
        bool operator() (pair<int,char> &a, pair<int,char> &b)
        {
            if(a.first != b.first)
            return a.first < b.first; //max heap
            return a.second < b.second;
        }
    };
    string longestDiverseString(int a, int b, int c) {
        priority_queue <pair<int,char>, vector<pair<int,char>> ,cmp> pq;
        vector<char> res;
        int seat = 0;
        if(a>0)
        pq.push({a,'a'});
        if(b>0)
        pq.push({b,'b'});
        if(c>0)
        pq.push({c,'c'});
        
        while(!pq.empty())
        {
            pair<int,char> p= pq.top();
            pq.pop();
            if(seat < 2 || res[seat -1] != p.second || res[seat-2] != p.second)
            {
                res.push_back(p.second);
                seat++;
                if(p.first-1 > 0)
                {
                    pq.push({p.first-1, p.second});
                }
            }
            else
            {
                if(pq.empty())
                break;
                pair<int,char> p2= pq.top();
                pq.pop();
                res.push_back(p2.second);
                seat++;
                if(p2.first-1 > 0)
                {
                    pq.push({p2.first-1, p2.second});
                }
                pq.push(p);
            }
            
        }
        return string(res.begin(), res.end());
    }
};