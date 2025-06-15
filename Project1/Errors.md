# Errors I Ran Into

## Syntax Errors
``` 
Matrix33::printFunc()
{
    std::cout << "\nPrint Function Called" << std::endl;
}

```
This is wrong because I need to declare the function type before I specify the scope of the function itself

Correct: ``` void Matrix33::printFunc() ```