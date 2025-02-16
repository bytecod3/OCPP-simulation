/**
 * Handshake 
 */
#include <stdio.h>
#include "ocpp.h"
#include <string.h>
#include <stdint.h>

const char* cms_url = "ws://centralsystem.com/ocpp";


uint8_t get_str_length(const char* str) {
    uint8_t length = 0;
    while (str[0] != '\0')
    {
        ++length;
    }

    return length;
    
}

void ocpp_establish_handshake(char* cms_url) {
    // check for correct websocket address 
    int tok;

    
    // modify the url to append the charge point identity

}


void ocpp_server_response(char*) 
{
    // receive the server response and save into a buffer
    // check the server response for:
    // 404-> does not recognize the cp ID
    // subprotocol agreement 
    // parse JSON and check for the above 
    
}