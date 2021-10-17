
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include "Paket.h"
using namespace std;

using boost::asio::ip::tcp;


struct Output {

    boost::array<char, 128> buffer;
    size_t len;

    void ReadBuffer() {
        std::cout.write(buffer.data(), len);
    }

};

Output OpenSocket(const std::string &message) {

    try {
        boost::asio::io_context io_context;

        tcp::socket socket(io_context);
        socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 13));

        std::cout << "Rasberry Pi je uspijesno povezan sa serverom" << std::endl;

        for (;;) {
            boost::array<char, 128> buffer;
            //send something and get it back


            boost::system::error_code error;

            boost::asio::write(socket, boost::asio::buffer(message), error);
            std::cout << "Poslan Serveru Pozdrav" << std::endl;

            size_t len = socket.read_some(boost::asio::buffer(buffer), error);

            struct Output output;
            output.len = len;
            output.buffer = buffer;

            return(output);

        }
    }
    

    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

}

int main()
{
 
    
    const std::string message = "poruka za joe bidena\n";


    std::cout << "Uspostavljanje veze..." << std::endl;

    Output output = OpenSocket(message);
    

    


    return 0;
}