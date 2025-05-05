/*
    Program File Name: Ch6Ex24.cpp
    Programmer: Gabriel Inocentes
    Date: May 5, 2025
    Requirements: Make a program that simulates the game "Rock Paper Scissors"
*/

#include <iostream>
#include <random>
#include <time.h>

using namespace std;

void inputChecker(int& choice);
void menuDisplay();

int main() {
    //Function that displays menu options
    menuDisplay();
    
    //Declares choice variables and allows input
    int choice;
    cin >> choice;
    inputChecker(choice);

    //Declares the what the selection would need to be in order to win, in the following correlation:
    // 1 Rock
    // 2 Paper
    // 3 Scissors
    const int rules[4] = { 0,3,1,2 };
    const string names[4] = { "", "Rock", "Paper", "Scissors"};
    int i = 1;

    while (i == 1) {
        //Generates random number
        srand(time(0));
        int randChoice = rand() % 3 + 1;
        cout << endl << names[choice] << " selected" << endl;
        cout << "The computer chose " << names[randChoice] << endl << endl;

        //Tie case
        if (choice == randChoice) {
            cout << "You and the computer both chose " << names[choice] << endl;
            menuDisplay();
            cin >> choice;
            i = 1;
            cin.clear();
        }
        //Win case
        else if (rules[choice] == randChoice) {
            cout << "You win, " << names[choice] << " beats " << names[randChoice] << endl;
            i = 0;
            cin.clear();
        }
        //Loss case
        else {
            cout << "You lose, " << names[randChoice] << " beats " << names[choice] << endl;
            i = 0;
            cin.clear();
        }
    }
}


//Checks to make sure input is valid
void inputChecker(int& choice) {
    while (choice < 1 || choice > 3 || cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "The entered input is invalid, please try again with one of the following options: " << endl;
        menuDisplay();
        cin >> choice;
    }
}


//Displays menu options 
void menuDisplay() {
    cout << endl << "Select with the corresponding number, Rock, Paper, or Scissors: " << endl;
    cout << "1. Rock " << endl;
    cout << "2. Paper " << endl;
    cout << "3. Scissors" << endl << endl;
}