/*
 * Mac.h
 *
 *  Created on: Sep 16, 2018
 *      Author: Zubia Ishrat
 */

#ifndef MAC_H_
#define MAC_H_

#include <omnetpp.h>

#include "MacMessage_m.h"
#include "AppMessage_m.h"


using namespace omnetpp;

namespace cosc418assignment

{

    class Mac : public :: omnetpp:: cSimpleModule


    {

    public:

        Mac(void);

        ~Mac(void);

        virtual void initialize(void);


        virtual void handleMessage1(omnetpp::cMessage *msg);
        virtual void handleMessage2(omnetpp::cMessage *mmsg);

        MacMessage* GenerateMessage(void);

    private:

        int Buff_Size;

        int bufferSize;

        double backoffDistribution;

        int maxBackoffs;

        int backoffCounter;

        virtual void macbuffer(omnetpp::cCommBuffer *Buff_Size);

          int i;
           int n;
           int j;

    };
}







#endif /* MAC_H_ */
