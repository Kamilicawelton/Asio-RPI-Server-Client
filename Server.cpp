


#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string read_(tcp::socket& socket) {
    boost::asio::streambuf buf;
    boost::asio::read_until(socket, buf, "\n");
    std::string data = boost::asio::buffer_cast<const char*>(buf.data());
    return data;
}

void send_(tcp::socket& socket, const std::string& message) {
    const std::string msg = message + "\n";
    boost::asio::write(socket, boost::asio::buffer(message));
}


int main()
{
   
    try
    {

        boost::asio::io_context io_context;

        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 13));

        std::cout << "Server pokrenut na portu " << "13" << std::endl;
        

        for (;;)
        {
            
            tcp::socket socket(io_context);
            acceptor.accept(socket);
            std::cout << "Klijent konektan" << std::endl;

            //pošto je server sinkron, ne idemo dalje dok korak se ne odradi
            //u ovom slucaju cekamo da nam nesto posalje klijent pa onda ce nas cekat klijent da mu posaljemo mi nesto
            //kad se to odradi io_context koji je kao lista poslova koji se moraju odraditi bit ce prazan, kad je prazan automatski exita kod samo klijent

            std::cout << "Poruka od Klijenta: " << std::endl;
            std::string readmessage = read_(socket);
            std::cout << readmessage << std::endl;


            std::string sendmessage = "Poruka";

            boost::system::error_code ignored_error;
            boost::asio::write(socket, boost::asio::buffer(sendmessage), ignored_error);
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}