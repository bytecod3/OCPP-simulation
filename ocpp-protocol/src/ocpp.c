/**
 * Handshake 
 */
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "ocpp.h"

/* custom parameters */
char cms_url[50] = "ws://centralsystem.com/ocpp";
char* charge_point_id = "CP01";

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

/**
 * @brief generate BOOT NOTIFICATION JSON PDU 
 */
char* compose_json_boot_request() {
    char* 
    cJSON* string = NULL;

    cJSON* call_type = NULL;
    cJSON* msg_id = NULL;
    cJSON* msg_type = NULL;
    cJSON* properties = NULL;
    cJSON* charge_point_vendor = NULL;
    cJSON* charge_point_model = NULL;
    cJSON* charge_point_serial_number = NULL;
    cJSON* charge_box_serial_number = NULL;
    cJSON* firmware_version = NULL;
    cJSON* iccid = NULL;
    cJSON* imsi = NULL;
    cJSON* meter_type = NULL;
    cJSON* meter_serial_number = NULL;

    cJSON* boot_notification_obj = cJSON_CreateObject();
    if(boot_notification_obj == NULL) {
        goto end;
    }
    
    properties = cJSON_CreateObject();
    if(properties == NULL) {
        goto end;
    }
    charge_point_vendor = cJSON_CreateString("charge_point_vendor");
    cJSON_AddItemToObject(properties, "properties", charge_point_vendor);

    end:
    cJSON_Delete(obj);
    return string;
}

uint8_t ocpp_establish_handshake(char* cms_url) {
    /*check for correct URL - I am checking if the URL starts
    with "ws://"
    */ 

    if(strcmp("ws://", get_substring(cms_url, 0, 5)) == 0) {
        // modify the url to append the charge point identity
        strcat(cms_url, charge_point_id);
        
        /* new CMS url with charge point ID - create JSON object*/

        

        return 1;
    } else {
        return 0;
    }

}


// void ocpp_server_response(char*) {
    // receive the server response and save into a buffer
    // check the server response for:
    // 404-> does not recognize the cp ID
    // subprotocol agreement 
    // parse JSON and check for the above 
    
// }
