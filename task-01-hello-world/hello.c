#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("candriam");
MODULE_DESCRIPTION("Hello World kernel module - Eudyptula Task 01");

static int __init hello_init(void)
{
	pr_debug("Hello World!\n");
	return (0);
}

static void __exit hello_exit(void)
{
	pr_debug("Bye World!\n");
}

module_init(hello_init);
module_exit(hello_exit);
