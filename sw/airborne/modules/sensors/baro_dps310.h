#ifndef BARO_DPS310_H
#define BARO_DPS310_H

#include <stdbool.h>

extern float baro_alt;
extern bool baro_alt_valid;

void baro_dps310_init(void);
void baro_dps310_periodic(void);
void baro_dps310_event(void);

#endif /* BARO_DPS310_H */

