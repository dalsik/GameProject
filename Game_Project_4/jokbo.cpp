#include "jokbo.h"
#include <map>
#include <algorithm>
#include <vector>
#include <string>

jokbo::jokbo() {
    // 족보와 가중치 초기화
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

//족보 체크 string으로 리턴해서 어떤 족보인지 판별해줌
string jokbo::check(vector<pair<string, string>> c) {
    std::string num[5];
    std::string suit[5];
    int nums[5]; // nums 배열 선언 추가

    std::map<std::string, int> numCount; //숫자의 중복을 세어줌.(key -> 숫자, value -> 나온 횟수)
    std::map<std::string, int> suitCount; //문양의 중복을 세어줌

    for (int i = 0; i < 5; i++) { //카드 개수만큼 넣어줌
        num[i] = c[i].first; //카드의 숫자(넘버)
        suit[i] = c[i].second; //카드의 무늬
    }

    //중복 세기 전에 정렬 먼저.(스트레이트, 하이카드 판별용)
    for (int i = 0; i < 5; i++) {
        nums[i] = convertString(num[i]);
    } //string을 int로 바꿔서
    //sort(정렬할꺼임)
    sort(nums, nums + 5);

    bool straight = true;
    bool royalFlush = false;

    for (int i = 0; i < 4; i++) {
        if (nums[i] + 1 != nums[i + 1]) { //연속 확인
            straight = false;
            break;
        }
    }
    //로얄 플러시
    if (straight && (nums[0] == 10)) {
        royalFlush = true;
    }

    // 숫자와 문양의 카운트 계산
    for (int i = 0; i < 5; i++) {
        numCount[num[i]]++;
        suitCount[suit[i]]++;
    }

    int pairCount = 0;
    bool TOK = false;
    bool FOK = false;
    bool flush = false;
    bool fullHouse = false;

    // 숫자를 카운트해준다.
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

    if (pairCount == 0 && !straight) { //페어도 없고 연속도 없음 ->하이카드
        jokbonum.push_back(listOfJokbo[9].second);
    }
    if (pairCount == 1) {
        jokbonum.push_back(listOfJokbo[8].second); // 원페어
    }
    if (pairCount == 2) {
        jokbonum.push_back(listOfJokbo[7].second); // 투페어
    }
    if (TOK) {
        jokbonum.push_back(listOfJokbo[6].second); //쓰리오브 카인드
    }
    if (straight) {
        jokbonum.push_back(listOfJokbo[5].second); //스트레이트
    }
    if (flush) {
        jokbonum.push_back(listOfJokbo[4].second);
    }
    if (pairCount == 1 && TOK) { // pair + 트리플 => 풀하우스
        jokbonum.push_back(listOfJokbo[3].second);
    }
    if (FOK) {
        jokbonum.push_back(listOfJokbo[2].second); //포 오브 카드스
    }
    if (straight && flush) {
        jokbonum.push_back(listOfJokbo[1].second); //스트레이트 플러시
    }
    if (royalFlush && flush) {
        jokbonum.push_back(listOfJokbo[0].second); //로얄 플러시
    }

    sort(jokbonum.begin(), jokbonum.end()); //있는 가중치들 정렬때려서 가장 앞에 것만 갖고 올꺼임(가장 높은 족보)

    for (int i = 0; i < 10; i++) {
        if (listOfJokbo[i].second == jokbonum[0]) {
            return listOfJokbo[i].first;
        }
    }
    return ""; // Default return to avoid compiler warnings
}
