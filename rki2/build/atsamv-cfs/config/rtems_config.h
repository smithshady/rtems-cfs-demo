/*
** rtems_config.h
**
**  Author:  Alan Cudmore
**
**  This contains the configuration settings for an RTEMS Application
**
*/

/*
** RTEMS Includes
*/
#include <rtems.h>
#include <bsp.h>

#ifdef RKI_INCLUDE_MONITOR
   #include <rtems/monitor.h>
#endif

#ifdef RKI_INCLUDE_TARFS
   #include <rtems/untar.h>
#endif

#ifdef RKI_INCLUDE_LIBBSD 
   #include <rtems/bsd/bsd.h>
   #include <rtems/bsd/modules.h>
   #include <machine/rtems-bsd-commands.h>
#endif

// #include <rtems/dhcpcd.h>
#include <rtems/console.h>
// #include <rtems/netcmds-config.h>
#include <bsp/irq-info.h>
#include <net/if.h>
#include <rtems/rtl/dlfcn-shell.h>
#include <rtems/rtl/rap-shell.h>

/*
** RTEMS OS Configuration defintions
*/
#define TASK_INTLEVEL 0
#define CONFIGURE_INIT
#define CONFIGURE_INIT_TASK_ATTRIBUTES	(RTEMS_FLOATING_POINT | RTEMS_PREEMPT | RTEMS_NO_TIMESLICE | RTEMS_ASR | RTEMS_INTERRUPT_LEVEL(TASK_INTLEVEL))
#define CONFIGURE_INIT_TASK_STACK_SIZE	(32*1024)
#define CONFIGURE_INIT_TASK_PRIORITY	120

#define CONFIGURE_MAXIMUM_TASKS                       128
#define CONFIGURE_MAXIMUM_TIMERS                        5
#define CONFIGURE_MAXIMUM_SEMAPHORES                  512
#define CONFIGURE_MAXIMUM_MESSAGE_QUEUES              128

/* POSIX Keys are needed for the Shell */
#define CONFIGURE_MAXIMUM_POSIX_KEYS                   32
#define CONFIGURE_MAXIMUM_POSIX_KEY_VALUE_PAIRS        64

#define CONFIGURE_MAXIMUM_PARTITIONS                   2

#define CONFIGURE_EXECUTIVE_RAM_SIZE	( 2 * 1024 * 1024 )

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE
#define CONFIGURE_MAXIMUM_DRIVERS                     32 
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER

#define CONFIGURE_USE_IMFS_AS_BASE_FILESYSTEM

#define CONFIGURE_MAXIMUM_FILE_DESCRIPTORS           200

#define CONFIGURE_APPLICATION_NEEDS_LIBBLOCK
#define CONFIGURE_SWAPOUT_TASK_PRIORITY               10

#define CONFIGURE_SHELL_COMMANDS_INIT
#define CONFIGURE_SHELL_COMMANDS_ALL
#define CONFIGURE_SHELL_MOUNT_RFS
#define CONFIGURE_SHELL_MOUNT_MSDOS

#ifdef RKI_INCLUDE_LIBBSD
  #define CONFIGURE_SHELL_USER_COMMANDS \
  &bsp_interrupt_shell_command, \
  &rtems_shell_ARP_Command, \
  &rtems_shell_HOSTNAME_Command, \
  &rtems_shell_PING_Command, \
  &rtems_shell_ROUTE_Command, \
  &rtems_shell_NETSTAT_Command, \
  &rtems_shell_IFCONFIG_Command, \
  &rtems_shell_TCPDUMP_Command, \
  &rtems_shell_SYSCTL_Command, \
  &rtems_shell_VMSTAT_Command
#endif

#include <rtems/shellconfig.h>

#define CONFIGURE_MICROSECONDS_PER_TICK              10000

#define CONFIGURE_STACK_CHECKER_ENABLED

#define CONFIGURE_MAXIMUM_USER_EXTENSIONS 32
#define CONFIGURE_UNLIMITED_ALLOCATION_SIZE 32

#define CONFIGURE_APPLICATION_NEEDS_STUB_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_ZERO_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_LIBBLOCK

#define CONFIGURE_BDBUF_BUFFER_MAX_SIZE (64 * 1024)
#define CONFIGURE_BDBUF_MAX_READ_AHEAD_BLOCKS 4
#define CONFIGURE_BDBUF_CACHE_MEMORY_SIZE (1 * 1024 * 1024)

/*
** Filesystems needed
*/
/* IMFS and RFS will always be used */
#define CONFIGURE_FILESYSTEM_IMFS
#define CONFIGURE_FILESYSTEM_RFS
#define CONFIGURE_FILESYSTEM_MSDOS

/* #define CONFIGURE_FILESYSTEM_TFTPFS */

/*
** Init task prototype
*/
rtems_task Init (rtems_task_argument argument);

/*
** This include file must be AFTER the
** configuration data.
*/
#include <rtems/confdefs.h>


