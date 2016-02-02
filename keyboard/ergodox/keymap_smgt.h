static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    KEYMAP(  // layer 0 : default
        // left hand
        EQL,  1,   2,   3,   4,   5,   ESC,
        TAB,  Q,   W,   E,   R,   T,   FN1,
        LCTL, A,   S,   D,   F,   G,
        LSFT, Z,   X,   C,   V,   B,   BSLS,
        NO,GRV,NO,LGUI,LALT,
                                      LCTL,LALT,
                                           BSLS,
                                 BSPC,LGUI, LALT,
        // right hand
             FN3, 6,   7,   8,   9,   0,   MINS,
             LBRC,Y,   U,   I,   O,   P,   RBRC,
                  H,   J,   K,   L,   SCLN,QUOT,
             FN1, N,   M,   COMM,DOT, SLSH,RSFT,
                       LEFT,DOWN,UP,  RGHT,RGUI,
        RALT,RCTL,
        NO,
        FN2,ENT, SPC
    ),

    KEYMAP(  // layer 1 : function and symbol keys
        // left hand
        TRNS,F1,  F2,  F3,  F4,  F5,  F11,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN1,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F12, F6,  F7,  F8,  F9,  F10, TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,F15, VOLU,
                  TRNS,TRNS,TRNS,TRNS,F14, VOLD,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,MPLY,
                       MPRV,TRNS,TRNS,MNXT,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // layer 2 : keyboard functions
        // left hand
        TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             FN4, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             RBRC,TRNS,TRNS,TRNS,TRNS,TRNS,LBRC,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        FN0,TRNS,
        TRNS,
        FN2,TRNS,TRNS
    ),

    KEYMAP(  // layer 3: numpad
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,NLCK,PSLS,PAST,PAST,PMNS,BSPC,
             TRNS,NO,  P7,  P8,  P9,  PMNS,BSPC,
                  NO,  P4,  P5,  P6,  PPLS,PENT,
             TRNS,NO,  P1,  P2,  P3,  PPLS,PENT,
                       P0,  PDOT,SLSH,PENT,PENT,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY
};

enum macro_id {
    SV_KEY_AO,
    SV_KEY_AE,
    SV_KEY_OE,
    CHANGE_LAYOUT
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    ACTION_FUNCTION(TEENSY_KEY),                    // FN0 - Teensy key
    ACTION_LAYER_MOMENTARY(1),                      // FN1 - switch to Layer1
    //ACTION_LAYER_TOGGLE(2),                  // FN2 - set Layer2
    ACTION_MACRO(CHANGE_LAYOUT),               // FN2 - change keyboard layout on the computer
    ACTION_LAYER_TOGGLE(3),                         // FN3 - toggle Layer3 aka Numpad layer
    ACTION_LAYER_SET(0, ON_PRESS),                  // FN4 - set Layer0
    ACTION_MACRO(SV_KEY_AE), //FN5
    ACTION_MACRO(SV_KEY_AO), //FN6
    ACTION_MACRO(SV_KEY_OE), //FN7
};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    print("action_function called\n");
    print("id  = "); phex(id); print("\n");
    print("opt = "); phex(opt); print("\n");

    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    } else if(id == SV_KEY_AO) {
      print("å");
      //ACTION_MODS_KEY(MOD_LALT, KC_A);
    }

}

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case SV_KEY_AO:
            return (record->event.pressed ?
                    MACRO( D(LALT), D(A), W(255), U(LALT), U(A), END ) :
                    MACRO_NONE );
        case SV_KEY_AE:
            return (record->event.pressed ?
                    MACRO( D(LALT), D(U), U(LALT), U(U), T(A), END ) :
                    MACRO_NONE );
        case SV_KEY_OE:
            return (record->event.pressed ?
                    MACRO( D(LALT), D(TAB), END ) :
                    MACRO( U(TAB), END ));
        case CHANGE_LAYOUT:
            if( record->event.pressed ) {
              //default_layer_state_set(2);
              //layer_state = (1<<2);
              return MACRO( D(LALT), D(LGUI), D(LCTL), D(SPC), W(255), U(LALT), U(LGUI), U(LCTL), U(SPC), END );

            } else {
              return MACRO_NONE;
            }

    }
    return MACRO_NONE;
}


#define KEYMAPS_SIZE    (sizeof(keymaps) / sizeof(keymaps[0]))
#define FN_ACTIONS_SIZE (sizeof(fn_actions) / sizeof(fn_actions[0]))

uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key)
{
    print("layer  = "); phex(layer); print("\n");

    if (layer < KEYMAPS_SIZE) {
        print("key = "); phex(&keymaps[(layer)][(key.row)][(key.col)]); print("\n");
        return pgm_read_byte(&keymaps[(layer)][(key.row)][(key.col)]);
    } else {
        // fall back to layer 0
        print("key = "); phex(&keymaps[0][(key.row)][(key.col)]); print("\n");
        return pgm_read_byte(&keymaps[0][(key.row)][(key.col)]);
    }
}
