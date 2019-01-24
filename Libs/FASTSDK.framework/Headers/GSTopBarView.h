//
//  GSTopBarView.h
//  FASTSDK
//
//  Created by Sheng on 2017/7/27.
//  Copyright © 2017年 Gensee. All rights reserved.
//

#import <UIKit/UIKit.h>

@class GSSubjectView;

/**
 视频上方bar的栏目设置
 */
typedef NS_ENUM(NSInteger, GSFastTopBarStyle) {
    
//    GSFastTopBarBitStream           = 1 << 0,       //码流切换
    
    GSFastTopBarBarrage             = 1 << 1,       //弹幕
    
    GSFastTopBarAllStyles = (GSFastTopBarBarrage),
    
};

@interface GSTopBarView : UIView

@property (retain,nonatomic) GSSubjectView *subjectView;

//@property (nonatomic, strong) UILabel *title;

@property (nonatomic, strong) UIButton *backBtn;

@property (nonatomic, strong) UIButton *barrageBtn;

@property (nonatomic, strong) UIButton *bitChangeBtn;

@property (nonatomic, strong) UIButton *moreBtn;

//- (void)show;
//
//- (void)hide;

@end
