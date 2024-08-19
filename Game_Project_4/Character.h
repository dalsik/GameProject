#pragma once
#include <string>
#include <vector>
using namespace std;
class Character_Select;

class Character {
protected:
	int rerollcnt = 2;
	static int Gold;			// 골드
	static int Defense;			// 방어력
	static int HP;				// 체력
	static int Attack;			// 공격력

public:
	static vector<pair<string, string>> deck;		// 52개의 카드
	static vector<pair<string, string>> player_card;
	Character() {				// 캐릭터의 기본 스탯 설정
		Gold = 0;
		Defense = 1;
		HP = 20;
		Attack = 10;
	}
	void card();		// 카드 매핑
	void draw_card();	// 카드 뽑기
	void reroll();
	void enhance_HP();
	void enhance_Defense();
	void enhance_Attack();
	void show_stats();
	int get_Gold();
	void addGold(int amount);
	int getHP();
};