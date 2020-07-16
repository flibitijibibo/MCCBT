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

/* Note that GameKeyboardMouseMappings and AbstractButton use the same index */
static struct
{
	struct
	{
		Uint32 VirtualKeyCodes[NUM_BINDINGS];
	} GameKeyboardMouseMappings[NUM_ACTIONS];
} CustomKeyboardMouseMapping[NUM_GAMES];

int main(int argc, char **argv)
{
	char *settingsIn;
	SDL_RWops *settingsOut;
	char *secondHalf, *cur, *tmp;
	size_t settingsLen, firstHalfLen, secondHalfLen;
	uint8_t i, j, k;
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
				CustomKeyboardMouseMapping[i]
					.GameKeyboardMouseMappings[j]
					.VirtualKeyCodes[k] = SDL_atoi(cur);
			}
		}
	}

	/* TODO: Print bindings to human-readable action sets */
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
