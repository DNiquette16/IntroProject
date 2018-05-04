#include <iostream>
#define SUITS 4
#define VALUES 13
using namespace std;

class card{
public:
string faces[13] = {".------.\n|2.--. |\n| (\/)  |\n|  :\/: |\n| '--'2|\n`------'", ".------.\n|3.--. |\n| (\/)  |\n|  :\/: |\n| '--'3|\n`------'", ".------.\n|4.--. |\n| (\/)  |\n|  :\/: |\n| '--'4|\n`------'", ".------.\n|5.--. |\n| (\/)  |\n|  :\/: |\n| '--'5|\n`------'", ".------.\n|6.--. |\n| (\/)  |\n|  :\/: |\n| '--'6|\n`------'", ".------.\n|7.--. |\n| (\/)  |\n|  :\/: |\n| '--'7|\n`------'", ".------.\n|8.--. |\n| (\/)  |\n|  :\/: |\n| '--'8|\n`------'", ".------.\n|9.--. |\n| (\/)  |\n|  :\/: |\n| '--'9|\n`------'", ".------.\n|10.--.|\n| (\/)  |\n|  :\/: |\n|'--'10|\n`------'", ".------.\n|J.--. |\n| (\/)  |\n|  :\/: |\n| '--'J|\n`------'", ".------.\n|Q.--. |\n| (\/)  |\n|  :\/: |\n| '--'Q|\n`------'", ".------.\n|K.--. |\n| (\/)  |\n|  :\/: |\n| '--'K|\n`------'", ".------.\n|A.--. |\n| (\/)  |\n|  :\/: |\n| '--'A|\n`------'"};
string suits[SUITS];
string values[VALUES] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
string card_suit;
string card_value;
int loadSuits(string filename);
string setSuit(string a);
string setSuit2(int c);
string setValue2(int a);
string setValue(string b);
string getSuit();
string getValue();
string getEverything(card a);
void printSuit();
void printValue();
void printFace(card a);
card();


};
