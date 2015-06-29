#include <iostream>
#include <SFML/Network.hpp>

int main(){

    // ----- The server -----
    // Create a listener to wait for incoming connections on port 55001
    sf::TcpListener listener;
    listener.listen(55001);
    // Waits for a connection
    sf::TcpSocket socket;
    listener.accept(socket);
    std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl;
    //  Catch message from client
    char buffer[1024];
    std::size_t received = 0;
    socket.receive(buffer, sizeof(buffer), received);
    std::cout << "The client said: " << buffer << std::endl;
    // Send a response
    std::string message = "Welcome, client";
    socket.send(message.c_str(), message.size() + 1);

    return 0;
}
