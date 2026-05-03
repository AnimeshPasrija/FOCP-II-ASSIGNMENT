#include <iostream>
#include <string>
#include <vector>
#include <ctime>   // For time()
#include <cstdlib> // For rand() and srand()

int main() {
    // 1. SEEDING: Run this once to ensure random results every time the program opens
    std::srand(static_cast<unsigned int>(std::time(0)));

    char choice;

    // 2. MAIN LOOP: Keeps the program running as long as the user wants
    do {
        std::string studentName = "";

        std::cout << "\n========================================" << std::endl;
        std::cout << "   OFFICIAL STUDENT EXCUSE GENERATOR    " << std::endl;
        std::cout << "========================================\n" << std::endl;

        // 3. INPUT VALIDATION: Prevents empty names
        while (true) {
            std::cout << "Enter the student's full name: ";
            std::getline(std::cin, studentName);

            if (studentName.empty()) {
                std::cout << ">> Error: Name cannot be blank. Please try again.\n";
            } else {
                break; // Name is valid, move to the next step
            }
        }

        // 4. STORAGE: 10 Excuse templates with placeholders
        std::vector<std::string> excuses = {
            "Please excuse {name}, as their alarm clock was hijacked by a mischievous cat.",
            "Due to a sudden localized gravity failure, {name} was unable to leave the house.",
            "The textbook required by {name} was unfortunately seized by pirates.",
            "I am writing to inform you that {name} is late because they had to solve a dispute between two squirrels.",
            "A rogue cloud followed {name} all morning, making travel impossible.",
            "The internet connection at {name}'s house was tired and needed a nap.",
            "Please forgive {name}; they accidentally entered a witness protection program for the morning.",
            "A group of ducks blocked the driveway, and {name} didn't want to be rude by honking.",
            "While studying, {name} accidentally discovered a portal to the year 1922.",
            "The dog didn't eat the homework, but he did hide {name}'s shoes in the freezer."
        };

        // 5. RANDOM SELECTION
        int index = std::rand() % excuses.size();
        std::string selectedExcuse = excuses[index];

        // 6. PLACEHOLDER REPLACEMENT
        std::string target = "{name}";
        size_t pos = selectedExcuse.find(target);
        if (pos != std::string::npos) {
            selectedExcuse.replace(pos, target.length(), studentName);
        }

        // 7. DISPLAY RESULT
        std::cout << "\nGENERATED NOTE:" << std::endl;
        std::cout << "\"" << selectedExcuse << "\"" << std::endl;

        // 8. REPLAY FEATURE
        std::cout << "\nWould you like another excuse? (y/n): ";
        std::cin >> choice;

        /* 
           CLEANING THE BUFFER:
           When you type 'y' and hit Enter, 'y' goes into 'choice' 
           but the 'Enter' key (\n) stays in the buffer. 
           We clear it so the next getline() doesn't think we hit Enter immediately.
        */
        std::cin.ignore(1000, '\n');

    } while (choice == 'y' || choice == 'Y');

    std::cout << "\nProgram closed. Good luck explaining that to the teacher!" << std::endl;

    return 0;
}