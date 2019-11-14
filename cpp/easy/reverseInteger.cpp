#include <regex>

class Solution {
public:
    int reverse(int x) {
        // convert to String
        auto stringInt = std::to_string(x);
        auto sign = "";
        // check for negative sign
        if (std::regex_search(stringInt, std::regex("-"))) {
            sign = "-";
        }
        // reverse string
        std::reverse(stringInt.begin(), stringInt.end());

        // exit early on overflow
        long long unsignedStringInt = std::stoll(stringInt);
        if ((int)unsignedStringInt < unsignedStringInt) return 0;
        
        // join sign with reversed string      
        auto joinedInt = sign + stringInt;
        // convert back to int
        auto revInt = std::stoll(joinedInt);
        return revInt;
    }
};
