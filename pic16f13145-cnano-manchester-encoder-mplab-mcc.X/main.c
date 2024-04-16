 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include <stdbool.h>

#define START_BYTE              0x0F    
#define STOP_BYTE               0xF0 

#define MANCHESTER_BAUD_RATE    625000

#define TIMER_PERIOD(x)         (uint8_t)((float)(_XTAL_FREQ / (8 * x)) - 1)

// define the period between auto-generated messages (BeaconMessage)
#define AUTOFRAME_PERIOD_MS(x)  (20 * x)

uint8_t BeaconMessage[] = "PIC16F13145 Manchester Encoder-Decoder\r\n";

uint8_t FrameBuffer[64];
uint8_t frameWrIndex;
bool newFrame;

void ResetFrame(void)
{
    frameWrIndex = 0;
    newFrame = false;
}

void ConfigureBitRate(uint32_t rate)
{
    TMR0_Stop();
    TMR0_Write(0x00);
    TMR0_Reload(TIMER_PERIOD(rate));
    TMR0_Start();
}

void ManchesterTransmit(uint8_t* buffer, uint8_t length)
{
    while (CLBCONbits.BUSY == 1); 
    CLBSWINM = START_BYTE;
    CLBSWINLbits.CLBSWIN1 = 0;    
    for (uint8_t i = 0; i < (length); i++)
    {
        while (PIR7bits.CLB1IF0 == 0);
        PIR7bits.CLB1IF0 = 0;
       
        while (CLBCONbits.BUSY == 1);
        CLBSWINM = buffer[i];
        CLBSWINLbits.CLBSWIN1 = 0;            
    }
    while (PIR7bits.CLB1IF0 == 0);
    PIR7bits.CLB1IF0 = 0;
    CLBSWINLbits.CLBSWIN1 = 1;
}



int main(void)
{
    static uint8_t oldByte;
    uint8_t receivedByte;
    uint16_t beaconCnt;
    
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    //INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 
    
    ConfigureBitRate(MANCHESTER_BAUD_RATE);
    CLBSWINLbits.CLBSWIN1 = 1;
    PIR7bits.CLB1IF0 = 0;
    
    while (1)
    {
        if(EUSART1_IsRxReady() == true)
        {   
            beaconCnt = 0x00;
            receivedByte = EUSART1_Read();
            if ((receivedByte == 0x0A) && ( oldByte == 0x0D))
            {
                newFrame = true;
            }
            FrameBuffer[frameWrIndex++] = receivedByte;
            oldByte = receivedByte;

            if (newFrame == true)
            {
                ManchesterTransmit(FrameBuffer, frameWrIndex);
                ResetFrame();
                LED0_Toggle();
            }
            if (frameWrIndex > 64) 
            {
                ResetFrame();
            }
        }

        __delay_us(50);
        beaconCnt++;
        if (beaconCnt >= AUTOFRAME_PERIOD_MS(500))
        {
            beaconCnt = 0x00;
            ManchesterTransmit(BeaconMessage, sizeof(BeaconMessage));
            LED0_Toggle();
        }        
    }    
}