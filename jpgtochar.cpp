

#include <iostream>
#include <fstream>

size_t filesize;
socket.send(boost::asio::buffer(JpgToChar(filesize), filesize));

unsigned char buff[11585];
size_t bytes_transferred = socket.receive(boost::asio::buffer(buff));
size_t size = sizeof(buff) / sizeof(buff[0]);
BufferToJpg(buff, size);




void BufferToJpg(unsigned char* output, size_t &size) {

    std::ofstream fout("D:/slika.jpg", std::ios::binary);
    if (!fout.good())
        return;
    fout.write((char*)output, size);


}

unsigned char* JpgToChar(size_t &filesize) {

    
    std::ifstream DataFile("D:/Programiranje/fileovi/slikica.jpg", std::ios::binary);
    if (!DataFile.good())
        return 0;

    DataFile.seekg(0, std::ios::end);
    filesize = (int)DataFile.tellg();
    DataFile.seekg(0);

    
    
     unsigned char *output = new unsigned char[filesize];
     DataFile.read((char*)output, filesize);
    

    return output;


}


int main(){

    std::ifstream DataFile("abc.jpeg", std::ios::binary);
    if(!DataFile.good())
        return 0;

    DataFile.seekg(0, std::ios::end);
    size_t filesize = (int)DataFile.tellg();
    DataFile.seekg(0);

    unsigned char output[filesize];
    //or std::vector
    //or unsigned char *output = new unsigned char[filesize];
    if(DataFile.read((char*)output, filesize))
    {
        std::ofstream fout("D:/Programiranje/def.jpg", std::ios::binary);
        if(!fout.good())
            return 0;
        fout.write((char*)output, filesize);
    }

    
    int size = sizeof(output)/sizeof(output[0]);
    cout<<size<<endl;



    return 0;
}
