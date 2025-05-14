#include<string>
#include<algorithm>
#include<cctype>
#include<iostream>
#include<unordered_map>


class Solution {
    public:
        bool isPalindrome(std::string s) {
            int left = 0, right = s.size() - 1;
        while (left < right) {
            // 找到左邊第一個是字母/數字的字元
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[left]))) ++left;
            // 找到右邊第一個是字母/數字的字元
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[right]))) --right;

            // 比較時忽略大小寫
            if (std::tolower(static_cast<unsigned char>(s[left])) != 
                std::tolower(static_cast<unsigned char>(s[right]))) {
                return false;
            }

            ++left;
            --right;
        }
        return true;
    };
};

