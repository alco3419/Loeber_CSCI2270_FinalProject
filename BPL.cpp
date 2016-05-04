#include "BPL.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <cctype>

using namespace std;

BPL::BPL()
{
    tail=NULL;
}

BPL::~BPL()
{
    //dtor
}

void BPL::addplayer(struct player* head,string team,string number,string name,string pos,string born,string international,int played,int goals,int yellows,int reds,string status)
{
    string av="yes";
    player* inserter=new player(team,number,name,pos,born,international,played,goals,yellows,reds,status,av);
    player* blah=head;
    while(blah->next!=NULL)
    {
        blah=blah->next;
    }
    inserter->prev=blah;
    inserter->next=NULL;
    blah->next=inserter;
}

void BPL::printLinkedPlayerList(struct player* head)
{
    if(head!=NULL)
    {
        player* tmp=head;
        cout<<"PLAYERS"<<endl;
        cout<<"NULL <- ";
        while(tmp->next!=NULL)
        {
            cout<<tmp->name<<" <-> ";
            tmp=tmp->next;
        }
        cout<<tmp->name<<" -> NULL"<<endl;
    }
}

void BPL::linkedListBubbleSortplayed(struct player*head)
{
    {
    int counter=0;
    player *start=head;
    while(start->next!=NULL)
    {
        counter++;
        start=start->next;
    }
    if(head==NULL)
    {
        return;
    }
    if(head->next==NULL)
    {
        return;
    }
    else
    {
        player *current=head;
        player *previous=NULL;
        player *temp=NULL;
        int changeFlag=0;
        for(int i=0;i<counter;i++)
        {
            while(current->next!=NULL)
            {
                temp=current->next;
                if(current->played<temp->played)
                {
                    changeFlag=1;
                    current->next=temp->next;
                    temp->next=current;
                    if(previous!=NULL)
                    {
                        previous->next=temp;
                    }
                    previous=temp;
                    if(head==current)
                    {
                        head=temp;
                    }
                    if(current->next==NULL)
                    {
                        tail=current;
                    }
                }
                else
                {
                    previous=current;
                    current=current->next;
                }
            }
            if(changeFlag==0)
            {
                break;
            }
            else
            {
                previous=NULL;
                current=head;
                changeFlag=0;
            }
        }
    }
    player *printhead=head;
    int n=1;
    cout<<"======MOST PLAYED (ALL TIME)======"<<endl;
    cout<<n<<". "<<printhead->name<<" "<<printhead->played<<endl;
    printhead=printhead->next;
    n++;
    while(printhead!=NULL)
    {
        cout<<n<<". "<<printhead->name<<" "<<printhead->played<<endl;
        n++;
        printhead=printhead->next;
    }
}
}

void BPL::linkedListBubbleSortreds(struct player* head)
{
    {
    int counter=0;
    player *start=head;
    while(start->next!=NULL)
    {
        counter++;
        start=start->next;
    }
    if(head==NULL)
    {
        return;
    }
    if(head->next==NULL)
    {
        return;
    }
    else
    {
        player *current=head;
        player *previous=NULL;
        player *temp=NULL;
        int changeFlag=0;
        for(int i=0;i<counter;i++)
        {
            while(current->next!=NULL)
            {
                temp=current->next;
                if(current->reds<temp->reds)
                {
                    changeFlag=1;
                    current->next=temp->next;
                    temp->next=current;
                    if(previous!=NULL)
                    {
                        previous->next=temp;
                    }
                    previous=temp;
                    if(head==current)
                    {
                        head=temp;
                    }
                    if(current->next==NULL)
                    {
                        tail=current;
                    }
                }
                else
                {
                    previous=current;
                    current=current->next;
                }
            }
            if(changeFlag==0)
            {
                break;
            }
            else
            {
                previous=NULL;
                current=head;
                changeFlag=0;
            }
        }
    }
    player *printhead=head;
    int n=1;
    cout<<"======MOST RED CARDS (ALL TIME)======"<<endl;
    cout<<n<<". "<<printhead->name<<" "<<printhead->reds<<endl;
    printhead=printhead->next;
    n++;
    while(printhead!=NULL)
    {
        cout<<n<<". "<<printhead->name<<" "<<printhead->reds<<endl;
        n++;
        printhead=printhead->next;
    }
}
}

