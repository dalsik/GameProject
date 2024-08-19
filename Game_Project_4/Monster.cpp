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
        monsterAttack = regularAttack(playerDefense); // 일반 공격
    }
    else {
        monsterAttack = specialAttack(playerDefense, player); // 특수 공격
    }
    playerHP -= std::max(monsterAttack, 0);
    std::cout << "플레이어의 남은 체력: " << playerHP << std::endl << endl;
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
    if (name == "고블린") {
        damage = ((Attack + 1) * 2) - playerDefense;
        std::cout << name << "이(가) 쎄게 치기를 시전합니다! 플레이어가 " << damage << "의 피해를 입었습니다." << std::endl << endl;
    }
    else if (name == "미믹") {
        damage = ((Attack + 1) * 2) - playerDefense;
        std::cout << name << "이(가) 삼키기를 시전합니다! 플레이어가 " << damage << "의 피해를 입었습니다." << std::endl << endl;
    }
    else if (name == "황금슬라임") {
        std::cout << name << "이(가) 금화를 뿜어냅니다! 플레이어가 10 골드를 얻습니다." << std::endl << endl;
        player.addGold(10);
    }
    else if (name == "킹 황금 고블린") {
        damage = ((Attack + 1) * 2) - playerDefense;
        std::cout << name << "이(가) 고블린의 저력을 시전합니다! 플레이어가 " << damage << "의 피해를 입었습니다." << std::endl << endl;
    }
    return damage;
}

int Monster::regularAttack(int playerDefense) const {
    int damage = std::max(Attack - playerDefense, 0);
    std::cout << name << "이(가) 일반 공격을 시전합니다! 플레이어가 " << damage << "의 피해를 입었습니다." << std::endl << endl;
    return damage;
}

int Monster::getRewardGold() const {
    if (name == "고블린") {
        return 25;
    }
    else if (name == "미믹") {
        return 33;
    }
    else if (name == "황금슬라임") {
        return 44;
    }
    else if (name == "킹 황금 고블린") {
        return 300;
    }
    return 0;
}

Monster Monster::createRandomMonster() {
    srand(static_cast<unsigned int>(time(0)));
    int monsterProbability = rand() % 100 + 1;
    if (monsterProbability <= 40) {
        return Monster("고블린", 20, 5);
    }
    else if (monsterProbability <= 90) {
        return Monster("미믹", 50, 3);
    }
    else {
        return Monster("황금슬라임", 25, 0);
    }
}

Monster Monster::createBossMonster() {
    return Monster("킹 황금 고블린", 150, 17);
}
