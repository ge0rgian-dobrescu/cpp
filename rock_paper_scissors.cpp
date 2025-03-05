#include <iostream>
#include <cstdlib> // librarie pentru functia rand(), srand().
#include <cstdio> // librarie pentru functia getchar.

using namespace std;

char CompChoice (){  // functie tip char - returneaza o litera - genereaza alegerea calculatorului. 
    int random = rand() % 3;
    if (random == 0) return 'R';
    if (random == 1) return 'S';
    return 'P';
}

string whoWins (char user, char computer){ // - functie tip string - returneaza o propozitie - determina castigatorul.
    // cazul I - egalitate.
    if (user == computer) return "Draw. No one wins :("; 

    // cazul II - user-ul castiga.
    if ( (user == 'R' && computer == 'S') || (user == 'P' && computer == 'R') || (user == 'S' && computer == 'P') ){  return "You win!"; }
    
    // cazul III - alt rezultat => calculatorul castiga.
    return "You lose!"; 
}

int main(){
   
    srand(time(0)); // generarea variantei calculatorului.

    cout<< "Insert your option(Rock(R), Paper(P), Scissors(S)):" << endl;
    
    char User;
    cin >> User; 

    if (User != 'R' && User != 'S' && User != 'P' ){ // caz invalid
        cout << "Invalid choice." << endl;
        return 1; // iesire din functie
    }

    char Computer = CompChoice();

    cout << "You chose: " << User << endl;
    cout << "Computer chose: " << Computer << endl;

    cout << whoWins(User, Computer) << endl;
    
    
    return 0;
}