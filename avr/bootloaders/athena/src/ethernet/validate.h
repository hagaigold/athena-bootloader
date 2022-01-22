#ifndef validate_h
#define validate_h

#include <stdint.h>

//#define ENABLE_INTEGRITY_CHECK

void InitValid(void);
void calcImageIntegrity(uint8_t* buffer, uint16_t length);
uint8_t isValidImage(void);

#endif
