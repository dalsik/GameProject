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
    cout << "#                       홀덤 RPG                      #\n";
    cout << "#                                                     #\n";
    cout << "#######################################################\n" << endl;
    cout << endl << endl;


    // 게임 스토리 여기에 추가 
    cout << "나는 응애맨이다." << endl;
    cout << "직업은 도박사, 취미는 도박이지만 잘하는 것도 도박이다." << endl;
    cout << "그런데 어제 도박하다 꼴아버렸다...." << endl;
    cout << "빚도 엄청 많은데.." << endl;
    cout << "그냥 뛰어들자!" << endl;
    cout << endl;
    cout << "---삐이이익!---" << endl;
    cout << "   쾅!" << endl;
    cout << endl;
    cout << "익숙한 천장이 아니다.." << endl;
    cout << "아니, 여긴 어딘건데.." << endl;
    cout << "트럭...천장..이세계로구나!" << endl;
    cout << endl;

    cout << "뭔가 본능적으로 여기 보스를 잡으면 돌아갈 수 있을 것 같아!" << endl;
    Character_Select p1;				// 플레이어1 생성	
    while (true) {
        if (p1.get_walkcnt() < 5) {
            cout << "<선택지를 입력해 주세요>" << endl;
            cout << "1. 걸어가기\t 2. 강화하기\t (임시종료 : -1)>> ";
            cout << "걸어간 횟수 :" << p1.get_walkcnt() << endl;
        }
        else {
            cout << endl;
            cout << "지금부터 보스를 만나러 갈 수 있는 선택지가 추가 됩니다." << endl << endl;
            cout << "<선택지를 입력해 주세요>" << endl;
            cout << "1. 걸어가기\t 2. 강화하기\t 3. 보스 만나러 가기 (임시종료:-1)>> ";
        }

        int n;
        cin >> n;

        if (n == -1) {
            cout << "게임을 종료합니다." << endl;
            break;
        }

        if (n == 1) {
            p1.player_card.clear();
            p1.card();                    // 카드 매핑
            p1.draw_card();                // 카드 뽑기
            p1.reroll();                    // 카드 리롤 유무
            p1.walking();                // 주인공 걸어가는 중 몬스터 조우
            Monster monster = Monster::createRandomMonster();
            if (monster.getName() == "고블린") {
                std::cout << "***********************************************" << std::endl;
                std::cout << "*                                             *" << std::endl;
                std::cout << "*              고블린이 나타났다!             *" << std::endl;
                std::cout << "*                                             *" << std::endl;
                std::cout << "*              _______________                *" << std::endl;
                std::cout << "*             /               \\               *" << std::endl;
                std::cout << "*            /    _________    \\              *" << std::endl;
                std::cout << "*           /    /         \\    \\             *" << std::endl;
                std::cout << "*          /    /           \\    \\            *" << std::endl;
                std::cout << "*          |   |             |   |            *" << std::endl;
                std::cout << "*          |   |    O   O    |   |            *" << std::endl;
                std::cout << "*          |   |      ∇      |   |            *" << std::endl;
                std::cout << "*          |    \\    \\_/    /    |            *" << std::endl;
                std::cout << "*           \\    \\_________/    /             *" << std::endl;
                std::cout << "*            \\                 /              *" << std::endl;
                std::cout << "*             \\_______________/               *" << std::endl;
                std::cout << "*                                             *" << std::endl;
                std::cout << "***********************************************" << std::endl;
                std::cout << endl;
            }

            else if (monster.getName() == "미믹") {
                //미믹

                std::cout << "*****************************************" << endl;
                std::cout << "*                                       *" << endl;
                std::cout << "*          미믹이 나타났다!!            *" << endl;
                std::cout << "*    ______________________________     *" << endl;
                std::cout << "*   /           ㅇ   ㅇ            |_   *" << endl;
                std::cout << "*  |    ___________ㅅ________________|  *" << endl;
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

            else if (monster.getName() == "황금슬라임") {
                //슬라임

                cout << "*****************************************" << endl;
                cout << "*                                       *" << endl;
                cout << "*        황금 슬라임이 나타났다!!       *" << endl;
                cout << "*             ___                       *" << endl;
                cout << "*            /   \\                      *" << endl;
                cout << "*           ㅇ   /\\                     *" << endl;
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
                //보스

                cout << "#########################################" << endl;
                cout << "#                                       #" << endl;
                cout << "#            킹 황금 고블린             #" << endl;
                cout << "#                                       #" << endl;
                cout << "#########################################" << endl;
                cout << "#                                       #" << endl;
                cout << "#                     △_△_△          #" << endl;
                cout << "#            . ／---\\             #" << endl;
                cout << "#             / O   O\\            #" << endl;
                cout << "#             ＿ノ \\  V  ノ＼＿        #" << endl;
                cout << "#             / /   ^ Y ^  \\  \\      #" << endl;
                cout << "#            ( ( __________)   )       #" << endl;
                cout << "#            |  ) ㅅ | ㅅ (    |      #" << endl;
                cout << "#             \\________ㅅ_______／        #" << endl;
                cout << "#             ｜(  王  )〈            #" << endl;
                cout << "#             / `---―   \\         #" << endl;
                cout << "#            /   \\_／  \\          #" << endl;
                cout << "#             ｜        |           #" << endl;


            }
            p1.battle(monster);
        }
        else if (n == 2) {
            cout << "<현재 가지고 있는 골드 : " << p1.get_Gold() << " 원>" << endl;
            p1.enhance();
        }
        else if (p1.get_walkcnt() >= 5 && n == 3) {
            // 보스 만나러 가는 코드 출력
            cout << endl << endl;
            cout << "BBBBB   OOO  SSSS  SSSS" << endl;
            cout << "B    B O   O S     S    " << endl;
            cout << "BBBBB  O   O  SSS   SSS " << endl;
            cout << "B    B O   O     S     S" << endl;
            cout << "BBBBB   OOO  SSSS  SSSS " << endl;
            cout << endl;
            cout << "보스와의 전투가 시작됩니다!" << endl;

            p1.player_card.clear(); // 보스 전투 전에 플레이어의 카드 초기화
            p1.card(); // 카드 매핑
            p1.draw_card(); // 카드 뽑기
            p1.reroll(); // 카드 리롤 유무

            Monster boss = Monster::createBossMonster(); // 보스 몬스터 생성
            p1.battle(boss); // 플레이어와 보스 전투

            if (p1.getHP() <= 0) {
                cout << "패배했습니다. 게임을 종료합니다." << endl;
                return 0;
            }
            else {
                cout << "보스를 이겼습니다!" << endl;
                cout << "나는 이제 돌아가겠다...부자가 됬으니까!" << endl;
                cout << "집에 가자!" << endl;
                break;
            }
        }
    }

    return 0;
}