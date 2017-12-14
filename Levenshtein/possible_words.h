#pragma once
#include "stdafx.h"

class PossibleWords
{
public:
	PossibleWords();
	~PossibleWords();
	void setWord(string w);
	void setDistance(int d);
	string getWord();
	int getDistance();
private:
	string word;
	int distance;
};