void BPL::linkedListBubbleSortyellows(struct player* head)
{
    {
    int counter=0;
    player *start=head;
    while(start->next!=NULL)
    {
        counter++;
        start=start->next;
    }
    if(head==NULL)
    {
        return;
    }
    if(head->next==NULL)
    {
        return;
    }
    else
    {
        player *current=head;
        player *previous=NULL;
        player *temp=NULL;
        int changeFlag=0;
        for(int i=0;i<counter;i++)
        {
            while(current->next!=NULL)
            {
                temp=current->next;
                if(current->yellows<temp->yellows)
                {
                    changeFlag=1;
                    current->next=temp->next;
                    temp->next=current;
                    if(previous!=NULL)
                    {
                        previous->next=temp;
                    }
                    previous=temp;
                    if(head==current)
                    {
                        head=temp;
                    }
                    if(current->next==NULL)
                    {
                        tail=current;
                    }
                }
                else
                {
                    previous=current;
                    current=current->next;
                }
            }
            if(changeFlag==0)
            {
                break;
            }
            else
            {
                previous=NULL;
                current=head;
                changeFlag=0;
            }
        }
    }
    player *printhead=head;
    int n=1;
    cout<<"======MOST YELLOW CARDS (ALL TIME)======"<<endl;
    cout<<n<<". "<<printhead->name<<" "<<printhead->yellows<<endl;
    printhead=printhead->next;
    n++;
    while(printhead!=NULL)
    {
        cout<<n<<". "<<printhead->name<<" "<<printhead->yellows<<endl;
        n++;
        printhead=printhead->next;
    }
}
}

void BPL::linkedListBubbleSortgoals(struct player* head)
{
    int counter=0;
    player *start=head;
    while(start->next!=NULL)
    {
        counter++;
        start=start->next;
    }
    if(head==NULL)
    {
        return;
    }
    if(head->next==NULL)
    {
        return;
    }
    else
    {
        player *current=head;
        player *previous=NULL;
        player *temp=NULL;
        int changeFlag=0;
        for(int i=0;i<counter;i++)
        {
            while(current->next!=NULL)
            {
                temp=current->next;
                if(current->goals<temp->goals)
                {
                    changeFlag=1;
                    current->next=temp->next;
                    temp->next=current;
                    if(previous!=NULL)
                    {
                        previous->next=temp;
                    }
                    previous=temp;
                    if(head==current)
                    {
                        head=temp;
                    }
                    if(current->next==NULL)
                    {
                        tail=current;
                    }
                }
                else
                {
                    previous=current;
                    current=current->next;
                }
            }
            if(changeFlag==0)
            {
                break;
            }
            else
            {
                previous=NULL;
                current=head;
                changeFlag=0;
            }
        }
    }
    player *printhead=head;
    int n=1;
    cout<<"======TOP GOAL SCORERS (ALL TIME)======"<<endl;
    cout<<n<<". "<<printhead->name<<" "<<printhead->goals<<endl;
    printhead=printhead->next;
    n++;
    while(printhead!=NULL)
    {
        cout<<n<<". "<<printhead->name<<" "<<printhead->goals<<endl;
        n++;
        printhead=printhead->next;
    }
}

