#include <vector>
#include <iostream>
#include <string>
#include <random>
using namespace std;
#include "Character.h"
#include "Character_Select.h"


int main() {
    cout << "#######################################################\n";
    cout << "#                                                     #\n";
    cout << "#                       Ȧ�� RPG                      #\n";
    cout << "#                                                     #\n";
    cout << "#######################################################\n" << endl;
    cout << endl << endl;


    // ���� ���丮 ���⿡ �߰� 
    cout << "���� ���ָ��̴�." << endl;
    cout << "������ ���ڻ�, ��̴� ���������� ���ϴ� �͵� �����̴�." << endl;
    cout << "�׷��� ���� �����ϴ� �þƹ��ȴ�...." << endl;
    cout << "���� ��û ������.." << endl;
    cout << "�׳� �پ����!" << endl;
    cout << endl;
    cout << "---��������!---" << endl;
    cout << "   ��!" << endl;
    cout << endl;
    cout << "�ͼ��� õ���� �ƴϴ�.." << endl;
    cout << "�ƴ�, ���� ���ǵ�.." << endl;
    cout << "Ʈ��...õ��..�̼���α���!" << endl;
    cout << endl;

    cout << "���� ���������� ���� ������ ������ ���ư� �� ���� �� ����!" << endl;
    Character_Select p1;				// �÷��̾�1 ����	
    while (true) {
        if (p1.get_walkcnt() < 5) {
            cout << "<�������� �Է��� �ּ���>" << endl;
            cout << "1. �ɾ��\t 2. ��ȭ�ϱ�\t (�ӽ����� : -1)>> ";
            cout << "�ɾ Ƚ�� :" << p1.get_walkcnt() << endl;
        }
        else {
            cout << endl;
            cout << "���ݺ��� ������ ������ �� �� �ִ� �������� �߰� �˴ϴ�." << endl << endl;
            cout << "<�������� �Է��� �ּ���>" << endl;
            cout << "1. �ɾ��\t 2. ��ȭ�ϱ�\t 3. ���� ������ ���� (�ӽ�����:-1)>> ";
        }

        int n;
        cin >> n;

        if (n == -1) {
            cout << "������ �����մϴ�." << endl;
            break;
        }

        if (n == 1) {
            p1.player_card.clear();
            p1.card();                    // ī�� ����
            p1.draw_card();                // ī�� �̱�
            p1.reroll();                    // ī�� ���� ����
            p1.walking();                // ���ΰ� �ɾ�� �� ���� ����
            Monster monster = Monster::createRandomMonster();
            if (monster.getName() == "���") {
                std::cout << "***********************************************" << std::endl;
                std::cout << "*                                             *" << std::endl;
                std::cout << "*              ����� ��Ÿ����!             *" << std::endl;
                std::cout << "*                                             *" << std::endl;
                std::cout << "*              _______________                *" << std::endl;
                std::cout << "*             /               \\               *" << std::endl;
                std::cout << "*            /    _________    \\              *" << std::endl;
                std::cout << "*           /    /         \\    \\             *" << std::endl;
                std::cout << "*          /    /           \\    \\            *" << std::endl;
                std::cout << "*          |   |             |   |            *" << std::endl;
                std::cout << "*          |   |    O   O    |   |            *" << std::endl;
                std::cout << "*          |   |      ��      |   |            *" << std::endl;
                std::cout << "*          |    \\    \\_/    /    |            *" << std::endl;
                std::cout << "*           \\    \\_________/    /             *" << std::endl;
                std::cout << "*            \\                 /              *" << std::endl;
                std::cout << "*             \\_______________/               *" << std::endl;
                std::cout << "*                                             *" << std::endl;
                std::cout << "***********************************************" << std::endl;
                std::cout << endl;
            }

            else if (monster.getName() == "�̹�") {
                //�̹�

                std::cout << "*****************************************" << endl;
                std::cout << "*                                       *" << endl;
                std::cout << "*          �̹��� ��Ÿ����!!            *" << endl;
                std::cout << "*    ______________________________     *" << endl;
                std::cout << "*   /           ��   ��            |_   *" << endl;
                std::cout << "*  |    ___________��________________|  *" << endl;
                std::cout << "*  |   /    \\/  \\/  \\/ \\/ \\/   \\/    /  *" << endl;
                std::cout << "*  |  /                             /   *" << endl;
                std::cout << "*  | /                             /    *" << endl;
                std::cout << "*  |/         _________           /     *" << endl;
                std::cout << "*  /         \\     \\     \\       /      *" << endl;
                std::cout << "*  |__________\\     \\     \\_______\\     *" << endl;
                std::cout << "*  |           \\     \\     \\       \\    *" << endl;
                std::cout << "*  |            |     |    |        |   *" << endl;
                std::cout << "*  |            |     |    |        |   *" << endl;
                std::cout << "*  |             \\          \\       |   *" << endl;
                std::cout << "*  |              -----------       |   *" << endl;
                std::cout << "*  __________________________________   *" << endl;
                std::cout << "*                                       *" << endl;
                std::cout << "*****************************************" << endl << endl;
            }

            else if (monster.getName() == "Ȳ�ݽ�����") {
                //������

                cout << "*****************************************" << endl;
                cout << "*                                       *" << endl;
                cout << "*        Ȳ�� �������� ��Ÿ����!!       *" << endl;
                cout << "*             ___                       *" << endl;
                cout << "*            /   \\                      *" << endl;
                cout << "*           ��   /\\                     *" << endl;
                cout << "*              /    \\                   *" << endl;
                cout << "*           --         --               *" << endl;
                cout << "*         /              \\              *" << endl;
                cout << "*       -        O    O     -           *" << endl;
                cout << "*    __/             t      \\__         *" << endl;
                cout << "*      \\           t  t     /           *" << endl;
                cout << "*       \\__________________/            *" << endl;
                cout << "*                                       *" << endl;
                cout << "*****************************************" << endl << endl;
            }

            else {
                //����

                cout << "#########################################" << endl;
                cout << "#                                       #" << endl;
                cout << "#            ŷ Ȳ�� ���             #" << endl;
                cout << "#                                       #" << endl;
                cout << "#########################################" << endl;
                cout << "#                                       #" << endl;
                cout << "#                     ��_��_��          #" << endl;
                cout << "#            . ��---\\             #" << endl;
                cout << "#             / O   O\\            #" << endl;
                cout << "#             �߫� \\  V  �Ρ���        #" << endl;
                cout << "#             / /   ^ Y ^  \\  \\      #" << endl;
                cout << "#            ( ( __________)   )       #" << endl;
                cout << "#            |  ) �� | �� (    |      #" << endl;
                cout << "#             \\________��_______��        #" << endl;
                cout << "#             ��(  ��  )��            #" << endl;
                cout << "#             / `---��   \\         #" << endl;
                cout << "#            /   \\_��  \\          #" << endl;
                cout << "#             ��        |           #" << endl;


            }
            p1.battle(monster);
        }
        else if (n == 2) {
            cout << "<���� ������ �ִ� ��� : " << p1.get_Gold() << " ��>" << endl;
            p1.enhance();
        }
        else if (p1.get_walkcnt() >= 5 && n == 3) {
            // ���� ������ ���� �ڵ� ���
            cout << endl << endl;
            cout << "BBBBB   OOO  SSSS  SSSS" << endl;
            cout << "B    B O   O S     S    " << endl;
            cout << "BBBBB  O   O  SSS   SSS " << endl;
            cout << "B    B O   O     S     S" << endl;
            cout << "BBBBB   OOO  SSSS  SSSS " << endl;
            cout << endl;
            cout << "�������� ������ ���۵˴ϴ�!" << endl;

            p1.player_card.clear(); // ���� ���� ���� �÷��̾��� ī�� �ʱ�ȭ
            p1.card(); // ī�� ����
            p1.draw_card(); // ī�� �̱�
            p1.reroll(); // ī�� ���� ����

            Monster boss = Monster::createBossMonster(); // ���� ���� ����
            p1.battle(boss); // �÷��̾�� ���� ����

            if (p1.getHP() <= 0) {
                cout << "�й��߽��ϴ�. ������ �����մϴ�." << endl;
                return 0;
            }
            else {
                cout << "������ �̰���ϴ�!" << endl;
                cout << "���� ���� ���ư��ڴ�...���ڰ� �����ϱ�!" << endl;
                cout << "���� ����!" << endl;
                break;
            }
        }
    }

    return 0;
}