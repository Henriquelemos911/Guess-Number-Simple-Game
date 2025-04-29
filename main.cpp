#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <cctype>

using namespace std;

int main()
{
    srand(time(0));

    int secretNumber = rand() % 101;
    int userAnswer;
    int quantityTries = 0;
    char dificulty;

    try
    {
        // Dificulty selector.
        cout << "CHOOSE A DIFICULTY: " << endl;
        cout << "- Easy:   (E)   quantity of tries: 10" << endl;
        cout << "- Normal: (N)   quantity of tries: 7" << endl;
        cout << "- Hard:   (H)   quantity of tries: 5" << endl;

        cin >> dificulty;
        if (!cin)
        { // verify the input if that is a number or not.
            throw runtime_error("Error: Invalid input!.");
        }

        dificulty = toupper(dificulty);

        if (dificulty == 'E')
        {
            quantityTries = 10;
        }
        else if (dificulty == 'N')
        {
            quantityTries = 7;
        }
        else if (dificulty == 'H')
        {
            quantityTries = 5;
        }
        else
        {
            throw runtime_error("Error: Invalid difficulty selected!");
        }

        int triesUsed = 0;

        while (true)
        {
            // The principal part of the game.
            cout << "\nYou already have: " << quantityTries << " tries\n";
            cout << "Type a number from 0 ~ 100: \n";
            cin >> userAnswer;
            triesUsed++;
            quantityTries--;
            if (!cin)
            { // verify the input if that is a number or not.
                throw runtime_error("Error: Invalid input!You typed something that is not a number.");
            }

            if (quantityTries == 1 && userAnswer != secretNumber)
            {
                cout << "Your tries are ended:(\nThe secret number is: ";
                cout << secretNumber << endl;
                break;
            }
            else if (userAnswer > secretNumber)
            {
                cout << "The secret number is smaller!\n";
            }
            else if (userAnswer < secretNumber)
            {
                cout << "The secret number is bigger!\n";
            }
            else
            {
                cout << "CONGRATULATIONS! You got the right secret number\nIt was: " << secretNumber << endl;
                cout << "You guessed in: " << triesUsed << " Tries" << endl;
                break;
            }
        }
    }

    catch (const exception &e)
    {
        cout << "\nError: Something got wrong: " << e.what() << endl;
    }
    return 0;
}
