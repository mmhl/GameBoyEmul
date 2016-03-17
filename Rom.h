//
// Created by mhl on 3/16/16.
//

#ifndef GAMEBOYEMUL_ROM_H
#define GAMEBOYEMUL_ROM_H

#include <boost/filesystem.hpp>


enum class RomError {
    ROM_UNSUPP, // Unsupported Cartrige
    ROM_INVALID, // Invalid ROM (e.g. wrong nintendo logo, etc
};

class Rom {
public:
    constexpr static uint8_t NINTENDO_MAGIC[] = {
            0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B, 0x03,
            0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D, 0x00, 0x08,
            0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E, 0xDC, 0xCC, 0x6E,
            0xE6, 0xDD, 0xDD, 0xD9, 0x99, 0xBB, 0xBB, 0x67, 0x63,
            0x6E, 0x0E, 0xEC, 0xCC, 0xDD, 0xDC, 0x99, 0x9F, 0xBB,
            0xB9, 0x33, 0x3E
    };
    constexpr static int NINTENDO_MAGIC_OFFSET = 0x104;
    constexpr static int NINTENDO_MAGIC_LEN = 48;
    static Rom loadFromFile(const std::string &path);

    std::vector<uint8_t> getBytes() const;
    bool verify() const;
private:
    Rom(std::vector<uint8_t> &bytes);

    std::vector<uint8_t> mRomBytes;

};

class RomException : public std::runtime_error {
public:
    RomException(RomError err, const Rom rom);
    virtual const char *what() const throw();

private:
    Rom mRom;
    RomError mError;
};

#endif //GAMEBOYEMUL_ROM_H
