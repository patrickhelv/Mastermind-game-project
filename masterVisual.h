#pragma once
#include "Graph.h"
#include "Simple_window.h"

constexpr int winW = 500; //velg vindu bredde
constexpr int winH = 500; // velg vindu høyde

constexpr int padY = (winH) / (2*8+1); // velg  x skalering
constexpr int padX = (winW) / (2*5+1); // velg y skalering
constexpr int radCircle = padX/8; // velg sirkel radius


constexpr int btnW = padX;
constexpr int btnH = padY;
constexpr int inBoxW = winW -3*padX-btnW;
constexpr int inBoxH = padY;
constexpr Point upperLeftCornerInBox = Point{padX,padY};
constexpr Point upperLeftCornerBtn = Point{winW-padX-btnW,padY};



class MastermindWindow:public Window{
public:
    MastermindWindow(Point xy,int w, int h, const string& title);
    static void cb_guess(Address, Address pw){
        reference_to<MastermindWindow>(pw).newGuess();
    }
    string wait_for_guess();
    Vector_ref<Rectangle> vr;
    Vector_ref<Circle> vc;
    string getInput(unsigned int n, int lower, int upper);
    void redraw(){
        Fl::wait();
        Fl::redraw();
    }
private:
    void newGuess(){button_pressed = true;}
    bool button_pressed;
    Button guessBtn;
    In_box guess;
};




void addGuess(MastermindWindow &mwin, const string code,const int size, const int round);
void hideCode(MastermindWindow &mwin,const int size);

void addFeedback(MastermindWindow &mwin, vector<int> guessCodeVector, const int correctCharacter,
const int size, const int round);

void playMasterMind();

int checkCharacterAndPosition(string guess, string code);

int checkCharacter(string guess, string code);

Color pickColor(int option);

int cinFail(int input);