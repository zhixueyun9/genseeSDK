//
//  GSTagsContentView.h
//  RtSDKDemo
//
//  Created by Sheng on 2018/7/24.
//  Copyright © 2018年 gensee. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface GSTagsContentView : UIView

@property (nonatomic, assign) BOOL selectOnload; //所有tag初始化为选中状态

@property (nonatomic, assign) BOOL allowSelect; //允许选择 default NO -  YES :默认为灰色底色，选择后变颜色

@property (nonatomic, assign) BOOL supportMultiSelect; //是否支持多选

@property (nonatomic, copy) void(^handler)(NSInteger index, NSString *text,BOOL isSelect); //block回调

- (instancetype)initWithFrame:(CGRect)frame tags:(NSArray <NSString *>*)tagTexts handler:(void (^)(NSInteger index, NSString *text,BOOL isSelect))handler;

@end
