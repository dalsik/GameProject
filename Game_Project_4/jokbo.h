
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class jokbo {
    std::vector<std::pair<std::string, std::string>> cards;
    std::vector<std::pair<std::string, int>> listOfJokbo;
    std::map<std::string, int> numCount; // 숫자의 중복을 세어주는 맵
    std::map<std::string, int> suitCount; // 문양의 중복을 세어주는 맵

public:
    jokbo();
    int convertString(string num);
    std::string check(std::vector<std::pair<std::string, std::string>> c);
};


// convertString 함수 내부에서 weight 맵을 정적으로 초기화합니다.
inline int jokbo::convertString(std::string num) {
    static std::map<std::string, int> weight = {
        {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5},
        {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9},
        {"10", 10}, {"J", 11}, {"Q", 12}, {"K", 13}, {"A", 14}
    };

    return weight.at(num);
}