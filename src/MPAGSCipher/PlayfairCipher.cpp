#include <string>
#include <iostream>
#include <algorithm>

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

    // Store the coords of each letter

    // Store the playfair cipher key map
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