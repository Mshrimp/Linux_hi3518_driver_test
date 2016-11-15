#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>

#include "driver.h"


static int my_driver_open(struct inode *node, struct file *pfile)
{
	printk("MY_Driver file open!\n");

	return 0;
}

/*
static int my_driver_read(struct file *pfile, char __user *puser, size_t n, loff_t *ploff)
{
	printk("MY_Driver read data!\n");

	return 0;
}

static int my_driver_write(struct file *pfile, char __user *puser, size_t n, loff_t *ploff)
{
	printk("MY_Driver write data!\n");

	return 0;
}
*/



static struct file_operations	my_driver_fops = {
	.owner	= THIS_MODULE,
	.open	= my_driver_open,		
	//.read	= my_driver_read,
	//.write	= my_driver_write,
//	.unlocked_ioctl		= my_driver_ctl,
};


static struct miscdevice misc_my_driver = {
	//.minor	= MINOR_NUMBER,
	.minor	= MISC_DYNAMIC_MINOR,
	.name	= DRIVER_NAME,
	.fops	= &my_driver_fops,		
};



static int my_driver_init(void)
{
	printk("MY_Driver module start!\n");

	misc_register(&misc_my_driver);

	return 0;
}



static void my_driver_exit(void)
{
	printk("MY_Driver module stop!\n");

	misc_deregister(&misc_my_driver);

	return;
}



module_init(my_driver_init);
module_exit(my_driver_exit);

MODULE_AUTHOR("Build by Chiyuan.Ma at 2016.09.09");
MODULE_DESCRIPTION("This is a driver test module!");
MODULE_LICENSE("GPL");
