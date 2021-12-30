##
## Paths for the RTEMS tools and RTEMS BSP
## Change these macros to point to your toolchain and BSP
## installation.
## I prefer to keep my RTEMS toolchain in a different directory than
## the BSPs that I build.
##
##
# RTEMS_TOOL_BASE ?= /opt/rtems6
# RTEMS_BSP_BASE ?= /opt/rtems6
RTEMS_TOOL_BASE ?= $(HOME)/rtems/tools/6
RTEMS_BSP_BASE ?= $(HOME)/rtems/bsps/6