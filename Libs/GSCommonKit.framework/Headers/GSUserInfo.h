//
//  GSUserInfo.h
//  RtSDK
//
//  Created by Gaojin Hsu on 3/12/15.
//  Copyright (c) 2015 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 用户在直播中的身份
 */
typedef NS_ENUM(NSInteger, GSUserRole) {
    
    /**
     *  组织者
     */
    GSUserRoleOrganizer = 1,
    
    /**
     *  主讲人
     */
    GSUserRoleLecturer = 2,
    
    /**
     *  嘉宾
     */
    GSUserRolePanelist = 4,
    
    /**
     *  普通参加者
     */
    GSUserRoleAttendee = 8,
    
    /**
     *  普通参加者web用户
     */
    GSUserRoleAttendeeWeb = 16,
};


/**
 *   用户使用的平台
 */
typedef NS_ENUM(NSInteger, GSUserType){
    
    /**
     *   PC 客户端
     */
    GSUserTypePCClient = 0,
    
    /**
     *   Web 嵌入flash
     */
    GSUserTypeWebHttpFlash,
    
    /**
     *   纯http
     */
    GSUserTypeWebHttp,
    
    /**
     *   iPad web
     */
    GSUserTypeIPadWeb,
    
    /**
     *   iPhone web
     */
    GSUserTypeIPhoneWeb,
    
    /**
     *   Adroid pad web
     */
    GSUserTypeAndroidPadWeb,
    
    /**
     *   Android phone web
     */
    GSUserTypeAndroidPhoneWeb,
    
    /**
     *   iPad app
     */
    GSUserTypeIPadApp,
    
    /**
     *   iPhone app
     */
    GSUserTypeIPhoneApp,
    
    /**
     *   Android pad app
     */
    GSUserTypeAndroidPadApp,
    
    /**
     *   Android phone app
     */
    GSUserTypeAndroidPhoneApp,
    
    /**
     *   Mac client
     */
    GSUserTypeMacClient,
    
    /**
     *   Telephone
     */
    GSUserTypeTelephone,
    
    /**
     *   web flash
     */
    GSUserTypeFlash,
    
    /**
     *  mobile sdk
     */
    GSUserTypeMobileSDK,
    
    /**
     *  pc sdk
     */
    GSUserTypePCSDK,
    
    /**
     *  ios playerSDK
     */
    GSUserTypeIOSPlayerSDK,
    
    /**
     *  android playerSDK
     */
    GSUserTypeAndroidPlayerSDK,
};


/**
 *  插播视频的ID，插播视频的ID是固定的，其他摄像头视频的ID是对应用户的userID
 */
#define LOD_USER_ID (0x7f00000000000000)






/**
 *  直播中的用户信息类
 */
@interface GSUserInfo : NSObject

/**
 *  用户ID
 */
@property(assign, nonatomic)long long userID;

/**
 *  用户名
 */
@property(strong, nonatomic)NSString* userName;

/**
 *  用户角色
 *  @see  GSUserRole
 */
@property(assign, nonatomic)GSUserRole role;

/**
 *  用户状态
 *  如麦克风是否打开等状态
 */
@property(assign, nonatomic)unsigned status DEPRECATED_MSG_ATTRIBUTE("已经有单独的属性判断各种状态");

/**
 *  用户使用平台类型
 *  @see GSUserType
 */
@property(assign, nonatomic)GSUserType userType;

/**
 *  用户是否有麦克风设备
 */
@property (assign, nonatomic)BOOL hasMicrophone;

/**
 *  用户是否有摄像头设备
 */
@property (assign, nonatomic)BOOL hasCamera;

/**
 *  用户麦克风是否打开
 */
@property (assign, nonatomic)BOOL isMicrophoneOpen;

/**
 *  麦克风是否静音
 */
@property (assign, nonatomic)BOOL isMicrophoneMute;

/**
 *  摄像头是否打开
 */
@property (assign, nonatomic)BOOL isCameraOpen;

/**
 *  此用户的视频是否为直播视频
 */
@property (assign, nonatomic)BOOL isVideoActivated;

/**
 *  该用户是否举手
 */
@property (assign, nonatomic)BOOL isHandup;

/**
 *  该用户是否被禁止聊天或提问
 */
@property (assign, nonatomic)BOOL isChatForbidden;

/**
 *  判断是否为组织者
 */
@property (assign, nonatomic)BOOL isOrganizer;

@property (copy, nonatomic) NSString *userData;

@end
