#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

class Observer {
private:
    boost::asio::io_context io_context;
    boost::asio::ssl::context ssl_context;
    boost::asio::ssl::stream<boost::asio::ip::tcp::socket> ssl_socket;

public:
    Observer(const boost::asio::ip::tcp::endpoint& endpoint, const std::string& cert_file)
        : ssl_socket(io_context, ssl_context) {
        ssl_context.load_verify_file(cert_file);
        ssl_socket.next_layer().connect(endpoint);
        ssl_socket.handshake(boost::asio::ssl::stream_base::client);
        startListening();
    }

    void startListening() {
        boost::asio::async_read_until(ssl_socket, boost::asio::dynamic_buffer(buffer), '\n',
            [this](const boost::system::error_code& ec, std::size_t length) {
                if (!ec) {
                    std::string message(std::istreambuf_iterator<char>(&buffer), {});
                    buffer.consume(length);
                    handleUpdate(message);
                    startListening();
                }
            }
        );
    }

private:
    boost::asio::streambuf buffer;

    void handleUpdate(const std::string& message) {
        std::cout << "Received update: " << message << std::endl;
    }
};

int main() {
    // Erstellen von zwei Observer mit TLS
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::make_address("127.0.0.1"), 12345);
    Observer observer1(endpoint, "server.crt");
    Observer observer2(endpoint, "server.crt");

    // Schleife zum Verhindern, dass das Programm sofort beendet wird
    std::cout << "Observer is running. Press Enter to exit." << std::endl;
    std::cin.ignore();

    return 0;
}
