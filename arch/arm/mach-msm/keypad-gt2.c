/*
 * Copyright (C) 2007 Google, Inc.
 * Copyright (c) 2008-2009, Code Aurora Forum. All rights reserved.
 * Author: Brian Swetland <swetland@google.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/platform_device.h>
#include <linux/gpio_event.h>

#include <asm/mach-types.h>

/* don't turn this on without updating the ffa support */
#define SCAN_FUNCTION_KEYS 0



#if defined(CONFIG_MACH_CALLISTO)  || defined(CONFIG_MACH_GT2)
#ifdef CONFIG_MACH_GT2R
	static unsigned int keypad_row_gpios[] = { 35, 34, 33, 32, 31, 80, 79, 26}; /* GPIO_NUM for KBC(0) ~ KBC(2) */
#else
	static unsigned int keypad_row_gpios[] = { 35, 34, 33, 32, 31, 80, 79, 22}; /* GPIO_NUM for KBC(0) ~ KBC(2) */
#endif
  static unsigned int keypad_col_gpios[] = { 42, 41,40, 39, 38,76 };
#endif


//#define KEYMAP_INDEX(col, row) ((col)*ARRAY_SIZE(keypad_row_gpios) + (row))
#define KEYMAP_INDEX(row, col) ((row)*ARRAY_SIZE(keypad_col_gpios) + (col))


