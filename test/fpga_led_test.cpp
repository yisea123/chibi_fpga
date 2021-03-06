#include "main.h"
#include "pads.h"

#include "fpga.h"
#include "fpga_led_test.hpp"

/*
 ******************************************************************************
 * DEFINES
 ******************************************************************************
 */

/*
 ******************************************************************************
 * EXTERNS
 ******************************************************************************
 */

/*
 ******************************************************************************
 * PROTOTYPES
 ******************************************************************************
 */

/*
 ******************************************************************************
 * GLOBAL VARIABLES
 ******************************************************************************
 */

/*
 ******************************************************************************
 ******************************************************************************
 * LOCAL FUNCTIONS
 ******************************************************************************
 ******************************************************************************
 */

/*
 ******************************************************************************
 * EXPORTED FUNCTIONS
 ******************************************************************************
 */

/**
 *
 */
void fpga_led_test(FPGADriver *fpgap, size_t turns) {
  osalDbgCheck(fpgap->state == FPGA_READY);

  fpgaword_t *ledp = fpgaGetSlicePtr(fpgap, FPGA_WB_SLICE_LED);
  uint8_t pattern = 0;
  uint8_t mask = (1 << 6) - 1;

  while (turns--) {
    osalThreadSleepMilliseconds(50);
    ledp[0] = pattern & mask;
    pattern++;
    green_led_toggle();
  }
}
