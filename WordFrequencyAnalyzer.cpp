#include "WordFrequencyAnalyzer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

WordFrequencyAnalyzer::WordFrequencyAnalyzer(const std::string& input, const std::string& output)
    : inputFilename(input), outputFilename(output) {}

std::string WordFrequencyAnalyzer::readInputFile() const {
    std::ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        std::cout << "Error: Unable to open input file: " << inputFilename << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    inputFile.close();

    return buffer.str();
}

void WordFrequencyAnalyzer::writeOutputFile(const std::string& text, const std::map<std::string, int>& wordFrequency) const {
    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cout << "Error: Unable to open output file: " << outputFilename << std::endl;
        return;
    }

    outputFile << text << std::endl;
    for (const auto& pair : wordFrequency) {
        outputFile << pair.first << ": " << pair.second << std::endl;
    }

    outputFile.close();

    std::cout << "Results saved to " << outputFilename << std::endl;
}

void WordFrequencyAnalyzer::splitWords(const std::string& text, std::map<std::string, int>& wordFreq) const {
    std::istringstream iss(text);
    std::string word;
    while (iss >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        word.erase(std::remove_if(word.begin(), word.end(), [](char c) { return !std::isalpha(c); }), word.end());
        if (!word.empty()) {
            wordFreq[word]++;
        }
    }
}

std::string WordFrequencyAnalyzer::findMostFrequentWord(const std::map<std::string, int>& wordFrequency) const {
    std::string mostFrequentWord;
    int maxFrequency = 0;
    for (const auto& pair : wordFrequency) {
        if (pair.second > maxFrequency) {
            mostFrequentWord = pair.first;
            maxFrequency = pair.second;
        }
    }
    return mostFrequentWord + " (Frequency: " + std::to_string(maxFrequency) + ")";
}

void WordFrequencyAnalyzer::analyze() const {
    std::string text = readInputFile();
    if (text.empty()) {
        std::cout << "Error: Empty input text." << std::endl;
        return;
    }

    // Виведення повного тексту
    std::cout << text << std::endl;

    std::map<std::string, int> wordFrequency;
    splitWords(text, wordFrequency);

    std::cout << "Word Frequencies:\n";
    for (const auto& pair : wordFrequency) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::string mostFrequentWord = findMostFrequentWord(wordFrequency);
    std::cout << "Most frequent word: " << mostFrequentWord << std::endl;

    writeOutputFile(text, wordFrequency);
}