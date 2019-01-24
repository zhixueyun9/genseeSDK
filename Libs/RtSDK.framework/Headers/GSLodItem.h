//
//  GSLodItem.h
//  RtSDK
//
//  Created by Gaojin Hsu on 5/6/16.
//  Copyright © 2016 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GSLodItem : NSObject

@property (nonatomic, assign)int type;

@property (nonatomic, copy) NSString *lodID;

@property (nonatomic, copy) NSString *lodName;

@property (nonatomic, assign)int playtimes;

@property (nonatomic, assign) unsigned totalTime;

@property (nonatomic, assign) unsigned currentime;

@end
