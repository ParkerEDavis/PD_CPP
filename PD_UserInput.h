#ifndef USER_INPUT_H_INCLUDED
#define USER_INPUT_H_INCLUDED

#include <iostream>

using namespace std;

namespace PD_UserInput
{
    /**
    User Input Function
    @post Returns user's input, with modifications.
    Changes input to lowercase and clears the cin buffer afterwards.
    If a fail state is called (Should only be when a char value is passed to an int), then a value of -1 is returned
    **/
        template <typename T>
        inline T userInput();

    /**
    String To Boolean
    @pre - Any string is passed as argument.
    @post - True or False is returned, depending on contents of string.
    For True: "yes", "y", "1", "True"
    For True: "no", "n", "0", "False"

    Any value that is not explicitly "yes" returns false.
    **/
        inline bool stringToBoolean(string user_input);

    /**
    Handles Integer-Based menu choices
    @post - Returns an integer chosen by the user.
    Range is min_value - max_value, inclusive
    **/
        inline int menuChoice(int min_value, int max_value);

    /**
    Turns a string containing any cases, and turns all letters into lowercase
    @post - Entered string is returned in lowercase form
    **/
        inline string stringToLower(string given_string);

    /**
    Turns a string containing any cases, and turns all letters into uppercase
    @post - Entered string is returned in uppercase form
    **/
        inline string stringToUpper(string given_string);
}


template <typename T>
T PD_UserInput::userInput()
{
    T input;

    /** Take User Input **/
    if (!(cin >> input)) /// If cin fails (a character input for an integer), then clear the fail state.
    {
        cin.clear();
        input = -1; /// Fail Value
    }

    /** Clear the rest of the cin buffer for any bad input, or any lingering characters in a char input **/
    cin.ignore(1000, '\n');

    return input;
}

bool PD_UserInput::stringToBoolean(string given_string)
{
    bool yesOrNo;

    /// Change all characters in the string to lowercase, for ease of checking.
    given_string = PD_UserInput::stringToLower(given_string);

    /// Valid True Options: yes, y, true, t, 1
    if ((given_string == "yes") || (given_string == "y") || (given_string == "true") || (given_string == "t") || (given_string == "1"))
    {
        yesOrNo = true;
    }
    /// If user enters an equivalent no, or any invalid value, then the program returns false as a default.
    else
    {
        yesOrNo = false;
    }

    return yesOrNo;
}


int PD_UserInput::menuChoice(int min_value, int max_value)
{
    bool looping = true;
    int choice;

    do /// User is stuck in this loop until they choose a valid option.
    {
        /** Get User Input **/
        choice = userInput<int>();

        if ((choice < min_value) || (choice > max_value)) /// If the user's choice is outside the given bounds, the loop does not exit.
        {
            cout << "Invalid Input, enter a number (" << min_value << " - " << max_value << ')' << endl;
        }
        else /// If the choice is valid, the loop ends, and the user's choice is returned.
        {
            looping = false;
        }
    } while (looping);

    return choice;
}


string PD_UserInput::stringToLower(string given_string)
{
    /// Iterates through all characters in string and, if char is an uppercase letter, turn it into a lowercase version
    for (int i = 0; i < given_string.length(); i++)
    {
        if (isalpha(given_string[i]) && isupper(given_string[i]))
        {
            given_string[i] = tolower(given_string[i]);
        }
    }

    return given_string;
}

string PD_UserInput::stringToUpper(string given_string)
{
    /// Iterates through all characters in string and, if char is an uppercase letter, turn it into a lowercase version
    for (int i = 0; i < given_string.length(); i++)
    {
        if (isalpha(given_string[i]) && isupper(given_string[i]))
        {
            given_string[i] = toupper(given_string[i]);
        }
    }

    return given_string;
}

#endif // USER_INPUT_H_INCLUDED