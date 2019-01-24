//
//  GSGrabInfo.h
//  RtSDK
//
//  Created by Gaojin Hsu on 5/30/16.
//  Copyright © 2016 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface GSUserGrabInfo : NSObject

@property (nonatomic, copy) NSString *hongbaoID;

@property (nonatomic, assign) long grabTime;

@property (nonatomic, assign) unsigned money;

@property (nonatomic, assign)long long userID;

@property (nonatomic, copy)NSString *userName;

@property (nonatomic, assign)BOOL bBest;

@end



@interface GSHongbaoInfo : NSObject

@property (nonatomic, copy)NSString *hongbaoID;

@property (nonatomic, assign)long long userID;

@property (nonatomic, copy)NSString *userName;

@property (nonatomic, assign) unsigned moneySum;

@property (nonatomic, assign)unsigned count;

@property (nonatomic, assign)long timeLimit;

@property (nonatomic, assign) unsigned type; //0:随机红包，1：固定红包，2：定向红包

@property (nonatomic, assign) long createTime;

@property (nonatomic, copy) NSString *comment;

@property (nonatomic, assign) int state;

@property (nonatomic, assign) int leftCount;


@property (nonatomic, assign) unsigned leftMoney;

@property (nonatomic, assign)long long toUser;

@property (nonatomic, copy) NSString *toUserName;

@end




@interface GSGrabInfo : NSObject

@property (nonatomic, assign)long long llUserID;

@property (nonatomic, copy) NSString *username;

@property (nonatomic, assign)long grabTime;

@property (nonatomic, assign)unsigned money;

@property (nonatomic, assign)BOOL bBest;

@end


