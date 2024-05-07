#include <iostream>
#include <string>
#include <sstream> // For string stream
#include <cctype>  // For character classification
#include <vector>  // For vector
#include <algorithm> // For std::count_if

int count_words(const std::string& text) {
    std::stringstream ss(text);
    std::string word;
    int word_count = 0;
    while (ss >> word) {
        word_count++;
    }
    return word_count;
}

int count_sentences(const std::string& text) {
    int sentence_count = 0;
    for (char c : text) {
        if (c == '.' || c == '!' || c == '?') {
            sentence_count++;
        }
    }
    return sentence_count;
}

int count_characters(const std::string& text) {
    int char_count = 0;
    for (char c : text) {
        if (!std::isspace(c)) { // Count only non-space characters
            char_count++;
        }
    }
    return char_count;
}

int count_paragraphs(const std::string& text) {
    std::stringstream ss(text);
    std::string line;
    int paragraph_count = 0;
    while (std::getline(ss, line)) {
        // Check if the line has non-space characters
        if (!line.empty() && std::count_if(line.begin(), line.end(), [](char c) { return !std::isspace(c); }) > 0) {
            paragraph_count++;
        }
    }
    return paragraph_count;
}

int main() {
    std::cout << "Enter a paragraph: ";
    std::string paragraph;
    std::getline(std::cin, paragraph); // Read the entire paragraph

    // Count words, sentences, characters, and paragraphs
    int word_count = count_words(paragraph);
    int sentence_count = count_sentences(paragraph);
    int char_count = count_characters(paragraph);
    int paragraph_count = count_paragraphs(paragraph);

    // Display the results
    std::cout << "Word count: " << word_count << std::endl;
    std::cout << "Sentence count: " << sentence_count << std::endl;
    std::cout << "Character count (excluding spaces): " << char_count << std::endl;
    std::cout << "Paragraph count: " << paragraph_count << std::endl;

    return 0;
}
