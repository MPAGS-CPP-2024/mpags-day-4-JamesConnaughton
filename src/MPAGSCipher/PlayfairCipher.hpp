#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP

#include <string>
#include "CipherMode.hpp"

/**
 * \file PlayfairCipher.hpp
 * \brief Contains the declaration of the PlayfairCipher class
 */

/**
 * \class PlayfairCipher
 * \brief Encrypt or decrypt text using the Playfair cipher with the given key
 */
class PlayfairCipher {
  public:
    /**
     * \brief Create a new PlayfairCipher with the given key
     * 
     * \param key the key to use in the cipher
     */
    PlayfairCipher(const std::string& key);

    /**
     * \brief Apply the cipher to the provided text
     * 
     * \param inputText the text to encrypt or decrypt
     * \param cipherMode whether to encrypt or decrypt the input text
     * \return the result of applying the cipher to the input text
     */
    std::string applyCipher(const std::string& inputText, const CipherMode cipherMode) const;
  private:
    /**
     * \brief Set the variable key_ appropriately for the cipher according to the input key
     * 
     * \param key the inputted key
     */
    void setKey(const std::string& key);
    
    /// The cipher key
    std::string key_{""};
};

#endif // MPAGSCIPHER_PLAYFAIRCIPHER_HPP