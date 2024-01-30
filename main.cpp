#include <iostream>
#include <fstream>
#include <map>
#include <string>

void readDictionary(std::map<std::string, std::string>& dictionary, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string word, meaning;
        while (file >> word >> meaning) {
            dictionary[word] = meaning;
        }
        file.close();
        std::cout << "Dictionary loaded successfully.\n";
    }
    else {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
}

void writeDictionary(const std::map<std::string, std::string>& dictionary, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& entry : dictionary) {
            file << entry.first << " " << entry.second << std::endl;
        }
        file.close();
        std::cout << "Dictionary saved successfully.\n";
    }
    else {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
}

int main() {
    std::map<std::string, std::string> dictionary;
    std::string filename = "dictionary.txt";

    readDictionary(dictionary, filename);

    int choice;
    std::string word, meaning;
    while (true) {
        std::cout << "\nDictionary Menu:\n";
        std::cout << "1. Search word\n";
        std::cout << "2. Add word\n";
        std::cout << "3. Remove word\n";
        std::cout << "4. Edit word\n";
        std::cout << "5. Display dictionary\n";
        std::cout << "6. Save and Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter word to search: ";
            std::cin.ignore();
            std::getline(std::cin, word);
            if (dictionary.find(word) != dictionary.end()) {
                std::cout << "Meaning: " << dictionary[word] << std::endl;
            }
            else {
                std::cout << "Word not found in dictionary.\n";
            }
            break;
        case 2:
            std::cout << "Enter word to add: ";
            std::cin.ignore();
            std::getline(std::cin, word);
            std::cout << "Enter meaning: ";
            std::getline(std::cin, meaning);
            dictionary[word] = meaning;
            std::cout << "Word added to dictionary.\n";
            break;
        case 3:
            std::cout << "Enter word to remove: ";
            std::cin.ignore();
            std::getline(std::cin, word);
            if (dictionary.erase(word) == 1) {
                std::cout << "Word removed from dictionary.\n";
            }
            else {
                std::cout << "Word not found in dictionary.\n";
            }
            break;
        case 4:
            std::cout << "Enter word to edit: ";
            std::cin.ignore();
            std::getline(std::cin, word);
            if (dictionary.find(word) != dictionary.end()) {
                std::cout << "Enter new meaning: ";
                std::getline(std::cin, meaning);
                dictionary[word] = meaning;
                std::cout << "Word edited in dictionary.\n";
            }
            else {
                std::cout << "Word not found in dictionary.\n";
            }
            break;
        case 5:
            std::cout << "Dictionary:\n";
            for (const auto& entry : dictionary) {
                std::cout << entry.first << ": " << entry.second << std::endl;
            }
            break;
        case 6:
            writeDictionary(dictionary, filename);
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}