
KERNEL_DIR = /opt/hi3518/Hi3518_SDK_V1.0.a.0/osdrv/kernel/linux-3.0.y

DRIVER_NAME = MY_Driver

PWD = ${shell pwd}

DRIVER_RELAY += ./driver.o
DRIVER_RELAY += ./HAL.o

obj-m := $(DRIVER_NAME).o
$(DRIVER_NAME)-objs := $(DRIVER_RELAY)

all:
	#make -C $(KERNEL_DIR) M=`pwd` modules
	make -C $(KERNEL_DIR) M=${PWD} modules
	arm-hisiv100nptl-linux-gcc app_led.c -o app
	@cp $(DRIVER_NAME).ko app /mnt/nfs/mcy/target/ -rf
	@mkdir ./build
	@mv *.o *mod.c *.order Module* build/

clean:
	make -C $(KERNEL_DIR) M=`pwd` clean
	@rm ./build -rf
	@rm app *.ko -rf

app:
	arm-hisiv100nptl-linux-gcc app_led.c -o app
	#gcc app_led.c -o app_pc


