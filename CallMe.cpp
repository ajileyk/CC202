#include <iostream>
#include <cctype>
using namespace std;

// to check if the user only input numeric values
bool isNumeric(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {

    string milTime;
    string delimiter = ":";
    int hours, minutes;

    do {
        cout << "\nTime the call started (in military format e.g. 16:00): ";
        cin >> milTime;

        // to check if milTime is exactly 5 characters
        if (milTime.length() != 5) {
            cout << "\nInvalid input. Please try again using HH:MM.\n";
            continue;
        }

        size_t pos = 0;
        string token;

        // kay basta ga error kung wala flag hahaha ty chatgpt
        bool isValidHour = true;

        while ((pos = milTime.find(delimiter)) != string::npos) {
            token = milTime.substr(0, pos);

            // conversion of hours into an int variable
            if (token == "00" || token == "0") {
                hours = 0;
            } else {

                // calling the isNumeric function to check if it's a valid integer
                if (isNumeric(token)) {
                    hours = stoi(token);
                } else {
                    cout << "Invalid value. Please enter a valid integer for hours." << endl;
                    isValidHour = false;
                    break;
                }

                // to check if hours are in the valid range
                if (hours < 0 || hours > 24) {
                    cout << "Invalid value. Please enter an hour between 0 and 24." << endl;
                    isValidHour = false;
                    break;
                }
            }

            milTime.erase(0, pos + delimiter.length());
        }

        // to check if hour is valid before proceeding
        if (!isValidHour) {
            continue;
        }

        // to check if there are no more colons remaining in milTime
        if (milTime.find(delimiter) != string::npos) {
            cout << "Invalid value. Please enter a valid integer for minutes." << endl;
            continue;
        }

        // the remaining value in milTime will be the minutes
        if (isNumeric(milTime)) {
            minutes = stoi(milTime);
        } else {
            cout << "Invalid value. Please enter a valid integer for minutes." << endl;
            continue;
        }

        // to check if minutes are in the valid range
        if (minutes < 0 || minutes > 59) {
            cout << "Invalid value. Please enter minutes between 0 and 59." << endl;
            continue;
        }

        // i output ko lang to check nga gagana
        cout << endl;
        cout << "Hours: " << hours << endl;
        cout << "Minutes: " << minutes << endl;
        cout << endl;

        break;

    } while (true);

    return 0;
}
