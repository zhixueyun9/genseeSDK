//
//  GSFastSDK.h
//  FASTSDK
//
//  Created by Sheng on 2017/7/27.
//  Copyright © 2017年 陈伯伦. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GSFastSDKConfig.h"

NS_ASSUME_NONNULL_BEGIN

/**
 SDK类
 */
@interface GSFastSDK : NSObject

/**
 SDK 所支持的旋转方向值
 */
@property (nonatomic, assign) UIInterfaceOrientationMask orientationMask;


+ (instancetype)sharedInstance;

#pragma mark - Watch 观看

/**
 观看直播

 @param minfo 直播参数
 @param mconfig 直播配置信息
 @param animate 是否开启跳转动画
 @param completion 进入回调
 */
- (void)enterLive:(GSConnectInfo*)minfo config:(GSFastSDKConfig*)mconfig animate:(BOOL)animate completion:(void (^ __nullable)(void))completion; //is present ViewController
/**
 设置退出回调,仅使用'enterLive:config:animate:completion:'方法时有效

 @param completion 退出回调
 */
- (void)setLeaveCompletion:(void (^ __nullable)(void))completion;


#pragma mark - Publish 发布

/**
 发布直播

 @param minfo 直播参数
 @param mconfig 直播配置信息
 */
- (void)publishLive:(GSConnectInfo *)minfo config:(GSFastSDKConfig*)mconfig;

#pragma mark - private

/**
 登出 并清除部分资源 （用户不需要主动调用）
 */
- (void)logout;



@end



NS_ASSUME_NONNULL_END



