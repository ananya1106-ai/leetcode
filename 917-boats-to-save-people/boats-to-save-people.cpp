class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int c=0;
        sort(people.begin() , people.end());
        int l=0, r=n-1;

        while(l<r)
        {
            if(people[l] + people[r] > limit)
            {
                c++;
                r--;
            }
            else 
            {
                l++;
                r--;
                c++;
            }
        }
        if(l == r)
           c++;
        return c;
    }
};