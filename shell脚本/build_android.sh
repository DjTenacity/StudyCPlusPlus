#!/bin/bash

#全局变量，多个shell脚本都可以使用
export ANDROID_NDK_HOME=/usr/ndk/android-ndk-r10e
export PLATFORM_VERSION=android-9

function build_ffmpeg
{
	echo "start build ffmpeg $ARCH"
	./configure --target-os=linux \
	--prefix=$PREFIX \
	--arch=$ARCH \
	--enable-shared \
	--disable-static \
	--disable-yasm \
	--disable-ffmpeg \
	--disable-ffplay \
	--disable-ffprobe \
	--disable-ffserver \
	--disable-doc \
	--enable-cross-compile \
	--cross-prefix=$CROSS_COMPILE \
	--sysroot=$PLATFORM \
	--extra-cflags="-fpic"
	make clean
	make
	make install

	echo "build finished $ARCH"
}

#exec 1>jason_build_stdout.txt
#exec 2>jason_build_stdout.txt
#arm
ARCH=arm
CPU=arm
PREFIX=$(pwd)/android/$CPU
TOOLCHAIN=$ANDROID_NDK_HOME/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64
CROSS_COMPILE=$TOOLCHAIN/bin/arm-linux-androideabi-
PLATFORM=$ANDROID_NKD_HOME/platforms/$PLATFORM_VERSION/arch-$ARCH
build_ffmpeg

#x86
ARCH=x86
CPU=x86
PREFIX=$(pwd)/android/$CPU
TOOLCHAIN=$ANDROID_NDK_HOME/toolchains/x86-4.9/prebuilt/linux-x86_64
CROSS_COMPILE=$TOOLCHAIN/bin/i686-linux-android-
PLATFORM=$ANDROID_NKD_HOME/platforms/$PLATFORM_VERSION/arch-$ARCH
build_ffmpeg




