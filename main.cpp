#include <iostream>
#include <string>
using namespace std;

// functions
void printWelcome();
void printMenu();
int getOption();
string getPlayerName();
int getRollOne();
int getRollTwo(int rollOne);
int calcTotalScore(int rollOne, int rollTwo);
void printScoreMessage(string playerName, int totalScore);
void printWinner(int numPlayers, string playerNames[], int playerScores[]);

// constants
const int MAX_PLAYERS = 100;
const int STRIKE_SCORE = 10;
const int MENU_ADD_PLAYERS = 1;
const int MENU_EXIT = 2;

int main() {
  int rollOne = 0;
  int rollTwo = 0;
  int totalScore = 0;
  int option = 0;
  int numPlayers = 0;
  string playerName = "";
  int playerScores[MAX_PLAYERS] = {0};
  string playerNames[MAX_PLAYERS];

  printWelcome();

  while (option != MENU_EXIT) {
    printMenu();

    option = getOption();

    if (option == MENU_ADD_PLAYERS) {
      playerNames[numPlayers] = getPlayerName();

      rollOne = getRollOne();
      
      rollTwo = getRollTwo(rollOne);

      totalScore = calcTotalScore(rollOne, rollTwo);

      playerScores[numPlayers] += totalScore;

      printScoreMessage(playerNames[numPlayers], playerScores[numPlayers]);

      numPlayers++;
    }

    else if (MENU_EXIT) {
      printWinner(numPlayers, playerNames, playerScores);
      break;
    }
  }

  return 0;
}


// printWelcome
// Pre: none
// Post:welcomes user and informs them of the menu
void printWelcome() {
  cout << "Welcome to The Alley!\n" << endl;
  cout << "Please enter options 1 or 2 from the menu below!" << endl;
}


// printMenu
// Pre:none
// Post:User will choose from menu items
void printMenu() {
  cout << "============================" << endl;
  cout << "        The Alley        " << endl;
  cout << "============================" << endl;
  cout << "1. Add players" << endl;
  cout << "2. Exit" << endl;
  cout << "============================" << endl;
  cout << "Enter your choice: ";
}


// getOption
// Pre:none
// Post:reads the user's menu choice
int getOption() {
  int option;
  cin >> option;
  return option;
}


// getPlayerName
// Pre:none
// Post:string function asks user for name
string getPlayerName() {
  string playerName = "";
  cout << "Please enter Bowler name: ";
  cin.ignore();
  getline(cin, playerName);
  return playerName;
}


// getRollOne
// Pre:none
// Post:gets score from user
int getRollOne() {
  int rollOne = 0;
  cout << "Roll One Score: ";
  cin >> rollOne;
  return rollOne;
}


// getRollTwo
// Pre:none
// Post:gets second score from user, if strike function will not activate
int getRollTwo(int rollOne) {
  int rollTwo = 0;
  if (rollOne == 10) {
    cout << "You got a strike!!!" << endl;
    return 0;
  }

  cout << "Roll Two Score: ";
  cin >> rollTwo;
  return rollTwo;
}


// calcTotalScore
// Pre:Calulates user score from rollOne & rollTwo
// Post:Adds roll one and roll two to create a total number.
int calcTotalScore(int rollOne, int rollTwo) {
  int totalScore = 0;
  totalScore = rollOne + rollTwo;
  return totalScore;
}


// printScoreMessage
// Pre:Adds score one and 2 for one user
// Post: Tells user what their final score is.
void printScoreMessage(string playerName, int totalScore) {
  cout << playerName << "'s total score is: " << totalScore << endl;
  // cout << "Thank you for bowling at The Alley!" << endl;
}


// printWinner
// Pre:gets the highest score and name of player
// Post: Gets the winner from totaling up the scores and
// seeing which is higher, prints out goodbye message
void printWinner(int numPlayers, string playerNames[], int playerScores[]) {
  int maxScore = -1;
  string maxPlayer = "";
  for (int i = 0; i < numPlayers; i++) {
    if (playerScores[i] > maxScore) {
      maxScore = playerScores[i];
      maxPlayer = playerNames[i];
    }
  }
  cout << "The winner is " << maxPlayer << " with a score of " << maxScore
       << "!" << endl;
  cout << "Thank you for bowling at The Alley!" << endl;
}
