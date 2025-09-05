//Rene Rodriguez 09/05/2025 Lab Activities: Arrays & Vectors
//Challenge 2: Dynamic Grade Analysis with std::vector
#include<iostream>
#include <limits>
#include<vector>
using namespace std;

//i for iterating through vectors
int i;

//original prompt for users
void promptUser(){
    cout << "What would you like to do?" << endl;
    cout << "\t 1. Add a Grade" << endl;
    cout << "\t 2. Display All Grades" << endl;
    cout << "\t 3. Calculate Average Grade" << endl;
    cout << "\t 4. Find Highest and Lowest Grade" << endl;
    cout << "\t 5. Count Grades Above Threshold" << endl;
    cout << "\t 6. Quit" << endl;
}
//Used to verify input
int getInput(){
    int input;
    cin >> input;
    while(cin.fail()){
        cout << "Invalid input, try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cin >> input;

    }
    cout << "You entered " << input << endl;
    return input;
}
//Adds user input to vector using a reference parameter
void addGrade(vector<double>& updatedVect){
    double input;
    //Do while statement that makes sure user input isn't negative
    do{
        cout << "Enter grade to be added." << endl;
        input = getInput();
        if (input < 0){
            cout << "Can't enter a negative number!" << endl;
        }
    }while(input < 0);
    //adds user input to vector
    updatedVect.push_back(input);
}
//Iterates through vector which is a reference parameter
void displayGrades(vector<double>& myVect){
    cout << "Grades: ";
    for (i = 0; i < myVect.size(); ++i){
        cout << myVect.at(i) << "%";
        if (i < myVect.size() - 1){
            cout << ", ";
        }
    }
    cout << endl;
}
//Calculates the average while handling if the vector is empty to prevent errors
void calcAverage(const vector<double>& myVect){
    double sum = 0;
    if(myVect.size() == 0){
        cout << "No grades entered!" << endl;
    } else{
        for (i = 0; i < myVect.size(); ++i){
        sum = sum + myVect.at(i);
        }
    cout << "Average: " << sum / myVect.size() << "%" << endl;
    }
}
//Finds the highest and lowest grade in vector
void highAndLow(const vector<double>& myVect){
    double highestVal;
    double lowestVal;
    if(myVect.size() == 0){
        cout << "No grades entered!" << endl;
    } else{
        //I initialized at myVect.at(0) for good practice
        highestVal = myVect.at(0);
        lowestVal = myVect.at(0);
        for (i = 0; i < myVect.size(); ++i){
            if(myVect.at(i) > highestVal){
                highestVal = myVect.at(i);
            }
            if(myVect.at(i) < lowestVal){
                lowestVal = myVect.at(i);
            }
        }
        cout << "Highest Grade: " << highestVal << "%" << endl;
        cout << "Lowest Grade: " << lowestVal << "%" << endl;
    }
}
//Counts how many grades are greater than threshold which is input by user
void gradeThreshold(const vector<double>& myVect){
    cout << "Please enter threshold" << endl;
    int threshold = getInput();
    int count = 0;
    for (i = 0; i < myVect.size(); ++i){
        if(myVect.at(i) > threshold){
            count++;
        }
    }
    cout << "Grades greater than " << threshold << "%" << ": " << count << endl;
          
}
int main()
{
    vector<double> grades;
    int userInput;
    double average;
    //Do while statement that will continuously prompt user as long as
    //user input is not 6
    do{
        promptUser();
        cin >> userInput;
        //Verifies initial user input
        if (cin.fail()) {
            cout << "Invalid input, try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; 
        } else {
            cout << "You entered: " << userInput << endl;
        }
        //Switch statement that calls my functions conditionally
        switch (userInput){
            case 1:
                cout << "You chose Add a Grade" << endl;
                addGrade(grades);
                break;
            case 2:
                cout << "You chose Display All Grades" << endl;
                displayGrades(grades);
                break;
            case 3:
                cout << "You chose Calculate Average Grade" << endl;
                calcAverage(grades);
                
                break;
            case 4:
                cout << "You chose Find Highest and Lowest Grade" << endl;
                highAndLow(grades);
                break;
            case 5:
                cout << "You chose Count Grades Above Threshold" << endl;
                gradeThreshold(grades);
                break;
            case 6:
                cout << "Goodbye World";
                break;
            default:
                cout << "Enter number (1-6)" << endl;
        }
    } while(userInput != 6);
    
    return 0;
}