#include <iostream>
#include "utils/function_prototype.h"
#include <string>

#include <cstdlib>
#include <ctime>
#include <stdlib.h>

#include <sstream>
#include <iomanip>

#include <ctype.h>

using namespace std;


void ggs(){

}


int main(){
    bool co=true , oc=true;
    string option;
    intro();
    while (co==true) {
        option=optn();
        if (option == "1") {
            string game;
            bool og=true;
            while (og==true) {
                cout<<"\nSelect A Game You want To Play:- "<<endl;
                cout<<"\nCOMPUTER VS YOU:- \n"<<endl;
                cout<<"1.Cricket"<<endl;
                cout<<"2.Baseball"<<endl;
                cout<<"3.Hangman"<<endl;
                cout<<"4.Bingo"<<endl;
                cout<<"5. coming soon :)"<<endl;
                cout<<"6.Chopsticks"<<endl;
                cout<<"\n 2Player games:- \n"<<endl;
                cout<<"7.Tic Tac Toes ( XO )"<<endl;
                cout<<"8.Snake and ladder"<<endl;
                cout<<"\nEnter an option (1,2,3,4,5,6,7): ";
                cin>>game;

                if (game == "1") {
                    cricket();
                }
                else if (game == "2") {
                    cout << "Coming Soon :)" << endl;
                }
                else if (game == "3") {
                    cout << "Coming Soon :)" << endl;
                }
                else if (game == "4") {
                    cout << "Coming Soon :)" << endl;
                }
                else if (game == "5") {
                    cout << "Coming Soon :)" << endl;
                }
                else if (game == "6") {
                    cout << "Coming Soon :)" << endl;
                }
                else if (game == "7") {
                    cout << "Coming Soon :)" << endl;
                }
                else if (game == "lobby") {
                    cout<<"\n..........R.e.t.u.r.n.i.n.g...T.o...M.a.i.n...L.o.b.b.y.........."<<endl;
                    og=false;
                }
                else {
                    cout<<"\nSelect An Option Between (1,2,3,4,5,6,7) numbers only\n";
                }
            }
        }

        else if (option == "2") {
            cout<<"\nNote:- Commands are Mentioned in <> brackets";
            cout<<"\nModerator Commands:-"<<endl;
            cout<<"\t\t1.<exit> To exit everything Can be used anywhere in games."<<endl;
            cout<<"\t\t2.<lobby> To Return to main lobby while selecting games";
            cout<<"\nIn game commands:-"<<endl;
            cout<<"1.Cricket"<<endl;
            cout<<"\t\t1.<score();> To view your score any time inside a cricket match"<<endl;
            cout<<"\t\t2.<target> To view your score any time inside a cricket match"<<endl;
            cout<<"\t\t3.<stats> To view your stats after multiple matches"<<endl;
            cout<<"Other Games Are Under Development"<<endl;

        }
        else if (option == "3") {
            cout<<"---------------E.X.I.T.I.N.G---------------";
            co=false;
        }
        else {
            cout <<"..................E.R.R.O.R.................." << endl;
        }
    }

    cout << "\nSee You Soon:" << endl << "." << endl << "." << endl << "." << endl << "." << endl<< ".";
    return 0;
}
