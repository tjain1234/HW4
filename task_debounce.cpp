/** @file task_debounce.cpp
 *  @brief Contains the calculations / logic for the four overloaded functions 
 *         with the data types of bool, uint8_t, int8_t, and float.
 *  @author Miles Ibarra
 *  @date   November_08_2022
 */
#include "task_debounce.h"
#include "Arduino.h"
#include "PrintStream.h"

#define Button 13
/** @brief   Contains the logic for the function to print an array that contains boolean values similar to how we print a list in python. 
 *  @details The array and size are passed into the function but setup as needed parameters in order to print the array.
 *           This array will show a T or F based on the passed in values for the array. 
 *  @param   p_array  A pointer placeholder for the array to be passed in
 *           size     Total number of elements in the array
 *           device   A reference to the device connected to our PC, 
 *                    This is used in correspondance with Serial for Arduino.  
 */
void task_Debounce (Print& device)
{
    uint8_t state = 0;
    Serial << "Debounce is running" << endl;
    while (true)
    {
        
        //Creates State 0 which waits for the button to be pressed to switch to the next state
        if (state==0) 
        {
            if (Button==HIGH) //If the button is pressed
            {
                state = 1;
            }
            else 
            { 
                state = 0;
            }
        }
        //Creates State 1 which will print ? 10 times per second for 5 second before the program activates
        else if (state==1)
        {
           while (Button==HIGH)
           {
                for(uint8_t i=0; i < 100 ; i++)
                {   
                    //This will allow the iteration of 10 times per second. 100ms delay.
                    //vTaskDelay(100);
                    device.print('?');
                    if (i >= 50)
                    {
                        state = 2;
                    }
                    else state = 1;
                }
           }
           if (Button==LOW)
           {
            state = 0;
           }
        }
        //Creates State 2 which will print @ 10 times per second once the program activates
        else if (state == 2)
        {
            //This will allow the iteration of 10 times per second. 100ms delay.
            //vTaskDelay(100);
            device.print('@');
            if (Button==HIGH)
            {
                state = 3;
            }
            else state =2; //try without this line
        }
        //Creates State 3 which will print ! 10 times per second for 1 second
        else if (state==3)
        {
           while (Button==HIGH)
           {
                for(uint8_t i=0; i < 50 ; i++)
                {   
                    //This will allow the iteration of 10 times per second. 100ms delay.
                    //vTaskDelay(100);
                    device.print('!');
                    if (i >= 10)
                    {
                        state = 0;
                    }
                    else state = 3;
                }
           }
           if (Button==LOW)
           {
            state = 2;
           }
        }
        vTaskDelay(100);    
    }
}