static unsigned short keypad_keymap_surf[ARRAY_SIZE(keypad_col_gpios) *
					  ARRAY_SIZE(keypad_row_gpios)] = {

#if 0
	[KEYMAP_INDEX(0, 0)] = KEY_E,
	[KEYMAP_INDEX(0, 1)] = KEY_R,
	[KEYMAP_INDEX(0, 2)] = KEY_T,
	[KEYMAP_INDEX(0, 3)] = KEY_Y,
	[KEYMAP_INDEX(0, 4)] = KEY_U,
	[KEYMAP_INDEX(0, 5)] = KEY_I,
	[KEYMAP_INDEX(0, 6)] = KEY_O,
	[KEYMAP_INDEX(0, 7)] = KEY_P,
	
	[KEYMAP_INDEX(1, 0)] = KEY_BACK,
	[KEYMAP_INDEX(1, 1)] = KEY_LEFTSHIFT,
	[KEYMAP_INDEX(1, 2)] = KEY_A,
	[KEYMAP_INDEX(1, 3)] = KEY_S,
	[KEYMAP_INDEX(1, 4)] = KEY_D,
	[KEYMAP_INDEX(1, 5)] = KEY_F,
	[KEYMAP_INDEX(1, 6)] = KEY_G,
	[KEYMAP_INDEX(1, 7)] = KEY_H,
	
	[KEYMAP_INDEX(2, 0)] = KEY_J,
	[KEYMAP_INDEX(2, 1)] = KEY_K,
	[KEYMAP_INDEX(2, 2)] = KEY_L,
	[KEYMAP_INDEX(2, 3)] = KEY_ENTER,
	[KEYMAP_INDEX(2, 4)] = KEY_ENTER,
	[KEYMAP_INDEX(2, 5)] = KEY_LEFTALT,
	[KEYMAP_INDEX(2, 6)] = KEY_Z,
	[KEYMAP_INDEX(2, 7)] = KEY_X,
	
	[KEYMAP_INDEX(2, 0)] = KEY_J,
	[KEYMAP_INDEX(2, 1)] = KEY_K,
	[KEYMAP_INDEX(2, 2)] = KEY_L,
	[KEYMAP_INDEX(2, 3)] = KEY_ENTER,
	[KEYMAP_INDEX(2, 4)] = KEY_ENTER,
	[KEYMAP_INDEX(2, 5)] = KEY_LEFTALT,
	[KEYMAP_INDEX(2, 6)] = KEY_Z,
	[KEYMAP_INDEX(2, 7)] = KEY_X,
	
	[KEYMAP_INDEX(3, 0)] = KEY_C,
	[KEYMAP_INDEX(3, 1)] = KEY_V,
	[KEYMAP_INDEX(3, 2)] = KEY_B,
	[KEYMAP_INDEX(3, 3)] = KEY_N,
	[KEYMAP_INDEX(3, 4)] = KEY_M,
	[KEYMAP_INDEX(3, 5)] = KEY_Q,
	[KEYMAP_INDEX(3, 6)] = KEY_W,
	[KEYMAP_INDEX(3, 7)] = KEY_OK,
	
	[KEYMAP_INDEX(4, 0)] = KEY_RESERVED,
	[KEYMAP_INDEX(4, 1)] = KEY_SCREENLOCK,
	[KEYMAP_INDEX(4, 2)] = KEY_RESERVED,
	[KEYMAP_INDEX(4, 3)] = KEY_CAMERA,
	[KEYMAP_INDEX(4, 4)] = KEY_RESERVED,
	[KEYMAP_INDEX(4, 5)] = KEY_VOLUMEUP,
	[KEYMAP_INDEX(4, 6)] = KEY_VOLUMEDOWN,
	[KEYMAP_INDEX(4, 7)] = KEY_SPACE,
	
	[KEYMAP_INDEX(5, 0)] = KEY_RESERVED,
	[KEYMAP_INDEX(5, 1)] = KEY_SCREENLOCK,
	[KEYMAP_INDEX(5, 2)] = KEY_RESERVED,
	[KEYMAP_INDEX(5, 3)] = KEY_SPACE,
	[KEYMAP_INDEX(5, 4)] = KEY_SEND,
	[KEYMAP_INDEX(5, 5)] = KEY_OK,
	[KEYMAP_INDEX(5, 6)] = KEY_RESERVED,
	[KEYMAP_INDEX(5, 7)] = KEY_COMMA,
#endif
[KEYMAP_INDEX(0, 0)] = KEY_DOT,
[KEYMAP_INDEX(0, 1)] = KEY_I,
[KEYMAP_INDEX(0, 2)] = KEY_H,
[KEYMAP_INDEX(0, 3)] = KEY_B,
[KEYMAP_INDEX(0, 4)] = KEY_BACKSPACE,
[KEYMAP_INDEX(0, 5)] = KEY_OK, 

[KEYMAP_INDEX(1, 0)] = KEY_Q,
[KEYMAP_INDEX(1, 1)] = KEY_O,
[KEYMAP_INDEX(1, 2)] = KEY_J,
[KEYMAP_INDEX(1, 3)] = KEY_N,
[KEYMAP_INDEX(1, 4)] = KEY_ENTER,
//[KEYMAP_INDEX(1, 5)] = KEY_END,

[KEYMAP_INDEX(2, 0)] = KEY_W,
[KEYMAP_INDEX(2, 1)] = KEY_P,
[KEYMAP_INDEX(2, 2)] = KEY_K,
[KEYMAP_INDEX(2, 3)] = KEY_M,
[KEYMAP_INDEX(2, 4)] = KEY_WWW,  // change
[KEYMAP_INDEX(2, 5)] = KEY_VOLUMEUP,


[KEYMAP_INDEX(3, 0)] = KEY_E,
[KEYMAP_INDEX(3, 1)] = KEY_A,
[KEYMAP_INDEX(3, 2)] = KEY_L,
[KEYMAP_INDEX(3, 3)] = KEY_UP, 
[KEYMAP_INDEX(3, 4)] = KEY_LEFT,
[KEYMAP_INDEX(3, 5)] = KEY_VOLUMEDOWN,

[KEYMAP_INDEX(4, 0)] = KEY_R,
[KEYMAP_INDEX(4, 1)] = KEY_S,
[KEYMAP_INDEX(4, 2)] = KEY_Z,
[KEYMAP_INDEX(4, 3)] = KEY_DOWN, 
[KEYMAP_INDEX(4, 4)] = KEY_LEFTALT,
[KEYMAP_INDEX(4, 5)] = KEY_HOME,

[KEYMAP_INDEX(5, 0)] = KEY_T,
[KEYMAP_INDEX(5, 1)] = KEY_D,
[KEYMAP_INDEX(5, 2)] = KEY_X,
[KEYMAP_INDEX(5, 3)] = KEY_RIGHT,
[KEYMAP_INDEX(5, 4)] = KEY_COMMA,

[KEYMAP_INDEX(6, 0)] = KEY_Y,
[KEYMAP_INDEX(6, 1)] = KEY_F,
[KEYMAP_INDEX(6, 2)] = KEY_C,
[KEYMAP_INDEX(6, 3)] = KEY_LEFTSHIFT,//KEY_CANCEL, //symbol
[KEYMAP_INDEX(6, 4)] = KEY_MENU, //easyleft

[KEYMAP_INDEX(7, 0)] = KEY_U,
[KEYMAP_INDEX(7, 1)] = KEY_G,
[KEYMAP_INDEX(7, 2)] = KEY_V,
[KEYMAP_INDEX(7, 3)] = KEY_SPACE,
[KEYMAP_INDEX(7, 4)] = KEY_BACK,  //easyright

};


