#include QMK_KEYBOARD_H

//Create custom names for my two macro keys
enum custom_keycodes {
    MACRO_BLUESTACKS = SAFE_RANGE,
    MACRO_DISCORD
};

//Program exactly what those macros do when pressed
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MACRO_BLUESTACKS:
                // Opens Spotlight, waits 200ms, types the app name, hits Enter
                SEND_STRING(SS_LGUI(" ") SS_DELAY(200) "Bluestacks Air" SS_DELAY(200) SS_TAP(X_ENTER));
                return false;
            case MACRO_DISCORD:
                // Opens Spotlight, waits 200ms, types the app name, hits Enter
                SEND_STRING(SS_LGUI(" ") SS_DELAY(200) "Discord" SS_DELAY(200) SS_TAP(X_ENTER));
                return false;
        }
    }
    return true;
};

//Assign the macros and the Play/Pause key to my physical layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        MACRO_BLUESTACKS, MACRO_DISCORD, KC_MPLY
    )
};