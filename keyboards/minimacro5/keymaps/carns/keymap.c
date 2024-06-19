#include QMK_KEYBOARD_H

#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4
#define NUMBER_OF_ENCODERS 3

enum layers {
     _MAIN,
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder*/
    if (clockwise) {
      tap_code(KC_AUDIO_VOL_DOWN);
    } else {
      tap_code(KC_AUDIO_VOL_UP);
    }
  }
  else if (index == 1) { /* Second encoder*/
    if (clockwise) {
      tap_code(KC_MEDIA_PREV_TRACK);
    } else {
      tap_code(KC_MEDIA_NEXT_TRACK);
    }
  } else if (index == 2) { /* Third encoder*/
    if (clockwise) {
      tap_code(KC_F6);
    } else {
      tap_code(KC_F8);
    }
  }
  return false;
}

//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { //buttion closest to usb is first
  [_MAIN] = LAYOUT_ortho_1x5(
#if 1
     KC_AUDIO_MUTE, KC_MEDIA_PLAY_PAUSE, KC_F7, KC_F9, KC_F10
#else
     KC_AUDIO_MUTE, LCTL(KC_HOME), KC_F7, KC_F9, KC_F10
#endif
  )
};
