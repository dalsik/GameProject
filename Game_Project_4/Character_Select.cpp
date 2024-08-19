#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include "Character_Select.h"
#include "Fairy.h"

using namespace std;
// 주인공의 선택지 클래스 함수들 구현

#include "jokbo.h"

int Character_Select::walkcnt = 0;

int Character_Select::get_walkcnt() {
    return walkcnt;
}

void Character_Select::getDeck() {
    for (const auto& card : Character::deck) {
        cout << card.first << " " << card.second << endl;
    }
}

void Character_Select::walking() {
    cout << endl;
    cout << "걸어가는중....." << endl;
    srand(0); // srand() 함수를 한 번만 호출하고 시드 값을 0으로 지정

    int n = rand() % 2;
    while (n != 1) { // 20퍼센트 확률로 몬스터를 조우하도록 설정
        cout << "아직도 걸어가는중....." << endl << endl;
        n = rand() % 2;
    }

    cout << "뭔가 수상한 느낌이 든다......" << endl << endl;

    walkcnt++;		// 몬스터를 만날 때마다 횟수 증가
}



void Character_Select::receiveAdditionalCards(const vector<Card>& additionalCards) {
    for (const auto& card : additionalCards) {
        player_card.push_back(cardToPair(card));
    }
}


void Character_Select::battle(Monster& monster) {
    Fairy fairy;
    std::cout << monster.getName() << "와(과)의 전투가 시작됩니다!" << endl;
  
     // 플레이어의 카드를 담을 벡터
    std::vector<Card> additionalCards = fairy.giveCards();
   
    receiveAdditionalCards(additionalCards);
    

    //족보 객체 생성
    jokbo jk;

    //플레이어의 족보 확인
    std::string result = jk.check(player_card);

    bool canAttemptEscape = true; // 도망가기 시도 가능 여부

    while ((!monster.isDefeated()) && (Character::HP > 0)) {
        cout << endl;
        cout << "<선택지를 입력해주세요>" << endl;
        if (canAttemptEscape) {
            cout << "1. 공격하기\t 2. 족보 검사하기\t 3. 도망가기(25%)>>" << endl;
        }
        else {
            cout << "1. 공격하기\t 2. 족보 검사하기>>" << endl;
        }
        int s;
        cin >> s;

        if (canAttemptEscape && s == 3) {
            srand((unsigned)time(NULL));
            int r = rand() % 4;
            if (r == 3) {
                cout << monster.getName() << "(으)로부터 도망쳤습니다...!" << endl;
                return; // 전투 종료, 걸어가는 상태로 돌아감
            }
            else {
                cout << monster.getName() << "(으)로부터 도망치지 못했습니다...!" << endl;
                canAttemptEscape = false; // 도망가기에 실패한 경우, 더 이상 시도할 수 없음
                continue; // 다음 루프에서 도망가기 옵션을 제공하지 않음
            }
        }

        if (s == 1) {
            cout << endl;
            cout << monster.getName() << "에게 공격을 시전하였습니다!" << endl;
            int damage = 0;
            string result = jk.check(player_card);
            if (result == "Royal Straight Flush") {
                damage = 150 + Character::Attack;
                cout << "로얄 스트레이트 플러시! " << monster.getName() << "에게 " << damage << "딜을 주었습니다." << endl << endl;
            }
            else if (result == "Straight Flush") {
                damage = 30 + Character::Attack;
                cout << "스트레이트 플러시! " << monster.getName() << "에게 " << damage << "딜을 주었습니다." << endl << endl;
            }
            else if (result == "Four of a kind") {
                damage = 25 + Character::Attack;
                cout << "포카드! " << monster.getName() << "에게 " << damage << "딜을 주었습니다." << endl << endl;
            }
            else if (result == "Full house") {
                damage = 20 + Character::Attack;
                cout << "풀하우스! " << monster.getName() << "에게 " << damage << "딜을 주었습니다." << endl << endl;
            }
            else if (result == "Flush") {
                damage = 15 + Character::Attack;
                cout << "플러시! " << monster.getName() << "에게 " << damage << "딜을 주었습니다." << endl << endl;
            }
            else if (result == "Straight") {
                damage = 10 + Character::Attack;
                cout << "스트레이트! " << monster.getName() << "에게 " << damage << "딜을 주었습니다." << endl << endl;
            }
            else if (result == "Three of a kind") {
                damage = 8 + Character::Attack;
                cout << "트리플! " << monster.getName() << "에게 " << damage << "딜을 주었습니다." << endl << endl;
            }
            else if (result == "Two pair") {
                damage = 6 + Character::Attack;
                cout << "투페어! " << monster.getName() << "에게 " << damage << "딜을 주었습니다." << endl << endl;
            }
            else if (result == "One pair") {
                damage = 3 + Character::Attack;
                cout << "원페어! " << monster.getName() << "에게 " << damage << "딜을 주었습니다." << endl << endl;
            }
            else if (result == "High card") {
                damage = 1 + Character::Attack;
                cout << "하이카드! " << monster.getName() << "에게 " << damage << "딜을 주었습니다." << endl << endl;
            }

            // 몬스터의 체력을 감소시키고 체력이 0 이하로 떨어졌는지 확인.
            monster.takeDamage(damage);
            cout << monster.getName() << "의 체력이 " << monster.getHP() << "만큼 남았습니다!!" << endl << endl;

            if (monster.isDefeated()) {
                cout << monster.getName() << "을(를) 물리쳤습니다!" << endl << endl;
                cout << "요정 박시우가 당신에게 골드를 줍니다!!" << endl;
                fairy.giveGoldFromMonster(monster);
                Character::Gold += fairy.getGold();
                cout << "플레이어의 현재 골드 : " << Character::get_Gold() << endl;
                break; // 전투 종료
            }
            else {
                int characterHP = Character::HP;
                int characterDefense = Character::Defense;
                monster.Go_battle(characterHP, characterDefense, *this); // 몬스터의 공격
                Character::HP = characterHP;
                if (characterHP <= 0) {
                    cout << "플레이어가 패배했습니다..." << endl;
                    exit(0); // 전투 종료
                }
            }
            
            cout << "카드를 다시 뽑습니다." << endl;
            player_card.clear(); // 기존 카드 초기화
            draw_card(); // 새로운 카드 뽑기
            std::vector<Card> additionalCards = fairy.giveCards();
            receiveAdditionalCards(additionalCards);
        }
        //족보 체크 선택했을때
        else if (s == 2) {
            string result = jk.check(player_card);
            cout << result << endl;
        }
        else {
            cout << "잘못된 선택입니다. 다시 선택하세요." << endl;
        }
    }

    // 루프 밖에서 추가로 처리할 필요가 있는 경우를 제거
    if (Character::HP <= 0) {
        cout << "플레이어가 패배했습니다..." << endl;
        exit(0);
    }

    if (!first_monster_defeated && monster.isDefeated()) {
        cout << endl << "**************************************" << endl;
        cout << endl << "아니 골드가 대충 금 100배 정도라고??" << endl;
        cout << "이러면 나 도박 다시 할 수 있는거 아니야?" << endl;
        cout << "일확천금의 기회가 나에게 온거다..가자" << endl << endl;
        cout << "**************************************" << endl << endl;
        first_monster_defeated = true;
    }
}


void Character_Select::enhance() {
    while (true) {
        cout << endl << "강화할 스탯을 선택하여 주십시오 (현제 플레이어 골드:" << Character::Gold <<")" << endl;
        cout << "1. 공격력(+3)\t 2. HP(+10씩 누적증가)\t 3. 방어력(+2)\t 4. 스탯 확인 (강화종료 : 0) >>" << endl;
        int c;
        cin >> c;
        switch (c) {
        case 1:
            Character::enhance_Attack();
            break;
        case 2:
            Character::enhance_HP();
            break;
        case 3:
            Character::enhance_Defense();
            break;
        case 4:
            Character::show_stats();
            break;
        case 0:
            return;		// 함수 종료
        default:
            cout << "잘못된 입력입니다. 다시 선택해주세요." << endl;
        }
    }
}

int Character_Select::returning() {
    if (Character::Gold == 300)// 다모으면
    {
        cout << "************************************" << endl;
        cout << "			 축하합니다!!!			 " << endl;
        cout << "  골드를 다모아서 귀환하게 되었습니다. " << endl;
        cout << "************************************" << endl;
        return 0;
    }
    return -1;
}