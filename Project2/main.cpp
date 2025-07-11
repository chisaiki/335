#include "mains_functions.cpp"

std::string array[15];

int main()
{
    HashTable hashTable(7);

    /*Allow user to continously interact with the book database until they choose exit*/
    char selection;
    while(1){
        std::cout << "\n------- Main Menu -------\nSelect an option:\n(L)oad books from file.\n(S)earch for a book by title.\n(D)isplay table.\n(E)xit\nYour Selection: ";
        std::cin >> selection;
        
        switch(selection) {
            case 'L':{ /*Load*/

                char customList;
                std::cout << "\nType 'y' to use a custom file, or enter other letter to use the default file 'books.txt': ";
                std::cin >> customList;
                
                switch(customList){
                    /*Allow user to type in custom file*/
                     case 'y':{
                
                        std::string filename;
                        std::cout << "\nEnter File Name: ";
                        std::cin >> filename;
                        
                        if(hashTable.empty() == false)
                            hashTable.clear();

                        readFile(hashTable, filename);
                        break;
                    }
                    /*Default file is books.txt*/
                    default:{

                        readFile(hashTable);
                        break;
                    }
                }
                break;
            }
                
            case 'S':{ /*Search*/

                std::cout<< "Result: " << hashTable.search(searchFunction()) << std::endl;
                break;
            }
            
            case 'D':{ /*Display*/

                std::cout << "\n--Display Mode--" << std::endl;
                hashTable.display();
                break;
            }
            
            case 'E':{ /*Exit Program*/

                std::cout << "\nExiting Program ..." << std::endl;
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