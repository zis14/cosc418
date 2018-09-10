namespace cosc418assignment;

packet AppMessage 
{
	simtime_t timeStamp;
	int senderId;
	int seqno;
	int messageSize;
}
