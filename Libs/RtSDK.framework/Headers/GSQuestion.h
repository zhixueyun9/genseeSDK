//
//  GSQuestion.h
//  RtSDK
//
//  Created by Gaojin Hsu on 3/24/15.
//  Copyright (c) 2015 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  问答模式中的答案数据
 */
@interface GSAnswer : NSObject


/**
 *   答案ID
 */
@property (nonatomic, strong)NSString* answerID;


/**
 *  答案作者的用户ID
 */
@property (nonatomic, assign)long long ownerID;


/**
 *  答案作者的用户名
 */
@property (nonatomic, strong)NSString* ownerName;


/**
 *  作答时间
 */
@property (nonatomic, assign)long long answerTime;


/**
 *  答案内容
 */
@property (nonatomic, strong)NSString *answerContent;

@end

/**
 *  问答模式中的问题数据
 */
@interface GSQuestion : NSObject


/**
 *  问题ID
 */
@property (nonatomic, strong)NSString* questionID;


/**
 *  问题内容
 */
@property (nonatomic, strong)NSString* questionContent;


/**
 *  问题作者用户ID
 */
@property (nonatomic, assign)long long ownerID;


/**
 *   问题作者用户名
 */
@property (nonatomic, strong)NSString *ownerName;


/**
 *   问题发起时间
 */
@property (nonatomic, assign)long long questionTime;


/**
 *   问题答案
 */
@property (nonatomic, strong)NSArray *answers;


/**
 *   问题发布状态
 */
@property (nonatomic, assign)BOOL isPublished;


/**
 *   问题是否被分派给嘉宾
 */
@property (nonatomic, assign)BOOL isAssignedToPanelist;



/**
 *   问题是否语音回复中
 */
@property (nonatomic, assign)BOOL isNowReplyingByVoice;



/**
 *   问题是否已经语音回复结束
 */
@property (nonatomic, assign)BOOL isRepliedByVoice;


/**
 *   问题是否已经加入语音回复
 */
@property (nonatomic, assign)BOOL IsReplyByVoice;



@end

