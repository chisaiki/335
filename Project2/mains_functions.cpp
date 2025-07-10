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

void readFile(Books *array, std::string filename = "books.txt"){
                
                std::string myText;
                std::ifstream MyFile(filename);

                int entryCounter = 0;
                if(MyFile){
                    int i = 0;
                    while (getline(MyFile, myText)){
                        Books book;           /*Create Books object on stack*/
                        
                        // Find positions of commas to split the string
                        size_t firstComma = myText.find(',');
                        size_t secondComma = myText.find(',', firstComma + 1);
                        
                        if (firstComma != std::string::npos && secondComma != std::string::npos) {
                            // Extract title (from start to first comma)
                            book.title_ = myText.substr(0, firstComma);
                            
                            // Extract author (from first comma + 1 to second comma)
                            book.author_ = myText.substr(firstComma + 1, secondComma - firstComma - 1);
                            
                            // Extract genre (from second comma + 1 to end)
                            book.genre_ = myText.substr(secondComma + 1);
                        }
                        
                        array[i] = book;    // Store title in array
                        i++;
                        entryCounter++;
                    }
                    for (int i = 0; i < entryCounter; i++)
                    {
                        std::cout << "Book " << i << ":" << std::endl;
                        std::cout << "  Title: " << array[i].title_ << std::endl;
                        std::cout << "  Author: " << array[i].author_ << std::endl;
                        std::cout << "  Genre: " << array[i].genre_ << std::endl;
                        std::cout << std::endl;
                    }
                    
                    MyFile.close();
                }
                else{

                    std::cout << "Error: Failed to open file. Does it exist?" << std::endl;
                    return;
                }               
}

/*Need a function to split through the code*/

// Alternative function that stores complete Books objects
void readBooksToVector(std::vector<Books>& books, std::string filename = "books.txt"){
    std::string myText;
    std::ifstream MyFile(filename);
    
    if(MyFile){
        while (getline(MyFile, myText)){
            Books book;
            
            // Find positions of commas to split the string
            size_t firstComma = myText.find(',');
            size_t secondComma = myText.find(',', firstComma + 1);
            
            if (firstComma != std::string::npos && secondComma != std::string::npos) {
                // Extract title (from start to first comma)
                book.title_ = myText.substr(0, firstComma);
                
                // Extract author (from first comma + 1 to second comma)
                book.author_ = myText.substr(firstComma + 1, secondComma - firstComma - 1);
                
                // Extract genre (from second comma + 1 to end)
                book.genre_ = myText.substr(secondComma + 1);
                
                books.push_back(book);
            }
        }
        
        // Display all parsed books
        for (size_t i = 0; i < books.size(); i++) {
            std::cout << "Book " << i << ":" << std::endl;
            std::cout << "  Title: " << books[i].title_ << std::endl;
            std::cout << "  Author: " << books[i].author_ << std::endl;
            std::cout << "  Genre: " << books[i].genre_ << std::endl;
            std::cout << std::endl;
        }
        
        MyFile.close();
    }
    else{
        std::cout << "Error: Failed to open file. Does it exist?" << std::endl;
        return;
    }
}