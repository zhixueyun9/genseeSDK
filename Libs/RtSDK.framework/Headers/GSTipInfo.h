//
//  GSTipInfo.h
//  RtSDK
//
//  Created by Gaojin Hsu on 4/6/17.
//  Copyright © 2017 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 <#Description#>
 */
@interface GSTipInfo : NSObject


/**
 <#Description#>
 */
@property (nonatomic, copy) NSString *nickname;


/**
 <#Description#>
 */
@property (nonatomic, assign)long long userID;


/**
 <#Description#>
 */
@property (nonatomic, assign)unsigned int money;

@end


@interface GSTipInfoEx : NSObject


/**
 发送者 名称
 */
@property (nonatomic, copy) NSString *userName;

/**
 接受者 名称
 */
@property (nonatomic, copy) NSString *toUserName;

/**
 发送者 用户id
 */
@property (nonatomic, assign)long long userID;

/**
 接受者 用户id
 */
@property (nonatomic, assign)long long toUserID;

/**
 打赏金额
 */
@property (nonatomic, assign)unsigned int money;

/**
 消息 id
 */
@property (nonatomic, copy) NSString *tipID;

/**
 附带消息
 */
@property (nonatomic, copy) NSString *comment;

@end
