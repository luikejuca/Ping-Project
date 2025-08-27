/**
 * @file 
 * @brief IcmpMessage class definition
 */

#include <stdint.h>

#include <vector>
#include <string>

#ifndef PING-PROJECT_INCLUDE_ICMP_MESSAGE_H
#define PING-PROJECT_INCLUDE_ICMP_MESSAGE_H

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
    virtual std:vector<unint8_t> Encode();

    /**
     * \brief Decode parameter
     * \param Buffer The received message
     * \return True if message is decoded and false for other information
     */
    virtual bool Decode(std::vector<uint8_t> buffer);

    /**
     * \brief Get message type
     * \return The message type
     */
    inline unit8_t type() const
    {
        return type_;
    }
    /**
     * \brief Set message type
     * \param type The expected message type
     */
    inline void set_type(unit8_t type)
    {
       type_ = type;
    }
    /**
     * \brief Get message code
     * \return The message code
     */
    inline unit8_t code() const
    {
        return code_;
    }
    
    /**
     * \brief Set message code
     * \param type The expected message code
     */
    inline void set_code(unit8_t code)
    {
       code_ = code;
    }

    /**
     * \brief Get message data
     * \return The message data
     */
    inline unit16_t data() const
    {
        return data_;
    }

    /**
     * \brief Set message data
     * \param data The expected message data
     */
    inline void set_data(unit16_t data)
    {
       data_ = data;
    }

    private:
    uint8_t type_;      ///< Message type.
    uint8_t code_;      ///< Message code.
    uint16_t checksum_;     ///< Checksum of the icmp header.
    uint16_t id_;       ///< Packet identifier.
    uint16_t seq_;      ///< Packet sequence number.
    std::vector<uint8_t> data_;     ///<Message data
};

#endif

/*
@startuml

class IcmpMessage
{
    +Encode(): vector<unint8_t>
    +Decode(vector<uint8_t> buffer): bool
    +type() const: uint8_t
    +set_type(uint8_t): void
    +code() const: uint8_t
    +set_code(uint8_t): void
    +data() const: uint8_t
    +set_data(uint16_t): void
    
    -type_: uint8_t
    -code_: uint8_t
    -data_: uint16_t
    -checksum_: uint16_t
}

@enduml
*/
