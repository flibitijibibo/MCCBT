/* MCCBT - Master Chief Collection Binding Tool
 *
 * Copyright (c) 2020 Ethan Lee
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from
 * the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software in a
 * product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 *
 * Ethan "flibitijibibo" Lee <flibitijibibo@flibitijibibo.com>
 *
 */

#include <SDL.h>

#define NUM_GAMES 7
#define NUM_ACTIONS 68
#define NUM_BINDINGS 5

static const char *INTERNAL_Games[NUM_GAMES] =
{
	"Halo CE",
	"Halo 2",
	"UNKNOWN3",
	"Halo 3",
	"UNKNOWN5",
	"Halo Reach",
	"UNKNOWN7"
};

static const char *INTERNAL_Actions[NUM_GAMES][NUM_ACTIONS] =
{
	{ /* Halo CE */
		"Jump",
		"Switch Grenades",
		"Action",
		"Reload",
		"Change Weapon",
		"Melee",
		"Toggle Flashlight",
		"Throw Grenade",
		"Fire",
		"Crouch",
		"Zoom",
		"Zoom In",
		"Zoom Out",
		"UNKNOWN C?",
		NULL,
		NULL,
		NULL,
		NULL,
		"UNKNOWN Q?",
		"Move Forward",
		"Move Backward",
		"Move Left",
		"Move Right",
		NULL,
		NULL,
		NULL,
		"UNKNOWN VK_TAB?",
		"Toggle Visuals/Scoreboard",
		NULL,
		NULL,
		"UNKNOWN VK_LCONTROL?",
		"Vehicle Function 3",
		"UNKNOWN Z?",
		"UNKNOWN VK_LSHIFT?",
		"Vehicle Function 1",
		"UNKNOWN R?",
		"UNKNOWN F?",
		"UNKNOWN VK_LBUTTON?",
		"UNKNOWN VK_LSHIFT?",
		"UNKNOWN VK_LCONTROL?",
		"UNKNOWN VK_DELETE?",
		"UNKNOWN 1?",
		"UNKNOWN 2?",
		"UNKNOWN VK_OEM_3?",
		"UNKNOWN VK_RBUTTON?",
		"UNKNOWN VK_LMENU?",
		"UNKNOWN X?",
		"UNKNOWN Z?",
		"UNKNOWN C?",
		"UNKNOWN VK_RBUTTON?",
		"UNKNOWN VK_RIGHT?",
		"UNKNOWN VK_LEFT?",
		"UNKNOWN VK_RETURN?",
		"UNKNOWN E?",
		"UNKNOWN VK_SPACE?",
		"UNKNOWN VK_LSHIFT?",
		"UNKNOWN VK_LMENU?",
		"UNKNOWN R?",
		"UNKNOWN F?",
		"UNKNOWN VK_RBUTTON?",
		"UNKNOWN VK_RBUTTON?",
		"UNKNOWN E?",
		"UNKNOWN G?",
		"UNKNOWN C?",
		"UNKNOWN X?",
		"UNKNOWN F?",
		"UNKNOWN 3?",
		"UNKNOWN G?"
	},
	{ /* Halo 2 */
		"Jump",
		"Switch Grenades",
		"Action",
		"Reload",
		"Change Weapon",
		"Melee",
		"Toggle Flashlight",
		"Throw Grenade",
		"Fire",
		"Crouch",
		"Zoom",
		"Zoom In",
		"Zoom Out",
		"Dual-Wield",
		NULL,
		NULL,
		NULL,
		NULL,
		"Banshee Bomb",
		"Move Forward",
		"Move Backward",
		"Move Left",
		"Move Right",
		NULL,
		NULL,
		NULL,
		"UNKNOWN VK_TAB?",
		"Toggle Visuals/Scoreboard",
		NULL,
		NULL,
		"Vehicle Function 2",
		"Vehicle Function 3",
		"UNKNOWN Z?",
		"UNKNOWN VK_LSHIFT",
		"Vehicle Function 1",
		"Forge Ascend",
		"Forge Descend",
		"Forge Grab/Release Object",
		"Forge Boost",
		"Forge Precision Edit",
		"Forge Delete Object",
		"Forge Create Object/Object Properties",
		"Forge Tools",
		"Forge Switch Player Mode",
		"Forge Zoom",
		"Forge Rotation Mode",
		"Theater Toggle Panel",
		"Theater Toggle Interface",
		"Theater Toggle First/Third Person",
		"Theater Camera Reset",
		"Theater Jump Forward",
		"Theater Jump Back",
		"Theater Pause/Resume Playback",
		"Theater Fast Forward",
		"Theater Toggle Freecam",
		"Theater Boost",
		"Theater Panning",
		"Theater Ascend",
		"Theater Descend",
		"Fire Secondary",
		"Theater Zoom",
		"Forge Toggle Rotation Axes",
		"Forge Duplicate",
		"Forge Lock",
		"Forge Reset",
		"UNKNOWN F?",
		"UNKNOWN 3?",
		"UNKNOWN G?"
	},
	{ NULL },
	{ /* Halo 3 */
		"Jump",
		"Select Next Grenades",
		"Action",
		"Reload",
		"Change Weapon",
		"Melee",
		"Toggle Flashlight",
		"Throw Grenade",
		"Fire",
		"Crouch",
		"Zoom",
		"Zoom In",
		"Zoom Out",
		"Dual-Wield",
		NULL,
		NULL,
		NULL,
		NULL,
		"Banshee Bomb",
		"Move Forward",
		"Move Backward",
		"Move Left",
		"Move Right",
		NULL,
		NULL,
		NULL,
		"UNKNOWN VK_TAB?",
		"Toggle Scoreboard",
		NULL,
		NULL,
		"Vehicle Function 2",
		"Vehicle Function 3",
		"UNKNOWN Z?",
		"Use Equipment",
		"Vehicle Function 1",
		"Forge Ascend",
		"Forge Descend",
		"Forge Grab/Release Object",
		"Forge Boost",
		"Forge Precision Edit",
		"Forge Delete Object",
		"Forge Create Object/Object Properties",
		"Forge Tools",
		"Forge Switch Player Mode",
		"Forge Zoom",
		"Forge Rotation Mode",
		"Theater Toggle Panel",
		"Theater Toggle Interface",
		"Theater Toggle First/Third Person",
		"Theater Camera Reset",
		"Theater Jump Forward",
		"Theater Jump Back",
		"Theater Pause/Resume Playback",
		"Theater Fast Forward",
		"Theater Toggle Freecam",
		"Theater Boost",
		"Theater Panning",
		"Theater Ascend",
		"Theater Descend",
		"Fire Secondary",
		"Theater Zoom",
		"Forge Toggle Rotation Axes",
		"UNKNOWN C?",
		"UNKNOWN X?",
		"UNKNOWN VK_RBUTTON?",
		"Reload Secondary Weapon",
		"Select Previous Grenades",
		"UNKNOWN G?"
	},
	{ NULL },
	{ /* Halo Reach */
		"Jump",
		"Switch Grenades",
		"Action",
		"Reload",
		"Change Weapon",
		"Melee",
		"Toggle Night Vision",
		"Throw Grenade",
		"Fire",
		"Crouch",
		"Zoom",
		"Zoom In",
		"Zoom Out",
		"UNKNOWN C?",
		NULL,
		NULL,
		NULL,
		NULL,
		"UNKNOWN Q?",
		"Move Forward",
		"Move Backward",
		"Move Left",
		"Move Right",
		NULL,
		NULL,
		NULL,
		"UNKNOWN VK_TAB?",
		"Toggle Scoreboard",
		NULL,
		NULL,
		"Vehicle Function 2",
		"Vehicle Function 3",
		"UNKNOWN Z?",
		"Use Armor Ability",
		"Vehicle Function 1",
		"Forge Ascend",
		"Forge Descend",
		"Forge Grab/Release Object",
		"Forge Boost",
		"Forge Precision Edit",
		"Forge Delete Object",
		"Forge Create Object/Object Properties",
		"Forge Tools",
		"Forge Switch Player Mode",
		"Forge Zoom",
		"Forge Rotation Mode",
		"Theater Toggle Panel",
		"Theater Toggle Interface",
		"Theater Toggle First/Third Person",
		"Theater Camera Reset",
		"Theater Jump Forward",
		"Theater Jump Back",
		"Theater Pause/Resume Playback",
		"Theater Fast Forward",
		"Theater Toggle Freecam",
		"Theater Boost",
		"Theater Panning",
		"Theater Ascend",
		"Theater Descend",
		"UNKNOWN VK_RBUTTON?",
		"Theater Zoom",
		"Forge Toggle Rotation Axes",
		"UNKNOWN C?",
		"UNKNOWN X?",
		"UNKNOWN VK_RBUTTON?",
		"UNKNOWN F?",
		"UNKNOWN 3?",
		"UNKNOWN G?"
	},
	{ NULL }
};

