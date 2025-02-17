#include <stdio.h>
#include "ocpp.h"

int main() {
    //printf("%s\n", get_substring(cms_url, 0, 5));

    if(ocpp_establish_handshake()) { // TODO: write unit test for this
        printf("URL OK\n");
        
    } else {
        printf("URL FAIL\n");
    }

    return 0;
}