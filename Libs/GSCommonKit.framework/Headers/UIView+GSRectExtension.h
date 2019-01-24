//
//  UIView+GSRectExtension.h
//  RtSDKDemo
//
//  Created by Sheng on 2018/7/24.
//  Copyright © 2018年 gensee. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (GSRectExtension)

@property (nonatomic, assign) CGFloat gs_x;
@property (nonatomic, assign) CGFloat gs_y;
@property (nonatomic, assign) CGFloat gs_centerX;
@property (nonatomic, assign) CGFloat gs_centerY;
@property (nonatomic, assign) CGFloat gs_width;
@property (nonatomic, assign) CGFloat gs_height;
@property (nonatomic, assign) CGSize  gs_size;
@property (nonatomic, assign) CGPoint gs_origin;

@end
