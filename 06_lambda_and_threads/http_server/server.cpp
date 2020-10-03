#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio::ip;

class HTTPServer {
private:
  class Connection {
  public:
    tcp::socket socket;
    Connection(boost::asio::io_service &io_service) : socket(io_service) {}
  };

  boost::asio::io_service io_service;

  tcp::endpoint endpoint;
  tcp::acceptor acceptor;

  std::string determine_message(std::string requestType, std::string filePath, std::string protocol) {
    if (requestType == "GET" && protocol == "HTTP/1.1") {
      if (filePath == "/") {
        return "HTTP/1.1 200\r\n\r\nDette er hovedsiden";
      } else if (filePath == "/en_side") {
        return "HTTP/1.1 200\r\n\r\nDette er en side";
      } else {
        return "HTTP/1.1 404 Not Found";
      }
    } else {
      return "HTTP/1.1 404 Not Found";
    }
  }

  void handle_request(shared_ptr<Connection> connection) {
    auto read_buffer = make_shared<boost::asio::streambuf>();
    // Read from client until newline ("\r\n")
    async_read_until(connection->socket, *read_buffer, "\n",
                     [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
      // If not error:
      if (!ec) {
        // Retrieve message from client as string:
        istream read_stream(read_buffer.get());

        // Split first line into relevant tokens
        // - this won't errror out even if the line is e.g. "two words"
        std::string requestType, filePath, protocol;
        read_stream >> requestType >> filePath >> protocol;

        cout << "Request from a connected client: "
             << requestType << " " << filePath << " " << protocol << endl;

        // Read until end of headers
        async_read_until(connection->socket, *read_buffer, "\r\n\r\n",
                        [this, connection, read_buffer, requestType, filePath, protocol](const boost::system::error_code &ec, size_t) {
          // If not error:
          if (!ec) {
            auto write_buffer = make_shared<boost::asio::streambuf>();
            ostream write_stream(write_buffer.get());

            // Determine content to return:
            std::string return_message = determine_message(requestType, filePath, protocol);

            // Add message to be written to client:
            write_stream << return_message << "\r\n\r\n";

            cout << "Will return: " << return_message << endl;

            // Write to client
            async_write(connection->socket, *write_buffer,
                        [connection, write_buffer](const boost::system::error_code &ec, size_t) {
              // If not error:
              if (!ec)
                cout << "Success" << endl;
              return;
            });
          }
        });
      }
    });
  }

  void accept() {
    // The (client) connection is added to the lambda parameter and handle_request
    // in order to keep the object alive for as long as it is needed.
    auto connection = make_shared<Connection>(io_service);
    
    // Accepts a new (client) connection. On connection, immediately start accepting a new connection 
    acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
      accept();
      // If not error:
      if (!ec) {
        handle_request(connection);
      }
    });
  }

public:
  HTTPServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

  void start() {
    accept();

    io_service.run();
  }
};

int main() {
  HTTPServer http_server;

  cout << "Starting HTTP server" << endl
       << "Enter http://localhost:8080 in a web browser and see the magic happen..." << endl;

  http_server.start();
}
// vim:softtabstop=2:shiftwidth=2
