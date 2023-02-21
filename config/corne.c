/*
 * Copyright (c) 2020 duckyb
 *
 * SPDX-License-Identifier: MIT
 */

#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/outputs.h>
#include "keymap_italian.h"

// Layer definitions
    #define BASE 0
    #define SYM 1
    #define EXT 2
    #define FNC 3
    #define SYM2 4
    #define ACCENT 5
	#define SETTINGS 6
// -----------------#include <behaviors

&sk {
    ignore-modifiers;
};

/ {
	macros {
		// sometimes my device thinks a modifier is being held down
		// pressing all modifiers fixes it.
		unstick: unstick {
			label = "ZM_unstick";
			compatible = "zmk,behavior-macro";
			#binding-cells = <0>;
			bindings = <&kp LSHIFT &kp RSHIFT &kp LCTRL &kp RCTRL &kp LALT &kp RALT &kp LGUI &kp RGUI>;
		};
	};

    combos {
		compatible = "zmk,combos";
		// both right thumb keys
        combo_accent {
			timeout-ms = <200>;
			key-positions = <32 33>;
			bindings = <&mo ACCENT>;
        };
		// internal-left & external-right thumb keys
		combo_sym2 {
			timeout-ms = <200>;
			key-positions = <31 33>;
			bindings = <&mo SYM2>;
		};
		// both left thumb keys
		combo_settings {
			timeout-ms = <200>;
			key-positions = <30 31>;
			bindings = <&mo SETTINGS>;
		};
    };

    keymap {
		compatible = "zmk,keymap";

        // Base alpha layer
		default_layer {
			label = "Base";
			bindings = <
			&kp Q &kp W &kp E &kp R &kp T           &kp Y &kp U  &kp I     &kp O   &kp P 
			&kp A &kp S &kp D &kp F &kp G           &kp H &kp J  &kp K     &kp L &kp IT_OGRV
			&kp Z &kp X &kp C &kp V &kp B           &kp N &kp M  &kp COMMA &kp DOT &kp IT_UGRV
							&mo EXT &mt LSHIFT SPACE           &kp SPACE &sl SYM
			>;
		};

        // Numbers and high frequency symbols
		sym_layer {
			label = "Sym.";
			bindings = <
			&kp N1 &kp N2 &kp N3 &kp N4 &kp N5		                                    &kp N6 &kp N7 &kp N8 &kp N9 &kp N0
			&kp IT_LESS &kp IT_USD &kp IT_LPAR &kp IT_LBRC &kp IT_LBKT  &kp IT_EQL &kp IT_QUES &kp IT_SQUOT &kp IT_MINUS &kp IT_AST
			&kp IT_GREAT &kp IT_PERC &kp IT_RPAR &kp IT_RBRC &kp IT_RBKT 	&kp IT_AT &kp IT_EXCL &kp IT_DQUOT &kp IT_PLUS &kp IT_FSLH
														&mo FNC  &mo SYM2       &trans &trans
			>;
		};

        // Main modifiers and arrow keys
		ext_layer {
			label = "Mods";
			bindings = <
			&kp ESC  &kp C_PREV &kp C_PP  &kp C_NEXT  &kp C_PAUSE    	&kp PG_UP  &kp HOME &kp UP &kp END &kp CAPS
			&sk LALT &sk LGUI  &sk LSHIFT  &sk LCTRL  &kp RALT 			&kp PG_DN &kp LEFT  &kp DOWN  &kp RIGHT   &kp DEL
			&kp LC(Z)  &kp LC(X) &kp LC(C) &kp TAB   &kp LC(V)          &kp LC(BSPC) &kp BSPC &trans &trans  &trans
																		&trans &kp LCTRL    &kp ENTER  &mo FNC 
			>;
		};

        // Function keys with modifiers
		fnc_layer {
			label = "FRow";
			bindings = <
			&kp F1 &kp F2 &kp F3 &kp F4 &kp F5                  &kp F6 &kp F7 &kp F8 &kp F9 &kp F10 
			&sk LALT &sk LGUI &sk LSHIFT &sk LCTRL &kp RALT     &kp F11 &kp F12  &kp PRINTSCREEN &trans &trans
			&none &none &none &none &none				          &none &none &none &none &none 
							  &none &none              &none &none  
			>;
		};

        // Low frequency symbols.
		symbols_2_layer {
			label = "Sym.2";
			bindings = <
			&kp IT_CARET &kp IT_UNDER &kp IT_PND &kp IT_EUR &kp IT_HASH         &none &none &none &none &none 
			&kp IT_BKTK &kp IT_TILDE &kp IT_BSLH &kp IT_PIPE &kp IT_AND         &none &none &none &none &none
			&none 			&none 			 &kp IT_SECT &kp IT_CCED &kp IT_DEG				  &none &none &none &none &none
																	&none &none        	&none &none 
			>;
		};

        // Used to type regional accents.
		accent_layer {
			label = "Accent";
			bindings = <
			&none &none &none &kp IT_CEGR &none                         &none &none &none &none &none 
			&kp IT_AGRV &kp IT_IGRV &kp IT_OGRV &kp IT_EGRV &kp IT_EACU &none &none &none &none &none
			&none &none &none &kp IT_UGRV &none                         &none &none &none &none &none
									&none &none                         &none &none 
			>;
		};

        // Used to change the keyboard's settings.
		settings_layer {
				label = "Sett.";
				bindings = <
				&bootloader &none &none &bt BT_CLR &bt BT_SEL 0               &bt BT_SEL 3 &none &unstick &none &bootloader 
				&none &none &none &none      &bt BT_SEL 1 						  &bt BT_SEL 4 &none &none &none &none
				&none &none &none &none      &bt BT_SEL 2               &bt BT_SEL 5 &none &none &none &none
										&none &none                         &none &none 
				>;
		};
	};
};