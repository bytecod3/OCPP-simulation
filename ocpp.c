/**
 * Handshake 
 */
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "ocpp.h"

uint8_t get_str_length(const char* str) {
    uint8_t count = 0;
    while (str[count] != '\0')
    {
        ++count;
    }

    return count; 
}

/**
 * @brief extract a substring string 
 * @param start - index to start extracting
 * @param length - size of string to extract
 */
char* get_substring(char* str, uint8_t start, uint8_t length) {
    char ss[6]; /*to store the substring*/
    strncpy(ss, str+start, length);
    ss[length] = '\0'; /* nul terminate */
    char* t = (char*) malloc(sizeof(char) + 1); //  TODO: not advised on MCUs - look for alternatives

    strcpy(t, ss);

    return t;
}


uint8_t ocpp_establish_handshake(char* cms_url) {
    /*check for correct URL - i am checking if the URL starts
    with "ws://"
    */ 

    if(strcmp("ws://", get_substring(cms_url, 0, 5)) == 0) {
        return 1;
    } else {
        return 0;
    }
    
    // modify the url to append the charge point identity

}


// void ocpp_server_response(char*) {
    // receive the server response and save into a buffer
    // check the server response for:
    // 404-> does not recognize the cp ID
    // subprotocol agreement 
    // parse JSON and check for the above 
    
// }
