
#pragma once

#include <vector>
#include <string> 
#include "Monster.h"

// 카드 클래스 정의
class Card {
public:
    string suit; // 카드 숫자
    std::string number;  // 카드 무늬를 문자열로 표현

    // 생성자
    Card(const std::string& st, const std::string& num) : suit(st), number(num) {}
};

// 요정 클래스 정의
class Fairy {
private:
    std::vector<Card> cards; // 카드를 저장하는 벡터
    int gold;                 // 주인공에게 주는 골드
public:
    Fairy(); // 생성자
    void initializeDeck(); // 카드 덱 초기화 함수
    void shuffleDeck();    // 카드 덱 섞는 함수
    std::vector<Card> giveCards();
    void giveGoldFromMonster(const Monster& monster);
    int getGold() const; // 현재 골드를 확인하는 함수

};