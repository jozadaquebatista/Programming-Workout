#include <SFML/Graphics.hpp>
#include <iostream>
int main(){

    enum Direction { Down, Left, Right, Up};

    sf::Vector2i source(50, Down);

    sf::RenderWindow Window; //sf::Style::Titlebar | sf::Style::Minimize |sf::Style::Close
    Window.create(sf::VideoMode(800, 600), "My game");
    
    Window.setSize(sf::Vector2u(1024, 728));
    Window.setTitle("Vamos Jogar?");
    
    sf::Texture pTexture;
    sf::Sprite playerImage;
    
    if(!(pTexture.loadFromFile("main_char.png", sf::IntRect(50, 100, 32, 50))))
        std::cout << "Erro ao carregar imagem do player." << std::endl;
        
    playerImage.setTexture(pTexture);
    playerImage.setPosition(100, 100);
    
    while(Window.isOpen()){
        
        sf::Event Event;
        while(Window.pollEvent(Event)){
            
            switch(Event.type){
            
            case (sf::Event::Closed):
                
                Window.close();
                break;
            
            case (sf::Event::KeyPressed):
                
                if(Event.key.code == sf::Keyboard::Up)
                    source.y = Up;
                else if(Event.key.code == sf::Keyboard::Down)
                    source.y = Down;
                else if(Event.key.code == sf::Keyboard::Right)
                    source.y = Right;
                else if(Event.key.code == sf::Keyboard::Left)
                    source.y = Left;
                break;
            }
        }
        playerImage.setTextureRect(sf::IntRect(source.x * 50, source.y * 50, 50, 50));
        Window.draw(playerImage);
        Window.display();
    }
}
