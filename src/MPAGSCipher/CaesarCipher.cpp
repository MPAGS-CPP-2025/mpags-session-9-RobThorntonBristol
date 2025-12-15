#include "CaesarCipher.hpp"

#include <string>
#include <cctype>
#include <stdexcept>

CaesarCipher::CaesarCipher(unsigned long key)
    : key_{key}
{
}

CaesarCipher::CaesarCipher(const std::string& key)
{
    // key_ already defaults to 0
    if (key.empty()) {
        return;  // keep default of 0
    }

    // Check that all characters are digits
    for (char c : key) {
        if (!std::isdigit(static_cast<unsigned char>(c))) {
            throw std::invalid_argument(
                "Caesar cipher key must be a positive integer");
        }
    }

    // Safe to convert
    key_ = std::stoul(key);
}

unsigned long CaesarCipher::getKey() const
{
    return key_;
}

std::string CaesarCipher::applyCipher(const std::string& inputText, const std::size_t key, const CipherMode mode)
{
    // Create the output string
    std::string outputText;

    const std::size_t alphabetSize{alphabet_.size()};

    // Make sure that the key is in the range 0 - 25
    const std::size_t truncatedKey{key % alphabetSize};

    // Loop over the input text
    char processedChar{'x'};
    for (const auto& origChar : inputText) {
        // For each character in the input text, find the corresponding position in
        // the alphabet by using an indexed loop over the alphabet container
        for (size_t i{0}; i < alphabetSize; ++i) {
            if (origChar == alphabet_[i]) {
                // Apply the appropriate shift (depending on whether we're encrypting
                // or decrypting) and determine the new character
                // Can then break out of the loop over the alphabet
                if (mode == CipherMode::Encrypt) {
                    processedChar = alphabet_[(i + truncatedKey) % alphabetSize];
                } else {
                    processedChar = alphabet_[(i + alphabetSize - truncatedKey) %
                                             alphabetSize];
                }
                break;
            }
        }

        // Add the new character to the output text
        outputText += processedChar;
    }

    return outputText;
}