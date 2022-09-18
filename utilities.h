#include <vector>
#include <string>
using namespace std;

int incrementByValueNumTimes(int startValue, int increment, int numTimes);

void incrementRef(int& a, int increment, int numTimes);

void swap(int& x, int&y);

void randomizeVector(vector<int> &tableRandom, int n);

void sortVector(vector<int> &tableRandom);

double medianOfVector(vector<int> &tableRandom);

struct Student
{
    string navn;
    string studyProgram; 
    int age;
};

void printStudent(Student student);

string randomizeString(int n, char upperbound, char lowerbound);

string readInputString(int n, char upperbound, char lowerbound);

char failInput(char input);

int countChar(int n, string word);