static unsigned short keypad_keymap_surf_02[ARRAY_SIZE(keypad_col_gpios) *
					  ARRAY_SIZE(keypad_row_gpios)] = {
#ifdef CONFIG_MACH_GT2R
[KEYMAP_INDEX(0, 0)] = KEY_QUESTION,
[KEYMAP_INDEX(0, 1)] = KEY_I,
[KEYMAP_INDEX(0, 2)] = KEY_H,
[KEYMAP_INDEX(0, 3)] = KEY_B,
[KEYMAP_INDEX(0, 4)] = KEY_BACKSPACE,
[KEYMAP_INDEX(0, 5)] = KEY_OK,

[KEYMAP_INDEX(1, 0)] = KEY_Q,
[KEYMAP_INDEX(1, 1)] = KEY_O,
[KEYMAP_INDEX(1, 2)] = KEY_J,
[KEYMAP_INDEX(1, 3)] = KEY_N,
[KEYMAP_INDEX(1, 4)] = KEY_ENTER,
//[KEYMAP_INDEX(1, 5)] = KEY_END,

[KEYMAP_INDEX(2, 0)] = KEY_W,
[KEYMAP_INDEX(2, 1)] = KEY_P,
[KEYMAP_INDEX(2, 2)] = KEY_K,
[KEYMAP_INDEX(2, 3)] = KEY_M,
[KEYMAP_INDEX(2, 4)] = KEY_LEFTSHIFT,  // change
[KEYMAP_INDEX(2, 5)] = KEY_VOLUMEUP,


[KEYMAP_INDEX(3, 0)] = KEY_E,
[KEYMAP_INDEX(3, 1)] = KEY_A,
[KEYMAP_INDEX(3, 2)] = KEY_L,
[KEYMAP_INDEX(3, 3)] = KEY_UP, 
[KEYMAP_INDEX(3, 4)] = KEY_LEFT,
[KEYMAP_INDEX(3, 5)] = KEY_VOLUMEDOWN,

[KEYMAP_INDEX(4, 0)] = KEY_R,
[KEYMAP_INDEX(4, 1)] = KEY_S,
[KEYMAP_INDEX(4, 2)] = KEY_Z,
[KEYMAP_INDEX(4, 3)] = KEY_DOWN, 
[KEYMAP_INDEX(4, 4)] = KEY_LEFTALT,
[KEYMAP_INDEX(4, 5)] = KEY_HOME,

[KEYMAP_INDEX(5, 0)] = KEY_T,
[KEYMAP_INDEX(5, 1)] = KEY_D,
[KEYMAP_INDEX(5, 2)] = KEY_X,
[KEYMAP_INDEX(5, 3)] = KEY_RIGHT,
[KEYMAP_INDEX(5, 4)] = KEY_F2,

[KEYMAP_INDEX(6, 0)] = KEY_Y,
[KEYMAP_INDEX(6, 1)] = KEY_F,
[KEYMAP_INDEX(6, 2)] = KEY_C,
[KEYMAP_INDEX(6, 3)] = KEY_F1,//KEY_CANCEL, //symbol
[KEYMAP_INDEX(6, 4)] = KEY_COMMA, //easyleft

[KEYMAP_INDEX(7, 0)] = KEY_U,
[KEYMAP_INDEX(7, 1)] = KEY_G,
[KEYMAP_INDEX(7, 2)] = KEY_V,
[KEYMAP_INDEX(7, 3)] = KEY_SPACE,
[KEYMAP_INDEX(7, 4)] = KEY_DOT,  //easyright
#else

[KEYMAP_INDEX(0, 0)] = KEY_QUESTION,
[KEYMAP_INDEX(0, 1)] = KEY_I,
[KEYMAP_INDEX(0, 2)] = KEY_H,
[KEYMAP_INDEX(0, 3)] = KEY_B,
[KEYMAP_INDEX(0, 4)] = KEY_BACKSPACE,
[KEYMAP_INDEX(0, 5)] = KEY_F3, 

[KEYMAP_INDEX(1, 0)] = KEY_Q,
[KEYMAP_INDEX(1, 1)] = KEY_O,
[KEYMAP_INDEX(1, 2)] = KEY_J,
[KEYMAP_INDEX(1, 3)] = KEY_N,
[KEYMAP_INDEX(1, 4)] = KEY_ENTER,
//[KEYMAP_INDEX(1, 5)] = KEY_END,

[KEYMAP_INDEX(2, 0)] = KEY_W,
[KEYMAP_INDEX(2, 1)] = KEY_P,
[KEYMAP_INDEX(2, 2)] = KEY_K,
[KEYMAP_INDEX(2, 3)] = KEY_M,
[KEYMAP_INDEX(2, 4)] = KEY_LEFTSHIFT,  // change
[KEYMAP_INDEX(2, 5)] = KEY_VOLUMEUP,


[KEYMAP_INDEX(3, 0)] = KEY_E,
[KEYMAP_INDEX(3, 1)] = KEY_A,
[KEYMAP_INDEX(3, 2)] = KEY_L,
[KEYMAP_INDEX(3, 3)] = KEY_WWW, 
[KEYMAP_INDEX(3, 4)] = KEY_EMAIL,
[KEYMAP_INDEX(3, 5)] = KEY_VOLUMEDOWN,

[KEYMAP_INDEX(4, 0)] = KEY_R,
[KEYMAP_INDEX(4, 1)] = KEY_S,
[KEYMAP_INDEX(4, 2)] = KEY_Z,
[KEYMAP_INDEX(4, 3)] = KEY_SEARCH, 
[KEYMAP_INDEX(4, 4)] = KEY_LEFTALT,
[KEYMAP_INDEX(4, 5)] = KEY_HOME,

[KEYMAP_INDEX(5, 0)] = KEY_T,
[KEYMAP_INDEX(5, 1)] = KEY_D,
[KEYMAP_INDEX(5, 2)] = KEY_X,
[KEYMAP_INDEX(5, 3)] = KEY_CONNECT,
[KEYMAP_INDEX(5, 4)] = KEY_F2,

[KEYMAP_INDEX(6, 0)] = KEY_Y,
[KEYMAP_INDEX(6, 1)] = KEY_F,
[KEYMAP_INDEX(6, 2)] = KEY_C,
[KEYMAP_INDEX(6, 3)] = KEY_F1,//KEY_CANCEL, //symbol
[KEYMAP_INDEX(6, 4)] = KEY_COMMA, //easyleft

[KEYMAP_INDEX(7, 0)] = KEY_U,
[KEYMAP_INDEX(7, 1)] = KEY_G,
[KEYMAP_INDEX(7, 2)] = KEY_V,
[KEYMAP_INDEX(7, 3)] = KEY_SPACE,
[KEYMAP_INDEX(7, 4)] = KEY_DOT,  //easyright

#endif
};


