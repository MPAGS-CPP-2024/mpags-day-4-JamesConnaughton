//! Unit Tests for MPAGSCipher PlayfairCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "PlayfairCipher.hpp"

TEST_CASE("Playfair Cipher encryption", "[playfair]")
{
    PlayfairCipher pf{"MPAGSCIPHER"};
    REQUIRE(pf.applyCipher("HELLOWORLD", CipherMode::Encrypt) == "ERFZDUPWLULW");
}

TEST_CASE("Playfair Cipher decryption", "[playfair]")
{
    PlayfairCipher pf{"MPAGSCIPHER"};
    REQUIRE(pf.applyCipher("ERFZDUPWLUFW", CipherMode::Decrypt) == "HELXLOWORLDX");
}