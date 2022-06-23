[1:34 pm, 23/06/2022] Shada Sabea: //
// Created by Shada Sabea on 19/06/2022.
//
#include "Mtmchkin.h"

using std::string;

bool Mtmchkin::isPureInteger(const string& str)
{
    for(unsigned int i=0;i<str.length();i++)
    {
        if((std::isalpha(str[i])))
        {
            return false;
        }
    }
    return true;
}

bool Mtmchkin::checkCard(const std::string &cardName)
{
    if(cardName!=goblinStr &&cardName!=vampireStr&&cardName!=dragonStr &&cardName!=merchantStr&&
       cardName!=treasureStr&&cardName!=pitfallStr&&cardName!=barfightStr&&cardName!=fairyStr) {
        return false;
    }
    return true;
}

bool  Mtmchkin::checkClass(const std::string &className)
{
    if(className!= roguestr && className!=wizardstr && className!=fighterStr ) {
        return false;
    }
    return true;

}

bool Mtmchkin::checkPlayerName(const std::string &name)
{
    if(name.length()>15)
    {
        return false;
    }

    for(unsigned int i=0;i<name.length();i++)
    {
        if(!(std::isalpha(name[i])))
        {
            return false;
        }
    }
    return true;
}


int  Mtmchkin::checkPlayer(const std::string &str)
{
    int num =str.find(' ');
    string playerName=str.substr(0,num);
    if(!checkPlayerName(playerName))
        return invalidplayer;

    string playerClass=str.substr(num+1);
    if(!checkClass(playerClass))
        return invalidClass;

    return valid;


}

void Mtmchkin::buildCard(const std::string &line)
{
    if (line == goblinStr) {
        std::unique_ptr<Card> temp(new Goblin());
        m_cards.push_back(std::move(temp));

    }
    if (line == vampireStr) {
        std::unique_ptr<Card> temp(new Vampire());
        m_cards.push_back(std::move(temp));
    }
    if (line == dragonStr) {
        std::unique_ptr<Card> temp(new Dragon());
        m_cards.push_back(std::move(temp));
    }
    if (line == merchantStr) {
        std::unique_ptr<Card> temp(new Merchant());
        m_cards.push_back(std::move(temp));
    }
    if (line == treasureStr) {
        std::unique_ptr<Card> temp(new Treasure());
        m_cards.push_back(std::move(temp));
    }
    if (line == pitfallStr) {
        std::unique_ptr<Card> temp(new Pitfall());
        m_cards.push_back(std::move(temp));
    }
    if (line == barfightStr) {
        std::unique_ptr<Card> temp(new Barfight());
        m_cards.push_back(std::move(temp));
    }
    if (line == fairyStr) {
        std::unique_ptr<Card> temp(new Fairy());
        m_cards.push_back(std::move(temp));
    }
}

void Mtmchkin::buildPlayer(const std::string& name ,const std::string &job)
{

    if(job==wizardstr)
    {
        std::unique_ptr<Player> temp1(new Wizard(name.c_str()));
        m_players.push_back(std::move(temp1));
    }
    if(job==roguestr)
    {
        std::unique_ptr<Player> temp2(new Rogue(name.c_str()));
        m_players.push_back(std::move(temp2));
    }
    if(job==fighterStr)
    {
        std::unique_ptr<Player> temp3(new Fighter(name.c_str()));
        m_players.push_back(std::move(temp3));
    }
}

Mtmchkin::Mtmchkin(const std::string &fileName)
{
    m_numOfRounds=0;
    int countLine=0,countCards=0;
    string numPlayers;
    std::ifstream source(fileName);

    if(!source)
    {
        throw DeckFileNotFound();
    }

    std::string line;
    while(std::getline(source,line))
    {
        countLine++;
        line.c_str();
        if (!checkCard(line))
        {
            std::string strCountLine= std::to_string(countLine);
            throw DeckFileFormatError(strCountLine);

        }
        countCards++;

        buildCard(line);
    }

    if(countLine<5)
    {
        throw DeckFileInvalidSize();
    }

    printStartGameMessage();
    printEnterTeamSizeMessage();
    getline(std::cin,numPlayers);
    while(!isPureInteger(numPlayers) || stoi(numPlayers)<2 || stoi(numPlayers)>6)
    {
        printInval…
[1:35 pm, 23/06/2022] Shada Sabea: #ifndef MTMCHKIN_H_
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
