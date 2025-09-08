/**
 * @file 
 * @brief client class definition
 */

#include <string>

#include "icmp_message.h"

#ifndef PING_PROJECT_INCLUDE_CLIENT_H
#define PING_PROJECT_INCLUDE_CLIENT_H

/**
 * @file 
 * @brief client class
 */
class Client {
   public:
    Client(std::shared_ptr<Socket> socket = nullptr)
    bool Ping(std::string ip="127.0.0.1", size_t pkt_counter=1){

        buffer_send = msg.Encode()
        socket_->Send(buffer_send)

        buffer_recv = socket_->Recv();
        msg.Decode(buffer_recv)

        return true;
    }
}
 class client
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
     * \brief Get message identifier
     * \return The message identifier
     */
    inline unit16_t identifier() const
    {
        return identifier_;
    }

    /**
     * \brief Set message identifier
     * \return The message identifier
     */
    
    
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
