
#include <vector>
#include <string> 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Fairy.h"

// ������ ����
Fairy::Fairy() {
    gold = 0;             // �ʱ�ȭ
    initializeDeck();     // �� �ʱ�ȭ
    shuffleDeck();        // �� ����
}

// ī�� �� �ʱ�ȭ �Լ� ����
void Fairy::initializeDeck() {
    vector<string> suits = { "Ŭ�ι�", "�����̵�", "��Ʈ", "���̾�" };

    for (const auto& suit : suits) {
        for (int i = 2; i <= 10; ++i) {
            cards.push_back(Card(suit, to_string(i))); // ���ڿ� ����� ������ �ٲ���
        }
        cards.push_back(Card(suit, "J")); // J
        cards.push_back(Card(suit, "Q")); // Q
        cards.push_back(Card(suit, "K")); // K
        cards.push_back(Card(suit, "A")); // A
    }
}

// ī�� �� ���� �Լ� ����
void Fairy::shuffleDeck() {
    // ���� �߻��� �õ� ����
    srand(static_cast<unsigned int>(time(0)));
    // ī�� �� ����
    std::random_shuffle(cards.begin(), cards.end());
}

//���ΰ����� ī�� 3���� �ִ� �Լ�
std::vector<Card> Fairy::giveCards() {
    std::vector<Card> playerCards;
    // ī�� ���� ����ִ��� Ȯ��
    if (cards.empty()) {
        std::cout << "���� ī�尡 �����ϴ�." << std::endl;
        return playerCards; // �� ���� ��ȯ
    }
    // ī�� ���� ����
    shuffleDeck();
    for (int i = 0; i < 3 && !cards.empty(); ++i) {
        playerCards.push_back(cards.back());
        cards.pop_back();
    }
    return playerCards;
}

// ���͸� ����� �� ���ΰ����� ��带 �ִ� �Լ� ����
void Fairy::giveGoldFromMonster(const Monster& monster) {
    int rewardGold = monster.getRewardGold();
    gold += rewardGold; // ��� ����
    cout << "���ָ��� " << rewardGold << "��带 ȹ���߽��ϴ�." << endl << endl; // �޽��� ���
}

int Fairy::getGold() const {
    return gold;
}