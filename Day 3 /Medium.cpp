#include <iostream>
#include <unordered_map>
#include <string>

int lengthOfLongestSubstring(const std::string& s) {
    std::unordered_map<char, int> charIndexMap;
    int maxLength = 0;
    int start = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (charIndexMap.find(s[i]) != charIndexMap.end()) {
            start = std::max(start, charIndexMap[s[i]] + 1);
        }
        charIndexMap[s[i]] = i;
        maxLength = std::max(maxLength, i - start + 1);
    }

    return maxLength;
}

int main() {
    std::string input = "abcabcbb";
    std::cout << "Length of longest substring without repeating characters: " 
              << lengthOfLongestSubstring(input) << std::endl;
    return 0;
}