void BPL::teamRemovePlayers(struct player* head,struct team* team)
{
    string dpos;
    string playername;
    string fchoice;
    string mchoice;
    string dchoice;
    string gchoice;
    string for1;
    string for2;
    string for3;
    string mid1;
    string mid2;
    string mid3;
    string mid4;
    string mid5;
    string def1;
    string def2;
    string def3;
    string def4;
    string def5;
    string gk1;
    string gk2;
    cout<<"Enter Desired Position: ";
    getline(cin,dpos);
    if(dpos != "Forward" || dpos != "Midfielder" || dpos != "Defender" || dpos != "Goalkeeper") ///If the input does not match
    {
        cout<<"Not a valid position. Please check your spelling and try again."<<endl;
    }
    if(dpos=="Forward")
    {
        cout<<"Position Number? ";
        getline(cin,fchoice);
        if(fchoice=="1")
        {
            cout<<team->forward1->name<<" removed from team"<<endl;
            team->forward1->av="yes";
            team->forward1=NULL;
        }
        else if(fchoice=="2")
        {
            cout<<team->forward2->name<<" removed from team"<<endl;
            team->forward2->av="yes";
            team->forward2=NULL;
        }
        else if(fchoice=="3")
        {
            cout<<team->forward3->name<<" removed from team"<<endl;
            team->forward3->av="yes";
            team->forward3=NULL;
        }
    }
    if(dpos=="Midfielder")
    {
        cout<<"Position Number? ";
        getline(cin,mchoice);
        if(mchoice=="1")
        {
            cout<<team->mid1->name<<" removed from team"<<endl;
            team->mid1->av="yes";
            team->mid1=NULL;
        }
        else if(mchoice=="2")
        {
            cout<<team->mid2->name<<" removed from team"<<endl;
            team->mid2->av="yes";
            team->mid2=NULL;
        }
        else if(mchoice=="3")
        {
            cout<<team->mid3->name<<" removed from team"<<endl;
            team->mid3->av="yes";
            team->mid3=NULL;
        }
        else if(mchoice=="4")
        {
            cout<<team->mid4->name<<" removed from team"<<endl;
            team->mid4->av="yes";
            team->mid4=NULL;
        }
        else if(mchoice=="5")
        {
            cout<<team->mid5->name<<" removed from team"<<endl;
            team->mid5->av="yes";
            team->mid5=NULL;
        }
    }
    if(dpos=="Defender")
    {
        cout<<"Position Number? ";
        getline(cin,dchoice);
        if(dchoice=="1")
        {
            cout<<team->def1->name<<" removed from team"<<endl;
            team->def1->av="yes";
            team->def1=NULL;
        }
        else if(dchoice=="2")
        {
            cout<<team->def2->name<<" removed from team"<<endl;
            team->def2->av="yes";
            team->def2=NULL;
        }
        else if(dchoice=="3")
        {
            cout<<team->def3->name<<" removed from team"<<endl;
            team->def3->av="yes";
            team->def3=NULL;
        }
        else if(dchoice=="4")
        {
            cout<<team->def4->name<<" removed from team"<<endl;
            team->def4->av="yes";
            team->def4=NULL;
        }
        if(dchoice=="5")
        {
            cout<<team->def5->name<<" removed from team"<<endl;
            team->def5->av="yes";
            team->def5=NULL;
        }
    }
    if(dpos=="Goalkeeper")
    {
        cout<<"Position Number? ";
        getline(cin,gchoice);
        if(gchoice=="1")
        {
            cout<<team->gk1->name<<" removed from team"<<endl;
            team->gk1->av="yes";
            team->gk1=NULL;
        }
        else if(gchoice=="2")
        {
            cout<<team->gk2->name<<" removed from team"<<endl;
            team->gk2->av="yes";
            team->gk2=NULL;
        }
    }
}

void BPL::teamAddPlayers(struct player* head,struct team* team)
{
    string dpos;
    string for1;
    string for2;
    string for3;
    string mid1;
    string mid2;
    string mid3;
    string mid4;
    string mid5;
    string def1;
    string def2;
    string def3;
    string def4;
    string def5;
    string gk1;
    string gk2;
    cout<<"Enter Desired Position: ";
    getline(cin,dpos);
    if(dpos != "Forward" || dpos != "Midfielder" || dpos != "Defender" || dpos != "Goalkeeper") ///if the input does not match
    {
        cout<<"Not a valid position. Please check your spelling and try again."<<endl;
    }
    if(dpos=="Forward")
    {
        cout<<"Enter Forward 1's Name: ";
        getline(cin,for1);
        addNameForward1(head,team,for1);

        cout<<"Enter Forward 2's Name: ";
        getline(cin,for2);
        addNameForward2(head,team,for2);

        cout<<"Enter Forward 3's Name: ";
        getline(cin,for3);
        addNameForward3(head,team,for3);
    }
    if(dpos=="Midfielder")
    {
        cout<<"Enter Midfielder 1's Name: ";
        getline(cin,mid1);
        addNameMid1(head,team,mid1);

        cout<<"Enter Midfielder 2's Name: ";
        getline(cin,mid2);
        addNameMid2(head,team,mid2);

        cout<<"Enter Midfielder 3's Name: ";
        getline(cin,mid3);
        addNameMid3(head,team,mid3);

        cout<<"Enter Midfielder 4's Name: ";
        getline(cin,mid4);
        addNameMid4(head,team,mid4);

        cout<<"Enter Midfielder 5's Name: ";
        getline(cin,mid5);
        addNameMid5(head,team,mid5);

    }
    if(dpos=="Defender")
    {
        cout<<"Enter Defender 1's Name: ";
        getline(cin,def1);
        addNameDef1(head,team,def1);

        cout<<"Enter Defender 2's Name: ";
        getline(cin,def2);
        addNameDef2(head,team,def2);

        cout<<"Enter Defender 3's Name: ";
        getline(cin,def3);
        addNameDef3(head,team,def3);

        cout<<"Enter Defender 4's Name: ";
        getline(cin,def4);
        addNameDef4(head,team,def4);

        cout<<"Enter Defender 5's Name: ";
        getline(cin,def5);
        addNameDef5(head,team,def5);
    }
    if(dpos=="Goalkeeper")
    {
        cout<<"Enter Goalkeeper 1's Name: ";
        getline(cin,gk1);
        addNameGK1(head,team,gk1);

        cout<<"Enter Goalkeeper 2's Name: ";
        getline(cin,gk2);
        addNameGK2(head,team,gk2);
    }
}

