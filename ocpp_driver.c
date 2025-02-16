#include <stdio.h>
#include "ocpp.h"

char* cms_url = "ws://centralsystem.com/ocpp";

int main() {
    printf("%s\n", get_substring(cms_url, 0, 5));

    if(ocpp_establish_handshake(cms_url)) { // TODO: write unit test for this
        printf("URL OK\n");

        
    } else {
        printf("URL FAIL\n");
    }

    return 0;
}