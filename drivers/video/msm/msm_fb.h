/* Copyright (c) 2008-2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef MSM_FB_H
#define MSM_FB_H

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/time.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include "linux/proc_fs.h"

#include <mach/hardware.h>
#include <linux/io.h>
#include <mach/board.h>

#include <asm/system.h>
#include <asm/mach-types.h>
#include <mach/memory.h>
#include <linux/semaphore.h>
#include <linux/spinlock.h>
#include <linux/workqueue.h>
#include <linux/hrtimer.h>

#include <linux/fb.h>
#include <linux/list.h>
#include <linux/types.h>

#include <linux/msm_mdp.h>
#ifdef CONFIG_HAS_EARLYSUSPEND
#include <linux/earlysuspend.h>
#endif

#include "msm_fb_panel.h"
#include "mdp.h"

#ifdef CONFIG_MACH_MSM8960_OSCAR
#define CONFIG_ACL_FOR_RECOVERY
#endif
#if defined(CONFIG_MACH_MSM8960_EF45K) || defined(CONFIG_MACH_MSM8960_EF46L) ||\
	defined (CONFIG_MACH_MSM8960_EF47S)
extern int charger_flag;
#define CONFIG_LCD_SHARP_OFF_SEQUENCE
#endif

#define MSM_FB_DEFAULT_PAGE_SIZE 2
#define MFD_KEY  0x11161126
#define MSM_FB_MAX_DEV_LIST 32

struct disp_info_type_suspend {
	boolean op_enable;
	boolean sw_refreshing_enable;
	boolean panel_power_on;
	boolean op_suspend;
};

struct msmfb_writeback_data_list {
	struct list_head registered_entry;
	struct list_head active_entry;
	void *addr;
	struct ion_handle *ihdl;
	struct file *pmem_file;
	struct msmfb_data buf_info;
	struct msmfb_img img;
	int state;
};


struct msm_fb_data_type {
	__u32 key;
	__u32 index;
	__u32 ref_cnt;
	__u32 fb_page;

	panel_id_type panel;
	struct msm_panel_info panel_info;

	DISP_TARGET dest;
	struct fb_info *fbi;

	struct device *dev;
	boolean op_enable;
	uint32 fb_imgType;
	boolean sw_currently_refreshing;
	boolean sw_refreshing_enable;
	boolean hw_refresh;
#ifdef CONFIG_FB_MSM_OVERLAY
	int overlay_play_enable;
#endif

	MDPIBUF ibuf;
	boolean ibuf_flushed;
	struct timer_list refresh_timer;
	struct completion refresher_comp;

	boolean pan_waiting;
	struct completion pan_comp;

	/* vsync */
	boolean use_mdp_vsync;
	__u32 vsync_gpio;
	__u32 total_lcd_lines;
	__u32 total_porch_lines;
	__u32 lcd_ref_usec_time;
	__u32 refresh_timer_duration;

	struct hrtimer dma_hrtimer;

	boolean panel_power_on;
	struct work_struct dma_update_worker;
	struct semaphore sem;

	struct timer_list vsync_resync_timer;
	boolean vsync_handler_pending;
	struct work_struct vsync_resync_worker;

	ktime_t last_vsync_timetick;

	__u32 *vsync_width_boundary;

	unsigned int pmem_id;
	struct disp_info_type_suspend suspend;

	__u32 channel_irq;

	struct mdp_dma_data *dma;
	void (*dma_fnc) (struct msm_fb_data_type *mfd);
	int (*cursor_update) (struct fb_info *info,
			      struct fb_cursor *cursor);
	int (*lut_update) (struct fb_info *info,
			      struct fb_cmap *cmap);
	int (*do_histogram) (struct fb_info *info,
			      struct mdp_histogram_data *hist);
	int (*start_histogram) (struct mdp_histogram_start_req *req);
	int (*stop_histogram) (struct fb_info *info, uint32_t block);
	void (*vsync_ctrl) (int enable);
	void (*vsync_init) (int cndx, struct msm_fb_data_type *mfd);
	void (*update_panel_info)(struct msm_fb_data_type *mfd);
	bool (*is_panel_ready)(void);
	void *vsync_show;
	void *cursor_buf;
	void *cursor_buf_phys;

	void *cmd_port;
	void *data_port;
	void *data_port_phys;

	__u32 bl_level;

	struct platform_device *pdev;
	struct platform_device *panel_pdev;

	__u32 var_xres;
	__u32 var_yres;
	__u32 var_pixclock;
	__u32 var_frame_rate;