void BPL::addNameForward1(struct player* head,struct team* team,string playername)
{
    player* searcher=head;
    while(searcher->next!=NULL && team->forward1==NULL)
    {
        if(searcher->name==playername && searcher->av=="yes" && searcher->pos=="Forward")
        {
            team->forward1=searcher;
            searcher->av="no";
        }
        else if(searcher->name==playername && searcher->av=="no")
        {
            cout<<"Player Already Drafted. Enter Another Forward's Name"<<endl;
            getline(cin,playername);
        }
        else if(searcher->name==playername && searcher->pos!="Forward")
        {
            cout<<"Player is not a Forward. Please Choose Another Player."<<endl;
            getline(cin,playername);
        }
        searcher=searcher->next;
    }
}

void BPL::addNameForward2(struct player* head,struct team* team,string playername)
{
    player* searcher=head;
    while(searcher->next!=NULL && team->forward2==NULL)
    {
        if(searcher->name==playername && searcher->av=="yes" && searcher->pos=="Forward")
        {
            team->forward2=searcher;
            searcher->av="no";
        }
        else if(searcher->name==playername && searcher->av=="no")
        {
            cout<<"Player Already Drafted. Enter Another Forward's Name"<<endl;
            getline(cin,playername);
        }
        else if(searcher->name==playername && searcher->pos!="Forward")
        {
            cout<<"Player is not a Forward. Please Choose Another Player."<<endl;
            getline(cin,playername);
        }
        searcher=searcher->next;
    }
}

void BPL::addNameForward3(struct player* head,struct team* team,string playername)
{
    player* searcher=head;
    while(searcher->next!=NULL && team->forward3==NULL)
    {
        if(searcher->name==playername && searcher->av=="yes" && searcher->pos=="Forward")
        {
            team->forward3=searcher;
            searcher->av="no";
        }
        else if(searcher->name==playername && searcher->av=="no")
        {
            cout<<"Player Already Drafted. Enter Another Forward's Name"<<endl;
            getline(cin,playername);
        }
        else if(searcher->name==playername && searcher->pos!="Forward")
        {
            cout<<"Player is not a Forward. Please Choose Another Player."<<endl;
            getline(cin,playername);
        }
        searcher=searcher->next;
    }
}

void BPL::addNameMid1(struct player* head,struct team* team,string playername)
{
    player* searcher=head;
    while(searcher->next!=NULL && team->mid1==NULL)
    {
        if(searcher->name==playername && searcher->av=="yes" && searcher->pos=="Midfielder")
        {
            team->mid1=searcher;
            searcher->av="no";
        }
        else if(searcher->name==playername && searcher->av=="no")
        {
            cout<<"Player Already Drafted. Enter Another Midfielder's Name"<<endl;
            getline(cin,playername);
        }
        else if(searcher->name==playername && searcher->pos!="Midfielder")
        {
            cout<<"Player is not a Midfielder. Please Choose Another Player."<<endl;
            getline(cin,playername);
        }
        searcher=searcher->next;
    }
}

void BPL::addNameMid2(struct player* head,struct team* team,string playername)
{
    player* searcher=head;
    while(searcher->next!=NULL && team->mid2==NULL)
    {
        if(searcher->name==playername && searcher->av=="yes" && searcher->pos=="Midfielder")
        {
            team->mid2=searcher;
            searcher->av="no";
        }
        else if(searcher->name==playername && searcher->av=="no")
        {
            cout<<"Player Already Drafted. Enter Another Midfielder's Name"<<endl;
            getline(cin,playername);
        }
        else if(searcher->name==playername && searcher->pos!="Midfielder")
        {
            cout<<"Player is not a Midfielder. Please Choose Another Player."<<endl;
            getline(cin,playername);
        }
        searcher=searcher->next;
    }
}

void BPL::addNameMid3(struct player* head,struct team* team,string playername)
{
    player* searcher=head;
    while(searcher->next!=NULL && team->mid3==NULL)
    {
        if(searcher->name==playername && searcher->av=="yes" && searcher->pos=="Midfielder")
        {
            team->mid3=searcher;
            searcher->av="no";
        }
        else if(searcher->name==playername && searcher->av=="no")
        {
            cout<<"Player Already Drafted. Enter Another Midfielder's Name"<<endl;
            getline(cin,playername);
        }
        else if(searcher->name==playername && searcher->pos!="Midfielder")
        {
            cout<<"Player is not a Midfielder. Please Choose Another Player."<<endl;
            getline(cin,playername);
        }
        searcher=searcher->next;
    }
}

