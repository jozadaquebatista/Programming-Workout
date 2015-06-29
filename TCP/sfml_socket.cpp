#include <iostream>
#include <SFML/Network.hpp>

int main(){

    sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    sf::TcpSocket socket;
    
    char connectionType, mode;
    char buffer[2000];
    std::size_t received;
    std::string text = "Connected to: ";
    
    std::cout << "Enter (s) for server, and (c) for client: " << std::endl;
    std::cin >> connectionType;
    
    if(connectionType == 's'){
        sf::TcpListener listener;
        listener.listen(2000);
        listener.accept(socket);
        text += "Server";
        mode = 's';
    } else if(connectionType == 'c'){
        socket.connect(ip, 2000);
        text += "Client";
        mode = 'r';
    }
    
    //socket.send(text.c_str(), text.length() + 1);
    //socket.receive(buffer, sizeof(buffer), received);
    std::cout << buffer << std::endl;
    
    bool done = false;
    
    while(!done){
    
        if(mode == 's'){
        
            std::getline(std::cin, text);
            socket.send(text.c_str(), text.length() + 1);
            mode = 'r';
        } else if(mode == 'r'){
        
            socket.receive(buffer, sizeof(buffer), received);
            if(received > 0){
            
                std::cout << "Received: " << buffer << std::endl;
                mode = 's';
            }
        }
    }
    return 0;
}
