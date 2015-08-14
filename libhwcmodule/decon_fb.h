/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef __DECON_FB_H__
#define __DECON_FB_H__
#include <linux/fb.h>
#include <linux/kthread.h>
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#include <media/media-entity.h>
#define S3C_FB_MAX_WIN (5)
#define S3C_WIN_UPDATE_IDX (5)
#define DEV_DECON 6
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum s3c_fb_pm_status {
 POWER_ON = 0,
 POWER_DOWN = 1,
 POWER_HIBER_DOWN = 2,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum s3c_fb_psr_mode {
 S3C_FB_VIDEO_MODE = 0,
 S3C_FB_DP_PSR_MODE = 1,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 S3C_FB_MIPI_COMMAND_MODE = 2,
};
enum decon_trig_mode {
 DECON_HW_TRIG = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 DECON_SW_TRIG
};
struct decon_fb_videomode {
 struct fb_videomode videomode;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 u8 cs_setup_time;
 u8 wr_setup_time;
 u8 wr_act_time;
 u8 wr_hold_time;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 u8 auto_cmd_rate;
 u8 frame_skip:2;
 u8 rs_pol:1;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct s3c_fb_pd_win {
 struct decon_fb_videomode win_mode;
 unsigned short default_bpp;
 unsigned short max_bpp;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short virtual_x;
 unsigned short virtual_y;
 unsigned short width;
 unsigned short height;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct s3c_fb_platdata {
 void (*setup_gpio)(void);
 void (*backlight_off)(void);
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 void (*lcd_off)(void);
 struct s3c_fb_pd_win *win[S3C_FB_MAX_WIN];
 u32 default_win;
 u32 vidcon0;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 u32 vidcon1;
 int ip_version;
};
struct s3c_fb_variant {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int is_2443:1;
 unsigned short nr_windows;
 unsigned int vidtcon;
 unsigned short wincon;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short winmap;
 unsigned short keycon;
 unsigned short buf_start;
 unsigned short buf_end;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short buf_size;
 unsigned short osd;
 unsigned short osd_stride;
 unsigned short palette[S3C_FB_MAX_WIN];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int has_prtcon:1;
 unsigned int has_shadowcon:1;
 unsigned int has_blendcon:1;
 unsigned int has_alphacon:1;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int has_clksel:1;
 unsigned int has_fixvclk:1;
};
struct s3c_fb_win_variant {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int has_osd_c:1;
 unsigned int has_osd_d:1;
 unsigned int has_osd_alpha:1;
 unsigned int palette_16bpp:1;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short osd_size_off;
 unsigned short palette_sz;
 u32 valid_bpp;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct s3c_fb_driverdata {
 struct s3c_fb_variant variant;
 struct s3c_fb_win_variant *win[S3C_FB_MAX_WIN];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct s3c_fb_palette {
 struct fb_bitfield r;
 struct fb_bitfield g;
 struct fb_bitfield b;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct fb_bitfield a;
};
struct s3c_fb_win {
 struct s3c_fb_pd_win *windata;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct s3c_fb *parent;
 struct fb_info *fbinfo;
 struct s3c_fb_palette palette;
 struct s3c_fb_win_variant variant;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 u32 *palette_buffer;
 u32 pseudo_palette[16];
 unsigned int index;
 int fps;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int local;
 unsigned long state;
};
struct s3c_fb_vsync {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 wait_queue_head_t wait;
 ktime_t timestamp;
 bool active;
 int irq_refcount;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct mutex irq_lock;
 atomic_t eint_refcount;
 struct task_struct *thread;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct s3c_fb_win_rect {
 int x;
 int y;
 __u32 w;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 h;
};
struct s3c_fb {
 spinlock_t slock;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct device *dev;
 void __iomem *regs;
 struct s3c_fb_variant variant;
 bool output_on;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct mutex output_lock;
 struct s3c_fb_platdata *pdata;
 struct s3c_fb_win *windows[S3C_FB_MAX_WIN];
 int irq_no;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct s3c_fb_vsync vsync_info;
 enum s3c_fb_pm_status power_state;
 enum s3c_fb_psr_mode psr_mode;
 enum decon_trig_mode trig_mode;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int blank_mode;
 struct exynos5_bus_mif_handle *fb_mif_handle;
 struct exynos5_bus_int_handle *fb_int_handle;
 struct decon_lcd *lcd_info;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 atomic_t dsd_clk_ref_cnt;
 bool protected_content;
};
struct s3c_fb_rect {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int left;
 int top;
 int right;
 int bottom;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct s3c_fb_user_window {
 int x;
 int y;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct s3c_fb_user_plane_alpha {
 int channel;
 unsigned char red;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned char green;
 unsigned char blue;
};
struct s3c_fb_user_chroma {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int enabled;
 unsigned char red;
 unsigned char green;
 unsigned char blue;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct s3c_fb_user_ion_client {
 int fd;
 int offset;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum s3c_fb_pixel_format {
 S3C_FB_PIXEL_FORMAT_RGBA_8888 = 0,
 S3C_FB_PIXEL_FORMAT_RGBX_8888 = 1,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 S3C_FB_PIXEL_FORMAT_RGBA_5551 = 2,
 S3C_FB_PIXEL_FORMAT_RGB_565 = 3,
 S3C_FB_PIXEL_FORMAT_BGRA_8888 = 4,
 S3C_FB_PIXEL_FORMAT_BGRX_8888 = 5,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 S3C_FB_PIXEL_FORMAT_MAX = 6,
};
enum s3c_fb_blending {
 S3C_FB_BLENDING_NONE = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 S3C_FB_BLENDING_PREMULT = 1,
 S3C_FB_BLENDING_COVERAGE = 2,
 S3C_FB_BLENDING_MAX = 3,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum otf_status {
 S3C_FB_DMA,
 S3C_FB_LOCAL,
 S3C_FB_READY_TO_LOCAL,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 S3C_FB_S_STREAM,
};
struct s3c_fb_win_config {
 enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 S3C_FB_WIN_STATE_DISABLED = 0,
 S3C_FB_WIN_STATE_COLOR,
 S3C_FB_WIN_STATE_BUFFER,
 S3C_FB_WIN_STATE_OTF,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 S3C_FB_WIN_STATE_UPDATE,
 } state;
 union {
 __u32 color;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct {
 int fd;
 __u32 offset;
 __u32 stride;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 enum s3c_fb_pixel_format format;
 enum s3c_fb_blending blending;
 int fence_fd;
 int plane_alpha;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 };
 };
 int x;
 int y;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 w;
 __u32 h;
 bool protection;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define WIN_CONFIG_DMA(x) (regs->otf_state[x] != S3C_FB_WIN_STATE_OTF)
struct s3c_fb_win_config_data {
 int fence;
 struct s3c_fb_win_config config[S3C_FB_MAX_WIN];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define VALID_BPP(x) (1 << ((x) - 1))
#define VALID_BPP124 (VALID_BPP(1) | VALID_BPP(2) | VALID_BPP(4))
#define VALID_BPP1248 (VALID_BPP124 | VALID_BPP(8))
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define S3CFB_WIN_POSITION _IOW('F', 203,   struct s3c_fb_user_window)
#define S3CFB_WIN_SET_PLANE_ALPHA _IOW('F', 204,   struct s3c_fb_user_plane_alpha)
#define S3CFB_WIN_SET_CHROMA _IOW('F', 205,   struct s3c_fb_user_chroma)
#define S3CFB_SET_VSYNC_INT _IOW('F', 206, __u32)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define S3CFB_GET_ION_USER_HANDLE _IOWR('F', 208,   struct s3c_fb_user_ion_client)
#define S3CFB_WIN_CONFIG _IOW('F', 209,   struct s3c_fb_win_config_data)
#define S3CFB_WIN_PSR_EXIT _IOW('F', 210, int)
#endif
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
