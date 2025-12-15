#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>
#include <vector>
#include "CipherMode.hpp"

/**
 * \file CaesarCipher.hpp
 * \brief Declaration of the CaesarCipher class
 */

/**
 * \class CaesarCipher
 * \brief Holds ecryption key. Can retrieve key and apply cipher using this class.
 */
class CaesarCipher {
    public:
        explicit CaesarCipher(unsigned long key);
        explicit CaesarCipher(const std::string& key);

        std::string applyCipher(const std::string& inputText, const std::size_t key, const CipherMode mode);

        unsigned long getKey() const;

    private:
        unsigned long key_{0};                                ///< Cipher key
        const std::vector<char> alphabet_{                    ///< Alphabet
        'A','B','C','D','E','F','G','H','I','J','K','L','M',
        'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
        };
};



#endif    // MPAGSCIPHER_CAESARCIPHER_HPP