static unsigned short keypad_keymap_surf_04[ARRAY_SIZE(keypad_col_gpios) *
					  ARRAY_SIZE(keypad_row_gpios)] = {

[KEYMAP_INDEX(0, 0)] = KEY_QUESTION,
[KEYMAP_INDEX(0, 1)] = KEY_I,
[KEYMAP_INDEX(0, 2)] = KEY_H,
[KEYMAP_INDEX(0, 3)] = KEY_B,
[KEYMAP_INDEX(0, 4)] = KEY_BACKSPACE,
[KEYMAP_INDEX(0, 5)] = KEY_F3, 

[KEYMAP_INDEX(1, 0)] = KEY_Q,
[KEYMAP_INDEX(1, 1)] = KEY_O,
[KEYMAP_INDEX(1, 2)] = KEY_J,
[KEYMAP_INDEX(1, 3)] = KEY_N,
[KEYMAP_INDEX(1, 4)] = KEY_ENTER,
//[KEYMAP_INDEX(1, 5)] = KEY_END,

[KEYMAP_INDEX(2, 0)] = KEY_W,
[KEYMAP_INDEX(2, 1)] = KEY_P,
[KEYMAP_INDEX(2, 2)] = KEY_K,
[KEYMAP_INDEX(2, 3)] = KEY_M,
[KEYMAP_INDEX(2, 4)] = KEY_LEFTSHIFT,  // change
[KEYMAP_INDEX(2, 5)] = KEY_VOLUMEUP,


[KEYMAP_INDEX(3, 0)] = KEY_E,
[KEYMAP_INDEX(3, 1)] = KEY_A,
[KEYMAP_INDEX(3, 2)] = KEY_L,
[KEYMAP_INDEX(3, 3)] = KEY_WWW, 
[KEYMAP_INDEX(3, 4)] = KEY_EMAIL,
[KEYMAP_INDEX(3, 5)] = KEY_VOLUMEDOWN,

[KEYMAP_INDEX(4, 0)] = KEY_R,
[KEYMAP_INDEX(4, 1)] = KEY_S,
[KEYMAP_INDEX(4, 2)] = KEY_Z,
[KEYMAP_INDEX(4, 3)] = KEY_SEARCH, 
[KEYMAP_INDEX(4, 4)] = KEY_HOME,
[KEYMAP_INDEX(4, 5)] = KEY_LEFTALT,

[KEYMAP_INDEX(5, 0)] = KEY_T,
[KEYMAP_INDEX(5, 1)] = KEY_D,
[KEYMAP_INDEX(5, 2)] = KEY_X,
[KEYMAP_INDEX(5, 3)] = KEY_CONNECT,
[KEYMAP_INDEX(5, 4)] = KEY_F2,

[KEYMAP_INDEX(6, 0)] = KEY_Y,
[KEYMAP_INDEX(6, 1)] = KEY_F,
[KEYMAP_INDEX(6, 2)] = KEY_C,
[KEYMAP_INDEX(6, 3)] = KEY_F1,//KEY_CANCEL, //symbol
[KEYMAP_INDEX(6, 4)] = KEY_COMMA, //easyleft

[KEYMAP_INDEX(7, 0)] = KEY_U,
[KEYMAP_INDEX(7, 1)] = KEY_G,
[KEYMAP_INDEX(7, 2)] = KEY_V,
[KEYMAP_INDEX(7, 3)] = KEY_SPACE,
[KEYMAP_INDEX(7, 4)] = KEY_DOT,  //easyright

};


