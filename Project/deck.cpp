#include "deck.h"
#include <algorithm>


deck::deck(){

    for (int i = 0; i < 3; i++){
        cards[i].setSuit2(i);
        for (int j = 0; j < 12; j++){
            cards[(i*12)+j].setValue2(j);
        }
    }
}

bool deck::shuffle(){
bool match = true;
card a;
int b;
    for (int i = 0; i < 52; i++){
        b = rand() % 52;
        a = cards[i];
        cards[i] = cards[b];
        cards[b] = a;
    }

return match;
}

card deck::draw_card(){

card newCard;
newCard.getValue();
newCard.getSuit();
return newCard;

}

int deck::CalcScore(card a, card b){
string card_value = a.getValue();
string card_value2 = b.getValue();
int value = 0;
int value2 = 0;
if (card_value == "Ace"){
    value = 11;
}
else if ((card_value == "Jack") || (card_value == "Queen") || (card_value == "King")){
    value = 10;
}
else if ((card_value == "2") || (card_value == "3") || (card_value == "4") || (card_value == "5") || (card_value == "6") || (card_value == "7") || (card_value == "8") || (card_value == "9") || (card_value == "10")){
    value = stoi(card_value);
}

if (card_value2 == "Ace"){
    value2 = 11;
}
else if ((card_value2 == "Jack") || (card_value2 == "Queen") || (card_value2 == "King")){
    value2 = 10;
}
else if ((card_value2 == "2") || (card_value2 == "3") || (card_value2 == "4") || (card_value2 == "5") || (card_value2 == "6") || (card_value2 == "7") || (card_value2 == "8") || (card_value2 == "9") || (card_value2 == "10")){
    value2 = stoi(card_value2);
}


int total = value + value2;
if ((total > 21) && (value == 11)){
    value = 1;
    total = value + value2;

}
else if ((total > 21) && (value2 == 11)){
    value2 = 1;
    total = value + value2;
}
else if ((total > 21) && (value == 11) && (value2 == 11)){
    value = 1;
    total = value + value2;
}
return total;
}

int deck::CalcNextScore(card c, int total){
string card_value = c.getValue();
int value = 0;
if (card_value == "Ace"){
    value = 11;
}
else if ((card_value == "Jack") || (card_value == "Queen") || (card_value == "King")){
    value = 10;
}
else{
    value = stoi(card_value);
}

int new_total = total + value;
int i = 0;
while ((new_total > 21) && (card_value == "Ace") && (i<1)){
    value = 1;
    new_total = total + value;
    i++;
}
return new_total;
}

void deck::CompareScores(int dealer_score, int user_score, card a, card b){

int dealer_diff = 21 - dealer_score;
int user_diff = 21 - user_score;
if (dealer_score > 21){
    cout << "\033[31m//////     Dealer busts. You win!     //////\033[0m" << endl;
        a.printFace(a);
        b.printFace(b);

}
else if (dealer_diff < user_diff){
    cout << "\033[31m//////    You lose. The dealer scored \033[0m" << dealer_score << "\033[31m    /////\033[0m" << endl;
    a.printFace(a);
    b.printFace(b);
}
else if (user_diff <= dealer_diff){
cout << "\033[31m   _       ___                      \033[0m" << endl;
cout << "\033[31m  | |     / (_)___  ____  ___  _____\033[0m" << endl;
cout << "\033[31m  | | /| / / / __ l/ __ l/ _ l/ ___/\033[0m" << endl;
cout << "\033[31m  | |/ |/ / / / / / / / /  __/ /    \033[0m" << endl;
cout << "\033[31m  |__/|__/_/_/ /_/_/ /_/l___/_/     \033[0m" << endl;
    a.printFace(a);
    b.printFace(b);
}


}

void deck::CompareScores2(int dealer_score, int user_score, card a, card b, card c){

int dealer_diff = 21 - dealer_score;
int user_diff = 21 - user_score;
if (dealer_score > 21){
    cout << "\033[31m//////     Dealer busts. You win!     //////\033[0m" << endl;
        a.printFace(a);
        b.printFace(b);
        c.printFace(c);
}
else if (dealer_diff < user_diff){
    cout << "\033[31m//////    You lose. The dealer scored \033[0m" << dealer_score << "\033[31m    /////\033[0m" << endl;
    a.printFace(a);
    b.printFace(b);
    c.printFace(c);
}
else if (user_diff <= dealer_diff){
cout << "\033[31m   _       ___                      \033[0m" << endl;
cout << "\033[31m  | |     / (_)___  ____  ___  _____\033[0m" << endl;
cout << "\033[31m  | | /| / / / __ l/ __ l/ _ l/ ___/\033[0m" << endl;
cout << "\033[31m  | |/ |/ / / / / / / / /  __/ /    \033[0m" << endl;
cout << "\033[31m  |__/|__/_/_/ /_/_/ /_/l___/_/     \033[0m" << endl;
cout << "\033[31mThe dealer scored \033[0m" << dealer_score << "\033[31m.\033[0m" << endl;
    a.printFace(a);
    b.printFace(b);
    c.printFace(c);
}


}

void deck::CompareScores3(int dealer_score, int user_score, card a, card b, card c, card d){
    int dealer_diff = 21 - dealer_score;
    int user_diff = 21 - user_score;
    if (dealer_score > 21){
        cout << "\033[31m//////     Dealer busts. You win!     //////\033[0m" << endl;
        a.printFace(a);
        b.printFace(b);
        c.printFace(c);
        d.printFace(d);
    }
    else if (dealer_diff < user_diff){
        cout << "\033[31m//////    You lose. The dealer scored \033[0m" << dealer_score << "\033[31m    /////\033[0m" << endl;
        a.printFace(a);
        b.printFace(b);
        c.printFace(c);
        d.printFace(d);
    }
    else if (user_diff <= dealer_diff){
        cout << "\033[31m   _       ___                      \033[0m" << endl;
        cout << "\033[31m  | |     / (_)___  ____  ___  _____\033[0m" << endl;
        cout << "\033[31m  | | /| / / / __ l/ __ l/ _ l/ ___/\033[0m" << endl;
        cout << "\033[31m  | |/ |/ / / / / / / / /  __/ /    \033[0m" << endl;
        cout << "\033[31m  |__/|__/_/_/ /_/_/ /_/l___/_/     \033[0m" << endl;
        a.printFace(a);
        b.printFace(b);
        c.printFace(c);
        d.printFace(d);
    }




}
