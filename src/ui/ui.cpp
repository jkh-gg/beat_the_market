#include "ui.h"

UI::UI() {}

void UI::run(std::string state) {
    std::cout << "Welcome to the Text Adventure!\n";
    std::cout << "Type 'help' for a list of commands.\n";

    bool isTick=false;
    std::string command;

    while (!isTick) {
        std::cout << "> ";
        std::getline(std::cin, command);

        // process

        if (command == "q") {
            std::cout << "Exiting game. Goodbye!\n";
            break;
        }
    }
}