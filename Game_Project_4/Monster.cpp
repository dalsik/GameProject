#include "Monster.h"
#include "Character.h"
#include <iostream>
#include <cstdlib> // for rand()
#include <ctime>

Monster::Monster(std::string n, int hp, int attack, bool boss)
    : name(n), HP(hp), Attack(attack), isBoss(boss) {}

void Monster::takeDamage(int damage) {
    HP -= damage;
    if (HP < 0) {
        HP = 0;
    }
}

void Monster::Go_battle(int& playerHP, int playerDefense, Character& player) {
 
    int monsterAttack;

    if (rand() % 2 == 0) {
        monsterAttack = regularAttack(playerDefense); // �Ϲ� ����
    }
    else {
        monsterAttack = specialAttack(playerDefense, player); // Ư�� ����
    }
    playerHP -= std::max(monsterAttack, 0);
    std::cout << "�÷��̾��� ���� ü��: " << playerHP << std::endl << endl;
}

bool Monster::isDefeated() const {
    return HP <= 0;
}

std::string Monster::getName() const {
    return name;
}

int Monster::getHP() const {
    return HP;
}

int Monster::specialAttack(int playerDefense, Character& player) {
    int damage = 0;
    if (name == "���") {
        damage = ((Attack + 1) * 2) - playerDefense;
        std::cout << name << "��(��) ��� ġ�⸦ �����մϴ�! �÷��̾ " << damage << "�� ���ظ� �Ծ����ϴ�." << std::endl << endl;
    }
    else if (name == "�̹�") {
        damage = ((Attack + 1) * 2) - playerDefense;
        std::cout << name << "��(��) ��Ű�⸦ �����մϴ�! �÷��̾ " << damage << "�� ���ظ� �Ծ����ϴ�." << std::endl << endl;
    }
    else if (name == "Ȳ�ݽ�����") {
        std::cout << name << "��(��) ��ȭ�� �վ���ϴ�! �÷��̾ 10 ��带 ����ϴ�." << std::endl << endl;
        player.addGold(10);
    }
    else if (name == "ŷ Ȳ�� ���") {
        damage = ((Attack + 1) * 2) - playerDefense;
        std::cout << name << "��(��) ����� ������ �����մϴ�! �÷��̾ " << damage << "�� ���ظ� �Ծ����ϴ�." << std::endl << endl;
    }
    return damage;
}

int Monster::regularAttack(int playerDefense) const {
    int damage = std::max(Attack - playerDefense, 0);
    std::cout << name << "��(��) �Ϲ� ������ �����մϴ�! �÷��̾ " << damage << "�� ���ظ� �Ծ����ϴ�." << std::endl << endl;
    return damage;
}

int Monster::getRewardGold() const {
    if (name == "���") {
        return 25;
    }
    else if (name == "�̹�") {
        return 33;
    }
    else if (name == "Ȳ�ݽ�����") {
        return 44;
    }
    else if (name == "ŷ Ȳ�� ���") {
        return 300;
    }
    return 0;
}

Monster Monster::createRandomMonster() {
    srand(static_cast<unsigned int>(time(0)));
    int monsterProbability = rand() % 100 + 1;
    if (monsterProbability <= 40) {
        return Monster("���", 20, 5);
    }
    else if (monsterProbability <= 90) {
        return Monster("�̹�", 50, 3);
    }
    else {
        return Monster("Ȳ�ݽ�����", 25, 0);
    }
}

Monster Monster::createBossMonster() {
    return Monster("ŷ Ȳ�� ���", 150, 17);
}
