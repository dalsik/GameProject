#pragma once

#include <string>
#include "Character.h"

class Monster {
private:
    std::string name; // ���� �̸�
    int HP; // ���� ü��
    int Attack; // ���� ���ݷ�
    bool isBoss; // ���� ���� ����

public:
    // ������
    Monster(std::string n, int hp, int attack, bool boss = false);

    // ���� �Լ�
    void Go_battle(int& playerHP, int playerDefense, Character& player);

    // ���Ͱ� �׾����� Ȯ���ϴ� �Լ�
    bool isDefeated() const;

    // ���� �̸� ��ȯ
    std::string getName() const;

    // Ư�� ������ �����ϴ� �Լ�
    int specialAttack(int playerDefense, Character& player);

    // �Ϲ� ������ �����ϴ� �Լ�
    int regularAttack(int playerDefense) const;

    // ���͸� �׿��� �� �ִ� ��� ���� ��ȯ
    int getRewardGold() const;

    // ���� HP ��ȯ �Լ�
    int getHP() const;

    // �����ϰ� ���͸� �����ϴ� �Լ�
    static Monster createRandomMonster();

    // ���� ���� ����
    static Monster createBossMonster();

    // ���Ϳ��� �������� �ִ� �Լ�
    void takeDamage(int damage);
};
