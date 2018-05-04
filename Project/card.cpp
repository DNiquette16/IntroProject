#include "card.h"
#include <stdlib.h>
#include <fstream>
card::card(){
loadSuits("suits.txt");
int a = rand() % 4;
int c = rand() % 4;
card_suit = suits[c];
int b = rand() % 13;
card_value = values[b];
}

string card::setSuit(string a){

if ((a == "spades") || (a == "Spades")){
    card_suit = suits[0];
}
else if ((a == "hearts") || (a == "Hearts")){
    card_suit = suits[1];
}
else if ((a == "clubs") || (a == "Clubs")){
    card_suit = suits[2];
}
else if ((a == "diamonds") || (a == "Diamonds")){
    card_suit = suits[3];
}
return card_suit;

}

string card::setValue(string b){
int New_b = stoi(b);
if ((New_b <= 8) && (New_b >= 0)){
    card_value = b;
}
else if ((b == "Jack") || (b == "jack")){
    card_value = "Jack";
}
else if ((b == "Queen") || (b == "queen")){
    card_value = "Queen";
}
else if ((b == "King") || (b == "king")){
    card_value = "King";
}
else if ((b == "Ace") || (b == "ace")){
    card_value = "Ace";
}
return card_value;

}

string card::getSuit(){
    return card_suit;

}
string card::getValue(){
    return card_value;
}

string card::setSuit2(int c){
    card_suit = suits[c];
    return card_suit;

}
string card::setValue2(int a){
    card_value = values[a];
    return card_value;
}

void card::printSuit(){
    cout << card_suit << endl;
}
void card::printValue(){
    cout << card_value << " of ";
}

void card::printFace(card a){
    string card_value = a.getValue();
if (card_value == "2"){
    cout << faces[0] << endl;
}
else if (card_value == "3"){
    cout << faces[1] << endl;
}
else if (card_value == "4"){
    cout << faces[2] << endl;
}
else if (card_value == "5"){
    cout << faces[3] << endl;
}
else if (card_value == "6"){
    cout << faces[4] << endl;
}
else if (card_value == "7"){
    cout << faces[5] << endl;
}
else if (card_value == "8"){
    cout << faces[6] << endl;
}
else if (card_value == "9"){
    cout << faces[7] << endl;
}
else if (card_value == "10"){
    cout << faces[8] << endl;
}
else if (card_value == "Jack"){
    cout << faces[9] << endl;
}
else if (card_value == "Queen"){
    cout << faces[10] << endl;
}
else if (card_value == "King"){
    cout << faces[11] << endl;
}
else if (card_value == "Ace"){
    cout << faces[12] << endl;
}

}

string card::getEverything(card a){
        a.printValue();
        a.printSuit();
        a.printFace(a);

}

int card::loadSuits(string filename){
string line;
int i = 0;
ifstream suitsfile;

suitsfile.open(filename.c_str());

if (suitsfile.fail()){
    return -1;
}
else{

    while(getline(suitsfile, line)){
        suits[i] = line;
        i++;
    }

}
suitsfile.close();
return i;

}
