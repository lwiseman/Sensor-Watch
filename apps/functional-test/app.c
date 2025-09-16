#include <stdio.h>
#include <string.h>
#include <math.h>
#include "watch.h"

void app_init(void) {
}

void app_wake_from_backup(void) {
}

void app_setup(void) {
    gpio_set_pin_function(GPIO(GPIO_PORTA, 6), GPIO_PIN_FUNCTION_B);
    gpio_set_pin_function(GPIO(GPIO_PORTA, 7), GPIO_PIN_FUNCTION_B);
    gpio_set_pin_function(GPIO(GPIO_PORTC, 5), GPIO_PIN_FUNCTION_B);
    gpio_set_pin_function(GPIO(GPIO_PORTC, 6), GPIO_PIN_FUNCTION_B);
    gpio_set_pin_function(GPIO(GPIO_PORTC, 7), GPIO_PIN_FUNCTION_B);
    gpio_set_pin_function(GPIO(GPIO_PORTA, 8), GPIO_PIN_FUNCTION_B);
    gpio_set_pin_function(GPIO(GPIO_PORTA, 9), GPIO_PIN_FUNCTION_B);
    gpio_set_pin_function(GPIO(GPIO_PORTA, 10), GPIO_PIN_FUNCTION_B);
    gpio_set_pin_function(GPIO(GPIO_PORTA, 11), GPIO_PIN_FUNCTION_B); // SEG0
    gpio_set_pin_function(GPIO(GPIO_PORTC, 8), GPIO_PIN_FUNCTION_B); // SEG1
    gpio_set_pin_function(GPIO(GPIO_PORTC, 9), GPIO_PIN_FUNCTION_B); // SEG2
    gpio_set_pin_function(GPIO(GPIO_PORTC, 10), GPIO_PIN_FUNCTION_B); // SEG3
    gpio_set_pin_function(GPIO(GPIO_PORTC, 11), GPIO_PIN_FUNCTION_B); // SEG4
    gpio_set_pin_function(GPIO(GPIO_PORTC, 12), GPIO_PIN_FUNCTION_B); // SEG5
    gpio_set_pin_function(GPIO(GPIO_PORTC, 13), GPIO_PIN_FUNCTION_B); // SEG6
    gpio_set_pin_function(GPIO(GPIO_PORTB, 11), GPIO_PIN_FUNCTION_B); // SEG7
    gpio_set_pin_function(GPIO(GPIO_PORTB, 12), GPIO_PIN_FUNCTION_B); // SEG8
    gpio_set_pin_function(GPIO(GPIO_PORTB, 13), GPIO_PIN_FUNCTION_B); // SEG9
    gpio_set_pin_function(GPIO(GPIO_PORTB, 14), GPIO_PIN_FUNCTION_B); // SEG10
    gpio_set_pin_function(GPIO(GPIO_PORTB, 15), GPIO_PIN_FUNCTION_B); // SEG11
    gpio_set_pin_function(GPIO(GPIO_PORTC, 14), GPIO_PIN_FUNCTION_B); // SEG12
    gpio_set_pin_function(GPIO(GPIO_PORTC, 15), GPIO_PIN_FUNCTION_B); // SEG13
    gpio_set_pin_function(GPIO(GPIO_PORTA, 14), GPIO_PIN_FUNCTION_B); // SEG14
    gpio_set_pin_function(GPIO(GPIO_PORTA, 15), GPIO_PIN_FUNCTION_B); // SEG15
                                                                      //
    gpio_set_pin_function(GPIO(GPIO_PORTC, 16), GPIO_PIN_FUNCTION_B); // SEG16
    gpio_set_pin_function(GPIO(GPIO_PORTC, 17), GPIO_PIN_FUNCTION_B); // SEG17
    gpio_set_pin_function(GPIO(GPIO_PORTC, 18), GPIO_PIN_FUNCTION_B); // SEG18
    gpio_set_pin_function(GPIO(GPIO_PORTC, 19), GPIO_PIN_FUNCTION_B); // SEG19
    gpio_set_pin_function(GPIO(GPIO_PORTC, 20), GPIO_PIN_FUNCTION_B); // SEG20
    gpio_set_pin_function(GPIO(GPIO_PORTC, 21), GPIO_PIN_FUNCTION_B); // SEG21
    gpio_set_pin_function(GPIO(GPIO_PORTB, 16), GPIO_PIN_FUNCTION_B); // SEG22
    gpio_set_pin_function(GPIO(GPIO_PORTB, 17), GPIO_PIN_FUNCTION_B); // SEG23

    watch_enable_display();

    /*
    watch_enable_digital_output(RED);
    watch_enable_digital_output(GREEN);
    watch_enable_digital_input(BTN_LIGHT);
    watch_enable_pull_up(BTN_LIGHT);
    */
    watch_enable_digital_output(RED);
    watch_enable_digital_output(GREEN);
    watch_enable_digital_input(BTN_ALARM);
    watch_enable_digital_input(BTN_LIGHT);
    watch_enable_digital_input(BTN_MODE);
    watch_enable_pull_down(BTN_ALARM);
    watch_enable_pull_down(BTN_LIGHT);
    watch_enable_pull_down(BTN_MODE);

    gpio_set_pin_direction(GPIO(GPIO_PORTA, 30), GPIO_DIRECTION_OUT);
    //gpio_set_pin_level(GPIO(GPIO_PORTA, 30), 1);
    PORT->Group[0].PINCFG[30].bit.PMUXEN = 1;
    PORT->Group[0].PMUX[30 / 2].reg |= PORT_PMUX_PMUXE_H;
    GCLK->GENCTRL[0].bit.OE = 1;
    //GCLK->GENCTRL[0].bit.OOV = 0;
    while (GCLK->SYNCBUSY.reg)
        ;

    watch_enable_leds();

    watch_set_pixel(0, 1);
    watch_set_pixel(1, 1);
    watch_set_pixel(2, 1);
    watch_set_pixel(3, 1);
    watch_set_pixel(4, 1);
    watch_set_pixel(5, 1);
    watch_set_pixel(6, 1);

    watch_set_pixel(0, 4);
    watch_set_pixel(1, 4);
    watch_set_pixel(2, 4);
    watch_set_pixel(3, 4);
    watch_set_pixel(4, 4);
    watch_set_pixel(5, 4);
    watch_set_pixel(6, 4);

    watch_set_pixel(7, 4);

    watch_set_pixel(0, 5);
    watch_set_pixel(1, 5);
    watch_set_pixel(2, 5);
    watch_set_pixel(3, 5);
    watch_set_pixel(4, 5);
    watch_set_pixel(5, 5);
    watch_set_pixel(6, 5);

    watch_set_pixel(0, 6);
    watch_set_pixel(1, 6);
    watch_set_pixel(2, 6);
    watch_set_pixel(3, 6);
    watch_set_pixel(4, 6);
    watch_set_pixel(5, 6);
    watch_set_pixel(6, 6);

    watch_set_pixel(7, 6);

    watch_set_pixel(0, 7);
    watch_set_pixel(1, 7);
    watch_set_pixel(2, 7);
    watch_set_pixel(3, 7);
    watch_set_pixel(4, 7);
    watch_set_pixel(5, 7);
    watch_set_pixel(6, 7);

    watch_set_pixel(5, 8);
    watch_set_pixel(4, 8);
    watch_set_pixel(4, 9);
    watch_set_pixel(3, 9);

    watch_set_pixel(5, 10);
    watch_set_pixel(4, 10);
    watch_set_pixel(4, 11);
    watch_set_pixel(3, 11);

    watch_set_pixel(5, 12);
    watch_set_pixel(4, 12);
    watch_set_pixel(4, 13);
    watch_set_pixel(3, 13);

    watch_set_pixel(5, 14);
    watch_set_pixel(4, 14);
    watch_set_pixel(4, 15);
    watch_set_pixel(3, 15);

    watch_set_pixel(5, 16);
    watch_set_pixel(4, 16);
    watch_set_pixel(4, 17);
    watch_set_pixel(3, 17);

    watch_set_pixel(0, 16);
    watch_set_pixel(0, 18);

    watch_set_pixel(5, 18);
    watch_set_pixel(4, 18);
    watch_set_pixel(4, 19);
    watch_set_pixel(3, 19);

    watch_set_pixel(5, 20);
    watch_set_pixel(4, 20);
    watch_set_pixel(4, 21);
    watch_set_pixel(3, 21);

    watch_set_pixel(5, 22);
    watch_set_pixel(4, 22);
    watch_set_pixel(4, 23);
    watch_set_pixel(3, 23);

    gpio_set_pin_function(GPIO(GPIO_PORTC, 27), GPIO_PIN_FUNCTION_OFF);
    gpio_set_pin_direction(GPIO(GPIO_PORTC, 27), GPIO_DIRECTION_OUT);
    gpio_set_pin_level(GPIO(GPIO_PORTC, 27), true);
    /*
    watch_enable_display();

    watch_enable_buzzer();

    watch_enable_digital_output(RED);
    watch_enable_digital_output(GREEN);
    watch_enable_digital_input(BTN_ALARM);
    watch_enable_digital_input(BTN_LIGHT);
    watch_enable_digital_input(BTN_MODE);
    watch_enable_pull_down(BTN_ALARM);
    watch_enable_pull_up(BTN_LIGHT);
    watch_enable_pull_down(BTN_MODE);
    */
}

