//
// Created by rahul on 09-09-2022.
//


#include <iostream>
#include <string>

#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include <ctype.h>

using namespace std;

void ex() {
    cout<<"TERMINATING......................................";
    exit(0);
}

void intro() {
    cout << ":::::::::::::::::::::::::::::::::::\n" << endl;
    cout << "Welcome to Multiple.io !!! " << endl;
    cout << "\n:::::::::::::::::::::::::::::::::::" << endl;
}

string optn(){
    string op;
    cout<<"\nSelect an Option"<<endl;
    cout<<"1.Games"<<endl;
    cout<<"2.In Game Commands"<<endl;
    cout<<"3.Exit"<<endl;
    cin>>op;
    return op;
}

string pnames(string pn) {
    string dismantle;
    getline(cin,dismantle);
    cout<<"Enter your name: ";
    getline(cin,pn);
    return pn;
}

int toss() {
    bool y=false;
    srand(time(0));
    int tossed = rand ()%2;
    int playertoss;
    while (y==false) {
        string ptoss;
        cout << "\nFlipping coin...." << endl << "What do you want ? (HEADS or TAILS) : ";
        cin >> ptoss;
        //cout<<ptoss<<endl;
        if (ptoss=="head" || ptoss=="HEAD" || ptoss=="heads" || ptoss=="HEADS" || ptoss=="1"){
            playertoss=0;
            y=true;
        }
        else if (ptoss=="tail" || ptoss=="Tail" || ptoss=="tails" || ptoss=="TAIL" || ptoss=="2"){
            playertoss=1;
            y=true;
        }
        else if (ptoss=="exit"){
            ex();

        }
        else{
            cout<<"\nPlease Enter Heads or Tails !! \n"<<endl;
        }
    }
    //cout<<playertoss<<endl;
    //cout<<tossed<<endl;
    if (playertoss==tossed){
        cout<<"You won the toss ....."<<endl;
        return 1;
    }
    else{
        cout<<"Computer won the toss ....."<<endl;
        return 2;
    }
}


int bob(int a){
    srand(time(0));
    int ctoss = rand ()%2;
    if (a==1){
        bool y = false;
        while (y==false) {
            string choice;
            cout<<"\nWhat do you want play first ? (1. BATTING or 2.BOWLING): ";
            cin >> choice;
            if (choice=="BATTING" || choice=="batting" || choice=="BAT" || choice=="bat" || choice=="1" ){
                return 1;
                y=true;
            }
            else if (choice=="BOWLING" || choice=="bowling" || choice=="ball" || choice=="BALL" || choice=="2" || choice=="bowl"){
                return 2;
                y=true;
            }
            else if (choice=="exit"){
                ex();
            }
            else{
                cout<<"\tPlease enter a valid input !! "<<endl;
            }
        }
    }
    else{
        if (ctoss==0){
            cout<<"Computer choose Bowling first"<<endl;
            return 3;
        }
        else{
            cout<<"Computer choose Batting first"<<endl;
            return 4;
        }
    }
}


