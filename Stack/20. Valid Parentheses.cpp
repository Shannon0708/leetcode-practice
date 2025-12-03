#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::string open_bracket = "([{";
        std::string close_bracket = ")]}";
        
        std::stack<char> stk;

        for (auto c : s) {
            if(open_bracket.find(c) != std::string::npos) {
                stk.push(c);
            } 
            else {
                if(stk.empty() || stk.top() != open_bracket[close_bracket.find(c)]) {
                    return false;
                }
                else {
                    stk.pop();
                }
            }
        }
        return stk.empty();
    }
};