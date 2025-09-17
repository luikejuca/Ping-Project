#include "icmp_message.h"

#include <gtest/gtest.h>

class IcmpMessageTest : public ::testing::Test 
{
    public:
        void SetUp() override 
        {
        }
    private:
        std::vector<uint8_t> message_ = {5,//type
                                         0,//code
                                         0,//firts byte checksum
                                         0,//second byte checksum
                                         0,//identifier
                                         0,//identifier
                                         0,//sequence number
                                         0 //sequence number
                                        };

    };
    
TEST(IcmpMessageTest, ChecksumAllZeros)
{
    IcmpMessage expect_icmp_;
    std::vector<uint8_t> zero_message(8, 0);
    uint16_t checksum = expect_icmp_.createchecksum(zero_message);
    zero_message.at(2) = (checksum >> 8) & 0xFF;
    zero_message.at(3) = checksum & 0xFF;
    EXPECT_TRUE(expect_icmp_.verifychecksum(zero_message));
}
// Test for detecting corrupted message
TEST(IcmpMessageTest, ChecksumDetectsCorruption)
{
    IcmpMessage expect_icmp_;
    std::vector<uint8_t> message_;
    uint16_t checksum = expect_icmp_.createchecksum(message_);
    message_.at(2) = (checksum >> 8) & 0xFF;
    message_.at(3) = checksum & 0xFF;
    message_.at(0) = 8; 
    EXPECT_FALSE(expect_icmp_.verifychecksum(message_));
}
