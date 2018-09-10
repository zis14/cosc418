/*
 * PacketGenerator.h
 *
 */

#ifndef PACKETGENERATOR_H_
#define PACKETGENERATOR_H_

#include <omnetpp.h>
#include "AppMessage_m.h"

namespace cosc418assignment
{
    class PacketGenerator : public ::omnetpp::cSimpleModule
    {
    public:
        PacketGenerator(void);
        ~PacketGenerator(void);
        virtual void initialize(void);
        virtual void handleMessage(omnetpp::cMessage *message);
        AppMessage* GenerateMessage(void);
    private:
        int seqno;
        double iatDistribution;
        int messageSize;
    };
}



#endif /* PACKETGENERATOR_H_ */
