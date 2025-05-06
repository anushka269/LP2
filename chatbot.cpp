#include <iostream>
#include <string>
using namespace std;

// Stage 1: Welcome message
void greet() {
    cout << "Hello! My name is ChattyBot.\n";
    cout << "I was created to assist you and make your day fun.\n";
}

// Stage 2: Ask for user's name
void askName() {
    cout << "Please, remind me your name.\n";
    string name;
    getline(cin, name);
    cout << "What a great name you have, " << name << "!\n";
}

// Stage 3: Guess the age using remainders
void guessAge() {
    int rem3, rem5, rem7;
    cout << "Let me guess your age.\n";
    cout << "Enter remainders of dividing your age by 3, 5 and 7.\n";
    cin >> rem3 >> rem5 >> rem7;
    int age = (rem3 * 70 + rem5 * 21 + rem7 * 15) % 105;
    cout << "Your age is " << age << "; that's a good time to start programming!\n";
}

// Stage 4: Count to a number
void countToNumber() {
    int num;
    cout << "Now I will prove to you that I can count to any number you want.\n";
    cin >> num;
    for (int i = 0; i <= num; ++i)
        cout << i << "!\n";
}

// Stage 5: Ask a multiple-choice question
void quiz() {
    cout << "Let's test your programming knowledge.\n";
    cout << "Why do we use functions?\n";
    cout << "1. To repeat a statement multiple times.\n";
    cout << "2. To decompose a program into several small subroutines.\n";
    cout << "3. To determine the execution time of a program.\n";
    cout << "4. To interrupt the execution of a program.\n";

    int answer;
    do {
        cin >> answer;
        if (answer != 2)
            cout << "Please, try again.\n";
    } while (answer != 2);
    
    cout << "Congratulations, that's correct!\n";
}

// Ending
void end() {
    cout << "Thank you for chatting with me. Have a great day!\n";
}

int main() {
    greet();           // Stage 1
    askName();         // Stage 2
    guessAge();        // Stage 3
    countToNumber();   // Stage 4
    quiz();            // Stage 5
    end();             // Ending message
    return 0;
}
