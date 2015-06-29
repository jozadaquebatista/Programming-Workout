#include <iostream>
#include <SFML/Network.hpp>
int main(){
    // ----- The client -----
    // Create a socket and bind it to the port 55001
    sf::UdpSocket socket;
    socket.bind(55001);
    // Send a message to 192.168.1.50 on port 55002
    std::string message = "Hi, I am " + sf::IpAddress::getLocalAddress().toString();
    socket.send(message.c_str(), message.size() + 1, "127.0.0.1", 55002);
    // Receive an answer (most likely from 192.168.1.50, but could be anyone else)
    char buffer[1024];
    std::size_t received = 0;
    sf::IpAddress sender;
    unsigned short port;
    socket.receive(buffer, sizeof(buffer), received, sender, port);
    std::cout << sender.toString() << " said: " << buffer << std::endl;
}
