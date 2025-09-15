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
    gpio_set_pin_function(GPIO(GPIO_PORTC, 8), GPIO_PIN_FUNCTION_B); // SEG1
    gpio_set_pin_function(GPIO(GPIO_PORTC, 11), GPIO_PIN_FUNCTION_B); // SEG4
    gpio_set_pin_function(GPIO(GPIO_PORTC, 12), GPIO_PIN_FUNCTION_B); // SEG5
    gpio_set_pin_function(GPIO(GPIO_PORTC, 13), GPIO_PIN_FUNCTION_B); // SEG6
    gpio_set_pin_function(GPIO(GPIO_PORTB, 11), GPIO_PIN_FUNCTION_B); // SEG7
    gpio_set_pin_function(GPIO(GPIO_PORTC, 16), GPIO_PIN_FUNCTION_B); // SEG16
    gpio_set_pin_function(GPIO(GPIO_PORTC, 18), GPIO_PIN_FUNCTION_B); // SEG18

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

    watch_set_pixel(0, 0);
    watch_set_pixel(1, 0);
    watch_set_pixel(2, 0);
    watch_set_pixel(3, 0);
    watch_set_pixel(4, 0);
    watch_set_pixel(5, 0);
    watch_set_pixel(6, 0);

    watch_set_pixel(0, 1);
    watch_set_pixel(1, 1);
    watch_set_pixel(2, 1);
    watch_set_pixel(3, 1);
    watch_set_pixel(4, 1);
    watch_set_pixel(5, 1);
    watch_set_pixel(6, 1);

    watch_set_pixel(0, 2);
    watch_set_pixel(1, 2);
    watch_set_pixel(2, 2);
    watch_set_pixel(3, 2);
    watch_set_pixel(4, 2);
    watch_set_pixel(5, 2);
    watch_set_pixel(6, 2);

    watch_set_pixel(0, 3);
    watch_set_pixel(1, 3);
    watch_set_pixel(2, 3);
    watch_set_pixel(3, 3);
    watch_set_pixel(4, 3);
    watch_set_pixel(5, 3);
    watch_set_pixel(6, 3);

    watch_set_pixel(0, 4);
    watch_set_pixel(1, 4);
    watch_set_pixel(2, 4);
    watch_set_pixel(3, 4);
    watch_set_pixel(4, 4);
    watch_set_pixel(5, 4);
    watch_set_pixel(6, 4);

    watch_set_pixel(0, 5);
    watch_set_pixel(0, 6);

    gpio_set_pin_direction(GPIO(GPIO_PORTC, 1), GPIO_DIRECTION_IN);
    gpio_set_pin_function(GPIO(GPIO_PORTC, 1), GPIO_PIN_FUNCTION_B);
    gpio_set_pin_level(GPIO(GPIO_PORTC, 1), true);
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
