/* include/linux/asdk.h
 *
 *  Copyright (c) 2013 Ayysir
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 * 
*/

#ifndef __LINUX_ASDK_H__
#define __LINUX_ASDK_H__

#define ASDK_MIN_FREQ 192000
#define ASDK_MAX_FREQ 1512000

#define FREQSTEPS 35

#define MIN_VDD_SC		900000 /* uV */
#define MAX_VDD_SC		1350000 /* uV */
#define MAX_VDD_MEM		1350000 /* uV */
#define MAX_VDD_DIG		1350000 /* uV */

#define GPU_2D 228571000
#define GPU_3D 480000000

#define ON 1
#define OFF 0

/*asdk.c definitions*/

#define DEF_FREQUENCY_DOWN_DIFFERENTIAL		(10)
#define DEF_FREQUENCY_UP_THRESHOLD		(90)
#define DEF_SAMPLING_DOWN_FACTOR		(60)
#define MAX_SAMPLING_DOWN_FACTOR		(80000)
#define MICRO_FREQUENCY_DOWN_DIFFERENTIAL	(3)
#define MICRO_FREQUENCY_UP_THRESHOLD		(85)
#define MICRO_FREQUENCY_MIN_SAMPLE_RATE		(10000)
#define MIN_FREQUENCY_UP_THRESHOLD		(11)
#define MAX_FREQUENCY_UP_THRESHOLD		(100)
#define MIN_FREQUENCY_DOWN_DIFFERENTIAL		(1)

#define MIN_SAMPLING_RATE_RATIO			(2)

#define LATENCY_MULTIPLIER			(20)
#define MIN_LATENCY_MULTIPLIER			(20)
#define TRANSITION_LATENCY_LIMIT		(10 * 1000 * 1000)

#define POWERSAVE_BIAS_MAXLEVEL			(1000)
#define POWERSAVE_BIAS_MINLEVEL			(-1000)


#endif /* __LINUX_ASDK_H__ */

