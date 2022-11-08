/** @file task_debounce.h
 *  @brief 
 *  @author Miles Ibarra
 *  @date   November_09_2022
 */
#include "Arduino.h"
#include "Wire.h"

/** @brief   Sets up function to print an array that contains boolean values similar to how we print a list in python. 
 *  @details The array and size are passed into the function but setup as needed parameters in order to print the array.
 *           This array will show a T or F based on the passed in values for the array. 
 *  @param   p_array  A pointer placeholder for the array to be passed in
 *           size     Total number of elements in the array
 *           device   A reference to the device connected to our PC, 
 *                    This is used in correspondance with Serial for Arduino.  
 */
void task_Debounce (Print& device = Serial);

/** @brief   Sets up function to print an array that contains boolean values similar to how we print a list in python. 
 *  @details The array and size are passed into the function but setup as needed parameters in order to print the array.
 *           This array will show a T or F based on the passed in values for the array. 
 *  @param   p_array  A pointer placeholder for the array to be passed in
 *           size     Total number of elements in the array
 *           device   A reference to the device connected to our PC, 
 *                    This is used in correspondance with Serial for Arduino.  
 */
void task_Fast (void* p_params);