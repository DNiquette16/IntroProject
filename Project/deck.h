#include <iostream>

using namespace std;

class deck{

public:
card cards[52];
int total;
int dealers_score;
string filename;

deck();
bool shuffle();
card draw_card();
int CalcScore(card a, card b);
int CalcNextScore(card c, int total);
void CompareScores(int dealer_score, int user_score, card a, card b);
void CompareScores2(int dealer_score, int user_score, card a, card b, card c);
void CompareScores3(int dealer_score, int user_score, card a, card b, card c, card d);


};
