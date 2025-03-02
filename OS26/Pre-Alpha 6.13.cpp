#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <time.h>
#include <stdio.h>

void setDarkBlueColor() {
    textcolor(RED);
    textbackground(BLUE);
}

void resetColor() {
    textcolor(RED);
    textbackground(BLUE);
}

void displayMenu() {
    clrscr();
    setDarkBlueColor();
    cout << "===| NeTT OS25 6.13 |===\n";
    cout << "1 - Calculator\n";
    cout << "2 - Clock\n";
    cout << "3 - Write\n";
    cout << "4 - Echo\n";
    cout << "5 - Changelog\n";
    cout << "6 - Exit\n";
    cout << "Enter an option: ";
    resetColor();
}

void displayCalculatorMenu() {
    clrscr();
    setDarkBlueColor();
    cout << "***| Calculator |***\n";
    cout << "1 - Add\n";
    cout << "2 - Subtract\n";
    cout << "3 - Multiply\n";
    cout << "4 - Home\n";
    cout << "Enter an option: ";
    resetColor();
}

void performAddition() {
    clrscr();
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Result: " << num1 + num2 << "\n";
    getch();
}

// subtract
void performSubtraction() {
    clrscr();
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Result: " << num1 - num2 << "\n";
    getch();
}

// multiply 
void performMultiplication() {
    clrscr();
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Result: " << num1 * num2 << "\n";
    getch();
}

// date and time
void displayClock() {
    clrscr();
    time_t now = time(0);
    tm* ltm = localtime(&now);

    cout << "Date: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << "\n";
    cout << "Time: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << "\n";
    getch();
}

// echo
void echoUserInput() {
    clrscr();
    char userInput[100];
    cin.ignore();  // ignore previous newline character
    cout << "Enter text: ";
    cin.getline(userInput, 100);
    cout << "ECHO-$ " << userInput << "\n";
    getch();
}

// text
void displayTextMenu() {
    clrscr();
    setDarkBlueColor();
    cout << "***| Write |***\n";
    cout << "1 - Open Document\n";
    cout << "2 - Edit Document\n";
    cout << "3 - Home\n";
    cout << "Enter an option: ";
    resetColor();
}

// Open
void openDocument() {
    clrscr();
    ifstream inputFile("TEXT.TXT");

    if (inputFile) {
        cout << "Opening document...\n";
        char data[100];
        while (inputFile.getline(data, 100)) {
            cout << "Document contents: " << data << "\n";
        }
        inputFile.close();
    } else {
        cout << "Error: Unable to open document\n";
    }

    getch();
}

// Edit
void editDocument() {
    clrscr();
    ofstream outputFile("TEXT.TXT", ios::app);

    if (outputFile) {
        char userData[100];
        cin.ignore();  // ignore previous newline character
        cout << "Enter document contents: ";
        cin.getline(userData, 100);
        outputFile << userData << "\n";
        cout << "Saved to document\n";
        outputFile.close();
    } else {
        cout << "Error: Unable to edit document\n";
    }

    getch();
}

// changelog
void displayChangelog() {
    clrscr();
    cout << "***| Changelog |***\n";
    cout << "- NeT OS25 6.13\n";
    cout << "- Changed the exiting text\n";
    cout << "- Better write\n";
    cout << "- Stablility enhancements\n";
    cout << "- C 2025 NeT Systems\n";
    getch();
}

// Main 
int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int calcChoice;
                do {
                    displayCalculatorMenu();
                    cin >> calcChoice;
                    switch (calcChoice) {
                        case 1:
                            performAddition();
                            break;
                        case 2:
                            performSubtraction();
                            break;
                        case 3:
                            performMultiplication();
                            break;
                        case 4:
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                            getch();
                    }
                } while (calcChoice != 4);
                break;
            }
            case 2:
                displayClock();
                break;
            case 3: {
                int textChoice;
                do {
                    displayTextMenu();
                    cin >> textChoice;
                    switch (textChoice) {
                        case 1:
                            openDocument();
                            break;
                        case 2:
                            editDocument();
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                            getch();
                    }
                } while (textChoice != 3);
                break;
            }
            case 4:
                echoUserInput();
                break;
            case 5:
                displayChangelog();
                break;
            case 6:
                cout << "Exiting OS15...\n";
                break;
            default:
                cout << "ERROR\n";
                getch();
        }

    } while (choice != 6);

    return 0;
}
