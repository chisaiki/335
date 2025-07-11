#include "hashmap.h"

void readFile(HashTable& table, std::string filename = "books.txt"){
                
                std::string myText;
                std::ifstream MyFile(filename);
                if(MyFile){
                    while (getline(MyFile, myText)){
                        Books book; /*Create Books object on stack*/
                        
                        /*Find positions of commas to split the string*/
                        size_t firstComma = myText.find(',');
                        size_t secondComma = myText.find(',', firstComma + 1);
                        if (firstComma != std::string::npos && secondComma != std::string::npos) {
                            /*Extract title (from start to first comma)*/
                            book.title_ = myText.substr(0, firstComma);
                            
                            /*Extract author (from first comma + 1 to second comma)*/
                            book.author_ = myText.substr(firstComma + 1, secondComma - firstComma - 1);
                            
                            /*Extract genre (from second comma + 1 to end)*/
                            book.genre_ = myText.substr(secondComma + 1);
                        }
                        table.insert(book.title_, book);  //The insert method will then internally combine the author and genre into a string (book.author_ + ", " + book.genre_) before storing it in the AVL tree all I need is to pass the book object
                    }
                    MyFile.close();
                }
                else{
                    std::cout << "Error: Failed to open file. Does it exist?" << std::endl;
                    return;
                }               
}

std::string searchFunction(){
    std::string searchTitle; 
    std::cout << "\n--Search Mode--" << std::endl;
    std::cout << "Enter book title: ";
    std::cin.ignore(); /*Clears Buffers of Previous Inputs*/
    std::getline(std::cin >> std::ws, searchTitle);
    return searchTitle;
}