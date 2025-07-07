#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <string>

using namespace std;

enum class Difficulty {EASY = 1, MEDIUM, HARD};

struct GameSettings{
    int maxNumber;
    int attempts;
    int prize;
};

class Game{
private:
    map<Difficulty, GameSettings> settingsMap;
    int totalWinnings;
    string playerName;

public:
    Game(){
        totalWinnings = 0;
        settingsMap[Difficulty::EASY] = {10, 5, 100};
        settingsMap[Difficulty::MEDIUM] = {50, 4, 300};
        settingsMap[Difficulty::HARD] = {100, 3, 800};
    }

    void start(){
        cout << "Welcome to Guess the Number! \n";
        cout << "Enter your name:";
        cin >> playerName;

        char playAgain;

        do{
            Difficulty difficulty = chooseDifficulty();
            playRound(difficulty);
            cout << "What about another round? (Y/N): ";
            cin>>playAgain;
        }while (playAgain =='Y' || playAgain == 'y');
        cout << "Well it was good to see you, " << playerName << "! Your total winnings: $" << totalWinnings << endl;
    }

private:
    Difficulty chooseDifficulty(){
        int choice;
        cout << "\n Choose Difficulty Level: \n";
        cout << "1. Easy (1-10, 5 attempts, $100 prize)\n";
        cout << "2. Medium (1-50, 4 attempts, $300 prize)\n";
        cout << "3. Hard (1-100, 3 attempts, $800 prize)\n"; 
        cout << "Enter choice (1-3): ";
        cin >> choice;

        while (choice < 1 || choice > 3){
            cout << "Invalid choice. Please enter 1,2 or 3: ";
            cin >> choice;
        }

        return static_cast<Difficulty>(choice);
    }

    void playRound (Difficulty difficulty){
        GameSettings settings = settingsMap[difficulty];
        int target = rand() % settings.maxNumber + 1;
        int guess;
        bool won = false;

        cout << "\nGuess a number between 1 and " << settings.maxNumber << ". You have " << settings.attempts << "attempts. \n";

        for (int i = 1 ; i <= settings.attempts; ++i){
            cout << "Attempt " << i << ": ";
            cin>>guess;

            if (guess == target){
                cout << "Congratulations!!! You guessed it! \n";
                cout << "You won $" << settings.prize << "!\n";
                totalWinnings += settings.prize;
                won = true;
                break;
            }else if (guess < target) {
                cout << "Too low! \n";
            }else{
                cout << "Too high! \n";
            }
        }

        if (!won){
            cout << "Sorry, you didn't guessed it. The number was: " << target << "\n";
        }
    }

};

int main(){
    srand(static_cast<unsigned int>(time(0)));
    Game game;
    game.start();
    return 0;
}