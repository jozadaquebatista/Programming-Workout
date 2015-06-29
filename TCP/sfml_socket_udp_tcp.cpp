#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

int main(){

    sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    sf::TcpSocket socket;
    char connectionType;
    
    std::cout << "Enter (s) for server, and (c) for client: " << std::endl;
    std::cin >> connectionType;
    
    if(connectionType == 's'){
        //Se a conexão for do tipo servidor, executa esse trecho
        sf::TcpListener listener;
        listener.listen(2000);
        listener.accept(socket);
    } else if(connectionType == 'c'){
        //Se for do tipo cliente, executa esse trecho
        socket.connect(ip, 2000);
    } else { std::cerr << "Ocorreu um erro. WARN!" << std::endl; return -1; }
    
    //AQUI DEFINE DOIS QUADRADOS
    sf::RectangleShape rect1, rect2;
    
    //TAMANHO
    rect1.setSize(sf::Vector2f(20, 20));
    rect2.setSize(sf::Vector2f(20, 20));
    //COLOCA COR
    rect1.setFillColor(sf::Color::Red);
    rect2.setFillColor(sf::Color::Blue);
    
    //Cria uma JANELA
    sf::RenderWindow Window(sf::VideoMode(1024, 728, 32), "Packets");
    
    sf::Vector2f prevPosition, p2Position;
    
    socket.setBlocking(false);
    
    bool update = false;
    
    while(Window.isOpen()){
        
        sf::Event Event;
        while(Window.pollEvent(Event)){
        
            if(Event.type == sf::Event::Closed || Event.key.code == sf::Keyboard::Escape)
                Window.close();
            else if(Event.type == sf::Event::GainedFocus)
                update = true;
            else if(Event.type == sf::Event::LostFocus)
                update = false;
        }
    
        prevPosition = rect1.getPosition();
        
        if(update){
        
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                rect1.move(0.5f, 0.0f);
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                rect1.move(-0.5f, 0.0f);
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                rect1.move(0.0f, -0.5f);
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                rect1.move(0.0f, 0.5f);
        }
        sf::Packet packet;
        //MANDA PARA POSICAO ATUAL PARA O SERVIDOR
        if(prevPosition != rect1.getPosition()){
            
            packet << rect1.getPosition().x << rect1.getPosition().y;
            socket.send(packet);
        }
        
        socket.receive(packet);
        
        if(packet >> p2Position.x >> p2Position.y)
            rect2.setPosition(p2Position);
        
        Window.draw(rect1);
        Window.draw(rect2);
        
        Window.draw(rect1);
        Window.draw(rect2);
        
        Window.display();
        Window.clear();
    }
    return 0;
}