void app_prepare_for_standby(void) {
}

void app_wake_from_standby(void) {
}

bool app_loop(void) {
    static int8_t loop = 0;
    /*
    watch_set_led_color(0, 0);
    delay_ms(5000);
    watch_set_led_color(255, 255);
    delay_ms(4000);
    */
    /*
    static uint8_t level = 0;
    if (!(watch_get_pin_level(BTN_ALARM)
       && watch_get_pin_level(BTN_LIGHT)
       && watch_get_pin_level(BTN_MODE))) {
        //watch_set_pin_level(RED, false);
        //watch_set_pin_level(GREEN, false);
        watch_set_led_color(0, 0);
    } else {
        //watch_set_pin_level(RED, true);
        //watch_set_pin_level(GREEN, true);
        watch_set_led_color(255, 255);
    }
    */
    /*
    if (!(watch_get_pin_level(BTN_ALARM) && watch_get_pin_level(BTN_LIGHT))) {
        watch_set_led_color(255, 255);
    } else {
        watch_set_led_off();
    }
    */
    /*
    if (!watch_get_pin_level(BTN_LIGHT)) {
        watch_set_pin_level(RED, false);
    }
    */
    static int last_button = 0;
    static int button = 0;
    static uint8_t level = 0;
    static int per_i = 0;
    static uint32_t pers[] = { 1024 - 1, 32768 - 1 };
    //int per_n = sizeof(pers) / sizeof(*pers);
    int per_n = 2;

    if (watch_get_pin_level(BTN_ALARM)) {
        button = 1;
    } else if (watch_get_pin_level(BTN_LIGHT)) {
        button = 2;
    } else if (watch_get_pin_level(BTN_MODE)) {
        button = 3;
    }

    if (button != last_button) {
        last_button = button;
        //level = (level + 1) % 10;
        //level = (level + 32) % 256;
        //watch_set_led_color(level, level);
        uint32_t period = hri_tcc_get_PER_reg(TCC0, TCC_PER_MASK);
        level = (level + 1) % (int)log2(period);
        hri_tcc_write_CCBUF_reg(TCC0, WATCH_RED_TCC_CHANNEL, pow(2, level));
        hri_tcc_write_CCBUF_reg(TCC0, WATCH_GREEN_TCC_CHANNEL, pow(2, level));

        /*
        per_i = (per_i + 1) % per_n;
        hri_tcc_write_PER_reg(TCC0, pers[per_i]);
        hri_tcc_write_CCBUF_reg(TCC0, WATCH_RED_TCC_CHANNEL, pers[per_i] / 2);
        hri_tcc_wait_for_sync(TCC0, TCC_SYNCBUSY_ENABLE);
        */

        //watch_buzzer_play_note(BUZZER_NOTE_C8, 100);
    }

    /*
    static const bool segmap[3][24] = {
       //0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1}
    };

    for(int com = 0; com < 3; com++) {
        for(int seg = 0; seg < 24; seg++) {
            if (segmap[com][seg]) (loop >= 0) ? watch_set_pixel(com, seg) : watch_clear_pixel(com, seg);
            else (loop < 0) ? watch_set_pixel(com, seg) : watch_clear_pixel(com, seg);
        }
    }

    loop++;
    */

    return false;
}
