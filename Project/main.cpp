#include "card.cpp"
#include "deck.cpp"
#include <unistd.h>
#include <string>
#include <fcntl.h>
#include <ctime>
#include <stdio.h>


int main(){
        cout << "\033[31m ____  _            _    _            _       \033[0m" << endl;
        cout << "\033[31m|  _ \\| |          | |  (_)          | |      \033[0m" << endl;
        cout << "\033[31m| |_) | | __ _  ___| | ___  __ _  ___| | __   \033[0m" << endl;
        cout << "\033[31m|  _ <| |/ _` |/ __| |/ / |/ _` |/ __| |/ /   \033[0m" << endl;
        cout << "\033[31m| |_) | | (_| | (__|   <| | (_| | (__|   <    \033[0m" << endl;
        cout << "\033[31m|____/|_|l__,_|l___|_|l_l |l__,_|l___l_ll_)   \033[0m" << endl;
        cout << "\033[31m                       _/ |                   \033[0m" << endl;
        cout << "\033[31m                      |__/                    \033[0m" << endl;
        cout << endl << endl;

    ofstream scoresFile;
    scoresFile.open("Scores.txt", ios::out);
    scoresFile << "Your Scores" << '\t' << "Dealer's Scores" << endl;
    char playagain;
    cout << "\033[31mWould you like to play Blackjack? (y) or (n) \a \033[0m" << endl;
    cin >> playagain;
    while(playagain == 'y'){
        srand( time(NULL));
        bool match = false;
        bool test = false;
        deck two;
        two.shuffle();
        usleep(1000000);
        cout << "\033[31mWe will now deal 2 cards to the deal and two cards to you.\033[0m" << endl;
        card dealerCard1;
        card dealerCard2;
        card dealerCard3;
        card dealerCard4;
        dealerCard1 = two.draw_card();
        dealerCard2 = two.draw_card();
        int first_score = two.CalcScore(dealerCard1, dealerCard2);
        if (first_score < 17){
           dealerCard3 = two.draw_card();
           first_score = two.CalcNextScore(dealerCard3, first_score);
           match = true;
           if (first_score < 17){
            dealerCard4 = two.draw_card();
            first_score = two.CalcNextScore(dealerCard4,first_score);
            test = true;
           }

        }
        cout << "\033[31mDealing...\033[0m" << endl;
        usleep(1500000);
        card newCard = two.draw_card();
        newCard.getEverything(newCard);
        usleep(1000000);
        card newCard2 = two.draw_card();
        newCard2.getEverything(newCard2);
        usleep(1000000);
        int user_score = two.CalcScore(newCard, newCard2);
        if (user_score == 21){
            cout << " \033[31m/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\033[0m" << endl;
            cout << " \033[31m/-/-/       Congratulations!!       /-/-/\033[0m" << endl;
            cout << " \033[31m/-/-/    You have won the game!!    /-/-/\033[0m" << endl;
            cout << " \033[31m/-/-/       You scored a 21.        /-/-/\033[0m" << endl;
            cout << " \033[31m/-/-/ Would you like to play again? /-/-/\033[0m" << endl;
            cout << " \033[31m/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\033[0m" << endl;
            scoresFile << user_score << '\t' << '\t' << first_score << endl;
            cin >> playagain;
        }
        cout << "\033[31m//////   Your current score is \033[0m" << user_score << "\033[31m   //////\033[0m" << endl;
        char user2;
        cout << "\033[31mHit or pass? (h) or (p)\033[0m" << endl;
        cin >> user2;
        if (user2 == 'p'){
                if ((match == true) && (test == false)){
                    scoresFile << user_score << '\t' << '\t' << first_score << endl;
                    two.CompareScores2(first_score,user_score, dealerCard1, dealerCard2, dealerCard3);
                    cout << "\033[31m//////    Would you like to play again? (y) or (n)     //////\033[0m" << endl;
                    cin >> playagain;

                }
                else if ((match == true) && (test == true)){
                    scoresFile << user_score << '\t' << '\t' << first_score << endl;
                    two.CompareScores3(first_score, user_score, dealerCard1, dealerCard2, dealerCard3, dealerCard4);
                    cout << "\033[31m//////    Would you like to play again? (y) or (n)     //////\033[0m" << endl;
                    cin >> playagain;

                }
                else{
                    scoresFile << user_score << '\t' << '\t' << first_score << endl;
                    two.CompareScores(first_score,user_score, dealerCard1, dealerCard2);
                    cout << "\033[31m//////    Would you like to play again? (y) or (n)     //////\033[0m" << endl;
                    cin >> playagain;

                        }
        }
        else{
            cout << "\033[31mDealing...\033[0m" << endl;
            usleep(1000000);
            card newCard3 = two.draw_card();
            newCard3.getEverything(newCard3);
            int user_score = two.CalcScore(newCard, newCard2);
            int user_next_score = two.CalcNextScore(newCard3, user_score);
            if (user_next_score == 21){
            scoresFile << user_next_score << '\t' << '\t' << first_score << endl;
            cout << " \033[31m/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\033[0m" << endl;
            cout << " \033[31m/-/-/            Congratulations!!            /-/-/\033[0m" << endl;
            cout << " \033[31m/-/-/         You have won the game!!         /-/-/\033[0m" << endl;
            cout << " \033[31m/-/-/            You scored a 21.             /-/-/\033[0m" << endl;
            cout << " \033[31m/-/-/      Would you like to play again?      /-/-/\033[0m" << endl;
            cout << " \033[31m/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\033[0m" << endl;
            cin >> playagain;

            }
            else if(user_next_score > 21){
                scoresFile << user_next_score << '\t' << '\t' << first_score << endl;
                cout << "\033[31m//////   You bust!    //////\033[0m" << endl;
                cout << "\033[31m//////    Would you like to play again? (y) or (n)     //////\033[0m" << endl;
                cin >> playagain;

            }
            cout << "\033[31mYour new score is \033[0m" << user_next_score << "." << endl;
                char user3;
                cout << "\033[31mHit or pass? (h) or (p)\033[0m" << endl;
                cin >> user3;
                if (user3 == 'p'){
                if ((match == true) && (test == false)){
                    scoresFile << user_next_score << '\t' << '\t' << first_score << endl;
                    two.CompareScores2(first_score,user_next_score, dealerCard1, dealerCard2, dealerCard3);
                    cout << "\033[31m//////    Would you like to play again? (y) or (n)     //////\033[0m" << endl;
                    cin >> playagain;
                }
                else if ((match == true) && (test == true)){
                    scoresFile << user_next_score << '\t' << '\t' << first_score << endl;
                    two.CompareScores3(first_score, user_next_score, dealerCard1, dealerCard2, dealerCard3, dealerCard4);
                    cout << "\033[31m//////    Would you like to play again? (y) or (n)     //////\033[0m" << endl;
                    cin >> playagain;
                }
                else{
                    scoresFile << user_next_score << '\t' << '\t' << first_score << endl;
                    two.CompareScores(first_score,user_next_score, dealerCard1, dealerCard2);
                    cout << "\033[31m//////    Would you like to play again? (y) or (n)     //////\033[0m" << endl;
                    cin >> playagain;

                        }
        }
                else if (user3 == 'h'){
                    char user4;
                        card newCard4 = two.draw_card();
                        newCard4.printValue();
                        newCard4.printSuit();
                        newCard4.printFace(newCard4);
                        int user_next_score2 = two.CalcNextScore(newCard4, user_next_score);
                        two.CompareScores2(first_score, user_next_score2,dealerCard1,dealerCard2,dealerCard3);
                        if (user_next_score2 == 21){
                            scoresFile << user_next_score2 << '\t' << '\t' << first_score << endl;
                            cout << " \033[31m/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\033[0m" << endl;
                            cout << " \033[31m/-/-/            Congratulations!!            /-/-/\033[0m" << endl;
                            cout << " \033[31m/-/-/         You have won the game!!         /-/-/\033[0m" << endl;
                            cout << " \033[31m/-/-/            You scored a 21.             /-/-/\033[0m" << endl;
                            cout << " \033[31m/-/-/      Would you like to play again?      /-/-/\033[0m" << endl;
                            cout << " \033[31m/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\033[0m" << endl;
                            cin >> playagain;
                        }
                        else if(user_next_score2 > 21){
                            scoresFile << user_next_score2 << '\t' << '\t' << first_score << endl;
                            cout << "\033[31mYou bust!\033[0m" << endl;
                            cout << "\033[31m//////    Would you like to play again? (y) or (n)     //////\033[0m" << endl;
                            cin >> playagain;
                        }
                        cout << "\033[31mYour new score is \033[0m" << user_next_score2 << "." << endl;


                }

        }

    }
    cout << "\033[31m//////    Have a nice day.     //////\033[0m" << endl;

}

