#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include "Character_Select.h"
#include "Fairy.h"

using namespace std;
// ���ΰ��� ������ Ŭ���� �Լ��� ����

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
    cout << "�ɾ����....." << endl;
    srand(0); // srand() �Լ��� �� ���� ȣ���ϰ� �õ� ���� 0���� ����

    int n = rand() % 2;
    while (n != 1) { // 20�ۼ�Ʈ Ȯ���� ���͸� �����ϵ��� ����
        cout << "������ �ɾ����....." << endl << endl;
        n = rand() % 2;
    }

    cout << "���� ������ ������ ���......" << endl << endl;

    walkcnt++;		// ���͸� ���� ������ Ƚ�� ����
}



void Character_Select::receiveAdditionalCards(const vector<Card>& additionalCards) {
    for (const auto& card : additionalCards) {
        player_card.push_back(cardToPair(card));
    }
}


void Character_Select::battle(Monster& monster) {
    Fairy fairy;
    std::cout << monster.getName() << "��(��)�� ������ ���۵˴ϴ�!" << endl;
  
     // �÷��̾��� ī�带 ���� ����
    std::vector<Card> additionalCards = fairy.giveCards();
   
    receiveAdditionalCards(additionalCards);
    

    //���� ��ü ����
    jokbo jk;

    //�÷��̾��� ���� Ȯ��
    std::string result = jk.check(player_card);

    bool canAttemptEscape = true; // �������� �õ� ���� ����

    while ((!monster.isDefeated()) && (Character::HP > 0)) {
        cout << endl;
        cout << "<�������� �Է����ּ���>" << endl;
        if (canAttemptEscape) {
            cout << "1. �����ϱ�\t 2. ���� �˻��ϱ�\t 3. ��������(25%)>>" << endl;
        }
        else {
            cout << "1. �����ϱ�\t 2. ���� �˻��ϱ�>>" << endl;
        }
        int s;
        cin >> s;

        if (canAttemptEscape && s == 3) {
            srand((unsigned)time(NULL));
            int r = rand() % 4;
            if (r == 3) {
                cout << monster.getName() << "(��)�κ��� �����ƽ��ϴ�...!" << endl;
                return; // ���� ����, �ɾ�� ���·� ���ư�
            }
            else {
                cout << monster.getName() << "(��)�κ��� ����ġ�� ���߽��ϴ�...!" << endl;
                canAttemptEscape = false; // �������⿡ ������ ���, �� �̻� �õ��� �� ����
                continue; // ���� �������� �������� �ɼ��� �������� ����
            }
        }

        if (s == 1) {
            cout << endl;
            cout << monster.getName() << "���� ������ �����Ͽ����ϴ�!" << endl;
            int damage = 0;
            string result = jk.check(player_card);
            if (result == "Royal Straight Flush") {
                damage = 150 + Character::Attack;
                cout << "�ξ� ��Ʈ����Ʈ �÷���! " << monster.getName() << "���� " << damage << "���� �־����ϴ�." << endl << endl;
            }
            else if (result == "Straight Flush") {
                damage = 30 + Character::Attack;
                cout << "��Ʈ����Ʈ �÷���! " << monster.getName() << "���� " << damage << "���� �־����ϴ�." << endl << endl;
            }
            else if (result == "Four of a kind") {
                damage = 25 + Character::Attack;
                cout << "��ī��! " << monster.getName() << "���� " << damage << "���� �־����ϴ�." << endl << endl;
            }
            else if (result == "Full house") {
                damage = 20 + Character::Attack;
                cout << "Ǯ�Ͽ콺! " << monster.getName() << "���� " << damage << "���� �־����ϴ�." << endl << endl;
            }
            else if (result == "Flush") {
                damage = 15 + Character::Attack;
                cout << "�÷���! " << monster.getName() << "���� " << damage << "���� �־����ϴ�." << endl << endl;
            }
            else if (result == "Straight") {
                damage = 10 + Character::Attack;
                cout << "��Ʈ����Ʈ! " << monster.getName() << "���� " << damage << "���� �־����ϴ�." << endl << endl;
            }
            else if (result == "Three of a kind") {
                damage = 8 + Character::Attack;
                cout << "Ʈ����! " << monster.getName() << "���� " << damage << "���� �־����ϴ�." << endl << endl;
            }
            else if (result == "Two pair") {
                damage = 6 + Character::Attack;
                cout << "�����! " << monster.getName() << "���� " << damage << "���� �־����ϴ�." << endl << endl;
            }
            else if (result == "One pair") {
                damage = 3 + Character::Attack;
                cout << "�����! " << monster.getName() << "���� " << damage << "���� �־����ϴ�." << endl << endl;
            }
            else if (result == "High card") {
                damage = 1 + Character::Attack;
                cout << "����ī��! " << monster.getName() << "���� " << damage << "���� �־����ϴ�." << endl << endl;
            }

            // ������ ü���� ���ҽ�Ű�� ü���� 0 ���Ϸ� ���������� Ȯ��.
            monster.takeDamage(damage);
            cout << monster.getName() << "�� ü���� " << monster.getHP() << "��ŭ ���ҽ��ϴ�!!" << endl << endl;

            if (monster.isDefeated()) {
                cout << monster.getName() << "��(��) �����ƽ��ϴ�!" << endl << endl;
                cout << "���� �ڽÿ찡 ��ſ��� ��带 �ݴϴ�!!" << endl;
                fairy.giveGoldFromMonster(monster);
                Character::Gold += fairy.getGold();
                cout << "�÷��̾��� ���� ��� : " << Character::get_Gold() << endl;
                break; // ���� ����
            }
            else {
                int characterHP = Character::HP;
                int characterDefense = Character::Defense;
                monster.Go_battle(characterHP, characterDefense, *this); // ������ ����
                Character::HP = characterHP;
                if (characterHP <= 0) {
                    cout << "�÷��̾ �й��߽��ϴ�..." << endl;
                    exit(0); // ���� ����
                }
            }
            
            cout << "ī�带 �ٽ� �̽��ϴ�." << endl;
            player_card.clear(); // ���� ī�� �ʱ�ȭ
            draw_card(); // ���ο� ī�� �̱�
            std::vector<Card> additionalCards = fairy.giveCards();
            receiveAdditionalCards(additionalCards);
        }
        //���� üũ ����������
        else if (s == 2) {
            string result = jk.check(player_card);
            cout << result << endl;
        }
        else {
            cout << "�߸��� �����Դϴ�. �ٽ� �����ϼ���." << endl;
        }
    }

    // ���� �ۿ��� �߰��� ó���� �ʿ䰡 �ִ� ��츦 ����
    if (Character::HP <= 0) {
        cout << "�÷��̾ �й��߽��ϴ�..." << endl;
        exit(0);
    }

    if (!first_monster_defeated && monster.isDefeated()) {
        cout << endl << "**************************************" << endl;
        cout << endl << "�ƴ� ��尡 ���� �� 100�� �������??" << endl;
        cout << "�̷��� �� ���� �ٽ� �� �� �ִ°� �ƴϾ�?" << endl;
        cout << "��Ȯõ���� ��ȸ�� ������ �°Ŵ�..����" << endl << endl;
        cout << "**************************************" << endl << endl;
        first_monster_defeated = true;
    }
}


void Character_Select::enhance() {
    while (true) {
        cout << endl << "��ȭ�� ������ �����Ͽ� �ֽʽÿ� (���� �÷��̾� ���:" << Character::Gold <<")" << endl;
        cout << "1. ���ݷ�(+3)\t 2. HP(+10�� ��������)\t 3. ����(+2)\t 4. ���� Ȯ�� (��ȭ���� : 0) >>" << endl;
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
            return;		// �Լ� ����
        default:
            cout << "�߸��� �Է��Դϴ�. �ٽ� �������ּ���." << endl;
        }
    }
}

int Character_Select::returning() {
    if (Character::Gold == 300)// �ٸ�����
    {
        cout << "************************************" << endl;
        cout << "			 �����մϴ�!!!			 " << endl;
        cout << "  ��带 �ٸ�Ƽ� ��ȯ�ϰ� �Ǿ����ϴ�. " << endl;
        cout << "************************************" << endl;
        return 0;
    }
    return -1;
}