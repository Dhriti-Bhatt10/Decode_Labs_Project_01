#include <iostream>
#include <string>
#include <algorithm>

// Helper function to convert input to lowercase for easier matching
std::string toLowerCase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    std::string userInput;

    // --- Greeting ---
    std::cout << "==================================================\n";
    std::cout << "Welcome to the Fresh&Clean Dry Cleaning Assistant!\n";
    std::cout << "==================================================\n";
    std::cout << "How can I help you today?\n";
    std::cout << "(You can ask about 'services', 'pricing', 'status', or type 'exit' to quit)\n\n";

    // --- Continuous Loop ---
    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, userInput);
        
        // Clean up input to handle case-insensitivity
        std::string command = toLowerCase(userInput);

        // --- Decision-Making Logic (if-else) ---
        
        // 1. Exit Condition
        if (command == "exit" || command == "quit" || command == "bye") {
            std::cout << "\nBot: Thank you for choosing Fresh&Clean. Have a wonderful day!\n";
            break; // Breaks the continuous loop
        }
        
        // 2. Greetings
        else if (command == "hello" || command == "hi" || command == "hey") {
            std::cout << "Bot: Hello there! Hope your day is going well. How can we help with your laundry or dry cleaning today?\n\n";
        }
        
        // 3. Services Offered
        else if (command.find("service") != std::string::npos || command.find("do you do") != std::string::npos) {
            std::cout << "Bot: We offer premium Dry Cleaning, Stain Removal, Leather Cleaning, and Wash & Fold services.\n\n";
        }
        
        // 4. Pricing Inquiry
        else if (command.find("price") != std::string::npos || command.find("pricing") != std::string::npos || command.find("cost") != std::string::npos) {
            std::cout << "Bot: Our standard standard rates are:\n";
            std::cout << "     - Shirts/Blouses: $5.00\n";
            std::cout << "     - Pants/Suits: $12.00\n";
            std::cout << "     - Dresses: $15.00\n";
            std::cout << "     - Wash & Fold: $2.50 per lb\n\n";
        }
        
        // 5. Order Status Inquiry
        else if (command.find("status") != std::string::npos || command.find("ready") != std::string::npos) {
            std::cout << "Bot: Standard turnaround time is 48 hours. If you have an order number, please call our main desk directly at 555-0199 for a real-time update!\n\n";
        }
        
        // 6. Help / Default fallback
        else {
            std::cout << "Bot: I'm not quite sure I understood that. You can ask me about our 'services', 'prices', or type 'exit' to leave.\n\n";
        }
    }

    return 0;
}