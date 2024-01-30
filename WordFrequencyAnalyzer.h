#ifndef WORD_FREQUENCY_ANALYZER_H
#define WORD_FREQUENCY_ANALYZER_H

#include <map>
#include <string>

class WordFrequencyAnalyzer {
private:
    std::string inputFilename;
    std::string outputFilename;

    std::string readInputFile() const;
    void writeOutputFile(const std::string& text, const std::map<std::string, int>& wordFrequency) const;
    void splitWords(const std::string& text, std::map<std::string, int>& wordFreq) const;
    std::string findMostFrequentWord(const std::map<std::string, int>& wordFrequency) const;

public:
    WordFrequencyAnalyzer(const std::string& input, const std::string& output);
    void analyze() const;
};

#endif // WORD_FREQUENCY_ANALYZER_H