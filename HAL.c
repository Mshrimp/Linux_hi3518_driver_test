#include "3518.h"
#include "type.h"

void set_gpio_dir_output(u8int _group, u8int _bit)
{
	u32int data = 0;
	u32int addr;
	
	addr = ADDR_GPIO_DIR(_group);
	data = (u32int)readl(addr);

	//data = (u8int)readl(ADDR_GPIO_DIR(_group));
	data |= (0x01 << _bit);
	//writel(data, ADDR_GPIO_DIR(_group));
	writel(data, addr);

	return ;
}


void set_gpio_dir_input(u8int _group, u8int _bit)
{
	u8int data = 0;

	data = (u8int)readl(ADDR_GPIO_DIR(_group));
	data &= ~(0x01 << _bit);
	writel(data, ADDR_GPIO_DIR(_group));

	return ;
}


void set_gpio_output_high(u8int _group, u8int _bit)
{
}


void set_gpio_output_low(u8int _group, u8int _bit)
{

}


void set_bit(u32int _addr, u8int _bit)
{
	u32int data = 0;

	data = (u32int)readl(_addr) | (0x01 << _bit);
	writel(data, _addr);

	return ;
}


void set_bit_val(u32int _addr, u8int _b, u32int _val)
{
	u32int data = 0;
	u32int mask = 0;

	mask = _val & 0x01;
	data = (u32int)readl(_addr);
	data &= ~(0x01 << _b);
	data |= (mask << _b);
	writel(data, _addr);

	return ;
}


void set_nbits_val(u32int _addr, u8int _bit, u8int _n, u32int _val)
{
	u32int mask = 0;
	u32int data = 0;
	u8int _i = 0;

	for (_i=0; _i<_n; _i++)
	{
		mask |= 0x01 << _i;
	}
	
	_val &= mask;
	data = (u32int)readl(_addr);
	data &= ~(mask << _bit);
	data |= (_val << _bit);
	writel(data, _addr);

	return ;
}


void clr_bit(u32int _addr, u8int _bit)
{
	u32int data = 0;

	data = (u32int)readl(_addr) & ~(0x01 << _bit);
	writel(data, _addr);

	return ;
}



u32int get_bit(u32int _addr, u8int _bit)
{
	u32int data;

	data = (u32int)readl(_addr) & (0x01 << _bit);

	return data;
}


u32int get_nbits_val(u32int _addr, u8int _bit, u8int _n)
{
	u32int data = 0;
	u32int mask = 0;
	u8int _i = 0;

	for (_i=0; _i<_n; _i++)
	{
		mask |= (0x01 << _i);
	}

	data = (u32int)readl(_addr) & (mask << _bit);
	data = data >> _bit;
	data &= mask;

	return data >> _bit;
}






