#!/bin/bash
###############################################################################
#
#                           Kernel Build Script 
#
###############################################################################

##############################################################################
# set toolchain
##############################################################################
export ARCH=arm
export CROSS_COMPILE=/working1/sdv/thinhhoang/android/arm-eabi-4.6/bin/arm-eabi-

##############################################################################
# make zImage
##############################################################################
mkdir -p ../obj_830/KERNEL_OBJ/
make O=../obj_830/KERNEL_OBJ msm8960_ef46l_tp30_user_defconfig
make -j8 O=../obj_830/KERNEL_OBJ

##############################################################################
# Copy Kernel Image
##############################################################################
if [ -f ./obj/KERNEL_OBJ/arch/arm/boot/zImage ]
then
    cp -f ./obj/KERNEL_OBJ/arch/arm/boot/zImage ./
fi

