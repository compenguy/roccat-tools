#ifndef __ROCCAT_RYOSMKFX_H__
#define __ROCCAT_RYOSMKFX_H__

/*
 * This file is part of roccat-tools.
 *
 * roccat-tools is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * roccat-tools is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with roccat-tools. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ryos.h"

G_BEGIN_DECLS

#define USB_DEVICE_ID_ROCCAT_RYOS_MK_FX 0x2fda

#define RYOSMKFX_DEVICE_NAME "Ryos MK FX"

enum {
	RYOSMKFX_PROFILE_NUM = 5,
	RYOSMKFX_RKP_MACRO_NUM = 112,
	RYOSMKFX_MINIMUM_FIRMWARE_REQUIRED = 129,
};

typedef enum {
	RYOSMKFX_KEY_TYPE_MULTIMEDIA_MUTE_MICROPHONE = 0x73,
	RYOSMKFX_KEY_TYPE_FOLDER_DESKTOP = 0x74,
	RYOSMKFX_KEY_TYPE_FOLDER_FAVORITES = 0x75,
	RYOSMKFX_KEY_TYPE_FOLDER_FONTS = 0x76,
	RYOSMKFX_KEY_TYPE_FOLDER_MY_DOCUMENTS = 0x77,
	RYOSMKFX_KEY_TYPE_FOLDER_MY_DOWNLOADS = 0x78,
	RYOSMKFX_KEY_TYPE_FOLDER_MY_MUSIC = 0x79,
	RYOSMKFX_KEY_TYPE_FOLDER_MY_PICTURES = 0x7a,
	RYOSMKFX_KEY_TYPE_FOLDER_MY_NETWORK = 0x7b,
	RYOSMKFX_KEY_TYPE_FOLDER_PRINTERS = 0x7c,
	RYOSMKFX_KEY_TYPE_FOLDER_SYSTEM = 0x7d,
	
	RYOSMKFX_KEY_TYPE_SYSTEM_HIBERNATE = 0x9f,
	RYOSMKFX_KEY_TYPE_SYSTEM_REBOOT = 0xa0,
	RYOSMKFX_KEY_TYPE_SYSTEM_LOCK = 0xa1,
	RYOSMKFX_KEY_TYPE_SYSTEM_LOGOFF = 0xa2,
	
	RYOSMKFX_KEY_TYPE_BROWSER_NEW_TAB = 0xa5, /* Ctrl+t */
	RYOSMKFX_KEY_TYPE_BROWSER_NEW_WINDOW = 0xa6, /* Ctrl+n */
	
	RYOSMKFX_KEY_TYPE_SYSTEM_CONTROL_PANEL = 0xa8,
	RYOSMKFX_KEY_TYPE_SYSTEM_SYSTEM_PANEL = 0xa9,
	RYOSMKFX_KEY_TYPE_SYSTEM_TASK_MANAGER = 0xaa,
	RYOSMKFX_KEY_TYPE_SYSTEM_SCREEN_SETTINGS = 0xab,
	RYOSMKFX_KEY_TYPE_SYSTEM_SCREEN_SAVER = 0xac,
	RYOSMKFX_KEY_TYPE_SYSTEM_THEMES = 0xad,
	RYOSMKFX_KEY_TYPE_SYSTEM_DATE_TIME = 0xae,
	RYOSMKFX_KEY_TYPE_SYSTEM_NETWORK_SETTINGS = 0xaf,
	
	RYOSMKFX_KEY_TYPE_SYSTEM_ADMIN_PANEL = 0xe8,
	RYOSMKFX_KEY_TYPE_SYSTEM_WINDOWS_FIREWALL = 0xe9,
	RYOSMKFX_KEY_TYPE_SYSTEM_REGEDIT = 0xea,
	RYOSMKFX_KEY_TYPE_SYSTEM_EVENT_MONITOR = 0xeb,
	RYOSMKFX_KEY_TYPE_SYSTEM_PERFORMANCE_MONITOR = 0xec,
	RYOSMKFX_KEY_TYPE_SYSTEM_SOUND_SETTINGS = 0xed,
	RYOSMKFX_KEY_TYPE_SYSTEM_INTERNET_SETTINGS = 0xee,
	RYOSMKFX_KEY_TYPE_SYSTEM_DIRECTX_DIAGNOSTICS = 0xef,
	RYOSMKFX_KEY_TYPE_APP_COMMANDLINE = 0xf0,
	
	RYOSMKFX_KEY_TYPE_OPEN_DOCUMENT = 0xf2,
	RYOSMKFX_KEY_TYPE_OPEN_FOLDER = 0xf3,
	RYOSMKFX_KEY_TYPE_OPEN_WEBSITE = 0xf4,
} RyosmkfxKeyType;

typedef enum {
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_FOLDER_DESKTOP = 0x02,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_FOLDER_FAVORITES = 0x03,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_FOLDER_FONTS = 0x04,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_FOLDER_MY_DOCUMENTS = 0x05,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_FOLDER_MY_DOWNLOADS = 0x06,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_FOLDER_MY_MUSIC = 0x07,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_FOLDER_MY_PICTURES = 0x08,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_FOLDER_NETWORK = 0x09,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_FOLDER_PRINTERS = 0x0a,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_FOLDER_SYSTEM = 0x0b,

	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_WINDOWS_CONTROL_PANEL = 0x20,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_WINDOWS_SYSTEM_PANEL = 0x21,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_WINDOWS_TASK_MANAGER = 0x22,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_WINDOWS_SCREEN_SETTINGS = 0x23,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_WINDOWS_SCREENSAVER = 0x24,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_WINDOWS_THEMES = 0x25,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_WINDOWS_DATE_TIME = 0x26,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_WINDOWS_NETWORK_SETTINGS = 0x27,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_WINDOWS_ADMIN_PANEL = 0x28,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_WINDOWS_FIREWALL = 0x29,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_WINDOWS_REGEDIT = 0x2a,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_WINDOWS_EVENT_MONITOR = 0x2b,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_WINDOWS_PERFORMANCE_MONITOR = 0x2c,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_WINDOWS_SOUND_SETTINGS = 0x2d,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_WINDOWS_INTERNET_SETTINGS = 0x2e,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_WINDOWS_DIREKTX_DIAG = 0x2f,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_COMMANDLINE = 0x30,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_DOCUMENT = 0x31,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_FOLDER = 0x32,
	RYOSMKFX_SPECIAL_SUBTYPE_OPEN_WEBSITE = 0x33,
} RyosmkfxSpecialSubtypeOpen;

typedef enum {
	/* subtype = RyosmkfxSpecialSubtypeOpen
	 * data = key index
	 * action = RyosSpecialAction
	 */
	RYOSMKFX_SPECIAL_TYPE_OPEN = 0x11,

	/* data = 01 = powersave, 02 = full on
	 * action = 0x00
	 */
	RYOSMKFX_SPECIAL_TYPE_POWERSAVE = 0x12,
} RyosmkfxSpecialType;

guint16 ryosmkfx_color_to_hardware(guint8 color);
guint8 ryosmkfx_hardware_to_color(guint16 hardware);

static inline guint8 ryosmkfx_hardware_color_get_pwm(guint16 hardware) {
	return hardware & 0xff;
}

static inline guint8 ryosmkfx_hardware_color_get_brightness(guint16 hardware) {
	return hardware >> 8;
}

static inline guint16 ryosmkfx_hardware_color_build(guint8 pwm, guint8 brightness) {
	return pwm | (brightness << 8);
}

G_END_DECLS

#endif
