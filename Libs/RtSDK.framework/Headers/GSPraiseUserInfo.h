//
//  GSPraiseUserInfo.h
//  RtSDK
//
//  Created by Gaojin Hsu on 5/24/18.
//  Copyright © 2018 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, GSPraiseType) {
    GSPraiseTypeFavour,//点赞
    GSPraiseTypeMedal,//勋章
};

@interface GSPraiseInfo:NSObject
@property (nonatomic, assign) long long userID;
@property (nonatomic, copy) NSString* m_strUserName;
@property (nonatomic, assign)unsigned int m_dwTotal;
@end

@interface GSPraiseUserInfo:NSObject
@property (nonatomic, assign) long long userID;
@property (nonatomic, copy) NSString* m_strUserName;
@property (nonatomic, assign)unsigned int m_dwRemain;
@property (nonatomic, assign)unsigned int m_dwSend;
@property (nonatomic, assign)unsigned int m_dwRecv;
@end



