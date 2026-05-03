#include <iostream>
#include <string>
#include <vector>
#include <ctime>   // For time()
#include <cstdlib> // For rand() and srand()

int main() {
    // 1. SEEDING: Use the current time to ensure a different random sequence each run
    std::srand(static_cast<unsigned int>(std::time(0)));

    std::string userName = "";

    // 2. INPUT VALIDATION: Ensure the user doesn't enter an empty name
    while (true) {
        std::cout << "Enter your full name for a personalized roast: ";
        std::getline(std::cin, userName);

        if (userName.empty()) {
            std::cout << "Error: You can't be roasted if I don't know who you are! Try again.\n" << std::endl;
        } else {
            break; // Exit loop if name is valid
        }
    }

    // 3. STORAGE: A vector of 10 roasts with the {name} placeholder
    std::vector<std::string> roasts = {
        "I'd love to insult {name}, but nature already did a better job.",
        "Some people bring joy wherever they go; {name} brings joy whenever they leave.",
        "If I had a face like {name}, I'd sue my parents.",
        "I’m not saying {name} is slow, but it takes them two hours to watch 60 Minutes.",
        "I would roast {name}, but I'm legally not allowed to burn garbage.",
        "I've seen more life in a 'Do Not Disturb' sign than I see in {name}.",
        "If {name} was any more useless, they'd be a 'Terms and Conditions' button.",
        "Does {name} ever wonder what it's like to have a personality?",
        "I don't know what makes {name} so stupid, but it's really working.",
        "I'd agree with {name}, but then we’d both be wrong."
    };

    // 4. RANDOM SELECTION: Pick an index from 0 to 9
    int index = std::rand() % roasts.size();
    std::string selectedRoast = roasts[index];

    // 5. PLACEHOLDER REPLACEMENT: Swap {name} with the actual userName
    std::string target = "{name}";
    size_t pos = selectedRoast.find(target);
    
    if (pos != std::string::npos) {
        // replace(starting_position, length_to_remove, string_to_insert)
        selectedRoast.replace(pos, target.length(), userName);
    }

    // 6. OUTPUT: Display the result
    std::cout << "\n------------------------------------------------" << std::endl;
    std::cout << "THE COMPUTER SAYS:" << std::endl;
    std::cout << selectedRoast << std::endl;
    std::cout << "------------------------------------------------\n" << std::endl;

    return 0;
}