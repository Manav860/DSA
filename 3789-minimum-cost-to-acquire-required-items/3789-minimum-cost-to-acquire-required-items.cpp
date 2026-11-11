
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long maxi = max(need1, need2);
        long long mini = min(need1, need2);
        long long min1 = maxi * costBoth;
        long long mini2 = 1LL * need1 * cost1 + 1LL * need2 * cost2;
        long long mini3 = mini * costBoth + 1LL * (need1 - mini) * cost1 +1LL * (need2 - mini) * cost2;
        return min({min1, mini2, mini3});
    }
};
