#include <iostream>
#include <string>
#include <random>
#include "Character.h"
using namespace std;

// ���ΰ� Ŭ������ �Լ��� ����

// Character.cpp ���Ͽ� �߰�

#include "Character.h"

// ���� ������ �����Ͽ��� cpp ���� �κп��ٰ� �ʱⰪ ��������� �Ѵ�.
int Character::Gold = 0;
int Character::Defense = 1;
int Character::HP = 20;
int Character::Attack = 10;
vector<pair<string, string>> Character::deck;
vector<pair<string, string>> Character::player_card;
// deck �迭�� ���Ǵ� �ʿ信 ���� �߰��� �� ����

int  Character::getHP() {
	return Character::HP;
}

void Character::card() {			// ī�带 �����ϱ� ���� ī�� �Լ�
	vector<string> suits = { "Ŭ�ι�", "�����̵�", "��Ʈ", "���̾�" };

	for (const auto& suit : suits) {
		for (int i = 2; i <= 10; ++i) {
			deck.push_back(make_pair(to_string(i), suit)); // ���ڿ� ����� ������ �ٲ���
		}
		deck.push_back(make_pair("J", suit)); // J
		deck.push_back(make_pair("Q", suit)); // Q
		deck.push_back(make_pair("K", suit)); // K
		deck.push_back(make_pair("A", suit)); // A
	}
}

void Character::draw_card() {		// �÷��̾� ī�� 2���� �̴� �Լ�
	cout << endl;
	cout << " �� �տ� ���� ī�� 2���� �̰ڽ��ϴ�." << endl << endl;

	random_device rd;
	mt19937 gen(rd());
	int remaining_cards = deck.size();

	for (int i = 0; i < 2; i++) { // ī�� 2�� �̱�
		uniform_int_distribution<int> dist(0, remaining_cards - 1);
		int random_index = dist(gen);
		cout << i + 1 << " ��° ī��� " << deck[random_index].first << " " << deck[random_index].second << " �Դϴ�." << endl;
		player_card.push_back(make_pair(deck[random_index].first, deck[random_index].second));
		swap(deck[random_index], deck[remaining_cards - 1]);
		deck.pop_back(); // ������ ī�� ����
		remaining_cards--;
	}
}


void Character::reroll() {		// ī�� ���ΰ�ħ �Լ�

	cout << endl;
	cout << "ī�带 ���ΰ�ħ �Ͻðڽ��ϱ�?(����Ƚ��: " << rerollcnt << "�� (Y / N)) >> ";
	char c;
	cin >> c;
	cin.ignore();
	if (c == 'Y') {
		while (c != 'N') {
			card();
			draw_card();
			rerollcnt--;
			if (rerollcnt == 0) { break; }			// ���� Ƚ�� ����� ����
			cout << endl;
			cout << "ī�带 ���ΰ�ħ �Ͻðڽ��ϱ�?(����Ƚ��: " << rerollcnt << "�� (Y / N)) >> ";
			cin >> c;
		}
	}

}


void Character::enhance_HP() { // 5�� �����ϴ� ü�� ���� �Լ�
	int HPX = 5;
	int GoldX = 3;
	if (Gold >= GoldX) {
		// ��� ����
		Gold -= GoldX;
		GoldX += 2;
		// HP ��ȭ
		HP += HPX;
		HPX += 5; // 5�� ������ ����
	}
	else {
		cout << endl << "��尡 �����Ͽ� ü���� ��ȭ�� �� �����ϴ�." << endl;
		cout << "\"��尡 ������....\"" << endl;
	}
}

void Character::enhance_Defense() {
	int GoldX = 10;
	if (Gold >= GoldX) {
		// ��� ����
		Gold -= GoldX;
		GoldX += 10;
		// ���� ��ȭ
		Defense += 2; // ������ 2�� ����
	}
	else {
		cout << endl << "��尡 �����Ͽ� ������ ��ȭ�� �� �����ϴ�." << endl;
		cout << "\"��尡 ������....\"" << endl;
	}
}

void Character::enhance_Attack() {
	int GoldX = 7;
	if (Gold >= GoldX) {
		// ��� ����
		Gold -= GoldX;
		GoldX += 3;
		// ���ݷ� ��ȭ
		Attack += 3;
	}
	else {
		cout << endl << "��尡 �����Ͽ� ���ݷ��� ��ȭ�� �� �����ϴ�." << endl;
		cout << "\"��尡 ������....\"" << endl;
	}
}

void Character::show_stats() {
	cout << "���ݷ� :" << Attack << "\tHP :" << HP << "  " << "\t���� :" << Defense << endl;
}

int Character::get_Gold() {
	return Gold;
}

void Character::addGold(int amount) {
	Gold += amount;
}