#include<unordered_set>
#include<string>


// Solution 1: use unordered_set. Although the time complexity is O(n) and the space complexity is O(n).
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        size_t LEFT = 0;
        size_t RIGHT = 0;
        size_t MAX_LEN = 0;
        std::unordered_set<char> charSet;
        while (RIGHT < s.size()) {
            if (charSet.count(s[RIGHT]) == 0) {
                charSet.insert(s[RIGHT]);
                ++RIGHT;
                MAX_LEN = std::max(RIGHT - LEFT, MAX_LEN);
            }
            else {
                charSet.erase(s[LEFT]);
                ++LEFT;
            }
        }
        return MAX_LEN;
    }
};

// Solution 2: use fixed size array. Although the time complexity is O(n) and the space complexity is O(n).
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int index[128] = {0};  // ASCII 共 128 個字元，記錄每個字元「最後一次出現的位置 +1」
        int MAX_LEN = 0;
        int LEFT = 0;

        for (int RIGHT = 0; RIGHT < s.size(); ++RIGHT) {
            char current = s[RIGHT];
            LEFT = std::max(LEFT, index[current]); // 移動左指標（滑動窗口開始點）
            MAX_LEN = std::max(MAX_LEN, RIGHT - LEFT + 1);
            index[current] = RIGHT + 1;       // 記錄該字元出現的位置 +1（避免 0 與初始化混淆）
        }

        return MAX_LEN;
    }
};