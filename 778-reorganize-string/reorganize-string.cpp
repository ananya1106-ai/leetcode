class Solution {
public:
    struct cmp 
    {
        bool operator() (pair<int,char> &a , pair<int,char> &b)
        {
            if(a.first != b.first)
            return a.first < b.first;
            return a.second < b.second;
        }
    };

    string reorganizeString(string s) {
        int seat =0;
        string res = "";
        int n = s.size();
        // Max heap
        priority_queue <pair<int,char> , vector<pair<int,char>>,cmp> pq;
        unordered_map<char,int> mp;

        // Count frequency
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        // Push frequency + character
        for(auto it=mp.begin() ; it!=mp.end(); it++) 
        {
            pq.push({it->second, it->first});
        }
        while(!pq.empty())
        {
            pair<int,char> p = pq.top();
            pq.pop();
            if(seat == 0 || res[seat-1] != p.second)
            {
                res.push_back(p.second);
                seat++;
                p.first--;
                if(p.first > 0)
                {
                    pq.push(p);
                }
            }
            else
            {
                if(pq.empty())
                {
                    return "";
                }
                else
                {
                    pair<int,char> p2= pq.top();
                    pq.pop();
                    res.push_back(p2.second);
                    seat++;
                    p2.first--;
                    if(p2.first > 0)
                    {
                        pq.push(p2);
                        
                    }
                    pq.push(p);
                }
            }
        }
        return res;
    }
};