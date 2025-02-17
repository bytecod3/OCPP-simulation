## Introduction 
This is the implementation of the OCPP-1.6 protocol

### Tools
- Firmware-simulation: C
- CMS Websockets server: Python
- Platform: Windows

### Description of the OCPP protocol
OCPP protocol is a set of rules used to negotiate the relationship/communication between EV charge points and central management systems.  It describes how messages are packaged, server responses, error handling schemes, state transitions and the like.   
This protocol allows EV chargers to have remote monitoring, marriage with any vendor supporting OCPP, load balancing, control and payment schemes, among others. 

### Approach used to implement 
For implementation of this protocol, I mapped out the necessary functionality I need to implement. Listed below are the functions needed to have a full working OCPP stack:
- connection to CSMS
- BootNotification 
- Heartbeat
- Authorization 
- StartTransaction
- StatusNotification
- FirmwareUpdate

This implementation builds only the first 3 of these.

---
To connect to the CSMS via websockets, we need to have a websocket client and server. The client was build in C using ```libwebsockets```.  
Once a websocket connection is SUCCESS, the client(charge point) can send messages to the server. These PDUs(protocol data units) are formatted as JSON objects to conform with the **OCPP-JSON-1.6 Specification**. 


#### Boot notification
The boot notification request looks like shown below: 

```json
{
        "call_type":    2,
        "id":   "msg_001",
        "type": "BootNotification",
        "properties":   {
                "charge_point_vendor":  "VENDOR",
                "charge_point_model":   "CP001",
                "charge_point_serial_number":   "CJ-12345ABCD",
                "charge_box_serial_number":     "CJ-ABCD12345",
                "firmware_version":     "1.1",
                "iccid":        "1",
                "imsi": "1",
                "meter_type":   "dual-gun",
                "meter_serial_number":  "CJ-ABC123ABC"
        }
}

```

The server response is expected to have the following structure: 

```json

[3, "12345", {
    "status": "Accepted",
    "currentTime": "2025-02-17T12:00:00Z",
    "interval": 300
}]

```

#### Heartbeat
The interval value in the above server response represents the heartbeat interval set by the CSMS. 

The server is built using python.