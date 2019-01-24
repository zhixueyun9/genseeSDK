//  GSPTrafficMonitoring.h
//  PlayerSDK_forFastSDK
//  Created by jiangcj on 2017/8/25.
//  Copyright © 2017年 Geensee. All rights reserved.

#import <Foundation/Foundation.h>
@interface GSTrafficMonitoring : NSObject
+ (NSDictionary *)getTrafficMonitorings;
+ (void)reSetTrafficMonitorings;
@end
