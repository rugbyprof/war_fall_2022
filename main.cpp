#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

// struct Move{
//   string name;
//   int power;
//   string bestAgainst;
// };

// struct Pokemon{
//   string type;
//   int hp;
//   int attack;
//   vector<Move *> moves;
// };

template <class T> class Card {
protected:
  T value;

public:
  Card(T v) { value = v; }
  virtual T getValue() = 0;
  virtual void setValue(T v) = 0;
};

// class PokeCard : public Card<Pokemon>{

// };

class WarCard : public Card<int> {
  int multiplier;

public:
  WarCard() : Card(1) { multiplier = rand() % 5 + 1; }
  WarCard(int mul) : Card(1) { multiplier = mul; }
  WarCard(int val, int mul) : Card(val) { multiplier = mul; }
  void setMultiplier(int mul) { multiplier = mul; }
  int getValue() { return value; }
  void setValue(int v) { value = v; }
  int getMultiplier() { return multiplier; }
  int score() { return value * multiplier; }
};

template <class T> class Deck {
protected:
  vector<T *> deck;

  void init(int size) {
    int v = 0;
    for (int i = 0; i < size; i++) {
      deck.push_back(new T(i % 5 + 1, i % 5 + 1));
    }
  }

public:
  Deck() { init(50); }
  Deck(int s) { init(s); }
  void shuffle() {
    // auto rd = std::random_device{};
    // auto rng = std::default_random_engine{rd()};
    auto rng = std::default_random_engine{};
    std::shuffle(std::begin(deck), std::end(deck), rng);
  }
  void print() {
    for (int i = 0; i < deck.size(); i++) {
      cout << deck[i]->getValue() << " ";
    }
    cout << endl;
  }

  WarCard *draw() {
    WarCard *p = deck.back();
    deck.pop_back();
    return p;
  }

  void addCard(WarCard *c) { deck.push_back(c); }
};

template <class T>
class Hand: public Deck<T>{
protected:

public:
  Hand():Deck<WarCard>(0){
    
  }
};

class Player {
protected:
  Hand<WarCard> hand;
};

class War {};

int main() {
  Deck<WarCard> d(100);
  d.print();
  d.shuffle();
  d.print();
  d.shuffle();
  d.print();
  Hand<WarCard> h;
  WarCard* w = new WarCard;

  cout<<w->getValue()<<endl;
  h.addCard(w);
  cout<<endl<<endl;
  h.print();
}