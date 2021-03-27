#ifndef MAX7219_H
#define MAX7219_H

#include <stdint.h>

/*enums and defines*/

/// Used with set_mode to turn set the chip
/// in shutdown or normal operation
enum max7219_modes
{
    SHUTDOWN = 0,
    NORMAL   = 1,
};

/// Used with set_digit to specify
/// which digit to update
enum max7219_digits
{
    DIGIT_0 = 0,
    DIGIT_1 = 1,
    DIGIT_2 = 2,
    DIGIT_3 = 3,
    DIGIT_4 = 4,
    DIGIT_5 = 5,
    DIGIT_6 = 6,
    DIGIT_7 = 7,
};

/// Used with set_intensity to specify
/// how bright to make the led's
enum max7219_intensity
{
    INTENSITY_0  = 0,  // 1/32 (min on)
    INTENSITY_1  = 1,  // 3/32
    INTENSITY_2  = 2,  // 5/32
    INTENSITY_3  = 3,  // 7/32
    INTENSITY_4  = 4,  // 9/32
    INTENSITY_5  = 5,  // 11/32
    INTENSITY_6  = 6,  // 13/32
    INTENSITY_7  = 7,  // 15/32
    INTENSITY_8  = 8,  // 17/32
    INTENSITY_9  = 9,  // 19/32
    INTENSITY_10 = 10, // 21/32
    INTENSITY_11 = 11, // 23/32
    INTENSITY_12 = 12, // 25/32
    INTENSITY_13 = 13, // 27/32
    INTENSITY_14 = 14, // 29/32
    INTENSITY_15 = 15, // 31/32 (max on)
};

/// Used with set_scan_limit
/// to specify how many digits
/// are to be used
enum max7219_scan_limit
{   
    SCAN_1 = 0, //scan digit 0 only
    SCAN_2 = 1, //scan digits 0-1 only
    SCAN_3 = 2, //scan digits 0-2 only
    SCAN_4 = 3, //scan digits 0-3 only
    SCAN_5 = 4, //scan digits 0-4 only
    SCAN_6 = 5, //scan digits 0-5 only
    SCAN_7 = 6, //scan digits 0-6 only
    SCAN_8 = 7, //scan all digits

};

/// Used with set_display_test
/// to specify normal operations
/// or test mode
enum max7219_display_test
{
    NORMAL = 0,
    TEST   = 1, 
};


/// Used with set_decode_mode to
/// set determine which digits use BCD
/// decoding, or no decoding at all
#define MAX7219_DECODE_NONE 0x00
#define MAX7219_DECODE_ALL  0xFF
#define MAX7219_DECODE_DIGIT_0 0x01
#define MAX7219_DECODE_DIGIT_1 0x02
#define MAX7219_DECODE_DIGIT_2 0x04
#define MAX7219_DECODE_DIGIT_3 0x08
#define MAX7219_DECODE_DIGIT_4 0x10
#define MAX7219_DECODE_DIGIT_5 0x20
#define MAX7219_DECODE_DIGIT_6 0x40
#define MAX7219_DECODE_DIGIT_7 0x80

/// Used with set_digit_bcd
/// when the using decode mode
/// There are some special BCD codes
#define MAX7219_DECODE_BCD_DASH  0x0A
#define MAX7219_DECODE_BCD_E     0x0B
#define MAX7219_DECODE_BCD_H     0x0C
#define MAX7219_DECODE_BCD_L     0x0D
#define MAX7219_DECODE_BCD_P     0x0E
#define MAX7219_DECODE_BLANK 0x0F

/// Register address map in chip
#define ADDR_NO_OP        0x00
#define ADDR_DIG_0        0x01
#define ADDR_DIG_1        0x02
#define ADDR_DIG_2        0x03
#define ADDR_DIG_3        0x04
#define ADDR_DIG_4        0x05
#define ADDR_DIG_5        0x06
#define ADDR_DIG_6        0x07
#define ADDR_DIG_7        0x08
#define ADDR_DECODE_MODE  0x09
#define ADDR_INTENSITY    0x0A
#define ADDR_SCAN_LIMIT   0x0B
#define ADDR_MODE         0x0C
#define ADDR_DISPLAY_TEST 0x0F


void init(void(*f_write)(int,int),
          void(*f_delay_us)(int),
          uint8_t const data_out,
          uint8_t const clk, 
          uint8_t const load);
void set_digit_bcd(enum max7219_digits const digit, uint8_t const bcd);
void clear_all(void);
void clear_digit(enum max7219_digits const digit);
void set_decode_mode(uint8_t mode);
void set_intensity(enum max7219_intensity intensity);
void set_scan_limit(max7219_scan_limit const scan_limit);
void set_mode(enum max7219_modes const mode);
void set_display_test(enum max7219_display_test const mode);
void write(uint8_t const addr, uint8_t const data);

#endif //MAX7219__H