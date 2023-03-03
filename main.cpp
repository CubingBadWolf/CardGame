#include <iostream>
#include <algorithm>
#include <string>

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
public:
    Card deck[size];
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

};

int main(){
    Deck deck;
    deck.GenDeck();
    deck.shuffleDeck();
    for(int i = 0; i < 52; i++){
        std::cout << deck.deck[i].suit << deck.deck[i].number << ',';
    }
    return 0;
}