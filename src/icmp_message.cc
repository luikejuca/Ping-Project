/**
 * @file
 * @brief IcmpMessage class method
 */

#include "icmp_message.h"

bool IcmpMessage::decode(const std::vector<uint8_t> buffer)
{
    return false;
}

std::vector<uint8_t> IcmpMessage::encode()
{
    return std::vector<uint8_t>();
}

uint16_t IcmpMessage::createchecksum(const std::vector<uint8_t> &buffer)
{
    uint32_t sum = 0;
    size_t i = 0;

    while (i + 1 < buffer.size()) {
        uint16_t word = (buffer[i] << 8) + buffer[i + 1];
        sum += word;
        i += 2;
    }

    if (i < buffer.size()) {
        sum += buffer[i] << 8;
    }

    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }

    checksum_ = static_cast<uint16_t>(~sum);

    return checksum_;
}

bool IcmpMessage::verifyCheckSum(const std::vector<uint8_t>& buffer)
{
    return createCheckSum(buffer) == 0 ? true : false;
}