void BPL::addNameMid4(struct player* head,struct team* team,string playername)
{
    player* searcher=head;
    while(searcher->next!=NULL && team->mid4==NULL)
    {
        if(searcher->name==playername && searcher->av=="yes" && searcher->pos=="Midfielder")
        {
            team->mid4=searcher;
            searcher->av="no";
        }
        else if(searcher->name==playername && searcher->av=="no")
        {
            cout<<"Player Already Drafted. Enter Another Midfielder's Name"<<endl;
            getline(cin,playername);
        }
        else if(searcher->name==playername && searcher->pos!="Midfielder")
        {
            cout<<"Player is not a Midfielder. Please Choose Another Player."<<endl;
            getline(cin,playername);
        }
        searcher=searcher->next;
    }
}

void BPL::addNameMid5(struct player* head,struct team* team,string playername)
{
    player* searcher=head;
    while(searcher->next!=NULL && team->mid5==NULL)
    {
        if(searcher->name==playername && searcher->av=="yes" && searcher->pos=="Midfielder")
        {
            team->mid5=searcher;
            searcher->av="no";
        }
        else if(searcher->name==playername && searcher->av=="no")
        {
            cout<<"Player Already Drafted. Enter Another Midfielder's Name"<<endl;
            getline(cin,playername);
        }
        else if(searcher->name==playername && searcher->pos!="Midfielder")
        {
            cout<<"Player is not a Midfielder. Please Choose Another Player."<<endl;
            getline(cin,playername);
        }
        searcher=searcher->next;
    }
}

void BPL::addNameDef1(struct player* head,struct team* team,string playername)
{
    player* searcher=head;
    while(searcher->next!=NULL && team->def1==NULL)
    {
        if(searcher->name==playername && searcher->av=="yes" && searcher->pos=="Defender")
        {
            team->def1=searcher;
            searcher->av="no";
        }
        else if(searcher->name==playername && searcher->av=="no")
        {
            cout<<"Player Already Drafted. Enter Another Defender's Name"<<endl;
            getline(cin,playername);
        }
        else if(searcher->name==playername && searcher->pos!="Defender")
        {
            cout<<"Player is not a Defender. Please Choose Another Player."<<endl;
            getline(cin,playername);
        }
        searcher=searcher->next;
    }
}

void BPL::addNameDef2(struct player* head,struct team* team,string playername)
{
    player* searcher=head;
    while(searcher->next!=NULL && team->def2==NULL)
    {
        if(searcher->name==playername && searcher->av=="yes" && searcher->pos=="Defender")
        {
            team->def2=searcher;
            searcher->av="no";
        }
        else if(searcher->name==playername && searcher->av=="no")
        {
            cout<<"Player Already Drafted. Enter Another Defender's Name"<<endl;
            getline(cin,playername);
        }
        else if(searcher->name==playername && searcher->pos!="Defender")
        {
            cout<<"Player is not a Defender. Please Choose Another Player."<<endl;
            getline(cin,playername);
        }
        searcher=searcher->next;
    }
}

void BPL::addNameDef3(struct player* head,struct team* team,string playername)
{
    player* searcher=head;
    while(searcher->next!=NULL && team->def3==NULL)
    {
        if(searcher->name==playername && searcher->av=="yes" && searcher->pos=="Defender")
        {
            team->def3=searcher;
            searcher->av="no";
        }
        else if(searcher->name==playername && searcher->av=="no")
        {
            cout<<"Player Already Drafted. Enter Another Defender's Name"<<endl;
            getline(cin,playername);
        }
        else if(searcher->name==playername && searcher->pos!="Defender")
        {
            cout<<"Player is not a Defender. Please Choose Another Player."<<endl;
            getline(cin,playername);
        }
        searcher=searcher->next;
    }
}

void BPL::addNameDef4(struct player* head,struct team* team,string playername)
{
    player* searcher=head;
    while(searcher->next!=NULL && team->def4==NULL)
    {
        if(searcher->name==playername && searcher->av=="yes" && searcher->pos=="Defender")
        {
            team->def4=searcher;
            searcher->av="no";
        }
        else if(searcher->name==playername && searcher->av=="no")
        {
            cout<<"Player Already Drafted. Enter Another Defender's Name"<<endl;
            getline(cin,playername);
        }
        else if(searcher->name==playername && searcher->pos!="Defender")
        {
            cout<<"Player is not a Defender. Please Choose Another Player."<<endl;
            getline(cin,playername);
        }
        searcher=searcher->next;
    }
}