static const char *INTERNAL_VKCode[256] =
{
	NULL,
	"VK_LBUTTON",
	"VK_RBUTTON",
	"VK_CANCEL",
	"VK_MBUTTON",
	"VK_XBUTTON1",
	"VK_XBUTTON2",
	"UNDEFINED: 0x07",
	"VK_BACK",
	"VK_TAB",
	"RESERVED: 0x0A",
	"RESERVED: 0x0B",
	"VK_CLEAR",
	"VK_RETURN",
	"UNDEFINED: 0x0E",
	"UNDEFINED: 0x0F",
	"VK_SHIFT",
	"VK_CONTROL",
	"VK_MENU",
	"VK_PAUSE",
	"VK_CAPITAL",
	"VK_KANA/VK_HANGUEL/VK_HANGUL",
	"VK_IME_ON",
	"VK_JUNJA",
	"VK_FINAL",
	"VK_HANJA/VK_KANJI",
	"VK_IME_OFF",
	"VK_ESCAPE",
	"VK_CONVERT",
	"VK_NONCONVERT",
	"VK_ACCEPT",
	"VK_MODECHANGE",
	"VK_SPACE",
	"VK_PRIOR",
	"VK_NEXT",
	"VK_END",
	"VK_HOME",
	"VK_LEFT",
	"VK_UP",
	"VK_RIGHT",
	"VK_DOWN",
	"VK_SELECT",
	"VK_PRINT",
	"VK_EXECUTE",
	"VK_SNAPSHOT",
	"VK_INSERT",
	"VK_DELETE",
	"VK_HELP",
	"0",
	"1",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"UNDEFINED: 0x3A",
	"UNDEFINED: 0x3B",
	"UNDEFINED: 0x3C",
	"UNDEFINED: 0x3D",
	"UNDEFINED: 0x3E",
	"UNDEFINED: 0x3F",
	"UNDEFINED: 0x40",
	"A",
	"B",
	"C",
	"D",
	"E",
	"F",
	"G",
	"H",
	"I",
	"J",
	"K",
	"L",
	"M",
	"N",
	"O",
	"P",
	"Q",
	"R",
	"S",
	"T",
	"U",
	"V",
	"W",
	"X",
	"Y",
	"Z",
	"VK_LWIN",
	"VK_RWIN",
	"VK_APPS",
	"RESERVED: 0x5E",
	"VK_SLEEP",
	"VK_NUMPAD0",
	"VK_NUMPAD1",
	"VK_NUMPAD2",
	"VK_NUMPAD3",
	"VK_NUMPAD4",
	"VK_NUMPAD5",
	"VK_NUMPAD6",
	"VK_NUMPAD7",
	"VK_NUMPAD8",
	"VK_NUMPAD9",
	"VK_MULTIPLY",
	"VK_ADD",
	"VK_SEPARATOR",
	"VK_SUBTRACT",
	"VK_DECIMAL",
	"VK_DIVIDE",
	"VK_F1",
	"VK_F2",
	"VK_F3",
	"VK_F4",
	"VK_F5",
	"VK_F6",
	"VK_F7",
	"VK_F8",
	"VK_F9",
	"VK_F10",
	"VK_F11",
	"VK_F12",
	"VK_F13",
	"VK_F14",
	"VK_F15",
	"VK_F16",
	"VK_F17",
	"VK_F18",
	"VK_F19",
	"VK_20",
	"VK_21",
	"VK_22",
	"VK_23",
	"VK_24",
	"UNASSIGNED: 0x88",
	"UNASSIGNED: 0x89",
	"UNASSIGNED: 0x8A",
	"UNASSIGNED: 0x8B",
	"UNASSIGNED: 0x8C",
	"UNASSIGNED: 0x8D",
	"UNASSIGNED: 0x8E",
	"UNASSIGNED: 0x8F",
	"VK_NUMLOCK",
	"VK_SCROLL",
	"OEM: 0x92",
	"OEM: 0x93",
	"OEM: 0x94",
	"OEM: 0x95",
	"OEM: 0x96",
	"UNASSIGNED: 0x97",
	"UNASSIGNED: 0x98",
	"UNASSIGNED: 0x99",
	"UNASSIGNED: 0x9A",
	"UNASSIGNED: 0x9B",
	"UNASSIGNED: 0x9C",
	"UNASSIGNED: 0x9D",
	"UNASSIGNED: 0x9E",
	"UNASSIGNED: 0x9F",
	"VK_LSHIFT",
	"VK_RSHIFT",
	"VK_LCONTROL",
	"VK_RCONTROL",
	"VK_LMENU",
	"VK_RMENU",
	"VK_BROWSER_BACK",
	"VK_BROWSER_FORWARD",
	"VK_BROWSER_REFRESH",
	"VK_BROWSER_STOP",
	"VK_BROWSER_SEARCH",
	"VK_BROWSER_FAVORITES",
	"VK_BROWSER_HOME",
	"VK_VOLUME_MUTE",
	"VK_VOLUME_DOWN",
	"VK_VOLUME_UP",
	"VK_MEDIA_NEXT_TRACK",
	"VK_MEDIA_PREV_TRACK",
	"VK_MEDIA_STOP",
	"VK_MEDIA_PLAY_PAUSE",
	"VK_LAUNCH_MAIL",
	"VK_LAUNCH_MEDIA_SELECT",
	"VK_LAUNCH_APP1",
	"VK_LAUNCH_APP2",
	"RESERVED: 0xB8",
	"RESERVED: 0xB9",
	"VK_OEM_1",
	"VK_OEM_PLUS",
	"VK_OEM_COMMA",
	"VK_OEM_MINUS",
	"VK_OEM_PERIOD",
	"VK_OEM_2",
	"VK_OEM_3",
	"RESERVED: 0xC1",
	"RESERVED: 0xC2",
	"RESERVED: 0xC3",
	"RESERVED: 0xC4",
	"RESERVED: 0xC5",
	"RESERVED: 0xC6",
	"RESERVED: 0xC7",
	"RESERVED: 0xC8",
	"RESERVED: 0xC9",
	"RESERVED: 0xCA",
	"RESERVED: 0xCB",
	"RESERVED: 0xCC",
	"RESERVED: 0xCD",
	"RESERVED: 0xCE",
	"RESERVED: 0xCF",
	"RESERVED: 0xD0",
	"RESERVED: 0xD1",
	"RESERVED: 0xD2",
	"RESERVED: 0xD3",
	"RESERVED: 0xD4",
	"RESERVED: 0xD5",
	"RESERVED: 0xD6",
	"RESERVED: 0xD7",
	"UNASSIGNED: 0xD8",
	"UNASSIGNED: 0xD9",
	"UNASSIGNED: 0xDA",
	"VK_OEM_4",
	"VK_OEM_5",
	"VK_OEM_6",
	"VK_OEM_7",
	"VK_OEM_8",
	"RESERVED: 0xE0",
	"OEM: 0xE1",
	"VK_OEM_102",
	"OEM: 0xE3",
	"OEM: 0xE4",
	"VK_PROCESSKEY",
	"OEM: 0xE6",
	"VK_PACKET",
	"UNASSIGNED: 0xE8",
	"OEM: 0xE9",
	"OEM: 0xEA",
	"OEM: 0xEB",
	"OEM: 0xEC",
	"OEM: 0xED",
	"OEM: 0xEE",
	"OEM: 0xEF",
	"OEM: 0xF0",
	"OEM: 0xF1",
	"OEM: 0xF2",
	"OEM: 0xF3",
	"OEM: 0xF4",
	"OEM: 0xF5",
	"VK_ATTN",
	"VK_CRSEL",
	"VK_EXSEL",
	"VK_EREOF",
	"VK_PLAY",
	"VK_ZOOM",
	"VK_NONAME",
	"VK_PA1",
	"VK_OEM_CLEAR"
};