int player_bowling(int target) {
    if (target==0){
        bool y=true;
        int runs=0;
        string ball;
        while (y==true){
            srand(time(0));
            int cguess = rand() % 7;
            ostringstream cgs;
            cgs << cguess;
            string cg = cgs.str(); //cg=computer guess = string
            cout<<"\nEnter bowl : ";
            cin>>ball;
            if (ball== "1" or ball=="2" or ball=="3" or ball=="4" or ball=="5" or ball=="6" or ball=="0" or ball=="score();" or ball=="exit"){
                //edit:-
                if (ball == cg){
                    cout<<"\nYour ball: "<<ball<<endl;
                    cout<<"Computers run: "<<cg<<endl;
                    cout<<"You took Computers Wicket!\n"<<endl;
                    cout<<"\n Computer set a target of "<<runs+1<<" runs.\n"<<endl;
                    return runs+1;
                }
                else if (ball=="score();"){
                    cout<<"\nComputer scored "<<runs<<" runs.\n"<<endl;
                }
                else if (ball=="exit"){
                    ex();
                }
                else if (cg=="0"){
                    cout<<"Computer hit a dot ball."<<endl;
                    cout<<"Your ball: "<<ball<<endl;
                }
                else if (cg=="1"){
                    cout<<"Computer scored 2 runs."<<endl;
                    cout<<"Your ball: "<<ball<<endl;
                    runs=runs+1;
                }
                else if (cg=="2"){
                    cout<<"Computer scored 2 run"<<endl;
                    cout<<"Your ball: "<<ball<<endl;
                    runs=runs+2;
                }
                else if (cg=="3"){
                    cout<<"Computer scored 3 runs"<<endl;
                    cout<<"Your ball: "<<ball<<endl;
                    runs=runs+3;
                }
                else if (cg=="4"){
                    cout<<"Computer hits a Boundary ."<<endl;
                    cout<<"Your ball: "<<ball<<endl;
                    runs=runs+4;
                }
                else if (cg=="5"){
                    cout<<"Computer somehow scored 5 runs ."<<endl;
                    cout<<"Your ball: "<<ball<<endl;
                    runs=runs+5;
                }
                else if (cg=="6"){
                    cout<<"Computer hits a Sixer"<<endl;
                    cout<<"Your ball: "<<ball<<endl;
                    runs=runs+6;
                }
                else{cout<<"Its raining . But match will be continued"<<runs<<endl;}
            }
            else{
                cout<<"===============Invalid Input==============="<<endl;
            }
        }
    }
    else{
        bool y = true;
        int runs = 0 ;
        string ball;
        while (runs < target and y==true){
            srand(time(0));
            int cguess = rand() % 7;
            ostringstream cgs;
            cgs << cguess;
            string cg = cgs.str(); //cg=computer guess = string
            cout << "\nEnter ball: ";
            cin>>ball;
            if (ball== "1" or ball=="2" or ball=="3" or ball=="4" or ball=="5" or ball=="6" or ball=="0" or ball=="score();" or ball == "target" or ball=="exit"){
                if (ball == cg){
                    cout<<"\nYour ball: "<<ball<<endl;
                    cout<<"Computers run: "<<cg<<endl;
                    cout<<"You took Computers Wicket!\n"<<endl;
                    cout<<"Computer lose the match by "<<target-runs<<" runs.\n"<<endl;
                    y=false;
                }
                else if (ball=="score();" or ball=="target"){

                    cout<<"\nComputer scored "<<runs<<" runs.";
                    cout<<"Target is of "<<target<<" runs."<<endl;
                    cout<<"Computer needs "<<target-runs<<" runs to win.\n"<<endl;
                }
                else if (ball=="exit"){
                    ex();
                }
                else if (cg=="0"){
                    cout<<"Computer hit a dot ball."<<endl;
                    cout<<"Your ball: "<<ball<<endl;
                }
                else if (cg=="1"){
                    cout<<"Computer scored 2 runs."<<endl;
                    cout<<"Your ball: "<<ball<<endl;
                    runs=runs+1;
                }
                else if (cg=="2"){
                    cout<<"Computer scored 2 run"<<endl;
                    cout<<"Your ball: "<<ball<<endl;
                    runs=runs+2;
                }
                else if (cg=="3"){
                    cout<<"Computer scored 3 runs"<<endl;
                    cout<<"Your ball: "<<ball<<endl;
                    runs=runs+3;
                }
                else if (cg=="4"){
                    cout<<"Computer hits a Boundary ."<<endl;
                    cout<<"Your ball: "<<ball<<endl;
                    runs=runs+4;
                }
                else if (cg=="5"){
                    cout<<"Computer somehow scored 5 runs ."<<endl;
                    cout<<"Your ball: "<<ball<<endl;
                    runs=runs+5;
                }
                else if (cg=="6"){
                    cout<<"Computer hits a Sixer"<<endl;
                    cout<<"Your ball: "<<ball<<endl;
                    runs=runs+6;
                }
                else{cout<<"Its raining.. but match will be continue. "<<endl;}
            }
            else{
                cout<<"===============Invalid Input==============="<<endl;
            }

        }
        if (runs >= target){
            return -2; //computer won the match
        }
        else {
            return -1; //player won the match
        }
    }

}


