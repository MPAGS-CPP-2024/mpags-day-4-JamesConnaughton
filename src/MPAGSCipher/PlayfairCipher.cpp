#include <string>
#include <iostream>
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
    
    // TODO: Changne ints in the coords to size_t
    // Change this to a for loop and set up both in the same loop
    // Remove the +1
    // Store the coords of each letter
    int count{0};
    for (char c : key_) {
        int x = count / 5 + 1; 
        int y = count % 5 + 1;
        coordMap_[c] = std::make_pair(x, y);
        count++;
    }

    // Store the playfair cipher key map
    for (auto a: coordMap_) {
        cipherMap_[a.second] = a.first;
    }
}

std::string PlayfairCipher::applyCipher(const std::string& inputText, const CipherMode cipherMode) const {
    std::cout << "We are running the cipher with key " << key_ << std::endl;
    // Change J -> I

    // If repeated chars in a digraph add an X or Q if XX

    // If the siez of input is odd, add a trailing Z

    // Loop over the input in Digraphs

    //   - Find the coords in the grid for each digraph

    //   - Apply the rules to the coords to get 'new' coords

    //   - Find the letter associated with the new coords

    // return the text
    return inputText;
}