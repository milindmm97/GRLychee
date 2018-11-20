#include "mbed.h"
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

// main() runs in its own thread in the OS
int main() {
    printf("Hello World!\n\r");
    while (true) {
        
        led1 = !led1;
        wait(0.1);
        printf("Hello World!\n\r");     //trying to print without /n will not work
                                        //needs to flush buffer
        
        
    }
}

