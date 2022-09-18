#include "utilities.h"
#include <iostream>
#include <vector> 
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

const int MAX_NUM = 100;



int incrementByValueNumTimes(int startValue, int increment, int NumTimes){
    for(int i = 0; i < NumTimes; i++){
        startValue += increment;
    }

    return startValue;
}

void incrementRef(int& a, int increment, int numTimes){
    for(int i = 0; i < numTimes; i++){
        a += increment;
    }
}

void swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

void randomizeVector(vector<int> &tableRandom, int n){
    srand(static_cast<unsigned int>(time(nullptr)));
    for(int i = 0; i < n; i++){
        int u = rand() % MAX_NUM;
        cout << "u : " << u << endl;
        tableRandom.push_back(u);
    }
}

void sortVector(vector<int> &tableRandom){
    int temp = 0;
    for(unsigned int i = 1; i < tableRandom.size(); i++){
        temp = tableRandom[i];
        for(int j = i; j > 0; j--){
            if(tableRandom[j-1] > tableRandom[j]){
                temp = tableRandom[j];
                tableRandom[j] = tableRandom[j-1];
                tableRandom[j-1] = temp;
            }
        }
    }
}

double medianOfVector(vector<int> &tableRandom){
    sortVector(tableRandom);
    int temp = 0;
    double ans = 0;

    if(tableRandom.size()%2 != 0){ // method to find the median, check if number is odd or not
        temp = (tableRandom.size() - 1) / 2; // finds the index by subtracting the length of the vector and divides by 2
        ans = tableRandom[temp];
    }else{
        temp = tableRandom.size() / 2; // divides the vector by 2 if the size is an even number 
        ans = ( static_cast<double>(tableRandom[temp]) + static_cast<double>(tableRandom[temp - 1]) ) / 2; // calculates the average by adding the smallest numbers and divides them by 2
    }
    return ans;
}

void printStudent(Student student){ //method to print out student
    cout << "Navn på student : " << student.navn << endl;
    cout << "Studie program : " << student.studyProgram << endl;
    cout << "Alder : " << student.age << endl;
}


string randomizeString(int n, char upperbound, char lowerbound){
    srand(static_cast<unsigned int>(time(nullptr)));
    char value;
    int temp;
    string word;

    int intupperbound = static_cast<int>(upperbound);
    int intlowerbound = static_cast<int>(lowerbound);
    for(int i = 0; i < n; i++){ //for loop that generate a anscii char to generate a word
        temp = (rand() % ( (intupperbound - intlowerbound) + 1) ) + intlowerbound;
        value = static_cast<char>(temp);
        word += value;
    }
    return word;
}

char failInput(char input){ // Checks if there are error with cin
    while(cin.fail() || isdigit(input)){
        cin.clear();
        cout << "The input was wrong " << endl;
        cout << "Please enter a new character : " << endl;
        cin >> input;
    }
    return input;
}

string readInputString(int n, char upperbound, char lowerbound){
    char input;
    string output;
    string convertchar;
    bool temp = false;

    for(int i = 0; i < n; i++){
        cout << "Skriv inn "  << n << " tegn for å ha i en streng fra " << lowerbound << " til " << upperbound << endl;
        cin >> input;

        int intupperbound = static_cast<int>(upperbound); //char to int
        int intlowerbound = static_cast<int>(lowerbound);
        int intupperboundsUp = static_cast<int>(toupper(upperbound));
        int intlowerboundUp = static_cast<int>(toupper(lowerbound));
        
        
        input = failInput(input);
        int intinput = static_cast<int>(input);
        
        //if setning som sjekker om char skrevet inn er inni definert grensene hvis ja returnerer ingenting mens hvis ja så endrer verdi på temp
        if(!((intinput >= intlowerbound && intinput <= intupperbound) || (intinput >= intlowerboundUp && intinput <= intupperboundsUp))){
            temp = true;
        }
        while(temp){ // hvis temp er endret så kjører denne kodesnipen som spør brukeren å taste inn ny char hvis den ikke er innenfor grensene
            cout << "Du må taste inn en character innenfor grensene " << endl;
            cout << "vennligst prøv igjen, skriv inn en ny character fra " << lowerbound << " til " << upperbound << " : " << endl;
            cin >> input;
            int intinput = static_cast<int>(input);
            input = failInput(input);  //gjør en sjekk igjen for hvis man ikke har tastet inn rett char innefor grensen
            
            if(!((intinput >= intlowerbound && intinput <= intupperbound) || (intinput >= intlowerboundUp && intinput <= intupperboundsUp))){
                temp = true;
            }else{
                temp = false;
            }
        }
        cin.ignore(n, '\n');
        output += toupper(input); // legger til char til stringen output
    }

    
    return output;
}

int countChar(int n, string word){
    int counter = 0;
    char tochar = static_cast<char>(n);
    for(int i = 0; i < word.length(); i++){
        if(tochar == word[i]){
            counter++;
        }
    }
    return counter;
}


