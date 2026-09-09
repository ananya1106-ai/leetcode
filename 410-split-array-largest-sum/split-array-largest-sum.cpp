class Solution {
public:

bool isPossible(vector<int>& arr, int d, long long maxPages) {
        int students = 1;
        long long pages = 0;

        for (int i = 0; i < arr.size(); i++) {

            if (pages + arr[i] <= maxPages) {
                pages += arr[i];
            }
            else {
                students++;
                pages = arr[i];

                if (students > d)
                    return false;
            }
        }

        return true;
    }
    int splitArray(vector<int>& arr, int k) {
    if (k > arr.size())
            return -1;

        long long low = *max_element(arr.begin(), arr.end());

        long long high = accumulate(arr.begin(), arr.end(), 0LL);

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (isPossible(arr, k, mid)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return (int)low;
    }
};