void BPL::addNameDef5(struct player* head,struct team* team,string playername)
{
    player* searcher=head;
    while(searcher->next!=NULL && team->def5==NULL)
    {
        if(searcher->name==playername && searcher->av=="yes" && searcher->pos=="Defender")
        {
            team->def5=searcher;
            searcher->av="no";
        }
        else if(searcher->name==playername && searcher->av=="no")
        {
            cout<<"Player Already Drafted. Enter Another Defender's Name"<<endl;
            getline(cin,playername);
        }
        else if(searcher->name==playername && searcher->pos!="Defender")
        {
            cout<<"Player is not a Defender. Please Choose Another Player."<<endl;
            getline(cin,playername);
        }
        searcher=searcher->next;
    }
}

void BPL::addNameGK1(struct player* head,struct team* team,string playername)
{
    player* searcher=head;
    while(searcher->next!=NULL && team->gk1==NULL)
    {
        if(searcher->name==playername && searcher->av=="yes" && searcher->pos=="Goalkeeper")
        {
            team->gk1=searcher;
            searcher->av="no";
        }
        else if(searcher->name==playername && searcher->av=="no")
        {
            cout<<"Player Already Drafted. Enter Another Goalkeeper's Name"<<endl;
            getline(cin,playername);
        }
        else if(searcher->name==playername && searcher->pos!="Goalkeeper")
        {
            cout<<"Player is not a Goalkeeper. Please Choose Another Player."<<endl;
            getline(cin,playername);
        }
        searcher=searcher->next;
    }
}

void BPL::addNameGK2(struct player* head,struct team* team,string playername)
{
    player* searcher=head;
    while(searcher->next!=NULL && team->gk2==NULL)
    {
        if(searcher->name==playername && searcher->av=="yes" && searcher->pos=="Goalkeeper")
        {
            team->gk2=searcher;
            searcher->av="no";
        }
        else if(searcher->name==playername && searcher->av=="no")
        {
            cout<<"Player Already Drafted. Enter Another Goalkeeper's Name"<<endl;
            getline(cin,playername);
        }
        else if(searcher->name==playername && searcher->pos!="Goalkeeper")
        {
            cout<<"Player is not a Goalkeeper. Please Choose Another Player."<<endl;
            getline(cin,playername);
        }
        searcher=searcher->next;
    }
}

void BPL::printRoster(struct team* team)
{
    cout<<"Forwards: "<<endl;
    if(team->forward1==NULL)
    {
        cout<<"Forward 1: NULL"<<endl;
    }
    else if(team->forward1!=NULL)
    {
        cout<<team->forward1->name<<endl;
    }
    if(team->forward2==NULL)
    {
        cout<<"Forward 2: NULL"<<endl;
    }
    else if(team->forward2!=NULL)
    {
        cout<<team->forward2->name<<endl;
    }
    if(team->forward3==NULL)
    {
        cout<<"Forward 3: NULL"<<endl;
    }
    else if(team->forward3!=NULL)
    {
        cout<<team->forward3->name<<endl;
    }

    cout<<"Midfielders: "<<endl;
    if(team->mid1==NULL)
    {
        cout<<"Midfielder 1: NULL"<<endl;
    }
    else if(team->mid1!=NULL)
    {
        cout<<team->mid1->name<<endl;
    }
    if(team->mid2==NULL)
    {
        cout<<"Midfielder 2: NULL"<<endl;
    }
    else if(team->mid2!=NULL)
    {
        cout<<team->mid2->name<<endl;
    }
    if(team->mid3==NULL)
    {
        cout<<"Midfielder 3: NULL"<<endl;
    }
    else if(team->mid3!=NULL)
    {
        cout<<team->mid3->name<<endl;
    }
    if(team->mid4==NULL)
    {
        cout<<"Midfielder 4: NULL"<<endl;
    }
    else if(team->mid4!=NULL)
    {
        cout<<team->mid4->name<<endl;
    }
    if(team->mid5==NULL)
    {
        cout<<"Midfielder 5: NULL"<<endl;
    }
    else if(team->mid5!=NULL)
    {
        cout<<team->mid5->name<<endl;
    }

    cout<<"Defenders: "<<endl;
    if(team->def1==NULL)
    {
        cout<<"Defender 1: NULL"<<endl;
    }
    else if(team->def1!=NULL)
    {
        cout<<team->def1->name<<endl;
    }
    if(team->def2==NULL)
    {
        cout<<"Defender 2: NULL"<<endl;
    }
    else if(team->def2!=NULL)
    {
        cout<<team->def2->name<<endl;
    }
    if(team->def3==NULL)
    {
        cout<<"Defender 3: NULL"<<endl;
    }
    else if(team->def3!=NULL)
    {
        cout<<team->def3->name<<endl;
    }
    if(team->def4==NULL)
    {
        cout<<"Defender 4: NULL"<<endl;
    }
    else if(team->def4!=NULL)
    {
        cout<<team->def4->name<<endl;
    }
    if(team->def5==NULL)
    {
        cout<<"Defender 5: NULL"<<endl;
    }
    else if(team->def5!=NULL)
    {
        cout<<team->def5->name<<endl;
    }

    cout<<"Goalkeepers: "<<endl;
    if(team->gk1==NULL)
    {
        cout<<"Goalkeeper 1: NULL"<<endl;
    }
    else if(team->gk1!=NULL)
    {
        cout<<team->gk1->name<<endl;
    }
    if(team->gk2==NULL)
    {
        cout<<"Goalkeeper 2: NULL"<<endl;
    }
    else if(team->gk2!=NULL)
    {
        cout<<team->gk2->name<<endl;
    }

}

