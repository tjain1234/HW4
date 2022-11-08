/** @file main.cpp
 *  This file runs two tasks simulataneously to produce Square waves of 500Hz
 *  and 5Hz each at 50% duty cycle.
 */

#include "Arduino.h"
#include "PrintStream.h"
#include "task_debounce.h"


// Creates a variable FAST_PIN with a value of 12
#define FAST_PIN 12
#define Button 13

void task_Fast (void* p_params)
{
    //Prints a string to show that task_Fast is running
    Serial << "Fast is running" << endl;

    // Every task must contain an infinite loop, or things will crash.
    // Most tasks contain a vTaskDelay() or vTaskDelayUntil() call; 
    // otherwise they may read a queue and delay until the queue has
    // data in it.
    while (true)
    {
        digitalWrite(FAST_PIN,HIGH);
        vTaskDelay (1);
        digitalWrite(FAST_PIN,LOW);
        vTaskDelay (1);
    }
}


void setup () 
{
    // The serial port must begin before it may be used
    Serial.begin (115200);
    //GPIO Pin 12 set to output so we can send a signal
    pinMode(FAST_PIN,OUTPUT);
    //GPIO Pin 13 set to output so we can send a signal 
    pinMode(Button,INPUT_PULLUP); 
    while (!Serial) 
    {
    }
    //Sample string to show that out void setup works properly
    Serial << "Starting Tasks" << endl;

    // Create the task which produces the Fast 500Hz Square Wave
    xTaskCreate (task_Fast, "500Hz", 1024, NULL, 5, NULL);
    
    // Create the task with the button press
    xTaskCreate (task_Debounce, "100ms", 2048, NULL, 2, NULL);
}


/** @brief   The Arduino loop function.
 *  @details This function is called periodically by the Arduino system. It
 *           runs as a low priority task. On some microcontrollers it will
 *           crash when FreeRTOS is running, so we usually don't use this
 *           function for anything, instead just having it delay itself. 
 */
void loop (void)
{
    
    
    vTaskDelay (1000);
    // Delay for one second
    
}