/* SURF keypad platform device information */
static struct gpio_event_matrix_info surf_keypad_matrix_info = {
	.info.func	= gpio_event_matrix_func,
	.keymap		= keypad_keymap_surf,
	.output_gpios	= keypad_row_gpios,
	.input_gpios	= keypad_col_gpios,
	.noutputs	= ARRAY_SIZE(keypad_row_gpios),
	.ninputs	= ARRAY_SIZE(keypad_col_gpios),
	.settle_time.tv.nsec = 40 * NSEC_PER_USEC,
	.poll_time.tv.nsec = 20 * NSEC_PER_MSEC,
	.flags		= GPIOKPF_LEVEL_TRIGGERED_IRQ | GPIOKPF_REMOVE_SOME_PHANTOM_KEYS | GPIOKPF_PRINT_UNMAPPED_KEYS
};



/* SURF keypad platform device information */
static struct gpio_event_matrix_info surf_keypad_matrix_info_02 = {
	.info.func	= gpio_event_matrix_func,
	.keymap		= keypad_keymap_surf_02,
	.output_gpios	= keypad_row_gpios,
	.input_gpios	= keypad_col_gpios,
	.noutputs	= ARRAY_SIZE(keypad_row_gpios),
	.ninputs	= ARRAY_SIZE(keypad_col_gpios),
	.settle_time.tv.nsec = 40 * NSEC_PER_USEC,
	.poll_time.tv.nsec = 20 * NSEC_PER_MSEC,
	.flags		= GPIOKPF_LEVEL_TRIGGERED_IRQ | GPIOKPF_REMOVE_SOME_PHANTOM_KEYS | GPIOKPF_PRINT_UNMAPPED_KEYS
};

