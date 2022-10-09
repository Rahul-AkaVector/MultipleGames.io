#include <bits/stdc++.h>
using namespace std;

// Declaring Functions
void ex();
void intro();
int optn();
void cricket();
string pnames(string pn);
int toss();
int bob(int a);
int player_bowling(int target);
int player_batting(int target);

// Tic Tac Toe game functions declaration
void display_board();
void player_turn();
bool gameover();
void ticTacToe();

int main()
{
    bool co = true, oc = true;
    int option;
    intro();
    while (co == true)
    {
        option = optn();
        bool og = true;
        switch (option)
        {
        case 1:
            while (og == true)
            {
                cout << "\nSelect A Game You want To Play_";
                cout << "\n__COMPUTER VS YOU__\n\n";
                cout << "1. Cricket" << endl;
                cout << "2. Baseball" << endl;
                cout << "3. Hangman" << endl;
                cout << "4. Bingo" << endl;
                cout << "5. Coming soon :)" << endl;
                cout << "6. Chopsticks" << endl;
                cout << "\n Two Player games_\n\n";
                cout << "7. Tic Tac Toe (XO)" << endl;
                cout << "8. Snake and ladder" << endl;
                cout << "9. Lobby" << endl;

                int game;
                cout << "\nEnter your option: ";
                cin >> game;

                switch (game)
                {
                case 1:
                    cricket();
                    break;
                case 2:
                    cout << "Coming Soon :)" << endl;
                    break;
                case 3:
                    cout << "Coming Soon :)" << endl;
                    break;
                case 4:
                    cout << "Coming Soon :)" << endl;
                    break;
                case 5:
                    cout << "Coming Soon :)" << endl;
                    break;
                case 6:
                    cout << "Coming Soon :)" << endl;
                    break;
                case 7:
                    ticTacToe();
                    // cout << "Coming Soon :)" << endl;
                    break;
                case 8:
                    cout << "Coming Soon :)" << endl;
                    break;

                case 9:
                    cout << "\n____Returning To Main Lobby____\n";
                    og = false;
                    break;
                default:
                    cout << "\nPlz enter an Option 1 to 8 only_\n";
                }
            }
            break;

        case 2:
            cout << "\nNote:- Commands are Mentioned in <> brackets";
            cout << "\nModerator Commands:" << endl;
            cout << "\t\t1.<exit> To exit everything Can be used anywhere in games." << endl;
            cout << "\t\t2.<lobby> To Return to main lobby while selecting games";
            cout << "\nIn Game Commands:" << endl;
            cout << "1.Cricket" << endl;
            cout << "\t\t1.<score();> To view your score any time inside a cricket match" << endl;
            cout << "\t\t2.<target> To view your score any time inside a cricket match" << endl;
            cout << "\t\t3.<stats> To view your stats after multiple matches" << endl;
            cout << "Other Games Are Under Development" << endl;
            break;

        case 3:
            cout << "\n______Exiting______" << endl;
            cout << "_____Thank You_____\n\n";
            co = false;
            break;

        default:
            cout << "_X_X_X_X___ERROR___X_X_X_X_" << endl;
            break;
        }
    }
    return 0;
}

// Defining Functions
void ex()
{
    cout << "TERMINATING......................................";
    exit(0);
}

void intro()
{
    cout << "::::::::::::::::::::::::::::::::::::\n\n";
    cout << "   !!! Welcome to Multiple.io !!!  " << endl;
    cout << "\n::::::::::::::::::::::::::::::::::::\n";
}

int optn()
{
    int op;
    cout << "\nSelect an Option_" << endl;
    cout << "1. Games" << endl;
    cout << "2. In Game Commands" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter Option: ";
    cin >> op;
    return op;
}

