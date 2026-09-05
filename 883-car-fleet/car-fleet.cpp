class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, double>> cars;

        // position aur time store karo
        for (int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // position descending order
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double lastTime = 0;

        for (auto car : cars) {
            double time = car.second;

            if (time > lastTime) {
                fleets++;
                lastTime = time;
            }
        }

        return fleets;
    }
};