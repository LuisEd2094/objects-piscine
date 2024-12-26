#ifndef AUX_HPP
#   define AUX_HPP

#include <vector>

inline std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::string temp;

    for (std::size_t i = 0; i < str.size(); ++i) {
        if (str[i] == delimiter) {
            if (!temp.empty()) {
                result.push_back(temp); 
                temp.clear();
            }
        } else {
            temp += str[i];
        }
    }

    if (!temp.empty()) {
        result.push_back(temp);
    }

    return result;
}

inline bool is_only_digits(const std::string& str) {
    for (std::size_t i = 0; i < str.size(); ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

#endif