#pragma once

#include <string>
#include "Character.h"

class Monster {
private:
    std::string name; // 몬스터 이름
    int HP; // 몬스터 체력
    int Attack; // 몬스터 공격력
    bool isBoss; // 보스 몬스터 여부

public:
    // 생성자
    Monster(std::string n, int hp, int attack, bool boss = false);

    // 전투 함수
    void Go_battle(int& playerHP, int playerDefense, Character& player);

    // 몬스터가 죽었는지 확인하는 함수
    bool isDefeated() const;

    // 몬스터 이름 반환
    std::string getName() const;

    // 특수 공격을 수행하는 함수
    int specialAttack(int playerDefense, Character& player);

    // 일반 공격을 수행하는 함수
    int regularAttack(int playerDefense) const;

    // 몬스터를 죽였을 때 주는 골드 보상 반환
    int getRewardGold() const;

    // 몬스터 HP 반환 함수
    int getHP() const;

    // 랜덤하게 몬스터를 생성하는 함수
    static Monster createRandomMonster();

    // 보스 몬스터 생성
    static Monster createBossMonster();

    // 몬스터에게 데미지를 주는 함수
    void takeDamage(int damage);
};
