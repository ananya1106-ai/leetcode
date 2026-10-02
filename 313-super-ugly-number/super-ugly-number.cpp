class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(1);
        int ans = 0;
        while(n--)
        {
            ans = pq.top();
            pq.pop();
            for(int i : primes)
            {
                if(ans <= INT_MAX/i)
                {
                    pq.push(ans * i);
                }
                if (ans % i == 0)
                break;
            }
        }
        return ans;
    }
};