string BPL::teamBuildingMenu(struct player* head,string teamName,int teamnum)
{
    string buildingChoice="0";
    if(teamnum==1)
    {
        team* team1=new team;
        team1->teamName=teamName;
        while(buildingChoice!="5")
        {
            cout<<"******"<<teamName<<" Menu******"<<endl;
            cout<<"1. Add Players"<<endl;
            cout<<"2. Remove Players"<<endl;
            cout<<"3. Print Out Roster"<<endl;
            cout<<"4. Player Market"<<endl;
            cout<<"5. Return to League Menu"<<endl;
            getline(cin,buildingChoice);
            if(buildingChoice=="1")
            {
                teamAddPlayers(head,team1);
            }
            if(buildingChoice=="2")
            {
                teamRemovePlayers(head,team1);
            }
            if(buildingChoice=="3")
            {
                printRoster(team1);
            }
            if(buildingChoice=="4")
            {
                playerMarketMenu(head);
            }
        }
    }
    if(teamnum==2)
    {
        team* team2=new team;
        team2->teamName=teamName;
        while(buildingChoice!="5")
        {
            cout<<"******"<<teamName<<" Menu******"<<endl;
            cout<<"1. Add Players"<<endl;
            cout<<"2. Remove Players"<<endl;
            cout<<"3. Print Out Roster"<<endl;
            cout<<"4. Player Market"<<endl;
            cout<<"5. Return to League Menu"<<endl;
            getline(cin,buildingChoice);
            if(buildingChoice=="1")
            {
                teamAddPlayers(head,team2);
            }
            if(buildingChoice=="2")
            {
                teamRemovePlayers(head,team2);
            }
            if(buildingChoice=="3")
            {
                printRoster(team2);
            }
            if(buildingChoice=="4")
            {
                playerMarketMenu(head);
            }
        }
    }
    if(teamnum==3)
    {
        team* team3=new team;
        team3->teamName=teamName;
        while(buildingChoice!="5")
        {
            cout<<"******"<<teamName<<" Menu******"<<endl;
            cout<<"1. Add Players"<<endl;
            cout<<"2. Remove Players"<<endl;
            cout<<"3. Print Out Roster"<<endl;
            cout<<"4. Player Market"<<endl;
            cout<<"5. Return to League Menu"<<endl;
            getline(cin,buildingChoice);
            if(buildingChoice=="1")
            {
                teamAddPlayers(head,team3);
            }
            if(buildingChoice=="2")
            {
                teamRemovePlayers(head,team3);
            }
            if(buildingChoice=="3")
            {
                printRoster(team3);
            }
            if(buildingChoice=="4")
            {
                playerMarketMenu(head);
            }
        }
    }
    if(teamnum==4)
    {
        team* team4=new team;
        team4->teamName=teamName;
        while(buildingChoice!="5")
        {
            cout<<"******"<<teamName<<" Menu******"<<endl;
            cout<<"1. Add Players"<<endl;
            cout<<"2. Remove Players"<<endl;
            cout<<"3. Print Out Roster"<<endl;
            cout<<"4. Player Market"<<endl;
            cout<<"5. Return to League Menu"<<endl;
            getline(cin,buildingChoice);
            if(buildingChoice=="1")
            {
                teamAddPlayers(head,team4);
            }
            if(buildingChoice=="2")
            {
                teamRemovePlayers(head,team4);
            }
            if(buildingChoice=="3")
            {
                printRoster(team4);
            }
            if(buildingChoice=="4")
            {
                playerMarketMenu(head);
            }
        }
    }
    if(teamnum==5)
    {
        team* team5=new team;
        team5->teamName=teamName;
        while(buildingChoice!="5")
        {
            cout<<"******"<<teamName<<" Menu******"<<endl;
            cout<<"1. Add Players"<<endl;
            cout<<"2. Remove Players"<<endl;
            cout<<"3. Print Out Roster"<<endl;
            cout<<"4. Player Market"<<endl;
            cout<<"5. Return to League Menu"<<endl;
            getline(cin,buildingChoice);
            if(buildingChoice=="1")
            {
                teamAddPlayers(head,team5);
            }
            if(buildingChoice=="2")
            {
                teamRemovePlayers(head,team5);
            }
            if(buildingChoice=="3")
            {
                printRoster(team5);
            }
            if(buildingChoice=="4")
            {
                playerMarketMenu(head);
            }
        }
    }

    if(teamnum>5)
    {
        cout<<"TOO MANY TEAMS CREATED"<<endl;
        buildingChoice="7";
    }
}

