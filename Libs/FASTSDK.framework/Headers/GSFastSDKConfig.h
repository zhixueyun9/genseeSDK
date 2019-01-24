//
//  GSFastSDKConfig.h
//  FASTSDK
//
//  Created by Sheng on 2017/7/26.
//  Copyright © 2017年 陈伯伦. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import <RtSDK/RtSDK.h>
//#import "RtSDK.h"
//#import "GSThemeManager.h"
#import "GSCustomButtonRef.h"
#import "GSTopBarView.h"
@class GSConnectInfo;
/**
 GSFastModuleStyle  -  视频下面的模块种类
 */
typedef NS_ENUM(NSInteger, GSFastModuleStyle) {
    GSFastModuleUnknown           = 0,            //未设置
    GSFastModuleDoc               = 1 << 0,       //文档模块  1
    GSFastModuleChat              = 1 << 1,       //聊天模块  2
    GSFastModuleQa                = 1 << 2,       //问答模块  4
    GSFastModuleIntroduction      = 1 << 3,       //简介模块  8
    GSFastModuleMemberList        = 1 << 4,       //人员列表模块    1
    GSFastModuleAllStyles   = ( GSFastModuleDoc | GSFastModuleChat | GSFastModuleQa | GSFastModuleIntroduction),
};

/**
 GSFastPopupMenuStyle  -  视频右上角的弹出视图种类
 */

typedef NS_ENUM(NSInteger, GSFastPopupMenuStyle) {
    GSFastPopupMenuNone             = 0,            //未设置
    GSFastPopupMenuFaultReport      = 1 << 0,       //故障报告
    GSFastPopupMenuNetworkOptimization  = 1 << 1,   //优选网络
    GSFastPopupMenuOpenOrCloseVideo     = 1 << 2,   //打开关闭视频
};

//    GSFastPopupMenuStopOrResume     = 1 << 3,       //暂停恢复
//
//    GSFastPopupMenuBeauty           = 1 << 4,       //美颜
//
//    GSFastPopupMenuUpsideDown       = 1 << 5,       //上下颠倒交换


/**
 进入直播的方向参数
 */
typedef NS_ENUM(NSInteger, GSFastOrientationStyle) {
    GSFastOrientationPortrait       = 0,       //竖屏进入 模式
    GSFastOrientationLandscape      = 1,       //横屏进入 模式
};

/**
 主题风格
 */
typedef NS_ENUM(NSInteger, GSFastThemeStyle) {
    GSFastThemeBlack        =   0,       //黑色
    GSFastThemeWhite        =   1,       //白色
    GSFastThemeCustom       =   2,       //自定义图片
};

/**
 视频表面漂浮的按钮 设置
 */
typedef NS_ENUM(NSInteger, GSFastLiveSurfaceButtonStyle) {
    GSFastLiveSurfaceButtonFullScreen     = 0,            //全屏
    GSFastLiveSurfaceButtonHandup         = 1 << 0,       //举手
//    GSFastLiveSurfaceButtonReward         = 1 << 1,       //打赏
    GSFastLiveSurfaceButtonAllStyles = (GSFastLiveSurfaceButtonFullScreen | GSFastLiveSurfaceButtonHandup)
    
};


#define GSFastLiveSurfaceIsFullScreen(style) ((style&GSFastLiveSurfaceButtonFullScreen) == GSFastLiveSurfaceButtonFullScreen)
#define GSFastLiveSurfaceIsHandup(style) ((style&GSFastLiveSurfaceButtonHandup) == GSFastLiveSurfaceButtonHandup)


#define GSFastModuleStyleIsChat(style) ((style&GSFastModuleChat) == GSFastModuleChat)
#define GSFastModuleStyleIsDoc(style) ((style&GSFastModuleDoc) == GSFastModuleDoc)

typedef void(^GSCustomButtonAction)(id sender,int index,UIControlEvents event);



@interface GSFastSDKConfig : NSObject

#pragma mark - required
///**
// 建立直播链接信息
// */
//@property (nonatomic, strong) GSConnectInfo *connectInfo;

/**
 模块 配置信息
 */
@property (nonatomic, assign) GSFastModuleStyle moduleStyle;


/**
 进入直播的屏幕方向 default is Portrait
 */
@property (nonatomic, assign) GSFastOrientationStyle orientationStyle;

#pragma mark - optional

/**
 右上角 菜单栏配置信息
 */
@property (nonatomic, assign) GSFastPopupMenuStyle popupStyle;
/**
 top bar栏配置信息
 */
@property (nonatomic, assign) GSFastTopBarStyle topStyle;
/**
 视频表面漂浮的按钮 设置
 */
@property (nonatomic, assign) GSFastLiveSurfaceButtonStyle surfaceStyle;

/**
 自定义背景图  key值为 GSFastCustomPlayStopBackImage 等静态常量   value为图片路径
 */
@property (nonatomic, strong) NSDictionary *customBackImagePaths;

/**
 是否关闭画中画功能 default is NO
 */
@property (nonatomic, assign) BOOL isClosePIP;
/**
 主题背景 配置信息
 */
@property (nonatomic, assign) GSFastThemeStyle themeStyle;
/**
 打赏数组
 */
@property (nonatomic, strong) NSArray *rewardArray;

/**
 是否硬编
 */
@property (nonatomic, assign) BOOL isHardwareEncode;

#pragma mark - for 发布端
/**
 使用Https
 */
@property (nonatomic, assign) BOOL isHttps;
/**
 是否高清
 */
@property (nonatomic, assign) BOOL isHD;
/**
 是否进入默认横屏
 */
@property (nonatomic, assign) BOOL isLandscape;
/**
 是否老接口
 */
@property (nonatomic, assign) BOOL isOldVersion;
/**
 退出后强制设置设备方向为该值
 */
@property (nonatomic, assign) UIDeviceOrientation exitDeviceOrientation;

/**
 右侧自定义button的配置信息 最多自定义3个为界面上限
 */
@property (nonatomic, strong) NSArray<GSCustomButtonRef*>* customButtonRefs;
/**
 右侧自定义button的点击事件
 */
@property (nonatomic, copy) GSCustomButtonAction customButtonAction;

+ (instancetype)sharedInstance;

@end




