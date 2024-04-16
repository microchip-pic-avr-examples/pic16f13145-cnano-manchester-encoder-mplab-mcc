/**
 *  @file clbBitsream.s
 *
 *  @brief CLB bitstream data for the PIC16F13145 device family
 *
 **/
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

/*
    The bitstream data can be accesed from C source code by referencing the 'start_clb_config' symbol as such:

    extern uint16_t start_clb_config;
    uint16_t clbStartAddress = (uint16_t) &start_clb_config;

    IMPORTANT: You must always use the address of these symbols and not the value of the symbols themselves.
               If values instead of addresses are used, the linker will silently generate incorrect code.

    uint16_t clbStartAddress = start_clb_config; // This is incorrect!

    NOTE: This module requires C preprocessing.
          This can be enabled via the command line option: -xassembler-with-cpp
*/


#if !( defined(_16F13113) || defined(_16F13114) || defined(_16F13115) || \
       defined(_16F13123) || defined(_16F13124) || defined(_16F13125) || \
       defined(_16F13143) || defined(_16F13144) || defined(_16F13145) )

    #error This assembly file is intended to be used only with the PIC16F13145 device family!

#endif

GLOBAL  _start_clb_config
GLOBAL  _end_clb_config

PSECT  clb_config,global,class=STRCODE,delta=2,noexec,split=0,merge=0,keep

_start_clb_config:
    DW  0x28D4
    DW  0x0140
    DW  0x140F
    DW  0x046F
    DW  0x16AF
    DW  0x0B42
    DW  0x31D4
    DW  0x0380
    DW  0x0000
    DW  0x0000
    DW  0x000C
    DW  0x1B44
    DW  0x30FC
    DW  0x06F5
    DW  0x3E2F
    DW  0x1140
    DW  0x3018
    DW  0x1580
    DW  0x1800
    DW  0x0000
    DW  0x3C0F
    DW  0x294C
    DW  0x2814
    DW  0x0140
    DW  0x1CEE
    DW  0x1DE5
    DW  0x155F
    DW  0x29B5
    DW  0x2C49
    DW  0x0400
    DW  0x3C00
    DW  0x05E0
    DW  0x2894
    DW  0x0140
    DW  0x1400
    DW  0x0800
    DW  0x1405
    DW  0x0C00
    DW  0x0000
    DW  0x0000
    DW  0x001E
    DW  0x3183
    DW  0x3860
    DW  0x01E0
    DW  0x02A0
    DW  0x07E4
    DW  0x2814
    DW  0x13E1
    DW  0x3019
    DW  0x0980
    DW  0x180C
    DW  0x0187
    DW  0x300C
    DW  0x0148
    DW  0x1414
    DW  0x12A0
    DW  0x001E
    DW  0x3585
    DW  0x386C
    DW  0x0182
    DW  0x300C
    DW  0x0147
    DW  0x2814
    DW  0x0140
    DW  0x3019
    DW  0x0180
    DW  0x1800
    DW  0x0201
    DW  0x00C8
    DW  0x0980
    DW  0x3278
    DW  0x0180
    DW  0x151E
    DW  0x00A4
    DW  0x1E0A
    DW  0x0B40
    DW  0x280A
    DW  0x0180
    DW  0x3298
    DW  0x0180
    DW  0x001E
    DW  0x0000
    DW  0x1E00
    DW  0x0000
    DW  0x0000
    DW  0x018B
    DW  0x03E1
    DW  0x3C1F
    DW  0x03E1
    DW  0x3C1F
    DW  0x01F0
    DW  0x3E1F
    DW  0x03E0
    DW  0x3E1F
    DW  0x03E1
    DW  0x3C1F
    DW  0x0C00
    DW  0x0C00
    DW  0x000A
    DW  0x2318
    DW  0x06E8
    DW  0x3601
_end_clb_config:
