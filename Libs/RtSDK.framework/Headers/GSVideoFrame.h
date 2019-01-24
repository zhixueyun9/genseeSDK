//
//  GSVideoFrame.h
//  RtSDK
//
//  Created by Gaojin Hsu on 3/11/15.
//  Copyright (c) 2015 Geensee. All rights reserved.
//


#import <Foundation/Foundation.h>


/**
 *  视频帧数据
 *
 */
@interface GSVideoFrame : NSObject

@property(nonatomic, assign)float width;

@property(nonatomic, assign)float height;

@property(nonatomic, strong) NSData *luma;

@property(nonatomic, strong) NSData *chromaB;

@property(nonatomic, strong) NSData *chromaR;

- (void)cleanObj;

@end
