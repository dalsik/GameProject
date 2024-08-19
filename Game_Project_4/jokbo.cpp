#include "jokbo.h"
#include <map>
#include <algorithm>
#include <vector>
#include <string>

jokbo::jokbo() {
    // ������ ����ġ �ʱ�ȭ
    listOfJokbo.push_back({ "Royal Straight Flush", 1 });
    listOfJokbo.push_back({ "Straight Flush", 2 });
    listOfJokbo.push_back({ "Four of a kind", 3 });
    listOfJokbo.push_back({ "Full house", 4 });
    listOfJokbo.push_back({ "Flush", 5 });
    listOfJokbo.push_back({ "Straight", 6 });
    listOfJokbo.push_back({ "Three of a kind", 7 });
    listOfJokbo.push_back({ "Two pair", 8 });
    listOfJokbo.push_back({ "One pair", 9 });
    listOfJokbo.push_back({ "High card", 10 });
}

//���� üũ string���� �����ؼ� � �������� �Ǻ�����
string jokbo::check(vector<pair<string, string>> c) {
    std::string num[5];
    std::string suit[5];
    int nums[5]; // nums �迭 ���� �߰�

    std::map<std::string, int> numCount; //������ �ߺ��� ������.(key -> ����, value -> ���� Ƚ��)
    std::map<std::string, int> suitCount; //������ �ߺ��� ������

    for (int i = 0; i < 5; i++) { //ī�� ������ŭ �־���
        num[i] = c[i].first; //ī���� ����(�ѹ�)
        suit[i] = c[i].second; //ī���� ����
    }

    //�ߺ� ���� ���� ���� ����.(��Ʈ����Ʈ, ����ī�� �Ǻ���)
    for (int i = 0; i < 5; i++) {
        nums[i] = convertString(num[i]);
    } //string�� int�� �ٲ㼭
    //sort(�����Ҳ���)
    sort(nums, nums + 5);

    bool straight = true;
    bool royalFlush = false;

    for (int i = 0; i < 4; i++) {
        if (nums[i] + 1 != nums[i + 1]) { //���� Ȯ��
            straight = false;
            break;
        }
    }
    //�ξ� �÷���
    if (straight && (nums[0] == 10)) {
        royalFlush = true;
    }

    // ���ڿ� ������ ī��Ʈ ���
    for (int i = 0; i < 5; i++) {
        numCount[num[i]]++;
        suitCount[suit[i]]++;
    }

    int pairCount = 0;
    bool TOK = false;
    bool FOK = false;
    bool flush = false;
    bool fullHouse = false;

    // ���ڸ� ī��Ʈ���ش�.
    for (auto const& pair : numCount) {
        if (pair.second == 2) {
            pairCount++;
        }
        if (pair.second == 3) {
            TOK = true;
        }
        if (pair.second == 4) {
            FOK = true;
        }
    }

    for (auto const& pair : suitCount) {
        if (pair.second == 5) {
            flush = true;
        }
    }

    vector<int> jokbonum;

    if (pairCount == 0 && !straight) { //�� ���� ���ӵ� ���� ->����ī��
        jokbonum.push_back(listOfJokbo[9].second);
    }
    if (pairCount == 1) {
        jokbonum.push_back(listOfJokbo[8].second); // �����
    }
    if (pairCount == 2) {
        jokbonum.push_back(listOfJokbo[7].second); // �����
    }
    if (TOK) {
        jokbonum.push_back(listOfJokbo[6].second); //�������� ī�ε�
    }
    if (straight) {
        jokbonum.push_back(listOfJokbo[5].second); //��Ʈ����Ʈ
    }
    if (flush) {
        jokbonum.push_back(listOfJokbo[4].second);
    }
    if (pairCount == 1 && TOK) { // pair + Ʈ���� => Ǯ�Ͽ콺
        jokbonum.push_back(listOfJokbo[3].second);
    }
    if (FOK) {
        jokbonum.push_back(listOfJokbo[2].second); //�� ���� ī�彺
    }
    if (straight && flush) {
        jokbonum.push_back(listOfJokbo[1].second); //��Ʈ����Ʈ �÷���
    }
    if (royalFlush && flush) {
        jokbonum.push_back(listOfJokbo[0].second); //�ξ� �÷���
    }

    sort(jokbonum.begin(), jokbonum.end()); //�ִ� ����ġ�� ���Ķ����� ���� �տ� �͸� ���� �ò���(���� ���� ����)

    for (int i = 0; i < 10; i++) {
        if (listOfJokbo[i].second == jokbonum[0]) {
            return listOfJokbo[i].first;
        }
    }
    return ""; // Default return to avoid compiler warnings
}
