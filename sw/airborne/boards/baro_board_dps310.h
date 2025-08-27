#ifndef BOARDS_BARO_BOARD_DPS310_H
#define BOARDS_BARO_BOARD_DPS310_H

#ifndef BARO_BOARD
#define BARO_BOARD BARO_DPS310
#endif

#include "modules/sensors/baro_dps310.h"

/* Prototype for board specific baro event */
extern void baro_event(void);
#define BaroEvent baro_event

#endif /* BOARDS_BARO_BOARD_DPS310_H */
