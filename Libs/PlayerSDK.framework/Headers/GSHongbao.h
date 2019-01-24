//
//  ModelImfo.h
//  IJKPlayerDemo
//
//  Created by gensee on 2017/3/23.
//  Copyright © 2017年 gensee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GSHongbao : NSObject


/**
 数据类型， "hongbao"：红包；  "tip":打赏
 */
@property (nonatomic, strong) NSString *datatype;


/**
 如果是红包， "grab"：抢红包事件， “create": 创建红包事件；
 */
@property (nonatomic, strong) NSString *hongbaoEvent;


/**
 发送者username
 */
@property (nonatomic, strong) NSString *userName;


/**
 接受者username
 */
@property (nonatomic, strong) NSString *touserName;


/**
 发送者userid
 */
@property (nonatomic, strong) NSString *userId;


/**
 金额
 */
@property (nonatomic, strong) NSString *amount;


/**
 数量
 */
@property (nonatomic, strong) NSString *total;


/**
 红包id或者打赏id
 */
@property (nonatomic, strong) NSString *Id;


/**
 发生时间
 */
@property (nonatomic, strong) NSString *time;



/**
 发送目标的userid
 */
@property (nonatomic, strong) NSString *touser;


/**
 红包有效期
 */
@property (nonatomic, strong) NSString *duration;


/**
 红包类型：定向红包，群发红包
 */
@property (nonatomic, strong) NSString *hongbaotype;


/**
 评论
 */
@property (nonatomic, strong) NSString *comment;

- (id)initModelIndoWithDictionary:(NSDictionary *)dic;
+ (id)modelInfoWithDictionary:(NSDictionary *)dic;

@end
