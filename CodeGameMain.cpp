#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <algorithm>

int main() {

	int attempts = 0;
	int linesRead = 0;
	char keepPlaying = 'y';

	
	std::cout << "I am the master encoder!" << std::endl << "If you dare try to solve my code!" << std::endl;
	while (keepPlaying == 'y') {
		std::ifstream codes("codes.txt");  //Opening a text file that has the pass phrases in it
		int whichCode;
		int offSet;
		srand(time(NULL));
		whichCode = rand() % 10 + 1;		//selecting a pass phrase at random along with an off set
		offSet = rand() % 5 + 1;
		int linenumber = (whichCode);
		std::string answer;
		std::string soluton; 
		std::string currentCode;
		if (codes.is_open()) {		//making sure the file is open and then getting the exact line and storing it in current code
			while (codes) {
				getline(codes, currentCode);
				linesRead++;
				if (linesRead == linenumber) {
					codes.close();
					soluton = currentCode;
					for (int i = 0; i < offSet; i++) {
						for (int i = 0; i < currentCode.size(); i++) {		//aplying the off set
							++currentCode[i];
							std::replace(currentCode.begin(), currentCode.end(), '!', ' '); //making sure that all spaces stay spaces 
							std::replace(currentCode.begin(), currentCode.end(), '{', 'a'); // making z go to a
						}
					}


					while (true) {
						std::cout << std::endl << currentCode << std::endl<< "\nEnter the answer: " << std::endl;
						getline(std::cin, answer);
						if (answer == soluton) {		// now they get to try and guess what the code is
							std::cout << "Good job!" << std::endl;
							break;
						}
						else if (answer == "help") {
							std::cout << offSet << std::endl;		// secret help code if they get desprate 
						}
						else if (answer == "please help") {
							std::cout << soluton << std::endl;
						}
						
						if (attempts > 3) {
							std::cout << "You suck. I don't want to play with you any more." << std::endl; // they only get to play again if the guess it right 
							std::cin.get();
							return 0;
						}
						else {
							std::cout << "you fail!" << std::endl << "Try again." << std::endl; // they only get so many trys 
							attempts++;
						}
					}
					
				}
			}
		}
		std::cout << "Play again? y/n:";
		std::cin >> keepPlaying;
		attempts = 0;
		linesRead = 0;
		std::cin.ignore(100, '\n');
	}
	return 0;
}