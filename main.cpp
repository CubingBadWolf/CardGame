#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using std::vector;

struct Card{
    short value;
    char number;
    std::string suit;
    short rank;
};

class Deck{
private:
    static const short size = 52;
    const char nums[13] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    const std::string suits[4] = {"♤",	"♡", "♢", "♧"};
    short players;
public:
    Deck(short Players){
        players = Players;
    }
    Card deck[size];
    vector<vector<Card>> dealingDeck;
    void GenDeck(){
        for(short i = 0; i < size; i++){
            deck[i].value = (i+1)%13;
            deck[i].number = nums[(i+1)%13];
            deck[i].suit = suits[(i+1)%4];
            deck[i].rank = (i+1)%4;
        }
    }
    void shuffleDeck(){
        std::random_shuffle(std::begin(deck), std::end(deck));
    }
    void DealDeck(){
        int count = 0;
        for (Card item : deck){
            dealingDeck[count%players].push_back(item);
        }
    }
};

class Hand : protected Deck{
private:
    short playerNum;
public:
    using Deck::shuffleDeck;
    vector<Card> hand = dealingDeck[playerNum];
    
    Hand(short PlayerNum, short playerAmn) : Deck(playerAmn){
        playerNum = PlayerNum;
    }
};

int main(){
    const int NoOfPlayers = 4;
    Deck deck(NoOfPlayers);
    deck.GenDeck();
    deck.shuffleDeck();
    Hand player1(1, NoOfPlayers);
    for(int i = 0; i < 52; i++){
        std::cout << player1.hand[i].suit << player1.hand[i].number << ',';
    }
    player1.shuffleDeck();
 
    for(int i = 0; i < 52; i++){
        std::cout << deck.deck[i].suit << deck.deck[i].number << ',';
    }
    return 0;
}