#ifndef MPAGSCIPHER_CIPHERMODE_HPP
#define MPAGSCIPHER_CIPHERMODE_HPP


/**
 * \file CipherMode.hpp
 * \brief Declaration of the CipherMode enumeration
 */

/**
 * \enum CipherMode
 * \brief Fixes cipher mode options to encrypt and decrypt
 */
enum class CipherMode {
    Encrypt, ///< Encryption mode
    Decrypt  ///< Decryption mode
};

#endif    // MPAGSCIPHER_CIPHERMODE_HPP