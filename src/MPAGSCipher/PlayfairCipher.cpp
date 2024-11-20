#include <string>
#include <algorithm>
#include <map>

#include "CipherMode.hpp"
#include "PlayfairCipher.hpp"

PlayfairCipher::PlayfairCipher(const std::string& key){
    // Call setKey
    this->setKey(key);
}

void PlayfairCipher::setKey(const std::string& key){
    
    // Store the original key
    key_ = key;
    
    // Append the alphabet
    key_ += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Make sure the key is upper case
    std::transform(key_.begin(), key_.end(), key_.begin(), ::toupper);

    // Remove non-alpha characters
    key_.erase(std::remove_if(key_.begin(), key_.end(), 
                              [] (char c) {return !(std::isalpha(c));}), 
               key_.end());
    
    // Change J -> I
    std::transform(key_.begin(), key_.end(), key_.begin(),
                   [] (char c) {return (c == 'J') ? 'I' : c;});
    
    // Remove duplicated letters
    std::string encounteredLetters{""};
    auto checkEncountered = [&] (char c) {
        // Check if the char has not been encountered
        // If it has, then add it to the encountered letters
        // and return false since we want to keep it
        if (encounteredLetters.find(c) == std::string::npos){
            encounteredLetters += c;
            return false;
        }
        // Otherwise return true
        else {
            return true;
        }
    };
    key_.erase(std::remove_if(key_.begin(), key_.end(), checkEncountered), key_.end());
    
    // Store the coords of each letter
    // Store the playfair cipher key map
    std::size_t count{0};
    for (char c : key_) {
        std::size_t x = count / 5; 
        std::size_t y = count % 5;
        coordMap_[c] = std::make_pair(x, y);
        cipherMap_[std::make_pair(x, y)] = c;
        count++;
    }
}

std::string PlayfairCipher::applyCipher(const std::string& inputText, const CipherMode cipherMode) const {
    
    std::string cipherText = inputText;
    
    // Change J -> I
    std::transform(cipherText.begin(), cipherText.end(), cipherText.begin(),
                    [] (char c) {return (c == 'J') ? 'I' : c;});

    // If repeated chars in a digraph add an X or Q if XX
    {
    auto it{cipherText.begin()};
    while (it != cipherText.end()){
        if (*it == *(it - 1)) {
            char insertChar = 'X';
            if (*it == 'X') {
                insertChar = 'Q';
            }
            it = cipherText.insert(it, insertChar);
            ++it;
        }
        ++it;
    }
    }
    // If the size of input is odd, add a trailing Z
    if (cipherText.size() % 2 == 1) {
        cipherText += 'Z';
    }
    std::string outputText{""};
    // Loop over the input in Digraphs
    for (auto it{cipherText.begin()}; it != cipherText.end(); std::advance(it, 2)) {
        // Find the coords in the grid for each digraph
        std::pair<int, int> coord1 = (*coordMap_.find(*it)).second;
        std::pair<int, int> coord2 = (*coordMap_.find(*(it + 1))).second;

        std::pair<int, int> newCoord1{coord1};
        std::pair<int, int> newCoord2{coord2};

        // If encrypting we shift by 1 
        // If decrypting we shift by 4 (= 1 in other direction)
        std::size_t shift{1};
        if (cipherMode == CipherMode::Decrypt){
            shift = 4;
        }
        
        // If in the same row, pick the letters to the right
        if (coord1.first == coord2.first) {
            newCoord1.second = (coord1.second + shift) % 5;
            newCoord2.second = (coord2.second + shift) % 5;
        }
        // If in the same column, pick the letters beneath
        else if (coord1.second == coord2.second) {
            newCoord1.first = (coord1.first + shift) % 5;
            newCoord2.first = (coord2.first + shift) % 5;
        }
        // If forming a rectangle, exchange the columns
        else {
            newCoord1.second = coord2.second;
            newCoord2.second = coord1.second;
        }
        
        outputText += (*cipherMap_.find(newCoord1)).second;
        outputText += (*cipherMap_.find(newCoord2)).second;
    }

    // Return the text
    return outputText;
}