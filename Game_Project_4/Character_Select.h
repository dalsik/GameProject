#pragma once

#include "Character.h"
#include "jokbo.h"
#include "Monster.h"
#include "Fairy.h"
#include <vector>
#include <string>
#include <utility>

class jb;

class Character_Select : public Character {
    friend class jb;
protected:
    static int walkcnt;
    bool first_monster_defeated;
public:
    Character_Select() : first_monster_defeated(false) {}
    void select_Menu();
    void walking();
    void battle(Monster& monster);
    void enhance();
    int returning();
    void getDeck();
    static int get_walkcnt();
    void receiveAdditionalCards(const std::vector<Card>& additionalCards);
};

inline std::pair<std::string, std::string> cardToPair(const Card& card) {
    return std::make_pair(card.number, card.suit);
}
