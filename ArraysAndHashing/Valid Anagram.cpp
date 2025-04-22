#include <vector>
#include <unordered_map>
#include <cstdio>
#include <cstring>
#include <string>

// supports Unicode
bool isAnagramUnicode(std::string s, std::string t) {
    if (s.length() != t.length()) return false;

    std::unordered_map<char, int> count;

    for (char c : s) count[c]++;
    for (char c : t) {
        if (--count[c] < 0) return false;
    }
    return true;
}

bool isAnagram_char(char* s, char* t) {
    int S_LEN = strlen(s);
    int T_LEN = strlen(t);
    if (S_LEN != T_LEN) {
        return false;
    }
    int count[26] = {0};
    for (int i = 0; i < T_LEN; i++) {
        ++count[t[i] - 'a']; // Increment count for each character in t
    }
    for (int j = 0; j < S_LEN; j++) {
        if(count[s[j] - 'a'] > 0) {
            --count[s[j] - 'a'];
        }
        else {
            return false;
        };
    }
    return true;
}

bool isAnagram(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false;
    }
    int count[26] = {0};
    for (int i = 0; i < t.length(); i++) {
        ++count[t[i] - 'a']; // Increment count for each character in t
    }
    for (int j = 0; j < s.length(); j++) {
        if(count[s[j] - 'a'] > 0) {
            --count[s[j] - 'a'];
        }
        else {
            return false;
        };
    }
    return true;
}



int main() {
    char s[] = "anagram";
    char t[] = "nagara";
    isAnagram(s, t);
    printf("%s\n", isAnagram(s, t) ? "true" : "false");
    return 0;
}