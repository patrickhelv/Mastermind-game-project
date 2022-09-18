#include "test.h"
#include "utilities.h"
#include <iostream>
#include <vector> 

using namespace std;

void testCallByValue(){
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0 : " << v0 
         << " increment: " << increment
         << " iterations: " << iterations
         << " results: " << result << '\n';
}

void testCallByValueRef(){
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementRef(v0, increment, iterations);
    cout << "ny v0 er " << v0 << endl;

}

void testSwap(){
    int a = 100; 
    int b = 200;
    cout << "a inneholder før swap " << a << endl;
    cout << "b inneholder før swap " << b << endl;
    swap(a, b);
    cout << "a inneholder etter swap " << a << endl;
    cout << "b inneholder etter swap " << b << endl;
}

void testVectorSorting(){
    vector<int> percentages;
    int n = 8; 
    randomizeVector(percentages, n);

    for(int i = 0; i < n; i++){
        cout << "Prosent : " << i << " : " << percentages[i] << endl;
    }

    swap(percentages[0], percentages[1]);

    cout << "Etter swap : " << percentages[0] <<" | " <<  percentages[1] << endl;

    cout << "median : " << medianOfVector(percentages) << endl;

}

void sortVector(){
    vector<int> percentages;
    int n = 8; 
    randomizeVector(percentages, n);

    sortVector(percentages);
    for(int i = 0; i < percentages.size(); i++){
        cout << "Prosent : " << i << " : " << percentages[i] << endl;
    }

}

void testPrintStudent(){
    Student student;
    Student student2;
    student.navn = "Per";
    student.studyProgram = "dataingeniør";
    student.age = 26;

    printStudent(student);

    student2.navn = "Montenegrodu93";
    student2.studyProgram = "Aeronotique";
    student2.age = 19;

    printStudent(student2);
}


void testString(){
    char lowerbound = 'a';
    char upperbound = 'f';

    
    vector<int> gradescount;
    int n = 8;
    string grades;
    string temp;

    grades = randomizeString(n, toupper(upperbound), toupper(lowerbound));
    cout << "Word is : " << grades << endl;

    //temp = readInputString(n, upperbound, lowerbound);
    //cout << "word is : " << temp << endl;
    
    for(int i = 0; i < 6; i++){
        gradescount.push_back(countChar(65 + i, grades));
    }
    char value;
    for(int i = 0; i < gradescount.size(); i++){
        value = static_cast<int>(65 + i);
        cout << "Antall forekomster av " << temp << " er " << gradescount[i] << endl;
    }
    int counter = 0;
    for(int i = 0; i < gradescount.size(); i++){
        counter += gradescount[i] * (5 - i);
        cout << "counter " << counter << endl;
    }
    cout << "Snitt av karakterene er : " << static_cast<double>(counter) / static_cast<double>(gradescount.size()) << endl;
    cout << "\n\n\n\n\n";

}






