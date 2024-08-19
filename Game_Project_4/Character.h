#pragma once
#include <string>
#include <vector>
using namespace std;
class Character_Select;

class Character {
protected:
	int rerollcnt = 2;
	static int Gold;			// ���
	static int Defense;			// ����
	static int HP;				// ü��
	static int Attack;			// ���ݷ�

public:
	static vector<pair<string, string>> deck;		// 52���� ī��
	static vector<pair<string, string>> player_card;
	Character() {				// ĳ������ �⺻ ���� ����
		Gold = 0;
		Defense = 1;
		HP = 20;
		Attack = 10;
	}
	void card();		// ī�� ����
	void draw_card();	// ī�� �̱�
	void reroll();
	void enhance_HP();
	void enhance_Defense();
	void enhance_Attack();
	void show_stats();
	int get_Gold();
	void addGold(int amount);
	int getHP();
};