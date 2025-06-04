#include<vector>
#include<unordered_map>
#include<cstdio>

// Time Complexity: O(n), Space Complexity: O(1).

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int MAX_PROFIT = 0;
        int MIN = 10000;
        for( int i = 0 ; i < prices.size() ; i++ ) {
            if (prices[i] < MIN) {
                MIN = prices[i];
            }
            else if( MAX_PROFIT < (prices[i] - MIN)) {
                MAX_PROFIT = prices[i] - MIN;
            }
        }
        return MAX_PROFIT;
    }
};