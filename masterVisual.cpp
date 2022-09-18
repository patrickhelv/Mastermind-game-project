#include "masterVisual.h"
#include "test.h"
#include "utilities.h"
#include "std_lib_facilities.h"

Color pickColor(int option){

	switch(option){
		case 65:
			return Color::blue;
			break;
		case 66:
			return Color::green;
			break;
		case 67:
			return Color::red;
			break;
		case 68:
			return Color::yellow;
			break;
		case 69:
			return Color::cyan;
			break;
		case 70:
			return Color::black;
			break;
	}

	return Color::cyan;

}

void addGuess(MastermindWindow& mwin,const string code,const int size, const int round){
	int xPos = 45;
	int yPos = 70;
	int option = 0;

		for(int j = 0; j < size; j++){
			option = static_cast<int>(code[j]);
			mwin.vr.push_back(new Rectangle{Point{xPos + (j * 90), yPos + (round * 60)},padX, padY});
			mwin.vr[mwin.vr.size()-1].set_fill_color(pickColor(option));
			mwin.attach(mwin.vr[mwin.vr.size()-1]);
		}

}




void addFeedback(MastermindWindow &mwin, vector<int> guessCodeVector, const int size, const int round){
	int xPos = 420;
	int yPos = 85;

	for(int i = 0; i < size; i++){
		mwin.vc.push_back(new Circle{Point{xPos + (i * 10),yPos + (round * 60)},radCircle});
		if(guessCodeVector[i] == 1){
			mwin.vc[mwin.vc.size()-1].set_fill_color(pickColor(Color::black));
		}
		mwin.attach(mwin.vc[mwin.vc.size()-1]);
	}
}

void hideCode(MastermindWindow &mwin,const int size){
	mwin.vr.push_back(new Rectangle{Point{padX,3*padY},winW-size*padX,padY});
	mwin.vr[mwin.vr.size()-1].set_fill_color(Color::black);
	mwin.attach(mwin.vr[mwin.vr.size()-1]);
}



MastermindWindow::MastermindWindow(Point xy,int w, int h, const string& title):Window(xy,w,h,title),
    button_pressed{false},
	guessBtn{upperLeftCornerBtn,btnW,btnH,"Add",cb_guess},
    guess{upperLeftCornerInBox,inBoxW,inBoxH,"Guess"}
    {
        attach(guess);
        attach(guessBtn);
};

 string MastermindWindow::wait_for_guess(){
		while (!button_pressed)
			Fl::wait();
		button_pressed = false;
		Fl::redraw();
        string newGuess =guess.get_string();
        guess.clear_value();
        return newGuess;
}


string MastermindWindow::getInput(unsigned int n, int lower, int upper){
	bool validInput = false;
	string guess;
	while(!validInput){
		guess.clear();
		string input = wait_for_guess();
		if(input.size() == n){
			for(unsigned int i = 0; i < n; i++){
				char ch = input[i];
				if((int(toupper(ch)) < upper && int(toupper(ch)) > lower)){ //is it bigger or lower than the unicode code for A-F
					guess += toupper(ch);
				} 
				else 
				break;
			}
		}
		if(guess.size() == n) validInput=true;
		else cout<<"Invalid input guess again\n";
	}
	return guess;
}

int checkCharacterAndPosition(string guess, string code, vector<int>& guessCodeVector){
	int ans = 0;
	for(int i = 0; i < code.length(); i++){
		if(guess[i] == code[i]){
			ans++;
			guessCodeVector.push_back(1);
		}else{
			guessCodeVector.push_back(0);
		}
	}
	return ans;
}

int checkCharacter(string guess, string code){
	int value = 0;
	int ans = 0;

	for(int i = 0; i < guess.length(); i++){
		if(code.find(guess[i]) < code.length()){
			ans++;
		}
	}

	return ans;
}

int cinFail(string input){
	int i = 0;
	bool error = false;

	while(!error)
		try{
			i = stoi(input);
			error = true;
		}catch(...){
			cout << "You entered a wrong character, do you want to continue : " << endl;
			cout << "1) yes " << endl;
			cout << "2) no " << endl;
			cin >> input;
		}
	return i;
}


void playMasterMind(){
	constexpr int size = 4;
	bool finished = false;
	bool finishegame = false;
	constexpr int letters = 6;
	int nbguess = 0;
	string code;
	string guess;
	int counter = 0;
	string input = "";
	vector<int> guessCodeVector;

	while(!finished){

		MastermindWindow mwin{Point{winW, winH}, winW, winH, "Mastermind"};
		int upperbound = int('F') + 1;
		int lowerbound = int('A') - 1;
		code = randomizeString(size, 'A' + (letters - 1), 'A');
		cout << "*** Mastermind game WOW ***\n";
		cout << "Write inn a 4 letter code from A to F\n";
		cout << "A = blue, B = green, C = red, D = yellow, E = cyan, F = black " << endl;
		//cout << "code : " << code << endl;
		
		finishegame = false;

		while(!finishegame){
			guess = mwin.getInput(size, lowerbound, upperbound);
			
			nbguess = checkCharacterAndPosition(guess, code, guessCodeVector);
			addGuess(mwin,  guess, size, counter);
			addFeedback(mwin, guessCodeVector, size, counter);
			guessCodeVector.clear();

			if(nbguess == size){
				finishegame = true;
				cout << "You win :)" << endl;
				cout << "do you want to play again ? " << endl;
				cout << "1) yes " << endl;
				cout << "2) no " << endl;
				cin >> input;
				int i = cinFail(input);
				if(i == 2){
					finished = true;
				}

			}else{	
				cout << "OH no I missed " << endl;
				cout << "You guessed : " << guess << endl;
				cout << "You managed to guess " << checkCharacter(guess, code) <<" characters that are in the code " << endl;
				cout << "The number of correct of guesses in the right position this round is " << nbguess << "\n"; 
				counter++;
				cout << "Number of guesses : " << counter << endl;
			}

			if(counter == 6){
				finishegame = true;
				cout << "You lost\n";
				cout << "The code was : " << code << endl;
				cout << "do you want to play again ? " << endl;
				cout << "1) yes " << endl;
				cout << "2) no " << endl;
				cin >> input;
				int i = cinFail(input);
				if(i == 2){
					finished = true;
				}
			}
		}
	}

}






