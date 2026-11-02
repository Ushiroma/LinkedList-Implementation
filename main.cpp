#include "LinkedList.h"
#include <iostream>
#include <cctype>
#include <string>

// Function to sanitize a string by removing non-alphanumeric characters and converting to lowercase
std::string sanitizeString(std::string stat) {
    std::string cleanStat = "";
    for (int i = 0; i < stat.length(); i++) {
        if (isalnum(stat[i])) {
            cleanStat += std::tolower(stat[i]);
        }
    }
    return cleanStat;
}

void checkPalindrome(std::string stat) {
    LinkedList stat1; // Stack - reverse data
    LinkedList stat2; // Queue - maintain order of input

    // Preprocess string
    std::string testStat = sanitizeString(stat);

    // Populate both lists
    for (int i = 0; i < testStat.length(); i++) {
        stat1.insertAtFront(testStat[i]);
        stat2.insertAtBack(testStat[i]);
    }

    // Compare elements removed from the front of each list
    bool isPalindrome = true;

    for (int i = 0; i < testStat.length(); i++) {
        char ch1 = stat1.removeAtFront().getData();
        char ch2 = stat2.removeAtFront().getData();

        if (ch1 != ch2) {
            isPalindrome = false;
            break;
        }
    }

    // Output result
    if (isPalindrome) {
        std::cout << "Is a Palindrome" << std::endl;
    }
    else {
        std::cout << "Not a Palindrome" << std::endl;
    }
}

int main() {
    std::string sentence;
    std::cout << "Enter a string: ";
    std::getline(std::cin, sentence);

    checkPalindrome(sentence);

    return 0;
}