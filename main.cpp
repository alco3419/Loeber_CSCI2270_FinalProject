#include <iostream>
#include "BPL.h"
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <cctype>

using namespace std;

int main()
{
    BPL run;
    int headcounter=0;
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
    string line;
    string word;
    ifstream inFile;
    inFile.open("BPLdata.txt");
    if(inFile.good())
    {
        player* head=new player;
        while(getline(inFile,line) && headcounter==0)
        {
                int counter=0;
                stringstream iss(line);
                while(getline(iss,word,','))
                {
                    if(counter==0)
                    {
                        head->team=word;
                    }
                    else if(counter==1)
                    {
                        head->number=word;
                    }
                    else if(counter==2)
                    {
                        head->name=word;
                    }
                    else if(counter==3)
                    {
                        head->pos=word;
                    }
                    else if(counter==4)
                    {
                        head->born=word;
                    }
                    else if(counter==5)
                    {
                        head->international=word;
                    }
                    else if(counter==6)
                    {
                        head->played=atoi(word.c_str());
                    }
                    else if(counter==7)
                    {
                        head->goals=atoi(word.c_str());
                    }
                    else if(counter==8)
                    {
                        head->yellows=atoi(word.c_str());
                    }
                    else if(counter==9)
                    {
                        head->reds=atoi(word.c_str());
                    }
                    else
                    {
                        head->status=word;
                        headcounter++;
                    }
                    counter++;
                }
            }
            while(getline(inFile,line))
            {
                int counter=0;
                stringstream iss(line);
                while(getline(iss,word,','))
                {
                    if(counter==0)
                    {
                        team=word;
                    }
                    if(counter==1)
                    {
                        number=word;
                    }
                    if(counter==2)
                    {
                        name=word;
                    }
                    if(counter==3)
                    {
                        pos=word;
                    }
                    if(counter==4)
                    {
                        born=word;
                    }
                    if(counter==5)
                    {
                        international=word;
                    }
                    if(counter==6)
                    {
                        played=atoi(word.c_str());
                    }
                    if(counter==7)
                    {
                        goals=atoi(word.c_str());
                    }
                    if(counter==8)
                    {
                        yellows=atoi(word.c_str());
                    }
                    if(counter==9)
                    {
                        reds=atoi(word.c_str());
                    }
                    else if(counter==10)
                    {
                        status=word;
                    }
                    counter++;
                }
                run.addplayer(head,team,number,name,pos,born,international,played,goals,yellows,reds,status);
            }

    string mainchoice="0";
    while(mainchoice!="2")
    {
        cout<<"******Barclay's Premier League Fantasy Soccer******"<<endl;
        cout<<"1. Start a League"<<endl;
        cout<<"2. Quit"<<endl;
        getline(cin,mainchoice);

        if(mainchoice=="1")
        {
           run.displayLeagueMenu(head);
        }
    }

    }
}