string BPL::displayLeagueMenu(struct player* head)
{
    int teamnum=0;
    string leaguechoice="0";
    while(leaguechoice!="7")
    {
        cout<<"******Barclay's Premier League Fantasy Soccer******"<<endl;
        cout<<"1. Create a Team"<<endl;
        cout<<"2. Top Goal Scorers (All Time)"<<endl;
        cout<<"3. Most Yellow Cards (All Time)"<<endl;
        cout<<"4. Most Red Cards (All Time)"<<endl;
        cout<<"5. Most Played (All Time)"<<endl;
        cout<<"6. Player Market"<<endl;
        cout<<"7. Back to Main Menu"<<endl;
        getline(cin,leaguechoice);

        if(leaguechoice=="1")
        {
            teamnum++;
            string teamName;
            cout<<"Enter Team Name: "<<endl;
            getline(cin,teamName);
            teamBuildingMenu(head,teamName,teamnum);

        }

        if(leaguechoice=="2")
        {
            linkedListBubbleSortgoals(head);
        }

        if(leaguechoice=="3")
        {
            linkedListBubbleSortyellows(head);
        }

        if(leaguechoice=="4")
        {
            linkedListBubbleSortreds(head);
        }

        if(leaguechoice=="5")
        {
            linkedListBubbleSortplayed(head);
        }

        if(leaguechoice=="6")
        {
            playerMarketMenu(head);
        }

        if(leaguechoice=="7")
        {
            break;
        }

    }
    return leaguechoice;
}

string BPL::playerMarketMenu(struct player* head)
{
    string playermmenu="0";
    while(playermmenu!="5")
    {
        cout<<"******Player Market******"<<endl;
        cout<<"1. Search for Players by Premier League Team"<<endl;
        cout<<"2. Search for Players by International Team"<<endl;
        cout<<"3. Search for Players by Position"<<endl;
        cout<<"4. Search for Player by Name"<<endl;
        cout<<"5. Exit"<<endl;
        getline(cin,playermmenu);

        if(playermmenu=="1")
        {
            searchPremTeam(head);
        }

        if(playermmenu=="2")
        {
            searchInterTeam(head);
        }
        if(playermmenu=="3")
        {
            searchPos(head);
        }
        if(playermmenu=="4")
        {
            searchName(head);
        }
    }
    return playermmenu;
}

void BPL::searchPremTeam(struct player* head)
{
    string inputTeamName;
    cout<<"Enter Team Name: ";
    getline(cin,inputTeamName);

    player *searcher=head;
    while(searcher->next!=NULL)
    {
        if(searcher->team==inputTeamName)
        {
            cout<<searcher->team<<" "<<searcher->name<<" "<<searcher->pos<<" "<<searcher->av<<endl;
        }
        searcher=searcher->next;
    }
}

void BPL::searchInterTeam(struct player* head)
{
    string inputTeamName;
    cout<<"Enter International Team Name: ";
    getline(cin,inputTeamName);

    player* searcher=head;
    while(searcher->next!=NULL)
    {
        if(searcher->international==inputTeamName)
        {
            cout<<searcher->international<<" "<<searcher->team<<" "<<searcher->name<<" "<<searcher->pos<<" "<<searcher->av<<endl;
        }
        searcher=searcher->next;
    }
}

void BPL::searchPos(struct player* head)
{
    string inputPos;
    cout<<"Enter Position: ";
    getline(cin,inputPos);

    player* searcher=head;
    while(searcher->next!=NULL)
    {
        if(searcher->pos==inputPos)
        {
            cout<<searcher->team<<" "<<searcher->name<<" "<<searcher->pos<<" "<<searcher->av<<endl;
        }
        searcher=searcher->next;
    }
}

void BPL::searchName(struct player* head)
{
    string inputName;
    cout<<"Enter Name: ";
    getline(cin,inputName);
    player* searcher=head;
    while(searcher->next!=NULL)
    {
        if(searcher->name==inputName)
        {
            cout<<searcher->team<<" "<<searcher->name<<" "<<searcher->pos<<" "<<searcher->av<<" "<<endl;
        }
        searcher=searcher->next;
    }
}