/* Note that GameKeyboardMouseMappings and AbstractButton use the same index */
static struct
{
	struct
	{
		Uint32 VirtualKeyCodes[NUM_BINDINGS];
		Uint8 INTERNAL_HasMapping;
	} GameKeyboardMouseMappings[NUM_ACTIONS];
} CustomKeyboardMouseMapping[NUM_GAMES];

int main(int argc, char **argv)
{
	char *settingsIn;
	SDL_RWops *settingsOut;
	char *secondHalf, *cur, *tmp;
	size_t settingsLen, firstHalfLen, secondHalfLen;
	Uint32 keycode;
	Uint8 i, j, k;
	char bindingsLine[420];

	/* Load the file, store the parts of the file we're not touching */
	settingsIn = (char*) SDL_LoadFile("GameUserSettings.ini", &settingsLen);
	SDL_assert(settingsIn != NULL);
	tmp = SDL_strstr(settingsIn, "CustomKeyboardMouseMapping[0]");
	SDL_assert(tmp != NULL);
	firstHalfLen = (size_t) (tmp - settingsIn);
	secondHalf = SDL_strstr(settingsIn, "GraphicsQualityThrottles[6]");
	SDL_assert(secondHalf != NULL);
	secondHalfLen = settingsLen - (size_t) (secondHalf - settingsIn);

	/* Parse the mappings! */
	cur = tmp;
	for (i = 0; i < NUM_GAMES; i += 1)
	{
		cur = SDL_strstr(cur, "CustomKeyboardMouseMapping[");
		SDL_assert(cur != NULL);
		SDL_assert(SDL_atoi(cur + 27) == i);
		for (j = 0; j < NUM_ACTIONS; j += 1)
		{
			cur = SDL_strstr(cur, "GameKeyboardMouseMappings[");
			SDL_assert(cur != NULL);
			SDL_assert(SDL_atoi(cur + 26) == j);
			cur = SDL_strstr(cur, "AbstractButton=");
			SDL_assert(cur != NULL);
			SDL_assert(SDL_atoi(cur + 15) == j);
			for (k = 0; k < NUM_BINDINGS; k += 1)
			{
				cur = SDL_strstr(cur, "VirtualKeyCodes[");
				SDL_assert(cur != NULL);
				SDL_assert(SDL_atoi(cur + 16) == k);
				cur += 19;
				keycode = SDL_atoi(cur);
				CustomKeyboardMouseMapping[i]
				.GameKeyboardMouseMappings[j]
				.INTERNAL_HasMapping |= keycode != 0;
				CustomKeyboardMouseMapping[i]
				.GameKeyboardMouseMappings[j]
				.VirtualKeyCodes[k] = SDL_atoi(cur);

			}
		}
	}

	/* Print bindings to human-readable action sets */
	for (i = 0; i < NUM_GAMES; i += 1)
	{
		if (SDL_strstr(INTERNAL_Games[i], "UNKNOWN") != NULL)
		{
			continue;
		}
		SDL_Log("%s:\n", INTERNAL_Games[i]);
		for (j = 0; j < NUM_ACTIONS; j += 1)
		{
			if (	!CustomKeyboardMouseMapping[i]
				.GameKeyboardMouseMappings[j]
				.INTERNAL_HasMapping	)
			{
				continue;
			}
			if (SDL_strstr(INTERNAL_Actions[i][j], "UNKNOWN") != NULL)
			{
				continue;
			}
			SDL_snprintf(
				bindingsLine,
				sizeof(bindingsLine),
				"\t%2d, %s:",
				j,
				INTERNAL_Actions[i][j]
			);
			for (k = 0; k < NUM_BINDINGS; k += 1)
			if (	CustomKeyboardMouseMapping[i]
				.GameKeyboardMouseMappings[j]
				.VirtualKeyCodes[k] != 0	)
			{
				SDL_snprintf(
					bindingsLine,
					sizeof(bindingsLine),
					"%s %s",
					bindingsLine,
					INTERNAL_VKCode[
						CustomKeyboardMouseMapping[i]
						.GameKeyboardMouseMappings[j]
						.VirtualKeyCodes[k]
					]
				);
			}
			SDL_Log("%s", bindingsLine);
		}
	}

	/* TODO: Binding system with ImGui */

	/* Write the new ini, finally. */
	settingsOut = SDL_RWFromFile("GameUserSettings_MOD.ini", "w");
	SDL_RWwrite(settingsOut, settingsIn, firstHalfLen, 1);
	#define WRITE_TEXT \
		SDL_RWwrite( \
			settingsOut, \
			bindingsLine, \
			SDL_strlen(bindingsLine), \
			1 \
		)
	#define WRITE_CHAR(c) SDL_RWwrite(settingsOut, c, 1, 1)
	for (i = 0; i < NUM_GAMES; i += 1)
	{
		const char *lineEnd = ")\r\n";
		const size_t lineEndLen = SDL_strlen(lineEnd);
		SDL_snprintf(
			bindingsLine,
			sizeof(bindingsLine),
			"CustomKeyboardMouseMapping[%d]=(",
			i
		);
		WRITE_TEXT;
		for (j = 0; j < NUM_ACTIONS; j += 1)
		{
			SDL_snprintf(
				bindingsLine,
				sizeof(bindingsLine),
				"GameKeyboardMouseMappings[%d]=("
					"AbstractButton=%d,",
				j, j
			);
			WRITE_TEXT;
			for (k = 0; k < NUM_BINDINGS; k += 1)
			{
				SDL_snprintf(
					bindingsLine,
					sizeof(bindingsLine),
					"VirtualKeyCodes[%d]=%d",
					k,
					CustomKeyboardMouseMapping[i]
					.GameKeyboardMouseMappings[j]
					.VirtualKeyCodes[k]
				);
				WRITE_TEXT;
				if (k < (NUM_BINDINGS - 1))
				{
					WRITE_CHAR(",");
				}
			}
			WRITE_CHAR(")");
			if (j < (NUM_ACTIONS - 1))
			{
				WRITE_CHAR(",");
			}
		}
		SDL_RWwrite(settingsOut, lineEnd, lineEndLen, 1);
	}
	SDL_RWwrite(settingsOut, secondHalf, secondHalfLen, 1);
	SDL_RWclose(settingsOut);

	/* Clean up. We out. */
	SDL_free(settingsIn);
	return 0;
}
