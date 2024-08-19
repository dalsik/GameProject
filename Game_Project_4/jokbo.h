
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
    std::map<std::string, int> numCount; // ������ �ߺ��� �����ִ� ��
    std::map<std::string, int> suitCount; // ������ �ߺ��� �����ִ� ��

public:
    jokbo();
    int convertString(string num);
    std::string check(std::vector<std::pair<std::string, std::string>> c);
};


// convertString �Լ� ���ο��� weight ���� �������� �ʱ�ȭ�մϴ�.
inline int jokbo::convertString(std::string num) {
    static std::map<std::string, int> weight = {
        {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5},
        {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9},
        {"10", 10}, {"J", 11}, {"Q", 12}, {"K", 13}, {"A", 14}
    };

    return weight.at(num);
}