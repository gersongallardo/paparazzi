.. installation hardware_installation px4fmu_3.0

======================
PX4FMU v3.0
======================

The Pixhawk PX4FMU v3.0 board provides an STM32F427 MCU with
2&nbsp;MB of flash and 256&nbsp;KB of RAM. Use this board option when
working with hardware revisions that expose this larger memory
configuration.

Select ``px4fmu_3.0`` when building your autopilot in Paparazzi Center
(or ``px4fmu_3.0_chibios`` if using the ChibiOS port). The PX4IO board
remains at revision 2.4 and should be flashed as ``px4io_2.4``.

Programming is done via the PX4 bootloader. Plug the board over USB and
run ``make ap.upload`` (or the **Flash** action in Paparazzi Center) to
upload the firmware.
