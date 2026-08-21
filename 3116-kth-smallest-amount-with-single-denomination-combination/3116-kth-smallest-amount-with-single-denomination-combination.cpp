class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
    int n = coins.size();
    
    auto countMultiples = [&](long long M) -> long long {
        long long count = 0;
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long current_lcm = 1;
            int bits = 0;
            bool overflow = false;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    bits++;
                    current_lcm = std::lcm(current_lcm, (long long)coins[i]);
                    if (current_lcm > M) {
                        overflow = true;
                        break;
                    }
                }
            }

            if (!overflow) {
                count += (bits % 2 == 1 ? 1 : -1) * (M / current_lcm);
            }
        }
        return count;
    };

    long long low = 1, high = (long long)*min_element(coins.begin(), coins.end()) * k;
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (countMultiples(mid) >= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
};