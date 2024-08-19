#include <iostream>
#include <string>
#include <random>
#include "Character.h"
using namespace std;

// 주인공 클래스의 함수들 구현

// Character.cpp 파일에 추가

#include "Character.h"

// 전역 변수로 설정하여서 cpp 구현 부분에다가 초기값 설정해줘야 한다.
int Character::Gold = 0;
int Character::Defense = 1;
int Character::HP = 20;
int Character::Attack = 10;
vector<pair<string, string>> Character::deck;
vector<pair<string, string>> Character::player_card;
// deck 배열의 정의는 필요에 따라 추가될 수 있음

int  Character::getHP() {
	return Character::HP;
}

void Character::card() {			// 카드를 매핑하기 위한 카드 함수
	vector<string> suits = { "클로버", "스페이드", "하트", "다이아" };

	for (const auto& suit : suits) {
		for (int i = 2; i <= 10; ++i) {
			deck.push_back(make_pair(to_string(i), suit)); // 숫자와 모양의 순서를 바꿔줌
		}
		deck.push_back(make_pair("J", suit)); // J
		deck.push_back(make_pair("Q", suit)); // Q
		deck.push_back(make_pair("K", suit)); // K
		deck.push_back(make_pair("A", suit)); // A
	}
}

void Character::draw_card() {		// 플레이어 카드 2장을 뽑는 함수
	cout << endl;
	cout << " ※ 손에 들어올 카드 2장을 뽑겠습니다." << endl << endl;

	random_device rd;
	mt19937 gen(rd());
	int remaining_cards = deck.size();

	for (int i = 0; i < 2; i++) { // 카드 2장 뽑기
		uniform_int_distribution<int> dist(0, remaining_cards - 1);
		int random_index = dist(gen);
		cout << i + 1 << " 번째 카드는 " << deck[random_index].first << " " << deck[random_index].second << " 입니다." << endl;
		player_card.push_back(make_pair(deck[random_index].first, deck[random_index].second));
		swap(deck[random_index], deck[remaining_cards - 1]);
		deck.pop_back(); // 마지막 카드 제거
		remaining_cards--;
	}
}


void Character::reroll() {		// 카드 새로고침 함수

	cout << endl;
	cout << "카드를 새로고침 하시겠습니까?(남은횟수: " << rerollcnt << "번 (Y / N)) >> ";
	char c;
	cin >> c;
	cin.ignore();
	if (c == 'Y') {
		while (c != 'N') {
			card();
			draw_card();
			rerollcnt--;
			if (rerollcnt == 0) { break; }			// 리롤 횟수 만료시 중지
			cout << endl;
			cout << "카드를 새로고침 하시겠습니까?(남은횟수: " << rerollcnt << "번 (Y / N)) >> ";
			cin >> c;
		}
	}

}


void Character::enhance_HP() { // 5씩 증가하는 체력 증가 함수
	int HPX = 5;
	int GoldX = 3;
	if (Gold >= GoldX) {
		// 골드 차감
		Gold -= GoldX;
		GoldX += 2;
		// HP 강화
		HP += HPX;
		HPX += 5; // 5의 배율씩 증가
	}
	else {
		cout << endl << "골드가 부족하여 체력을 강화할 수 없습니다." << endl;
		cout << "\"골드가 부족해....\"" << endl;
	}
}

void Character::enhance_Defense() {
	int GoldX = 10;
	if (Gold >= GoldX) {
		// 골드 차감
		Gold -= GoldX;
		GoldX += 10;
		// 방어력 강화
		Defense += 2; // 방어력은 2씩 증가
	}
	else {
		cout << endl << "골드가 부족하여 방어력을 강화할 수 없습니다." << endl;
		cout << "\"골드가 부족해....\"" << endl;
	}
}

void Character::enhance_Attack() {
	int GoldX = 7;
	if (Gold >= GoldX) {
		// 골드 차감
		Gold -= GoldX;
		GoldX += 3;
		// 공격력 강화
		Attack += 3;
	}
	else {
		cout << endl << "골드가 부족하여 공격력을 강화할 수 없습니다." << endl;
		cout << "\"골드가 부족해....\"" << endl;
	}
}

void Character::show_stats() {
	cout << "공격력 :" << Attack << "\tHP :" << HP << "  " << "\t방어력 :" << Defense << endl;
}

int Character::get_Gold() {
	return Gold;
}

void Character::addGold(int amount) {
	Gold += amount;
}