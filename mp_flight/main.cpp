
#include "util/UserCommand.h"


#include <iostream>


int main(int argc, char *argv[]) {
    string userInput = "menu";
    UserCommand uc;
    std::cout << "Starting ...please enter a command:"  << std::endl;
    
    while(true) {
        if(userInput == "exit") break;
        std::cout << uc.executeInstruction(userInput)  << std::endl;
        std::getline (std::cin, userInput);
    }
    
}