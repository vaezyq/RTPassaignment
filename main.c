

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utils.h"
#include "RTPEnc.h"
#include "Network.h"

#pragma comment(lib, "ws2_32")

int main() {

    int len = 0;
    int res;
    int *stream = NULL;
    const char *fileName = "Sample.h264";

    RTPMuxContext rtpMuxContext;
    UDPContext udpContext = {
            .dstIp = "127.0.0.1",   // destination ip
            .dstPort = 1234         // destination port
    };

    res = readFile(&stream, &len, fileName);


//    len = 100;
//
//    int array[100];
//    for (int i = 0; i < 100; ++i) {
//        array[i] = rand() % 20;
//    }
//
//
//    stream = array;
//    res = 0;

    if (res) {
        printf("readFile error.\n");
        return -1;
    }

    // create udp socket
    res = udpInit(&udpContext);
    if (res) {
        printf("udpInit error.\n");
        return -1;
    }

    initRTPMuxContext(&rtpMuxContext);
    rtpSendH264HEVC(&rtpMuxContext, &udpContext, stream, len);

    free(stream);
    printf("test");

    return 0;
}