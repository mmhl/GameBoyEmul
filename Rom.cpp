//
// Created by mhl on 3/16/16.
//

#include "Rom.h"

#include <iomanip>
#include <boost/filesystem/fstream.hpp>
#include <iostream>

constexpr uint8_t Rom::NINTENDO_MAGIC[];

Rom Rom::loadFromFile(const std::string &filePath) {
    using namespace boost::filesystem;
    path file(filePath);
    if(!exists(file)) {
       throw std::system_error(ENOENT, std::system_category());
    }
    ifstream fstream;
    fstream.unsetf(std::ios::skipws); // Skip newlines
    fstream.open(file, std::ios::binary | std::ios::in);

    std::vector<uint8_t> bytes(file_size(file));
    bytes.insert(bytes.begin(), std::istream_iterator<uint8_t>(fstream), std::istream_iterator<uint8_t>());

    return Rom(bytes);
}

Rom::Rom(std::vector<uint8_t> &bytes) {
    mRomBytes = bytes;
}

Rom::Rom(uint8_t *bytes, int size) {

}

bool Rom::verify() {
    using namespace std;
    vector<uint8_t>::iterator magic_begin = mRomBytes.begin() + Rom::NINTENDO_MAGIC_OFFSET;
    vector<uint8_t>::iterator magic_end = mRomBytes.begin() + Rom::NINTENDO_MAGIC_OFFSET + Rom::NINTENDO_MAGIC_LEN;

    vector<uint8_t> rom_magic(magic_begin, magic_end);

    for(int i = 0; i < rom_magic.size(); ++i) {
        if(rom_magic[i] != Rom::NINTENDO_MAGIC[i])
            return false;
    }
    return true;
}


RomException::RomException(RomError err, const Rom rom) : std::runtime_error("ROM Exception"),
                                                          mRom(rom), mError(err) {

}

const char *RomException::what() const throw() {
    switch (mError) {
        case RomError::ROM_INVALID:
            return "Invalid ROM";
        case RomError::ROM_UNSUPP:
            return "Unsupported ROM type";
    }
}





