/**
 * validate.c
 *
 * Integrity check DEMO module.
 * This DEMO can help to deploy an integrity check for the upload image.
 *
 * Any integrity check will have to use some sort of post build process to add
 * someting to the image- e.g CRC, digital signature, etc.
 *
 * in the below example a 2 bytes xmodem CRC added at the end of the image-
 *  when the calulation start with 0
 *   and at the end adding the CRC value itself (big endian)
 *    it should sum back to 0
 *
 * For post build manipulation of the image try the SRecord tool,
 * other third-party tools, or deploy your own solution.
 *
 * SRecord tool: https://sourceforge.net/projects/srecord
 * 
 *      exmaple: adding 2 bytes (big endian) xmodem CRC at the end
 *               input-  HEX format image (in.hex)
 *               output- BIN format image (out.bin)
 * 
 *        srec_cat.exe in.hex -intel \
 *            -crc16-b-e "(" -MAXimum-Address in.hex -intel ")" -xmodem \
 *            -o out.bin -bin
 *
 */

#include "validate.h"

#ifdef ENABLE_INTEGRITY_CHECK

#include "debug.h"
#include "debug_vald.h"
#include <util/crc16.h>

static uint16_t crc;

void InitValid(void)
{
	crc = 0;
}

void calcImageIntegrity(uint8_t* buffer, uint16_t length)
{
	for(uint16_t i = 0; i < length; i++)
	{
		crc = _crc_xmodem_update(crc, buffer[i]);
	}
}

uint8_t isValidImage(void)
{
	if(crc == 0)
	{
		DBG_VALD(tracePGMlnVald(mDebugVald_VALID);)
		return 1;
	}
	else
	{
		DBG_VALD(tracePGMlnVald(mDebugVald_FAILED);)
		return 0;
	}
}

#endif
