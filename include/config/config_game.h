#pragma once

/*****************
 * GAME SETTINGS *
 *****************/

 /**
 * START_MAP lets the user set the map entered when starting a new save. Entry 0 is used
 * unless START_ENTRY is uncommented.
 */
// #define START_MAP   MAP_8C_SM_BANJOS_HOUSE
// #define START_ENTRY WARP_SM_BANJOS_HOUSE_1_ENTRANCE

/**
 * Use the OPA model's cube bounds instead of Rare's hardcoded cube bound offsets.
 * Enabled by default for custom level replacements. Breaks certain Vanilla levels.
 */
#define USE_OPA_CUBE_BOUNDS

/**
 * Unlocks all abilities for Banjo.
 */
#define START_WITH_ALL_MOVES
