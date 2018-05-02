void Init_D(void);

void LedSetOnMask(uint8_t ledMask);	// ledMask ist 8-Bit-Maske
void LedSetOffMaske(uint8_t ledMask);

void LedToggle(void);

void LedAllOff(void);
void LedAllOn(void);

void LedInit_A_D(void);

uint8_t getButtonPressed(void);