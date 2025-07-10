#include <iostream>
#include <fstream>
#include <vector>

struct Books{
    /*Title (string) — used as the key.*/
    std::string title_;
    /*Author (string)*/
    std::string author_;
    /*Genre (string)*/
    std::string genre_;
};

void readFile(std::string *array, std::string filename = "books.txt"){
                
                std::string myText;
                std::ifstream MyFile(filename);

                int entryCounter = 0;
                if(MyFile){
                    int i = 0;
                    while (getline(MyFile, myText)){
                        Books book;           /*Create Books object on stack*/

                        /*Split the file text*/
                        book.title_ = myText;
                        //book.author_ =
                        //book.genre_ =
                        
                        array[i] = book.title_;    // Store title in array
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
