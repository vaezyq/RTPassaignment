

#ifndef RTPSERVER_NETWORK_H
#define RTPSERVER_NETWORK_H

#include <winsock2.h>
#include <stdint.h>

typedef struct {
    const char *dstIp;
    int dstPort;
    struct sockaddr_in servAddr;
    SOCKET socket;
} UDPContext;

/* create UDP socket */
int udpInit(UDPContext *udp);

/* send UDP packet */
int udpSend(const UDPContext *udp, const uint8_t *data, uint32_t len);

#endif //RTPSERVER_NETWORK_H
