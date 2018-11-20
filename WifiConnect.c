#include "mbed.h"
#include<ESP32Interface.h>

#define MBED_CONF_APP_WIFI_SSID "Laptop_lenovo"
#define MBED_CONF_APP_WIFI_PASSWORD "Milind@1707"
ESP32Interface wifi(P5_3,P3_14,P7_1,P0_1,P7_7,P7_6);



DigitalOut led1(LED1);
const char *sec2str(nsapi_security_t sec)
{
    switch (sec) {
        case NSAPI_SECURITY_NONE:
            return "None";
        case NSAPI_SECURITY_WEP:
            return "WEP";
        case NSAPI_SECURITY_WPA:
            return "WPA";
        case NSAPI_SECURITY_WPA2:
            return "WPA2";
        case NSAPI_SECURITY_WPA_WPA2:
            return "WPA/WPA2";
        case NSAPI_SECURITY_UNKNOWN:
        default:
            return "Unknown";
    }
}

int scan_demo(WiFiInterface *wifi)
{
    WiFiAccessPoint *ap;
    int count = 15;    /* Limit number of network arbitrary to 15 */
 
    printf("Scan:\r\n");
 
    ap = new WiFiAccessPoint[count];
    count = wifi->scan(ap, count);
    for (int i = 0; i < count; i++)
    {
        printf("Network: %s secured: %s BSSID: %hhX:%hhX:%hhX:%hhx:%hhx:%hhx RSSI: %hhd Ch: %hhd\r\n", ap[i].get_ssid(),
               sec2str(ap[i].get_security()), ap[i].get_bssid()[0], ap[i].get_bssid()[1], ap[i].get_bssid()[2],
               ap[i].get_bssid()[3], ap[i].get_bssid()[4], ap[i].get_bssid()[5], ap[i].get_rssi(), ap[i].get_channel());
    }
    printf("%d networks available.\r\n", count);
 
    delete[] ap;
 
    return count;
}

// main() runs in its own thread in the OS
int main() {
    //int status = network('Navaneeth', 'Centum@1234', NSAPI_SECURITY_WPA_WPA2);
    int status =0;
    
    printf("\r Hello World \n \r");
//while (scan_demo(&wifi) == 0);
 
    printf("\r\nConnecting...\r\n");
    int ret = wifi.connect(MBED_CONF_APP_WIFI_SSID, MBED_CONF_APP_WIFI_PASSWORD, NSAPI_SECURITY_WPA_WPA2);
    if (ret != 0) {
        printf("\r\nConnection error\r\n");
        while(1);
    }
 
    printf("Success\r\n\r\n");
    /*
    printf("MAC: %s\r\n", wifi.get_mac_address());
    printf("IP: %s\r\n", wifi.get_ip_address());
    printf("Netmask: %s\r\n", wifi.get_netmask());
    printf("Gateway: %s\r\n", wifi.get_gateway());
    printf("RSSI: %d\r\n\r\n", wifi.get_rssi());
    */
        


    
    
            
    while (true) {
        led1 = !led1;
        wait(0.5);
    }
}

