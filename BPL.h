#include <iostream>
#ifndef BPL_H
#define BPL_H

using namespace std;

struct team
{
    string teamName;
    struct player* forward1;
    struct player* forward2;
    struct player* forward3;
    struct player* mid1;
    struct player* mid2;
    struct player* mid3;
    struct player* mid4;
    struct player* mid5;
    struct player* def1;
    struct player* def2;
    struct player* def3;
    struct player* def4;
    struct player* def5;
    struct player* gk1;
    struct player* gk2;
};

struct player
{
    string team;
    string number;
    string name;
    string pos;
    string born;
    string international;
    int played;
    int goals;
    int yellows;
    int reds;
    string status;
    string av;
    player *prev;
    player *next;

    player(){};

    player(std::string initTeam,string initNumber,string initName,string initPos,string initBorn,string initInternational,int initPlayed,int initGoals,int initYellows,int initReds,string initStatus,string initAv)
    {
        team=initTeam;
        number=initNumber;
        name=initName;
        pos=initPos;
        born=initBorn;
        international=initInternational;
        played=initPlayed;
        goals=initGoals;
        yellows=initYellows;
        reds=initReds;
        status=initStatus;
        av=initAv;
    }


};

class BPL
{
    public:
        BPL();
        ~BPL();
        player* headBuilder();
        void searchPremTeam(struct player* head);
        void searchInterTeam(struct player* head);
        void searchPos(struct player* head);
        void searchName(struct player* head);
        void printLinkedPlayerList(struct player* head);
        void addplayer(struct player* head,string team,string number,string name,string pos,string born,string international,int played,int goals,int yellows,int reds,string status);
        void linkedListBubbleSortgoals(struct player* head);
        void linkedListBubbleSortreds(struct player* head);
        void linkedListBubbleSortyellows(struct player* head);
        void linkedListBubbleSortplayed(struct player* head);
        void teamRemovePlayers(struct player* head,struct team* team);
        void teamAddPlayers(struct player* head,struct team* team);
        void remNameForward1(struct player* head,struct team* team);
        void remNameForward2(struct player* head,struct team* team);
        void remNameForward3(struct player* head,struct team* team);
        void addNameForward1(struct player* head,struct team* teamName,string playername);
        void addNameForward2(struct player* head,struct team* teamName,string playername);
        void addNameForward3(struct player* head,struct team* teamName,string playername);
        void addNameMid1(struct player* head,struct team* teamName,string playername);
        void addNameMid2(struct player* head,struct team* teamName,string playername);
        void addNameMid3(struct player* head,struct team* teamName,string playername);
        void addNameMid4(struct player* head,struct team* teamName,string playername);
        void addNameMid5(struct player* head,struct team* teamName,string playername);
        void addNameDef1(struct player* head,struct team* teamName,string playername);
        void addNameDef2(struct player* head,struct team* teamName,string playername);
        void addNameDef3(struct player* head,struct team* teamName,string playername);
        void addNameDef4(struct player* head,struct team* teamName,string playername);
        void addNameDef5(struct player* head,struct team* teamName,string playername);
        void addNameGK1(struct player* head,struct team* teamName,string playername);
        void addNameGK2(struct player* head,struct team* teamName,string playername);
        void printRoster(struct team* team);
        string teamBuildingMenu(struct player* head,string teamName,int teamnum);
        string playerMarketMenu(struct player* head);
        string displayLeagueMenu(struct player* head);
    protected:
    private:
        player *tail;
};

#endif // BPL_H
