class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n = nums.size();
        double sum = 0;
        int count = 0;
        double red = 0;
        priority_queue <double> pq;
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
            sum+= nums[i];
        }
        while(red < sum / 2.0)
        {
            double p = pq.top();
            pq.pop();
            double t = p / 2.0;
            red += t;
            count++;
            pq.push(t);
        }
        return count;
    }
};