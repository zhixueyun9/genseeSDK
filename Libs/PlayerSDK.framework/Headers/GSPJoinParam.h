//
//  GSPJoinParam.h
//  PlayerSDK
//
//  Created by Gaojin Hsu on 6/9/15.
//  Copyright (c) 2015 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GSCommonKit/GSConnectInfo.h>
/**
 *  直播服务类型
 */
typedef NS_ENUM(NSUInteger, GSPServiceType){
    /**
     *  webcast
     */
    GSPServiceTypeWebcast,
    /**
     *  training
     */
    GSPServiceTypeTraining,
};

/**
 *  直播参数
 */
@interface GSPJoinParam : GSConnectInfo


@end