void cricket()
{
    int win = 0, lose = 0;
    int ts;
    int target;
    string pn;
    pn = pnames(pn); // player name
    string again = "y";

    bool y = true, x = true;

    while (y == true)
    {
        ts = toss();      // getting toss value : 1 for player won :2 for computer won
        int ch = bob(ts); //   1 == player batting , //2 == player bowling , //3 == comp bowling , //4 == comp batting ,
        // if (ch==1) cout<<"player batting";
        // else if(ch==2) cout<<"player bowling";
        // else if(ch==3) cout<<"comp bowling";
        // else if(ch==4) cout<<"comp batting";

        if ((ch == 2) || (ch == 4))
        {
            cout << "\nInitializing Computers Batting..........\n"
                 << endl;
            target = player_bowling(0);

            cout << "\nInitializing Computers Bowling..........\n"
                 << endl;
            target = player_batting(target);
        }
        else
        {
            cout << "\nInitializing Computers Bowling........\n"
                 << endl;
            target = player_batting(0);

            cout << "\nInitializing Computers Batting.........\n"
                 << endl;
            target = player_bowling(target);
        }
        if (target == -1)
        {
            cout << "\nYou won the match !!!!\n"
                 << endl;
            win = win + 1;
        }
        else
        {
            cout << "\nComputer won the match !!!!\n"
                 << endl;
            lose = lose + 1;
        }
        x = true;
        while (x == true)
        {
            cout << "Do you want to play again (y/n) : ";
            cin >> again;

            if (again == "y")
            {
                cout << "\nRematch...." << endl;
                x = false;
            }
            else if (again == "n")
            {
                cout << "\nThank you for playing...." << endl;
                cout << "Clearing your data:" << endl
                     << "." << endl
                     << "." << endl
                     << "." << endl
                     << "." << endl
                     << ".";
                y = false;
                x = false;
            }
            else if (again == "stats")
            {
                double mpd = win + lose;
                double wp = (win / mpd) * 100;
                if (mpd > 3)
                {
                    cout << "\nYour Stats are\n"
                         << endl;
                    cout << setw(15) << "Wins" << setw(15) << "Lose" << setw(22) << "Matches Played" << setw(15) << "Win ratio" << endl;
                    cout << setw(15) << win << setw(15) << lose << setw(22) << mpd << setw(14) << wp << "%" << endl;
                }
                else
                {
                    cout << "\nNote :- You need to play 4 games to view your stats!!!!!!!." << endl;
                    cout << "You've played " << mpd << " till now" << endl;
                    cout << "You need to play " << 4 - mpd << " more game to view your stats\n"
                         << endl;
                }
            }
            else if (again == "exit")
            {
                ex();
            }
            else
            {
                cout << "Invalid input...." << endl;
            }
        }
    }
}

string pnames(string pn)
{
    string dismantle;
    getline(cin, dismantle);
    cout << "Enter your name: ";
    getline(cin, pn);
    return pn;
}

int toss()
{
    bool y = false;
    srand(time(0));
    int tossed = rand() % 2;
    int playertoss;
    while (y == false)
    {
        string ptoss;
        cout << "\nFlipping coin...." << endl
             << "What do you want ? (HEADS or TAILS) : ";
        cin >> ptoss;
        // cout<<ptoss<<endl;
        if (ptoss == "head" || ptoss == "HEAD" || ptoss == "heads" || ptoss == "HEADS" || ptoss == "1")
        {
            playertoss = 0;
            y = true;
        }
        else if (ptoss == "tail" || ptoss == "Tail" || ptoss == "tails" || ptoss == "TAIL" || ptoss == "2")
        {
            playertoss = 1;
            y = true;
        }
        else if (ptoss == "exit")
        {
            ex();
        }
        else
        {
            cout << "\nPlease Enter Heads or Tails !! \n"
                 << endl;
        }
    }
    // cout<<playertoss<<endl;
    // cout<<tossed<<endl;
    if (playertoss == tossed)
    {
        cout << "You won the toss ....." << endl;
        return 1;
    }
    else
    {
        cout << "Computer won the toss ....." << endl;
        return 2;
    }
}

