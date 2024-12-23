#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string makeLargestSpecial(std::string s) {
    std::vector<std::string> special;
    int count = 0, last = 0;

    for (int i = 0; i < s.size(); ++i) {
        count += (s[i] == '1') ? 1 : -1;
        if (count == 0) {
            special.push_back("1" + makeLargestSpecial(s.substr(last + 1, i - last - 1)) + "0");
            last = i + 1;
        }
    }

    std::sort(special.rbegin(), special.rend());
    std::string result;
    for (const auto& str : special) {
        result += str;
    }
    return result;
}

int main() {
    std::string s = "11011000";
    std::string result = makeLargestSpecial(s);
    std::cout << result << std::endl; // Output: "11100100"
    return 0;
}
