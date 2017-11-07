/*  
 *  hello.c - The simplest kernel module.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>		/* Needed by module_init */

#define AUTHOR "Gaurang Rathod <gaurang.rathod@softnautics.com>"
#define DESC "A sample driver"

static int __init hello_init (void)
{
	printk(KERN_INFO "Hello world from Kernel module\n");

	/*
	 * A non 0 return means init_module failed; module can't be loaded.
	 */
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Goodbye world from Kernel module.\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESC);

MODULE_SUPPORTED_DEVICE("testdevice");
