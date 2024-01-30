#include "WordFrequencyAnalyzer.h"

int main() {
    WordFrequencyAnalyzer analyzer("input.txt", "output.txt");
    analyzer.analyze();
    return 0;
}