// Levenshtein.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "distance.h"
#include "possible_words.h"
#include <fstream>

using namespace std;



int main()
{
	/*
	
	*/
	cout << "*******************************************************************************************" << endl;
	cout << "* \t\t\tWelcome to Levenshtein Distance Program.                          *\n" << endl;
	cout << "*   This is a spell checking program that measures the similarity between two words :     *\n" << endl;
	cout << "* \ta) One entered by the user and                                                    *\n" << endl;
	cout << "* \tb) One in our dictionary                                                          *\n" << endl;
	cout << "*   If your word was incorrect, it displays 20 correct possible words that can be used    *\n" << endl;
	cout << "*   to replace the wrong one.                                                             *\n" << endl;
	cout << "*   It orders the words with the most possible word at the top                            *\n" << endl;
	cout << "*   If your word was correct it will appear as the 1st word on the list but also display   *\n" << endl;
	cout << "*   other options                                                                          *" << endl;
	cout << "*******************************************************************************************" << endl;
	ifstream my_file_node("D:\\IT\\My Projects\\Levenshtein\\Levenshtein\\words.txt");
	string word,input;
	char first_letter, second_letter;
	int a = 0;
	vector <string> my_words;
	cout << "loading words from the dictionary..."<<endl;
	while (getline(my_file_node, word)) {
		my_words.push_back(word);
	}
	cout << "\n\n\nLoading Complete\n\nPress Any Key to Continue...";
	getchar();
	system("CLS");
	cout << "Enter your word: ";
	cin >> input;
	first_letter = input.at(0);

	if (input.size() > 1) 
		second_letter = input.at(1);
	else
		second_letter = ' ';

	Distance distance;
	int z,count=0;
	PossibleWords * posword = new PossibleWords[my_words.size()];

	cout << "\nComputing Similarities...\n\n" << endl;
	for (int j = 0; j <=3; j++) {
		for (int i = 0; i < my_words.size(); i++) {
			if (my_words[i].at(0) == input.at(1) || my_words[i].at(0) == input.at(0)) {
				if (my_words[i].size() >= input.size()-1 && my_words[i].size()<=input.size()+1)
				{
					z = distance.computeEditDistance(input, my_words[i]);
					if (z == j) {
						posword[count].setWord(my_words[i]);
						posword[count].setDistance(z);
						count++;
					}
				}				
			}
		}
	}
	cout << "Possible Correct Words"<<endl;
	
	for (int i = 0; i < 20; i++) {
		cout <<i+1<<" "<< posword[i].getWord()<< endl;
	}
	cout << "\n\nComputing successfull...";
	cin >> z;
    return 0;
}  
