#ifndef OCPP_H
#define OCPP_H

#include <stdint.h>
#include "lib/cJSON.h"

/**
 * @brief establish connection to CMS using the endpoint provided
 * 
 */

uint8_t ocpp_establish_handshake(void);

void ocpp_server_response(char*);

void ocpp_heartbeat();

/* helper functions */
char* get_substring(char* str, uint8_t start, uint8_t length);
uint8_t get_str_length(const char* str);
char* compose_json_boot_request();


#endif