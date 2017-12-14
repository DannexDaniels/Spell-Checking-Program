#include "stdafx.h"
#include "possible_words.h"


PossibleWords::PossibleWords()
{
}


PossibleWords::~PossibleWords()
{
}

void PossibleWords::setWord(string w) {
	word = w;
}
void PossibleWords::setDistance(int d) {
	distance = d;
}
string PossibleWords::getWord() {
	return word;
}
int PossibleWords::getDistance() {
	return distance;
}