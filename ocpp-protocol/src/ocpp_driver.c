#include <stdio.h>
#include "ocpp.h"

int main() {
    //printf("%s\n", get_substring(cms_url, 0, 5));

    // connect to webserver

    // if OK, send a boot notification
        // call server response parser
            // if accepted
                // create authorize packet
                // send authorize packet to CMS

    // if failed retry after some time 

    // 

    if(ocpp_establish_handshake()) { // TODO: write unit test for this
        printf("URL OK\n");
        
    } else {
        printf("URL FAIL\n");
    }

    return 0;
}