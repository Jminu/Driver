#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x92997ed8, "_printk" },
	{ 0xfe990052, "gpio_free" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x403f9529, "gpio_request_one" },
	{ 0xa0c562db, "gpio_to_desc" },
	{ 0x9c62fdb0, "gpiod_to_irq" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x474e54d2, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "49919CD808FFFA1B5CF8E7E");