int bob(int a)
{
    srand(time(0));
    int ctoss = rand() % 2;
    if (a == 1)
    {
        bool y = false;
        while (y == false)
        {
            string choice;
            cout << "\nWhat do you want play first ? (1. BATTING or 2.BOWLING): ";
            cin >> choice;
            if (choice == "BATTING" || choice == "batting" || choice == "BAT" || choice == "bat" || choice == "1")
            {
                return 1;
                y = true;
            }
            else if (choice == "BOWLING" || choice == "bowling" || choice == "ball" || choice == "BALL" || choice == "2" || choice == "bowl")
            {
                return 2;
                y = true;
            }
            else if (choice == "exit")
            {
                ex();
            }
            else
            {
                cout << "\tPlease enter a valid input !! " << endl;
            }
        }
    }
    else
    {
        if (ctoss == 0)
        {
            cout << "Computer choose Bowling first" << endl;
            return 3;
        }
        else
        {
            cout << "Computer choose Batting first" << endl;
            return 4;
        }
    }
}

int player_bowling(int target)
{
    if (target == 0)
    {
        bool y = true;
        int runs = 0;
        string ball;
        while (y == true)
        {
            srand(time(0));
            int cguess = rand() % 7;
            ostringstream cgs;
            cgs << cguess;
            string cg = cgs.str(); // cg=computer guess = string
            cout << "\nEnter bowl : ";
            cin >> ball;
            if (ball == "1" or ball == "2" or ball == "3" or ball == "4" or ball == "5" or ball == "6" or ball == "0" or ball == "score();" or ball == "exit")
            {
                // edit:
                if (ball == cg)
                {
                    cout << "\nYour ball: " << ball << endl;
                    cout << "Computers run: " << cg << endl;
                    cout << "You took Computers Wicket!\n"
                         << endl;
                    cout << "\n Computer set a target of " << runs + 1 << " runs.\n"
                         << endl;
                    return runs + 1;
                }
                else if (ball == "score();")
                {
                    cout << "\nComputer scored " << runs << " runs.\n"
                         << endl;
                }
                else if (ball == "exit")
                {
                    ex();
                }
                else if (cg == "0")
                {
                    cout << "Computer hit a dot ball." << endl;
                    cout << "Your ball: " << ball << endl;
                }
                else if (cg == "1")
                {
                    cout << "Computer scored 2 runs." << endl;
                    cout << "Your ball: " << ball << endl;
                    runs = runs + 1;
                }
                else if (cg == "2")
                {
                    cout << "Computer scored 2 run" << endl;
                    cout << "Your ball: " << ball << endl;
                    runs = runs + 2;
                }
                else if (cg == "3")
                {
                    cout << "Computer scored 3 runs" << endl;
                    cout << "Your ball: " << ball << endl;
                    runs = runs + 3;
                }
                else if (cg == "4")
                {
                    cout << "Computer hits a Boundary ." << endl;
                    cout << "Your ball: " << ball << endl;
                    runs = runs + 4;
                }
                else if (cg == "5")
                {
                    cout << "Computer somehow scored 5 runs ." << endl;
                    cout << "Your ball: " << ball << endl;
                    runs = runs + 5;
                }
                else if (cg == "6")
                {
                    cout << "Computer hits a Sixer" << endl;
                    cout << "Your ball: " << ball << endl;
                    runs = runs + 6;
                }
                else
                {
                    cout << "Its raining . But match will be continued" << runs << endl;
                }
            }
            else
            {
                cout << "===============Invalid Input===============" << endl;
            }
        }
    }
    else
    {
        bool y = true;
        int runs = 0;
        string ball;
        while (runs < target and y == true)
        {
            srand(time(0));
            int cguess = rand() % 7;
            ostringstream cgs;
            cgs << cguess;
            string cg = cgs.str(); // cg=computer guess = string
            cout << "\nEnter ball: ";
            cin >> ball;
            if (ball == "1" || ball == "2" || ball == "3" || ball == "4" || ball == "5" || ball == "6" || ball == "0" || ball == "score();" || ball == "target" || ball == "exit")
            {
                if (ball == cg)
                {
                    cout << "\nYour ball: " << ball << endl;
                    cout << "Computers run: " << cg << endl;
                    cout << "You took Computers Wicket!\n"
                         << endl;
                    cout << "Computer lose the match by " << target - runs << " runs.\n"
                         << endl;
                    y = false;
                }
                else if (ball == "score();" or ball == "target")
                {

                    cout << "\nComputer scored " << runs << " runs.";
                    cout << "Target is of " << target << " runs." << endl;
                    cout << "Computer needs " << target - runs << " runs to win.\n"
                         << endl;
                }
                else if (ball == "exit")
                {
                    ex();
                }
                else if (cg == "0")
                {
                    cout << "Computer hit a dot ball." << endl;
                    cout << "Your ball: " << ball << endl;
                }
                else if (cg == "1")
                {
                    cout << "Computer scored 2 runs." << endl;
                    cout << "Your ball: " << ball << endl;
                    runs = runs + 1;
                }
                else if (cg == "2")
                {
                    cout << "Computer scored 2 run" << endl;
                    cout << "Your ball: " << ball << endl;
                    runs = runs + 2;
                }
                else if (cg == "3")
                {
                    cout << "Computer scored 3 runs" << endl;
                    cout << "Your ball: " << ball << endl;
                    runs = runs + 3;
                }
                else if (cg == "4")
                {
                    cout << "Computer hits a Boundary ." << endl;
                    cout << "Your ball: " << ball << endl;
                    runs = runs + 4;
                }
                else if (cg == "5")
                {
                    cout << "Computer somehow scored 5 runs ." << endl;
                    cout << "Your ball: " << ball << endl;
                    runs = runs + 5;
                }
                else if (cg == "6")
                {
                    cout << "Computer hits a Sixer" << endl;
                    cout << "Your ball: " << ball << endl;
                    runs = runs + 6;
                }
                else
                {
                    cout << "Its raining.. but match will be continue. " << endl;
                }
            }
            else
            {
                cout << "===============Invalid Input===============" << endl;
            }
        }
        if (runs >= target)
        {
            return -2; // computer won the match
        }
        else
        {
            return -1; // player won the match
        }
    }
}

