//
//  GSConnectInfo.h
//  RtSDK
//
//  Created by Gaojin Hsu on 3/16/15.
//  Copyright (c) 2015 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *   使用的直播服务类型
 */
typedef NS_ENUM(NSInteger, GSBroadcastServiceType)
{
    /**
     *  Webcast 服务
     */
    GSBroadcastServiceTypeWebcast,
    
    /**
     *  Training 服务
     */
    GSBroadcastServiceTypeTraining,
};

/**
 *  允许何种身份进入直播
 */
typedef NS_ENUM(NSInteger, GSBroadcastPermission){
    /**
     *  只要密码正确，所有身份都可以进入直播
     */
    GSBroadcastPermissionAllRoles = 0x0,
    /**
     *  只允许观看者密码进入
     */
    GSBroadcastPermissionOnlyAttendee = 0x01,
    /**
     *  只允许组织者密码进入
     */
    GSBroadcastPermissionOnlyOrgnizer = 0x02,
};


/**
 * GSConnectInfo 封装了直播的连接参数信息
 */
@interface GSConnectInfo : NSObject<NSCopying>


/**
 *   域名（必填）
 */
@property(copy, nonatomic)NSString *domain;


/**
 *  WebcastID 和 RoomNumber只需要填写一个，如果都写了，将优先使用WebcastID
 */
@property(copy, nonatomic)NSString *webcastID;


/**
 *  WebcastID 和 RoomNumber只需要填写一个，如果都写了，将优先使用WebcastID
 */
@property(strong, nonatomic)NSString *roomNumber;


/**
 *  服务类型, 默认为webcast
 *  @see GSBroadcastServiceType
 */
@property(assign, nonatomic)GSBroadcastServiceType serviceType;


/**
 *  观看直播所显示的用户昵称
 */
@property(copy, nonatomic)NSString *nickName;


/**
 *  观看直播所需要的密码
 */
@property(copy, nonatomic)NSString *watchPassword;


/**
 *  登录网站的登录名，如果直播后台设置为必须登录才能观看，登录名和登录密码才会起作用
 */
@property(copy, nonatomic)NSString *loginName;


/**
 *   登录网站的密码
 */
@property(copy, nonatomic)NSString *loginPassword;


/**
 *  自定义userID; userID系统会分配，若无特殊需求，一般不需要设置此参数，自定义userID 大于1000000000（十亿）才生效，若小于十亿，将仍然使用系统分配ID,
 */
@property(assign, nonatomic)long long customUserID;


/**
 *  允许何种身份进入直播
 */
@property(assign, nonatomic)GSBroadcastPermission joinPermission;



/**
 * 是否使用带thirdToken的新接口，NO表示不使用
 */
@property (nonatomic, assign) BOOL oldVersion;

/**
 *  第三方验证K值，若无特殊需求，一般不需要设置此参数
 */
@property (nonatomic, copy) NSString *thirdToken;

@property (nonatomic, copy) NSString *userData;

//表示是否使用强制更新  G直播使用
@property (nonatomic, assign) BOOL gliveFlag;

//是否验证CustomUserId符合标准，符合则采用
@property (assign, nonatomic) BOOL needsValidateCustomUserID;
@end
