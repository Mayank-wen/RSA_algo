# RSA Encryption/Decryption System

This program implements the RSA encryption and decryption algorithm in C++.

## Description

RSA (Rivest–Shamir–Adleman) is a public-key cryptosystem widely used for secure data transmission. It uses the difficulty of factoring large integers into prime factors to provide security. In RSA, each participant has a public key used for encryption and a private key used for decryption.

This program generates RSA keys based on user-provided prime numbers and encrypts a user-provided message using the public key.

## Prerequisites

- C++ compiler
- Standard C++ libraries

## Usage

1. Compile the program using a C++ compiler:

    ```bash
    g++ -o rsa_rsaencryption rsa_encryption.cpp
    ```

2. Run the compiled program:

    ```bash
    ./rsa_rsaencryption
    ```

3. Follow the on-screen instructions:
   - Enter two prime numbers to generate the RSA keys.
   - Enter the message you want to encrypt.
   - The program will output the encrypted message using RSA encryption.
