#include <unistd.h>
#include <linux/reboot.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fd = open("hashdf", O_RDONLY);
    if (fd == -1) {
        perror("open file");
        printf("%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("LINUX_REBOOT_MAGIC1: 0x%08X\n", LINUX_REBOOT_MAGIC1);
    printf("LINUX_REBOOT_MAGIC2: 0x%08X\n", LINUX_REBOOT_MAGIC2);
    printf("LINUX_REBOOT_MAGIC2A: 0x%08X\n", LINUX_REBOOT_MAGIC2A);
    printf("LINUX_REBOOT_MAGIC2B: 0x%08X\n", LINUX_REBOOT_MAGIC2B);
    printf("LINUX_REBOOT_MAGIC2C: 0x%08X\n", LINUX_REBOOT_MAGIC2C);
    
    printf("\n");

    printf("LINUX_REBOOT_CMD_CAD_OFF: 0x%08X\n", LINUX_REBOOT_CMD_CAD_OFF);
    printf("LINUX_REBOOT_CMD_CAD_ON: 0x%08X\n", LINUX_REBOOT_CMD_CAD_ON);
    printf("LINUX_REBOOT_CMD_HALT: 0x%08X\n", LINUX_REBOOT_CMD_HALT);
    printf("LINUX_REBOOT_CMD_KEXEC: 0x%08x\n", LINUX_REBOOT_CMD_KEXEC);
    printf("LINUX_REBOOT_CMD_POWER_OFF: 0x%08X\n", LINUX_REBOOT_CMD_POWER_OFF);
    printf("LINUX_REBOOT_CMD_RESTART: 0x%08X\n", LINUX_REBOOT_CMD_RESTART);
    printf("LINUX_REBOOT_CMD_RESTART2: 0x%08X\n", LINUX_REBOOT_CMD_RESTART2);
    printf("LINUX_REBOOT_CMD_SW_SUSPEND: 0x%08X\n", LINUX_REBOOT_CMD_SW_SUSPEND);

    return 0;
}