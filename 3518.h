#ifndef	__3518_H__
#define __3518_H__



#define		BASE_ADDR		0x200F0000


#define		OFFSET_PWM_OUT0		0x0BC
#define		OFFSET_PWM_OUT1		0x0C0




// GPIO Address
#define		GPIO_BASE		0x20140000

#define		BASE_GPIO0		(GPIO_BASE)
#define		BASE_GPIO1		(GPIO_BASE + 1*0x10000)
#define		BASE_GPIO2		(GPIO_BASE + 2*0x10000)
#define		BASE_GPIO3		(GPIO_BASE + 3*0x10000)
#define		BASE_GPIO4		(GPIO_BASE + 4*0x10000)
#define		BASE_GPIO5		(GPIO_BASE + 5*0x10000)
#define		BASE_GPIO6		(GPIO_BASE + 6*0x10000)
#define		BASE_GPIO7		(GPIO_BASE + 7*0x10000)
#define		BASE_GPIO8		(GPIO_BASE + 8*0x10000)
#define		BASE_GPIO9		(GPIO_BASE + 9*0x10000)
#define		BASE_GPIO10		(GPIO_BASE + 10*0x10000)
#define		BASE_GPIO11		(GPIO_BASE + 11*0x10000)

#define		BASE_GPIO_GROUP(_group)		(GPIO_BASE + (_group)*0x10000)

#define		OFFSET_GPIO_DIR		0x400
#define		OFFSET_GPIO_IS		0x404
#define		OFFSET_GPIO_IBE		0x408
#define		OFFSET_GPIO_IEV		0x40C
#define		OFFSET_GPIO_IE		0x410
#define		OFFSET_GPIO_RIS		0x414
#define		OFFSET_GPIO_MIS		0x418
#define		OFFSET_GPIO_IC		0x41C		//


#define		ADDR_GPIO_DIR(_group)		(BASE_GPIO_GROUP(_group) + OFFSET_GPIO_DIR)


#define		OFFSET_GPIO_DATA_M(_b)	(_b << 2)
#define		OFFSET_GPIO_DATA_S(_b)	((0x01 << _b) << 2)


#define		ADDR_GPIO_DATA_M(_group, _b)	(BASE_GPIO_GROUP(_group) + OFFSET_GPIO_DATA_M(_b))
#define		ADDR_GPIO_DATA_S(_group, _b)	(BASE_GPIO_GROUP(_group) + OFFSET_GPIO_DATA_S(_b))


#define		GPIO_DIR_OUTPUT		0x01
#define		GPIO_DIR_INPUT		0x00
#define		GPIO_DIR(_group)	(BASE_GPIO_GROUP(_group) + GPIO_DIR_OFFSET)





#endif	/* __3518_H__ */


