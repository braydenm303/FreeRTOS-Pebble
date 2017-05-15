#pragma once
/* menu_layer.h
 */

#include "librebble.h"

#define MENU_CELL_BASIC_HEADER_HEIGHT ((const int16_t) 16)
#define MENU_INDEX_NOT_FOUND ((const uint16_t) ~0)
#define MENU_CELL_ROUND_FOCUSED_SHORT_CELL_HEIGHT ((const int16_t) 68)
#define MENU_CELL_ROUND_FOCUSED_TALL_CELL_HEIGHT ((const int16_t) 84)
#define MENU_CELL_ROUND_UNFOCUSED_SHORT_CELL_HEIGHT ((const int16_t) 24)
#define MENU_CELL_ROUND_UNFOCUSED_TALL_CELL_HEIGHT ((const int16_t) 24)

#define MenuIndex(section,row) (MenuIndex){.section = section, .row = row}

typedef struct MenuIndex
{
    uint16_t section;
    uint16_t row;
} MenuIndex;

typedef struct MenuCellSpan
{
    int16_t y;
    int16_t h;
    int16_t sep;
    MenuIndex index;
} MenuCellSpan;

typedef struct MenuLayer
{
    // TODO flesh out
} MenuLayer;

typedef uint16_t(* MenuLayerGetNumberOfSectionsCallback)(struct MenuLayer *menu_layer, void *callback_content);

typedef uint16_t(* MenuLayerGetNumberOfRowsInSectionsCallback)(struct MenuLayer *menu_layer, uint16_t section_index, void *callback_context);

typedef uint16_t(* MenuLayerGetCellHeightCallback)(struct MenuLayer *menu_layer, MenuIndex *cell_index, void *callback_context);

typedef int16_t(* MenuLayerGetHeaderHeightCallback)(struct MenuLayer *menu_layer, uint16_t section_index, void *callback_context);

typedef void(* MenuLayerDrawRowCallback)(GContext *ctx, const Layer *cell_layer, MenuIndex *cell_index, void *callback_context);

typedef void(* MenuLayerDrawHeaderCallback)(GContext *ctx, const Layer *cell_layer, uint16_t section_index, void *callback_context);

typedef void(* MenuLayerSelectCallback)(struct MenuLayer *menu_layer, MenuIndex *cell_index, void *callback_context);

typedef void(* MenuLayerSelectionChangedCallback)(struct MenuLayer *menu_layer, MenuIndex new_index, MenuIndex old_index, void *callback_context); // Was there a typo in the documentation? Those might need to be MenuIndex*

typedef int16_t(* MenuLayerGetSeparatorHeightCallback)(struct MenuLayer *menu_layer, MenuIndex *cell_index, void *callback_context);

typedef void(* MenuLayerDrawSeparatorCallback)(GContext *ctx, const Layer *cell_layer, MenuIndex *cell_index, void *callback_context);

typedef void(* MenuLayerSelectionWillChangeCallback)(struct MenuLayer *menu_layer, MenuIndex *new_index, MenuIndex old_index, void *callback_context); // Was there a typo in the documentation? That might need to be MenuIndex*

typedef void(* MenuLayerDrawBackgroundCallback)(GContext *ctx, const Layer *bg_layer, bool highlight, void *callback_context);

typedef struct MenuLayerCallbacks
{
    MenuLayerGetNumberOfSectionsCallback get_numb_sections;
    MenuLayerGetNumberOfRowsInSectionsCallback get_num_rows;
    MenuLayerGetCellHeightCallback get_cell_height;
    MenuLayerGetHeaderHeightCallback get_header_height;
    MenuLayerDrawRowCallback draw_row;
    MenuLayerDrawHeaderCallback draw_header;
    MenuLayerSelectCallback select_click;
    MenuLayerSelectCallback select_long_click;
    MenuLayerSelectionChangedCallback selection_changed;
    MenuLayerGetSeparatorHeightCallback get_separator_height;
    MenuLayerDrawSeparatorCallback draw_separator;
    MenuLayerSelectionWillChangeCallback selection_will_change;
    MenuLayerDrawBackgroundCallback draw_background;
} MenuLayerCallbacks;

typedef enum MenuRowAlign
{
    MenuRowAlignNone,
    MenuRowAlignCenter,
    MenuRowAlignTop,
    MenurowAlignBottom
} MenuRowAlign;

