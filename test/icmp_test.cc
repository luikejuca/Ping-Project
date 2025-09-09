#include "icmp_message.h"

#include <gtest/gtest.h>

class IcmpMessageTest : public ::testing::Test 
{
    public:
        void SetUp() override 
        {
        }
    
    private:
        Icmp expect_icmp;
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
    
TEST_F(IcmpMessageTest, ChecksumAllZeros)
{
    std::vector<uint8_t> zero_message(8, 0); // 8 bytes all zero
    uint16_t checksum = expect_icmp.createchecksum(zero_message);
    zero_message.at(2) = (checksum >> 8) & 0xFF;
    zero_message.at(3) = checksum & 0xFF;
    EXPECT_TRUE(expect_icmp.verifychecksum(zero_message));
}

TEST_F(IcmpMessageTest, ChecksumDetectsCorruption)
{
    std::vector<uint8_t> msg = message_;
    uint16_t checksum = expect_icmp.createchecksum(msg);
    msg.at(2) = (checksum >> 8) & 0xFF;
    msg.at(3) = checksum & 0xFF;
    msg.at(0) = 8;
    EXPECT_FALSE(expect_icmp.verifychecksum(msg));
}
