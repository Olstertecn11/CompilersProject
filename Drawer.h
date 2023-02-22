#include <SFML/Graphics.hpp>
#include "textNode.cpp"
#include <string>
using namespace std;

struct Nodo {
    char data;
    Nodo* left;
    Nodo* right;
    textNode text = textNode("", sf::Color::Red, 26);
    sf::CircleShape shape; 
    sf::Vertex rightone[2];
    sf::Vertex leftone[2];
    Nodo(char data) {
      this->data = data;
      this->data = data;
      left = right = nullptr;
    }
};

class Drawer{
  public:
    const int WIDTH = 1070;
    const int HEIGHT = 920;
    sf::RenderWindow window;
    char operators[7] =  {'+', '-', '*', '/', '(', ')', '^'};
    int root_x = 250;
    int root_y = 50;
    Nodo* aux;
    int priority(char);
    bool isOP(char);
    string infixToPosfix(string);
    Nodo* genExpTree(string);
    void Inorden(Nodo* , string , Nodo* ) ;
    void Display(Nodo*);
    void _run(string);
    void setup();
};
