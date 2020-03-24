/*
 * Copyright (c) 2016 Andrei Tatar
 * Copyright (c) 2017-2018 Vrije Universiteit Amsterdam
 * Modifications copyright (C) 2020 <Anna Kim>
 *
 * This program is licensed under the GPL2+.
 */

/* Types used by the RAMSES library */

#ifndef _HAMTIME_RAMSES_TYPES_H
#define _HAMTIME_RAMSES_TYPES_H 1

#include <stdint.h>

typedef uint64_t physaddr_t; /* Physical memory addresses; this is what the CPU sees */

/* Address reserved as error condition; nigh impossible to encounter in the wild */
#define RAMSES_BADADDR ((physaddr_t)-1)

struct DRAMAddr {
	uint8_t chan;
	uint8_t dimm;
	uint8_t rank;
	uint8_t bank;
	uint16_t row;
	uint16_t col;
}; /* DRAM Addresses; this is what the memory DIMMs see on the bus + selection pins */

struct DDR4Addr {
	uint8_t chan;
	uint8_t dimm;
	uint8_t rank;
	uint8_t bg; //add bank group
	uint8_t bank;
	uint16_t row;
	uint16_t col;
}
/* Address reserved as error condition; impossible to encounter in the wild */
#define RAMSES_BADDRAMADDR ((struct DRAMAddr){-1, -1, -1, -1, -1, -1})
#define RAMSES_BADDDR4ADDR ((struct DDR4Addr){-1, -1, -1, -1, -1, -1, -1}) // add DDR4 error condition



#endif /* types.h */
