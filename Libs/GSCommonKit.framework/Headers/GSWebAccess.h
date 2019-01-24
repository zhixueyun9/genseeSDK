//
//  GSWebAccess.h
//  GSCommonKit
//
//  Created by Sheng on 2018/8/30.
//  Copyright © 2018年 gensee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GSConnectInfo.h"
/**
 *  直播连接结果
 */
typedef NS_ENUM(NSUInteger, GSBroadcastConnectResult) {
    
    /**
     *  直播初始化成功
     */
    GSBroadcastConnectResultSuccess = 0,
    
    /**
     *  网络错误
     */
    GSBroadcastConnectResultNetworkError = 1,
    
    /**
     *  找不到对应的webcastID，可能情况：roomNumber, domain填写有误，找不到对应的直播,调用AccessInfo接口产生的错误
     */
    GSBroadcastConnectResultWebcastIDNotFound = 2,
    
    /**
     *  webcastID 错误， 找不到对应的直播初始化参数, 调用LoginInfo接口产生的错误
     */
    GSBroadcastConnectResultWebcastIDInvalid = 3,
    
    /**
     *  登录信息错误， 调用LoginInfo接口产生的错误
     */
    GSBroadcastConnectResultLoginFailed = 4,
    
    /**
     *  加会口令错误, 调用LoginInfo接口产生的错误
     */
    GSBroadcastConnectResultJoinCastPasswordError = 5,
    
    /**
     *  其他错误，域名，角色拼接错误, 调用LoginInfo接口产生的错误
     */
    GSBroadcastConnectResultRoleOrDomainError = 6,
    
    /**
     *  加会参数都正确，但是初始化失败
     */
    GSBroadcastConnectResultInitFailed = 7,
    
    /**
     *  未知错误
     */
    GSBroadcastConnectResultUnknownError = 8,

    /**
     *  第三方验证错误
     */
    GSBroadcastConnectResultThirdTokenError = 9,
    
    /**
     * 不支持移动端
     */
    GSBroadcastConnectResultMobileUnsupported = 10,
    
    /**
     * 直播已过期
     */
    GSBroadcastConnectResultExpired = 11,
    
    /**
     * 没有权限观看直播
     **/
    GSBroadcastConnectResultPermissionDeny = 12,
};

//SDK类型
typedef NS_ENUM(NSInteger, GSSDKType) {
    GSSDKTypeRt,  //RtSDK
    GSSDKTypePlayer, //PlayerSDK
};

typedef void (^GSWebAccessCompletion)(NSUInteger result,NSDictionary *resultDic);

@interface GSWebAccess : NSObject

@property (nonatomic, assign) BOOL httpsAPI; //是否使用https的API,默认为NO

@property (nonatomic, assign, readonly) GSSDKType sdk; //SDK类型

- (instancetype _Nullable )init;

- (void)accessWithParam:(nonnull GSConnectInfo*)info
                sdkType:(GSSDKType)type
             completion:(GSWebAccessCompletion)completion;

- (void)cancel;

- (NSString *)getParamString;

@end