int player_batting(int target) {

    if (target==0){
        bool y = true;
        int runs = 0 ;
        string run;
        while (y==true) {
            srand(time(0));
            int cguess = rand() % 7;
            ostringstream cgs;
            cgs << cguess;
            string cg = cgs.str(); //cg=computer guess = string
            cout << "\nEnter runs: ";
            cin>>run;
            if (run == cg){
                cout<<"\nComputer Balls :"<<cguess<<endl;
                cout<<"You are OUT.!!.\n"<<endl;
                cout<<"You set a target of "<<runs+1<<" runs"<<endl;
                return runs+1;
            }
            else if (run=="exit"){
                ex();
            }
            else if ( run == "0") {
                cout<<"You hit a dot ball. "<<endl;
                cout<<"Computer Balls :"<<cguess<<endl;
            }
            else if (run == "1"){
                cout<<"You scored 1 run. "<<endl;
                cout<<"Computer Balls :"<<cguess<<endl;
                runs = runs+1;
            }
            else if (run == "2"){
                cout<<"You scored 2 run. "<<endl;
                cout<<"Computer Balls :"<<cguess<<endl;
                runs = runs+2;
            }
            else if (run == "3"){
                cout<<"You managed to score 3 runs , fk. "<<endl;
                cout<<"Computer Balls :"<<cguess<<endl;
                runs = runs+3;
            }
            else if (run == "4"){
                cout<<"You hit a boundary. "<<endl;
                cout<<"Computer Balls :"<<cguess<<endl;
                runs = runs+4;
            }
            else if (run == "5"){
                cout<<"You scored 5 runs ,fast runner bruh. "<<endl;
                cout<<"Computer Balls :"<<cguess<<endl;
                runs = runs+5;
            }
            else if (run == "6"){
                cout<<"You hit a sixer! "<<endl;
                cout<<"Computer Balls :"<<cguess<<endl;
                runs = runs+6;
            }
            else if (run=="score();"){
                cout<<"Your current runs are "<<runs<<" runs"<<endl;
            }
            else {
                cout<<"===============Invalid Input==============="<<endl;
            }
        }
    }
    else{
        bool y = true;
        int runs = 0 ;
        string run;
        while (runs < target and y==true) {
            srand(time(0));
            int cguess = rand() % 7;
            ostringstream cgs;
            cgs << cguess;
            string cg = cgs.str(); //cg=computer guess = string
            cout << "Enter runs: ";
            cin>>run;
            if (run == cg){
                cout<<"\nComputer Balls :"<<cguess<<endl;
                cout<<"You are OUT.!!!\n"<<endl;
                cout<<"You lose match by "<<target-runs<<" runs.\n"<<endl;
                y=false;
            }
            else if (run == "exit"){
                ex();
            }
            else if ( run == "0") {
                cout<<"You hit a dot ball. "<<endl;
                cout<<"Computer Balls :"<<cguess<<endl;
            }
            else if (run == "1"){
                cout<<"You scored 1 run. "<<endl;
                cout<<"Computer Balls :"<<cguess<<endl;
                runs = runs+1;
            }
            else if (run == "2"){
                cout<<"You scored 2 run. "<<endl;
                cout<<"Computer Balls :"<<cguess<<endl;
                runs = runs+2;
            }
            else if (run == "3"){
                cout<<"You managed to score 3 runs , fk. "<<endl;
                cout<<"Computer Balls :"<<cguess<<endl;
                runs = runs+3;
            }
            else if (run == "4"){
                cout<<"You hit a boundary. "<<endl;
                cout<<"Computer Balls :"<<cguess<<endl;
                runs = runs+4;
            }
            else if (run == "5"){
                cout<<"You scored 5 runs ,fast runner bruh. "<<endl;
                cout<<"Computer Balls :"<<cguess<<endl;
                runs = runs+5;
            }
            else if (run == "6"){
                cout<<"You hit a sixer! "<<endl;
                cout<<"Computer Balls :"<<cguess<<endl;
                runs = runs+6;
            }
            else if (run=="score();" or run=="target"){
                cout<<"\nYou scored "<<runs<<" runs."<<endl;
                cout<<"Target is of "<<target<<" runs"<<endl;
                cout<<"You need "<<target-runs<<" runs to win.\n"<<endl;
            }
            else {
                cout<<"===============Invalid Input==============="<<endl;
            }
        }
        if (runs >= target){
            return -1; //player won the match
        }
        else {
            return -2; //computer won the match
        }
    }

}


