/*
 * Mac.cc
 *
 *  Created on: Sep 16, 2018
 *      Author: Zubia Ishrat
 */
#include <omnetpp.h>
#include "Mac.h"
#include "MacMessage_m.h"
#include "AppMessage_m.h"
#include <iostream>
#include <sstream>

using namespace omnetpp;
namespace cosc418assignment



{


Define_Module(Mac);

    /**
     * Constructor
     */
    Mac:: Mac() : cSimpleModule()

    {




    }

     /**
      *
     * Destructor
     */


    Mac::~Mac()
    {

        /**


             * set up the mac with initial values and start to send

             */


    }


  void

 Mac::initialize()
{
      //initial setup

 Buff_Size=5*64*1024; //  spaces for 64 bytes
 bufferSize=5;
 maxBackoffs=5; // fixed parameter
 backoffDistribution = par("backoffDisrtibution");
 WATCH(i);
WATCH(bufferSize);
scheduleAt(simTime()+backoffDistribution, new cMessage());
}




  MacMessage*

void
  Mac::GenerateMessage()
  {
     void encapsulate(cMessage *MacMessage);
  }


  void

  Mac :: handleMessage1(cMessage* msg)
  {
      gate("in")->setDeliverOnReceptionStart(true);

         for (int j=0;j<bufferSize;i++)
      {
             cMessage *macbuffer= receive(j);
          MacMessage*  mmsg= Mac::GenerateMessage();
      }
      delete(msg);
      EV << "Buffer Full, wait";
  }


  // **Storing incoming AppMessages into macBuffer- FIFO
  //template<typename T,typename A>
  //void doParsimPacking(omnetpp::cCommBuffer *macbuffer,const std::vector<T,A>& v)
         //{

      //int bufferSize = v.size();
         //doParsimPacking(macbuffer, bufferSize);
         //for (int i = 0; i < bufferSize; i++)
           //  {
           //  doParsimPacking(macbuffer, v[i]);
            // }
         //delete msg; // print log message
                   // EV << "Buffer Full, wait";
       //}

  //template<typename T, typename A>
 // void doParsimUnpacking(omnetpp::cCommBuffer *macbuffer, std::vector<T,A>& v)
  //
     //int bufferSize;
     // doParsimUnpacking(macbuffer, bufferSize);
      //v.resize(bufferSize);
     // for (int i = 0; i < bufferSize; i++)
        //  doParsimUnpacking(macbuffer, v[i]);
 // }

 // packet to be generated and transmitted

void
Mac :: handleMessage2(cMessage* mmsg)
{
for (backoffCounter=0; backoffCounter<maxBackoffs;backoffCounter++)
{
cChannel *txChannel = gate("out")->getTransmissionChannel();
simtime_t txFinishTime = txChannel->getTransmissionFinishTime();
if (txFinishTime <= simTime())
{
    // channel free; send out message immediately
    send(mmsg,"out");
}
else
  {
  wait(backoffDistribution);
  }
}
}

























}

