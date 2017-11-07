/*  line added to delete  
 *  hello.c - The simplest kernel module.
 *  author - gaurang rathod <gaurangdr@gmail.com>
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>		/* Needed by module_init */

static int __init hello_init (void)
{
	printk(KERN_INFO "Hello world 1.\n");
	printk(KERN_INFO "This code executed when module installed\n");
	/*
	 * A non 0 return means init_module failed; module can't be loaded.
	 */
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Goodbye world 1.\n");
}

module_init(hello_init);
module_exit(hello_exit);