int player_batting(int target)
{

    if (target == 0)
    {
        bool y = true;
        int runs = 0;
        string run;
        while (y == true)
        {
            srand(time(0));
            int cguess = rand() % 7;
            ostringstream cgs;
            cgs << cguess;
            string cg = cgs.str(); // cg=computer guess = string
            cout << "\nEnter runs: ";
            cin >> run;
            if (run == cg)
            {
                cout << "\nComputer Balls :" << cguess << endl;
                cout << "You are OUT.!!.\n"
                     << endl;
                cout << "You set a target of " << runs + 1 << " runs" << endl;
                return runs + 1;
            }
            else if (run == "exit")
            {
                ex();
            }
            else if (run == "0")
            {
                cout << "You hit a dot ball. " << endl;
                cout << "Computer Balls :" << cguess << endl;
            }
            else if (run == "1")
            {
                cout << "You scored 1 run. " << endl;
                cout << "Computer Balls :" << cguess << endl;
                runs = runs + 1;
            }
            else if (run == "2")
            {
                cout << "You scored 2 run. " << endl;
                cout << "Computer Balls :" << cguess << endl;
                runs = runs + 2;
            }
            else if (run == "3")
            {
                cout << "You managed to score 3 runs , fk. " << endl;
                cout << "Computer Balls :" << cguess << endl;
                runs = runs + 3;
            }
            else if (run == "4")
            {
                cout << "You hit a boundary. " << endl;
                cout << "Computer Balls :" << cguess << endl;
                runs = runs + 4;
            }
            else if (run == "5")
            {
                cout << "You scored 5 runs ,fast runner bruh. " << endl;
                cout << "Computer Balls :" << cguess << endl;
                runs = runs + 5;
            }
            else if (run == "6")
            {
                cout << "You hit a sixer! " << endl;
                cout << "Computer Balls :" << cguess << endl;
                runs = runs + 6;
            }
            else if (run == "score();")
            {
                cout << "Your current runs are " << runs << " runs" << endl;
            }
            else
            {
                cout << "===============Invalid Input===============" << endl;
            }
        }
    }
    else
    {
        bool y = true;
        int runs = 0;
        string run;
        while (runs < target and y == true)
        {
            srand(time(0));
            int cguess = rand() % 7;
            ostringstream cgs;
            cgs << cguess;
            string cg = cgs.str(); // cg=computer guess = string
            cout << "Enter runs: ";
            cin >> run;
            if (run == cg)
            {
                cout << "\nComputer Balls :" << cguess << endl;
                cout << "You are OUT.!!!\n"
                     << endl;
                cout << "You lose match by " << target - runs << " runs.\n"
                     << endl;
                y = false;
            }
            else if (run == "exit")
            {
                ex();
            }
            else if (run == "0")
            {
                cout << "You hit a dot ball. " << endl;
                cout << "Computer Balls :" << cguess << endl;
            }
            else if (run == "1")
            {
                cout << "You scored 1 run. " << endl;
                cout << "Computer Balls :" << cguess << endl;
                runs = runs + 1;
            }
            else if (run == "2")
            {
                cout << "You scored 2 run. " << endl;
                cout << "Computer Balls :" << cguess << endl;
                runs = runs + 2;
            }
            else if (run == "3")
            {
                cout << "You managed to score 3 runs , fk. " << endl;
                cout << "Computer Balls :" << cguess << endl;
                runs = runs + 3;
            }
            else if (run == "4")
            {
                cout << "You hit a boundary. " << endl;
                cout << "Computer Balls :" << cguess << endl;
                runs = runs + 4;
            }
            else if (run == "5")
            {
                cout << "You scored 5 runs ,fast runner bruh. " << endl;
                cout << "Computer Balls :" << cguess << endl;
                runs = runs + 5;
            }
            else if (run == "6")
            {
                cout << "You hit a sixer! " << endl;
                cout << "Computer Balls :" << cguess << endl;
                runs = runs + 6;
            }
            else if (run == "score();" or run == "target")
            {
                cout << "\nYou scored " << runs << " runs." << endl;
                cout << "Target is of " << target << " runs" << endl;
                cout << "You need " << target - runs << " runs to win.\n"
                     << endl;
            }
            else
            {
                cout << "===============Invalid Input===============" << endl;
            }
        }
        if (runs >= target)
        {
            return -1; // player won the match
        }
        else
        {
            return -2; // computer won the match
        }
    }
}

