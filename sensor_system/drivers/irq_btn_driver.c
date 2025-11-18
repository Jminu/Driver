#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio.h>
#include <linux/irqreturn.h>
#include <linux/interrupt.h>

static int __init btn_init(void) {

}

static void __exit btn_exit(void) {

}

module_init();
module_exit();

MODULE_LICENSE("GPL");
MODULE_AUTHOR("JIN MINU");
MODULE_DESCRIPTION("BUTTON IRQ DRIVER");
