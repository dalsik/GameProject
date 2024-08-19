
#include <vector>
#include <string> 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Fairy.h"

// 생성자 구현
Fairy::Fairy() {
    gold = 0;             // 초기화
    initializeDeck();     // 덱 초기화
    shuffleDeck();        // 덱 섞기
}

// 카드 덱 초기화 함수 구현
void Fairy::initializeDeck() {
    vector<string> suits = { "클로버", "스페이드", "하트", "다이아" };

    for (const auto& suit : suits) {
        for (int i = 2; i <= 10; ++i) {
            cards.push_back(Card(suit, to_string(i))); // 숫자와 모양의 순서를 바꿔줌
        }
        cards.push_back(Card(suit, "J")); // J
        cards.push_back(Card(suit, "Q")); // Q
        cards.push_back(Card(suit, "K")); // K
        cards.push_back(Card(suit, "A")); // A
    }
}

// 카드 덱 섞는 함수 구현
void Fairy::shuffleDeck() {
    // 난수 발생기 시드 설정
    srand(static_cast<unsigned int>(time(0)));
    // 카드 덱 섞기
    std::random_shuffle(cards.begin(), cards.end());
}

//주인공에에 카드 3장을 주는 함수
std::vector<Card> Fairy::giveCards() {
    std::vector<Card> playerCards;
    // 카드 덱이 비어있는지 확인
    if (cards.empty()) {
        std::cout << "덱에 카드가 없습니다." << std::endl;
        return playerCards; // 빈 벡터 반환
    }
    // 카드 덱을 섞음
    shuffleDeck();
    for (int i = 0; i < 3 && !cards.empty(); ++i) {
        playerCards.push_back(cards.back());
        cards.pop_back();
    }
    return playerCards;
}

// 몬스터를 잡았을 때 주인공에게 골드를 주는 함수 구현
void Fairy::giveGoldFromMonster(const Monster& monster) {
    int rewardGold = monster.getRewardGold();
    gold += rewardGold; // 골드 증가
    cout << "응애맨이 " << rewardGold << "골드를 획득했습니다." << endl << endl; // 메시지 출력
}

int Fairy::getGold() const {
    return gold;
}