// Tic Tac Toe game functions definations
char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};
int choice;
int row, column;
char turn = 'X';
bool draw = false;

void display_board()
{
    cout << "\n\tPLAYER - 1 [X]\t PLAYER - 2 [O]\n";
    cout << "\t    Enter 333 to Exit !!!\n\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    cout << "\t\t     |     |     \n";
}

void player_turn()
{
    if (turn == 'X')
    {
        cout << "\n\tPlayer - 1 [X] turn : ";
    }
    else if (turn == 'O')
    {
        cout << "\n\tPlayer - 2 [O] turn : ";
    }

    // Taking input from user
    cin >> choice;

    switch (choice)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;
    case 333:
        exit(0);
    default:
        cout << "Invalid Move";
    }

    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'X';
        display_board();
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'O';
        display_board();
        turn = 'X';
    }
    else
    {
        // if input position already filled
        cout << "Box already filled!n Please choose another!!\n\n";
        player_turn();
    }
}

// Function to get the game status e.g. GAME WON, GAME DRAW, GAME IN CONTINUE MODE
bool gameover()
{
    // checking the win for Simple Rows and Simple Column
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;

    // checking the win for both diagonal

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    // Checking the game is in continue mode or not
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    // Checking the if game already draw
    draw = true;
    return false;
}

// game's starting function

void ticTacToe()
{
    system("cls");
    cout << "\tT I C - T A C - T O E -- G A M E" << endl;
    cout << "\n\t\tFOR 2 PLAYERS";
    display_board();
    while (gameover())
    {
        player_turn();
    }
    if (turn == 'X' && draw == false)
    {
        cout << "\n\nCongratulations!Player with 'O' has won the game" << endl;
    }
    else if (turn == 'O' && draw == false)
    {
        cout << "\n\nCongratulations!Player with 'X' has won the game" << endl;
    }
    else
        cout << "\n\nGAME DRAW!!!\n\n";
}