/* SURF keypad platform device information */
static struct gpio_event_matrix_info surf_keypad_matrix_info_04 = {
	.info.func	= gpio_event_matrix_func,
	.keymap		= keypad_keymap_surf_04,
	.output_gpios	= keypad_row_gpios,
	.input_gpios	= keypad_col_gpios,
	.noutputs	= ARRAY_SIZE(keypad_row_gpios),
	.ninputs	= ARRAY_SIZE(keypad_col_gpios),
	.settle_time.tv.nsec = 40 * NSEC_PER_USEC,
	.poll_time.tv.nsec = 20 * NSEC_PER_MSEC,
	.flags		= GPIOKPF_LEVEL_TRIGGERED_IRQ | GPIOKPF_REMOVE_SOME_PHANTOM_KEYS | GPIOKPF_PRINT_UNMAPPED_KEYS
};


static struct gpio_event_info *surf_keypad_info[] = {
	&surf_keypad_matrix_info.info
};

static struct gpio_event_info *surf_keypad_info_02[] = {
	&surf_keypad_matrix_info_02.info
};

static struct gpio_event_info *surf_keypad_info_04[] = {
	&surf_keypad_matrix_info_04.info
};

static struct gpio_event_platform_data surf_keypad_data = {
//	.name		= "surf_keypad",
#if defined(CONFIG_MACH_CALLISTO)
#if (CONFIG_BOARD_REVISION < 0x03)
	.name		= "callisto_keypad0",	//sec: sm.kim
#else
	.name		= "callisto_keypad3",	//sec: sm.kim
#endif

#elif defined(CONFIG_MACH_GT2)
	.name		= "gt2_keypad0",	//sec: sm.kim
#elif defined(CONFIG_MACH_EUROPA)
	.name		= "europa_keypad0",	//sec: sm.kim
#endif
	.info		= surf_keypad_info,
	.info_count	= ARRAY_SIZE(surf_keypad_info)
};

static struct gpio_event_platform_data surf_keypad_data_02 = {
//	.name		= "surf_keypad",
#if defined(CONFIG_MACH_CALLISTO)
#if (CONFIG_BOARD_REVISION < 0x03)
	.name		= "callisto_keypad0",	//sec: sm.kim
#else
	.name		= "callisto_keypad3",	//sec: sm.kim
#endif

#elif defined(CONFIG_MACH_GT2)
	.name		= "gt2_keypad0",	//sec: sm.kim
#elif defined(CONFIG_MACH_EUROPA)
	.name		= "europa_keypad0",	//sec: sm.kim
#endif
	.info		= surf_keypad_info_02,
	.info_count	= ARRAY_SIZE(surf_keypad_info_02)
};
//mootest2
static struct gpio_event_platform_data surf_keypad_data_04 = {
//	.name		= "surf_keypad",
	.name		= "gt2_keypad0",	//sec: sm.kim
	.info		= surf_keypad_info_04,
	.info_count	= ARRAY_SIZE(surf_keypad_info_02)
};


struct platform_device keypad_device_surf = {
	.name	= GPIO_EVENT_DEV_NAME,
	.id	= -1,
	.dev	= {
		.platform_data	= &surf_keypad_data,
	},
};

struct platform_device keypad_device_surf_02 = {
	.name	= GPIO_EVENT_DEV_NAME,
	.id	= -1,
	.dev	= {
		.platform_data	= &surf_keypad_data_02,
	},
};

struct platform_device keypad_device_surf_04 = {
	.name	= GPIO_EVENT_DEV_NAME,
	.id	= -1,
	.dev	= {
		.platform_data	= &surf_keypad_data_04,
	},
};

