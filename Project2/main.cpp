#include "mains_functions.cpp"
#include "hashmap.h"

std::string array[15];

int main()
{
    AvlTree tree;
    AvlNode* book = new AvlNode("The Great Gatsby", "value");


    tree.insert(book->key, book->value);
    tree.insert("hello2", "sam1");
    tree.insert("TheGreatTheGreat", "sam2");

    /*Check if file is valid: Not empty, invalid entries*/
    /*Allow user to continously interact with the book database until they choose exit*/
    char selection;
    while(1){
        std::cout << "\n------- Main Menu -------\nSelect an option:\n(L)oad books from file.\n(S)earch for a book by title.\n(D)isplay table.\n(E)xit\nYour Selection: ";
        std::cin >> selection;
        /*Options*/
        switch(selection) {
            case 'L':{

                char customList;
                std::cout << "\nType 'y' to use a custom file, or any other key to use the default file 'books.txt': ";
                std::cin >> customList;
                
                switch(customList){
                    /*Allow user to type in custom file*/
                     case 'y':{
                        std::string filename;
                        std::cout << "\nEnter File Name: ";
                        std::cin >> filename;
                        
                        //readFile(array, filename);
                        break;
                    }
                    /*Default file is books.txt*/
                    default:{
                        std::cout << "Load" << std::endl;
                        //readFile(array);
                        break;
                    }
                }
                /*Create an object for each book*/
                /*Store each object into the hash map based on the index*/
                break;
            }
                
            case 'S':{
                std::string searchTitle;
                std::cout << "--Search Mode--" << std::endl;
                std::cout << "Enter book title: ";
                std::cin.ignore(); /*Clears Buffers of Previous Inputs*/
                std::getline(std::cin >> std::ws, searchTitle);
                if(tree.search(searchTitle) == NULL)
                {
                    std::cout << "Entry Not Found! " << searchTitle << " does not exist in the records." << std::endl;
                }
                else
                    std::cout<< "Entry Found: \n" << *(tree.search(searchTitle));
                break;
            }
            
            case 'D':{
                /*Need iterator*/
                std::cout << "Display" << std::endl;
                break;
            }
            
            case 'E':{
                std::cout << "Exiting Program ..." << std::endl;
                return 0;
            }

            /*For all other inputs*/
            default:{
                std::cout << "\nError! Invalid Input." << std::endl;
                break;
            }
        }

    }
    return 0;
}