void cricket() {
    int win=0 ,lose=0 ;
    int ts;
    int target;
    string pn;
    pn=pnames(pn); //player name
    string again="y";

    bool y=true , x=true;

    while (y==true) {
        ts = toss();     //getting toss value : 1 for player won :2 for computer won
        int ch = bob(ts); //   1 == player batting , //2 == player bowling , //3 == comp bowling , //4 == comp batting ,
        //if (ch==1) cout<<"player batting";
        //else if(ch==2) cout<<"player bowling";
        //else if(ch==3) cout<<"comp bowling";
        //else if(ch==4) cout<<"comp batting";

        if ((ch == 2) || (ch == 4)) {
            cout << "\nInitializing Computers Batting..........\n" << endl;
            target = player_bowling(0);

            cout << "\nInitializing Computers Bowling..........\n" << endl;
            target = player_batting(target);
        } else {
            cout << "\nInitializing Computers Bowling........\n" << endl;
            target = player_batting(0);

            cout << "\nInitializing Computers Batting.........\n" << endl;
            target = player_bowling(target);
        }
        if (target == -1) {
            cout << "\nYou won the match !!!!\n" << endl;
            win=win+1;
        } else {
            cout << "\nComputer won the match !!!!\n" << endl;
            lose=lose+1;
        }
        x=true;
        while (x == true) {
            cout << "Do you want to play again (yes/no) : ";
            cin >> again;

            if (again == "y" or again == "yes" or again == "yea" or again == "Y" or again == "Yes" or again=="1") {
                cout << "\nRematch...." << endl;
                x=false;
            }
            else if (again == "n" or again == "no" or again == "nah" or again == "N" or again == "NO" or again == "2") {
                cout << "\nThank you for playing...." << endl;
                cout << "Clearing your data:" << endl << "." << endl << "." << endl << "." << endl << "." << endl
                     << ".";
                y = false;
                x = false;
            }
            else if (again=="stats"){
                double mpd=win+lose;
                double wp=(win/mpd)*100;
                if (mpd>3){
                    cout<<"\nYour Stats are\n"<<endl;
                    cout<<setw(15)<<"Wins"<<setw(15)<<"Lose"<<setw(22)<<"Matches Played"<<setw(15)<<"Win ratio"<<endl;
                    cout<<setw(15)<<win<<setw(15)<<lose<<setw(22)<<mpd<<setw(14)<<wp<<"%"<<endl;
                }
                else{
                    cout<<"\nNote :- You need to play 4 games to view your stats!!!!!!!."<<endl;
                    cout<<"You've played "<<mpd<<" till now"<<endl;
                    cout<<"You need to play "<<4-mpd<<" more game to view your stats\n"<<endl;
                }
            }
            else if (again=="exit"){
                ex();
            }
            else {
                cout << "Invalid input...." << endl;
            }
        }
    }
}



//write functions
