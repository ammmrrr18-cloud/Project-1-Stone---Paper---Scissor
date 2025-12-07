
#include <iostream>
#include<string>
using namespace std;

enum ElementsOfPlaying { Stone = 1, Paper = 2, Scissors = 3 };
enum WhoIsWin { Player = 1, Computer = 2, Draw = 3 };



int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void ReadInputsOpponent(short& Player, short& Computer)
{
    do {
        cout << "Your choice : [1]Stone , [2]Paper , [3]Scissors ? ";
        cin >> Player;

    } while (Player < 1 || Player>3);

    Computer = RandomNumber(1, 3);
}

WhoIsWin GetWinner(short Player, short Computer)
{

    if (Player == ElementsOfPlaying::Stone && Computer == ElementsOfPlaying::Paper)
        return WhoIsWin::Computer;

    else if (Player == ElementsOfPlaying::Stone && Computer == ElementsOfPlaying::Scissors)
        return WhoIsWin::Player;

    else if (Player == ElementsOfPlaying::Paper && Computer == ElementsOfPlaying::Scissors)
        return WhoIsWin::Computer;

    else if (Player == ElementsOfPlaying::Paper && Computer == ElementsOfPlaying::Stone)
        return WhoIsWin::Player;

    else if (Player == ElementsOfPlaying::Scissors && Computer == ElementsOfPlaying::Paper)
        return WhoIsWin::Player;

    else if (Player == ElementsOfPlaying::Scissors && Computer == ElementsOfPlaying::Stone)
        return WhoIsWin::Computer;

    else
        return WhoIsWin::Draw;


}

void ChangeScreenColor(WhoIsWin Winner)
{

    switch (Winner)
    {

    case WhoIsWin::Player:
        system("color 2F");
        break;

    case WhoIsWin::Computer:
        system("color 4F");
        cout << "\a";
        break;

    case WhoIsWin::Draw:
        system("color 6F");
        break;

    }
}

string WinnerToString(WhoIsWin Winner)
{
    switch (Winner)
    {

    case WhoIsWin::Player:
        return "Player";

    case WhoIsWin::Computer:
        return "Computer";

    case WhoIsWin::Draw:
        return "Draw";

    }
}

string PlayingElementToString(short Element)
{
    switch (Element)
    {

    case ElementsOfPlaying::Stone:
        return "Stone";

    case ElementsOfPlaying::Paper:
        return "Paper";

    case ElementsOfPlaying::Scissors:
        return "Scissors";

    }
}

void ShowPointsEachRound(WhoIsWin Winner, short PlayerChoice, short ComputerChoice)
{

    cout << "\nPlayer Choice : " << PlayingElementToString(PlayerChoice) << endl;
    cout << "Computer Choice : " << PlayingElementToString(ComputerChoice) << endl;
    cout << "Round Winner : " << WinnerToString(Winner) << endl;
}

void WinLossDrawCounter(WhoIsWin WhoWinLossCounter, short& PlayerWinCounter, short& ComputerWinCounter, short& DrawCounter)
{

    if (WhoWinLossCounter == WhoIsWin::Player)
    {
        PlayerWinCounter++;

    }
    else if (WhoWinLossCounter == WhoIsWin::Computer)
    {
        ComputerWinCounter++;
    }
    else
    {
        DrawCounter++;
    }


}

string FinileWinner(short PlayerWinCounter, short ComputerWinCounter)
{
    if (PlayerWinCounter > ComputerWinCounter)
        return "Player";
    else if (ComputerWinCounter > PlayerWinCounter)
        return "Computer";

    else
        return "No Winner";
}

void GameResult(short Rounds, short PlayerWinCounter, short ComputerWinCounter, short DrawCounter, string WhoWinner)
{

    cout << "\n\n\t______________________________________________________________________\n\n";
    cout << "\t___________________________+++ G a m e  O v e r +++___________________";
    cout << "\n\n\t_______________________________________________________________________\n\n";

    cout << "\n\t_____________________________[ Game Results ]____________________________\n\n";

    cout << "\tGame Rounds        : " << Rounds << endl;
    cout << "\tPlayer Won times   : " << PlayerWinCounter << endl;
    cout << "\tComputer Won times : " << ComputerWinCounter << endl;
    cout << "\tDraw times         : " << DrawCounter << endl;
    cout << "\tFinile Winner      : " << WhoWinner << endl;

    cout << "\n\t___________________________________________________________________________\n\n";
}

void RestScreen()
{
    system("color 0F");
    system("cls");
}

short HowManyRounds()
{
    short ChoiceCountRounds = 0;
    do
    {
        cout << "How many rounds that you want (1 To 100)" << endl;
        cin >> ChoiceCountRounds;

    } while (ChoiceCountRounds < 1 || ChoiceCountRounds>100);

    return ChoiceCountRounds;
}

void StartGame(short ChoiceCountRounds, short& Player, short& Computer)
{
    WhoIsWin Winner;
    short PlayerWinCounter = 0, ComputerWinCounter = 0, DrawCounter = 0;
    string  Finile_Winner = "";

    for (int i = 1;i <= ChoiceCountRounds;i++)
    {
        cout << "\nRound [" << i << "]" << " begins : \n\n";

        ReadInputsOpponent(Player, Computer);

        Winner = GetWinner(Player, Computer);

        ChangeScreenColor(Winner);

        cout << "\n\n__________________Round [" << i << "]" << "__________________\n\n";

        ShowPointsEachRound(Winner, Player, Computer);

        cout << "\n\n________________________________________________________________\n\n";

        WinLossDrawCounter(Winner, PlayerWinCounter, ComputerWinCounter, DrawCounter);

    }
    Finile_Winner = FinileWinner(PlayerWinCounter, ComputerWinCounter);

    GameResult(ChoiceCountRounds, PlayerWinCounter, ComputerWinCounter, DrawCounter, Finile_Winner);

}





int main()
{
    srand((unsigned)time(NULL));

    short Player = 0, Computer = 0;
    char PlayAgain = 'a';

    do {
        RestScreen();

        StartGame(HowManyRounds(), Player, Computer);


        cout << "\nDo you want to play again? Y/N?" << endl;
        cin >> PlayAgain;


    } while (PlayAgain == 'Y' || PlayAgain == 'y');





    return 0;
}