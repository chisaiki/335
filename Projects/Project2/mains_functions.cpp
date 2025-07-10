#include <iostream>
#include <fstream>

void readFile(std::string *array, std::string filename = "books.txt"){
                
                std::string myText;
                std::ifstream MyFile(filename);


                int entryCounter = 0;
                if(MyFile){
                    int i = 0;
                    while (getline(MyFile, myText)){
                        array[i] = myText;
                        i++;
                        entryCounter++;
                    }
                    for (int i = 0; i < entryCounter; i++)
                    {
                        std::cout << "Array input " << i << ": " << array[i] << std::endl;
                    }
                    MyFile.close();
                }
                else{
                    std::cout << "Error: Failed to open file. Does it exist?" << std::endl;
                    return;
                }               
}
/*Allow user to type in file nested break to allow custom or default*/