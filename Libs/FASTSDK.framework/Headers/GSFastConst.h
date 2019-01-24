//
//  GSFastConst.h
//  FASTSDK
//
//  Created by Sheng on 2017/7/27.
//  Copyright © 2017年 陈伯伦. All rights reserved.
//

#import <Foundation/Foundation.h>

#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)    
// 颜色
#define FASTSDK_COLOR(r,g,b) [UIColor colorWithRed:(r/255.0) green:(g/255.0) blue:(b/255.0) alpha:1.0]
#define FASTSDK_COLORA(r,g,b,a)    [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:a]

#define FASTSDK_COLOR16(value) [UIColor colorWithRed:((float)((value & 0xFF0000) >> 16))/255.0 green:((float)((value & 0xFF00) >> 8))/255.0 blue:((float)(value & 0xFF))/255.0 alpha:1.0]
#define FASTSDK_COLOR16A(value,a) [UIColor colorWithRed:((float)((value & 0xFF0000) >> 16))/255.0 green:((float)((value & 0xFF00) >> 8))/255.0 blue:((float)(value & 0xFF))/255.0 alpha:a]
#define FASTSDK_COLOR_RANDOM  FASTSDK_COLOR(arc4random_uniform(256),arc4random_uniform(256),arc4random_uniform(256))
//图片获取
#define GSImageFromSource(path) [GUtil getImageByRetinaBundle:path]

//常用
#define FASTSDK_SCREEN_WIDTH     [UIScreen mainScreen].bounds.size.width
#define FASTSDK_SCREEN_HEIGHT    [UIScreen mainScreen].bounds.size.height
#define FASTSDK_SCREEN_SIZE      [UIScreen mainScreen].bounds.size
#define FASTSDK_STATUSBAR_HEIGHT [UIApplication sharedApplication].statusBarFrame.size.height 
#define FASTSDK_VIDEO_HEIGHT     ceil(([UIScreen mainScreen].bounds.size.width/16.00)*9)

#define FASTSDK_XBOTTM_HEIGHT 34

#define FASTSDK_SCREEN_MIN_LENGTH (MIN(FASTSDK_SCREEN_WIDTH, FASTSDK_SCREEN_HEIGHT))
#define FASTSDK_SCREEN_MAX_LENGTH (MAX(FASTSDK_SCREEN_WIDTH, FASTSDK_SCREEN_HEIGHT))


#define FASTSDK_IPHONE_X (IS_IPHONE && FASTSDK_SCREEN_MAX_LENGTH == 812.0)
#define FASTSDK_IPHONE_5_OR_LESS (IS_IPHONE && FASTSDK_SCREEN_MAX_LENGTH <= 568.0)
#define FASTSDK_IPHONE_5 (IS_IPHONE && FASTSDK_SCREEN_MAX_LENGTH == 568.0)
#define FASTSDK_IPHONE_6 (IS_IPHONE && FASTSDK_SCREEN_MAX_LENGTH == 667.0)
#define FASTSDK_IPHONE_6P (IS_IPHONE && FASTSDK_SCREEN_MAPX_LENGTH == 736.0)

#define FASTSDK_EMOTION_BUNDLE [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"FastSDK" ofType:@"bundle"]]

#define FASTSDK_DEBUG 0
//弹幕是否显示表情 attribute
#define BARRAGE_EMOTION 1

//animation 常量 统一设置 
#define FASTSDK_ANIMATION_DURATION 0.6f
#define FASTSDK_ANIMATION_DELAY 0.f
#define FASTSDK_ANIMATION_DAMPING 7.f
#define FASTSDK_ANIMATION_DAMPING_HIDE 8.f
#define FASTSDK_ANIMATION_VELOCITY 4.f

#pragma mark - 几个模块的自定义图片

//XXX:这里任何key值对应的都是字符串或者是存储字符串类型的数组,不可存储图片对象

//只有音频的背景图片 大图
static NSString * const GSFastCustomPlayOnlyAudioBackImage              = @"GSFastCustomPlayOnlyAudioBackImage";
//只有音频的背景图片 小图
static NSString * const GSFastCustomPlayOnlyAudioBackImageMini          = @"GSFastCustomPlayOnlyAudioBackImage";
//暂停直播的背景图片
static NSString * const GSFastCustomPlayStopBackImage                   = @"GSFastCustomPlayStopBackImage";
//无文档时的的背景图片
static NSString * const GSFastCustomPlayNoneDocBackImage                = @"GSFastCustomPlayNoneDocBackImage";
//正在加载的背景图片 数组 图片需要按照播放顺序排列
static NSString * const GSFastCustomPlayLoadingImagePaths               = @"GSFastCustomPlayLoadingImagePaths";



#pragma mark - 通知

static NSString * const GSFastNotificationDidChangedFullScreen                    = @"GSFastNotificationDidChangedFullScreen";

static NSString * const GSFastNotificationLiveOnJoin                               = @"GSFastNotificationLiveOnJoin";
//点击任一button重设3秒自动隐藏button的NSTimer通知
static NSString * const GSFastNotificationResetSurfaceTimer                               = @"GSFastNotificationResetSurfaceTimer";
