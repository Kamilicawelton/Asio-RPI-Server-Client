

#include <iostream>
#include <fstream>

using namespace std;

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
