#include "quantum.h"

enum custom_keycodes {
    MACRO_DISCORD = SAFE_RANGE,
    MACRO_BLUESTACKS,
    MACRO_MC_JAVA
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MACRO_DISCORD:
                SEND_STRING(SS_LGUI(" ") SS_DELAY(200) "Discord" SS_DELAY(200) SS_TAP(X_ENTER));
                return false;
            case MACRO_BLUESTACKS:
                SEND_STRING(SS_LGUI(" ") SS_DELAY(200) "Bluestacks Air" SS_DELAY(200) SS_TAP(X_ENTER));
                return false;
            case MACRO_MC_JAVA:
                SEND_STRING(SS_LGUI(" ") SS_DELAY(200) "Minecraft" SS_DELAY(200) SS_TAP(X_ENTER));
                return false;
        }
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        MACRO_DISCORD,   MACRO_BLUESTACKS, KC_NO,
        MACRO_MC_JAVA,   KC_NO,            KC_NO,
        KC_NO,           KC_NO,            KC_NO
    )
};