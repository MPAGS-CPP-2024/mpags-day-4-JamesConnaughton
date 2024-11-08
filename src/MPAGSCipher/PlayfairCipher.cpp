#include <string>
#include <iostream>

#include "CipherMode.hpp"
#include "PlayfairCipher.hpp"

PlayfairCipher::PlayfairCipher(const std::string& key){
    // Call setKey
    PlayfairCipher::setKey(key);
}

void PlayfairCipher::setKey(const std::string& key){
    
    // Store the original key
    key_ = key;
    
    // Make sure the key is upper case

    // Remove non-alpha characters

    // Change J -> I

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