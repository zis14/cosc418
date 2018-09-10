/*
 * PacketGenerator.cc
 *
 */
#include <omnetpp.h>

#include "PacketGenerator.h"
#include "AppMessage_m.h"

using namespace omnetpp;

namespace cosc418assignment
{
    Define_Module(PacketGenerator);

    /**
     * Constructor
     */
    PacketGenerator::PacketGenerator() : cSimpleModule()
    {

    }
    /**
     * Destructor
     */
    PacketGenerator::~PacketGenerator()
    {

    }

    /**
     * set up the packet generator with initial values
     * and start to send
     */
    void
    PacketGenerator::initialize()
    {
        //initial set up
        seqno = 0;
        iatDistribution = par("iatDistribution");
        messageSize = par("messageSize");

        //start loop of sending to itself
        scheduleAt(simTime() + iatDistribution, new cMessage());
    }

    /**
     * Generate Packets for the generator
     */
    AppMessage*
    PacketGenerator::GenerateMessage()
    {
        simtime_t currentTime = simTime();

        //TODO: update message name
        AppMessage* message = new AppMessage("tempName");

        message->setTimeStamp(currentTime);
        //TODO: update to transmitter node id
        message->setSenderId(1);
        message->setSeqno(seqno);
        message->setMessageSize(messageSize);

        //increase the sequence number after it has been used
        seqno++;

        return message;
    }

    /**
     * on getting a message from its self (scheduleAt())
     * generate a message and send it off to the next layer
     */
    void
    PacketGenerator::handleMessage(omnetpp::cMessage* message)
    {
        //messege is not needed so can be deleted
        delete message;

        AppMessage* messegeToSend = GenerateMessage();
        send(messegeToSend, "out");

        //continue loop of sending to self
        scheduleAt(simTime() + iatDistribution, new cMessage());
    }
}