#ifdef MSM_FB_ENABLE_DBGFS
	struct dentry *sub_dir;
#endif

#ifdef CONFIG_HAS_EARLYSUSPEND
	struct early_suspend early_suspend;
#ifdef CONFIG_FB_MSM_MDDI
	struct early_suspend mddi_early_suspend;
	struct early_suspend mddi_ext_early_suspend;
#endif
#endif
	u32 mdp_fb_page_protection;

	struct clk *ebi1_clk;
	boolean dma_update_flag;
	struct timer_list msmfb_no_update_notify_timer;
	struct completion msmfb_update_notify;
	struct completion msmfb_no_update_notify;
	struct mutex writeback_mutex;
	struct mutex unregister_mutex;
	struct list_head writeback_busy_queue;
	struct list_head writeback_free_queue;
	struct list_head writeback_register_queue;
	wait_queue_head_t wait_q;
	struct ion_client *iclient;
	unsigned long display_iova;
	unsigned long rotator_iova;
	struct mdp_buf_type *ov0_wb_buf;
	struct mdp_buf_type *ov1_wb_buf;
	u32 ov_start;
	u32 mem_hid;
	u32 mdp_rev;
	u32 writeback_state;
	bool writeback_active_cnt;
	int cont_splash_done;
#if defined(CONFIG_FB_MSM_RECOVER_PANEL) || defined(CONFIG_DEBUG_FS)
	struct mutex power_lock;
#endif
#ifdef CONFIG_FB_MSM_RECOVER_PANEL
	struct mutex nvrw_prohibit_draw;
#endif
	u32 acq_fen_cnt;
	struct sync_fence *acq_fen[MDP_MAX_FENCE_FD];
	int cur_rel_fen_fd;
	struct sync_pt *cur_rel_sync_pt;
	struct sync_fence *cur_rel_fence;
	struct sync_fence *last_rel_fence;
	struct sw_sync_timeline *timeline;
	int timeline_value;
	u32 last_acq_fen_cnt;
	struct sync_fence *last_acq_fen[MDP_MAX_FENCE_FD];
	struct mutex sync_mutex;
	struct completion commit_comp;
	u32 is_committing;
	struct work_struct commit_work;
	void *msm_fb_backup;
	boolean panel_driver_on;
};
struct msm_fb_backup_type {
	struct fb_info info;
	struct mdp_display_commit disp_commit;
};

struct dentry *msm_fb_get_debugfs_root(void);
void msm_fb_debugfs_file_create(struct dentry *root, const char *name,
				u32 *var);
void msm_fb_set_backlight(struct msm_fb_data_type *mfd, __u32 bkl_lvl);

struct platform_device *msm_fb_add_device(struct platform_device *pdev);
struct fb_info *msm_fb_get_writeback_fb(void);
int msm_fb_writeback_init(struct fb_info *info);
int msm_fb_writeback_start(struct fb_info *info);
int msm_fb_writeback_queue_buffer(struct fb_info *info,
		struct msmfb_data *data);
int msm_fb_writeback_dequeue_buffer(struct fb_info *info,
		struct msmfb_data *data);
int msm_fb_writeback_stop(struct fb_info *info);
int msm_fb_writeback_terminate(struct fb_info *info);
int msm_fb_detect_client(const char *name);
int calc_fb_offset(struct msm_fb_data_type *mfd, struct fb_info *fbi, int bpp);
void msm_fb_wait_for_fence(struct msm_fb_data_type *mfd);
int msm_fb_signal_timeline(struct msm_fb_data_type *mfd);
void msm_fb_release_timeline(struct msm_fb_data_type *mfd);
#ifdef CONFIG_FB_BACKLIGHT
void msm_fb_config_backlight(struct msm_fb_data_type *mfd);
#endif

void fill_black_screen(void);
void unfill_black_screen(void);
int msm_fb_check_frame_rate(struct msm_fb_data_type *mfd,
				struct fb_info *info);

#ifdef CONFIG_FB_MSM_LOGO
#define INIT_IMAGE_FILE "/initlogo.rle"
#if defined(CONFIG_MACH_MSM8960_EF45K) || defined(CONFIG_MACH_MSM8960_EF46L)||defined(CONFIG_MACH_MSM8960_EF47S)
#define INIT_RESET_IMAGE_FILE "/resetlogo.rle"
#endif
int load_565rle_image(char *filename, bool bf_supported);
#endif

#endif /* MSM_FB_H */