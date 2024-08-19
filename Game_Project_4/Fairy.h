
#pragma once

#include <vector>
#include <string> 
#include "Monster.h"

// ī�� Ŭ���� ����
class Card {
public:
    string suit; // ī�� ����
    std::string number;  // ī�� ���̸� ���ڿ��� ǥ��

    // ������
    Card(const std::string& st, const std::string& num) : suit(st), number(num) {}
};

// ���� Ŭ���� ����
class Fairy {
private:
    std::vector<Card> cards; // ī�带 �����ϴ� ����
    int gold;                 // ���ΰ����� �ִ� ���
public:
    Fairy(); // ������
    void initializeDeck(); // ī�� �� �ʱ�ȭ �Լ�
    void shuffleDeck();    // ī�� �� ���� �Լ�
    std::vector<Card> giveCards();
    void giveGoldFromMonster(const Monster& monster);
    int getGold() const; // ���� ��带 Ȯ���ϴ� �Լ�

};