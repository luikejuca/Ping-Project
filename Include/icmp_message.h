/**
 * @file
 * @brief IcmpMessage class definition
 */

#include <stdint.h>

#include <vector>
#include <string>

#ifndef PING_PROJECT_INCLUDE_ICMP_MESSAGE_H
#define PING_PROJECT_INCLUDE_ICMP_MESSAGE_H

/**
 * @file
 * @brief Icmp class
 */
class IcmpMessage
{
    public:
    /**
     * \brief Encode parameter
     * \return The message
     */
    virtual std::vector<uint8_t> encode();

    /**
     * \brief Decode parameter
     * \param Buffer The received message
     * \return True if message is decoded and false for other information
     */
    virtual bool decode(const std::vector<uint8_t>& buffer);

    /**
     * \brief Get message type
     * \return The message type
     */
    inline uint8_t type() const
    {
        return type_;
    }

    /**
     * \brief Set message type
     * \param type The expected message type
     */
    inline void set_type(uint8_t type)
    {
       type_ = type;
    }

    /**
     * \brief Get message code
     * \return The message code
     */
    inline uint8_t code() const
    {
        return code_;
    }
    
    /**
     * \brief Set message code
     * \param type The expected message code
     */
    inline void set_code(uint8_t code)
    {
       code_ = code;
    }

    /**
     * \brief Get message data
     * \return The message data
     */
    inline std::vector<uint8_t> data() const
    {
        return data_;
    }

    /**
     * \brief Set message data
     * \param data The expected message data
     */
    inline void set_data(const std::vector<uint8_t>& data)
    {
       data_ = data;
    }

    /**
     * \brief Get message checksum
     * \return The message checksum
     */
    inline uint16_t checksum() const
    {
        return checksum_;
    }

    /**
     * \brief Clear the checksum
     */
    inline void clear_checksum()
    {
        checksum_ = 0;
    };

    /**
     * \brief Create the word of a message [16-bits]
     * \param buffer The message
     * \return The 16-bits verification word
     */
    virtual uint16_t createchecksum(const std::vector<uint8_t>& buffer);

    /**
     * \brief Verify that the receveid message by checking the 16-bits verification word
     * \param buffer The received message
     * \return true if the message is complete and false otherwise
     */
    virtual bool verifychecksum(const std::vector<uint8_t>& buffer);

    private:
    uint8_t type_;              ///< Message type.
    uint8_t code_;              ///< Message code.
    uint16_t checksum_;         ///< Checksum of the icmp header.
    std::vector<uint8_t> data_; ///< Message data
};

#endif

/*

@startuml

class IcmpMessage
{
    +Encode(): vector<uint8_t>
    +Decode(vector<uint8_t> buffer): bool
    +type() const: uint8_t
    +set_type(uint8_t): void
    +code() const: uint8_t
    +set_code(uint8_t): void
    +data() const: vector<uint8_t>
    +set_data(vector<uint8_t>): void
    +checksum() const: uint16_t
    +clear_checksum(): void
    +verifychecksum(const std::vector<uint8_t> &buffer): bool
    +createchecksum(const std::vector<uint8_t> &buffer): uint16_t

    -type_: uint8_t
    -code_: uint8_t
    -checksum_: uint16_t
    -data_: vector<uint8_t>
}

@enduml
*/
