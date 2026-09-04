class Solution {
public:
    long long fun(vector<int>& piles, int speed)
    {
        long long h=0;
        for(int i=0;i< piles.size();i++)
        {
            h= h+ piles[i] / speed;
            if(piles[i] % speed != 0)
            h++;
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int guard) {
        int n= piles.size();
        int low=1;
        int high=0;
        for(int i=0;i<n;i++)
        {
            high = max(high, piles[i]);
        }
        int res=-1;
        while(low <= high)
        {
            int guess= (low+high)/2;
            long long hour= fun(piles,guess);
            if(hour > guard)
            {
                low= guess+1;
            }
            else
            {
                res= guess;
                high = guess-1;
            }
        }
        return res;
    }
};