#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

class Observable {
private:
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::acceptor acceptor;
    boost::asio::ssl::context ssl_context;
    std::vector<std::shared_ptr<boost::asio::ssl::stream<boost::asio::ip::tcp::socket>>> ssl_sockets;

public:
    Observable(const boost::asio::ip::tcp::endpoint& endpoint, const std::string& cert_file, const std::string& private_key_file)
        : acceptor(io_context, endpoint), ssl_context(boost::asio::ssl::context::sslv23) {
        ssl_context.use_certificate_chain_file(cert_file);
        ssl_context.use_private_key_file(private_key_file, boost::asio::ssl::context::pem);
        acceptConnections();
    }

    void attachObserver(const std::shared_ptr<boost::asio::ssl::stream<boost::asio::ip::tcp::socket>>& ssl_socket) {
        ssl_sockets.push_back(ssl_socket);
    }

    void notifyObservers(const std::string& message) {
        for (auto& ssl_socket : ssl_sockets) {
            boost::asio::write(*ssl_socket, boost::asio::buffer(message + "\n"));
        }
    }

private:
    void acceptConnections() {
        auto ssl_socket = std::make_shared<boost::asio::ssl::stream<boost::asio::ip::tcp::socket>>(io_context, ssl_context);
        acceptor.async_accept(
            ssl_socket->next_layer(),
            [this, ssl_socket](const boost::system::error_code& ec) {
                if (!ec) {
                    ssl_socket->async_handshake(boost::asio::ssl::stream_base::server,
                        [this, ssl_socket](const boost::system::error_code& ec) {
                            if (!ec) {
                                attachObserver(ssl_socket);
                                acceptConnections();
                            }
                        }
                    );
                }
            }
        );
    }
};

int main() {
    // Erstellen von Observable mit TLS
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 12345);
    Observable observable(endpoint, "server.crt", "server.key");

    // Schleife zum Lesen von Eingaben und Aktualisieren des Observable-Zustands
    std::string input;
    while (true) {
        std::cout << "Enter state (or 'exit' to quit): ";
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        }

        observable.notifyObservers(input);
    }

    return 0;
}
