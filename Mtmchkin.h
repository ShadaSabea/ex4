#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <string>
#include <deque>
#include <memory>
#include "./Cards/Card.h"
#include "./Cards/Goblin.h"
#include "./Cards/Fairy.h"
#include "./Cards/Merchant.h"
#include "./Cards/Barfight.h"
#include "./Cards/Vampire.h"
#include "./Cards/Dragon.h"
#include "./Cards/Pitfall.h"
#include "./Cards/Treasure.h"

#include "./Players/Wizard.h"
#include "./Players/Rogue.h"
#include "./Players/Fighter.h"

#include <iostream>

#include <functional>
#include <memory>


class Mtmchkin{

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    int m_numOfRounds;
    std::deque<std::unique_ptr<Card>> m_cards;
    std::deque<std::unique_ptr<Player>> m_players;
    std::deque<std::unique_ptr<Player>> m_winners;
    std::deque<std::unique_ptr<Player>> m_losers;



    const char *const goblinStr= "Goblin";
    const char *const vampireStr= "Vampire";
    const char *const dragonStr= "Dragon";
    const char *const merchantStr= "Merchant";
    const char *const treasureStr= "Treasure";
    const char *const pitfallStr= "Pitfall";
    const char *const barfightStr="Barfight";
    const char *const fairyStr= "Fairy";
    const char *const roguestr= "Rogue";
    const char *const wizardstr= "Wizard";
    const char *const fighterStr= "Fighter";
    static const int invalidplayer=0;
    static const int valid=1;
    static const int invalidClass=2;




    bool isPureInteger(const std::string& str);
    bool checkCard(const std::string& cardName);
    bool checkClass(const std::string& className);
    bool checkPlayerName(const std::string& name);
    int checkPlayer(const std::string& str);
    void buildCard(const std::string& str);
    void buildPlayer(const std::string& name ,const std::string& job);





};



#endif /* MTMCHKIN_H_ */
