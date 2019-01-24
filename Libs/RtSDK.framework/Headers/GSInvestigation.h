//
//  GSInvestigation.h
//  RtSDK
//
//  Created by Gaojin Hsu on 4/5/15.
//  Copyright (c) 2015 Geensee. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *   问卷调查中问题的题型
 */
typedef NS_ENUM(NSUInteger, GSInvestigationQuestionType) {
    
    /**
     *   单选题
     */
    GSInvestigationQuestionTypeSingleChoice,
    
    /**
     *   多选题
     */
    GSInvestigationQuestionTypeMultiChoice,
    
    /**
     *  问答题
     */
    GSInvestigationQuestionTypeEssay,
};


/**
 *   答题卡中问题的题型
 */
typedef NS_ENUM(NSUInteger, GSCardQuestionType) {
    
    /**
     *   单选题
     */
    GSCardQuestionTypeSingleChoice =1,
    
    /**
     *   多选题
     */
    GSCardQuestionTypeMultiChoice,
    
   
};




/**
 *   答题卡选项信息
 */
@interface GSCardAnswerInfo : NSObject

/**
 *   选择此选项的人数
 */
@property (nonatomic, assign)int choosedNum;

/**
 *   次选项是否为正确答案
 */
@property (nonatomic, assign)BOOL isRigth;

@end


/**
 *   问卷调查选择题选项数据
 */
@interface GSInvestigationOption : NSObject


/**
 *   答案ID，主动创建时使用NSUUID随机生成
 */
@property (nonatomic, copy)NSString *ID;


/**
 *   答案内容
 */
@property (nonatomic, copy)NSString *content;


/**
 *   此答案是否为正确选项
 */
@property (nonatomic, assign)BOOL isCorrectItem;


/**
 *   此选项是否被选中
 */
@property (nonatomic, assign)BOOL isSelected;


/**
 *   选择这个选项的总人数
 */
@property (nonatomic, assign)NSUInteger totalSumOfUsers;


/**
 *   所有选了这个选项的用户,userID
 */
@property (nonatomic, strong)NSArray<NSNumber*> *users;

@end


/**
 *  问卷调查中的问题数据
 */
@interface GSInvestigationQuestion : NSObject


/**
 *   问题ID，主动创建时使用NSUUID随机生成
 */
@property (nonatomic, copy)NSString *ID;


/**
 *   问题内容
 */
@property (nonatomic, copy)NSString *content;


/**
 *   问题答案，在题型为问答题时，该项为答案；如果是选择题，则忽略该项
 */
@property (nonatomic, copy)NSString *essayAnswer;


/**
 *   问题类型
 */
@property (nonatomic, assign)GSInvestigationQuestionType questionType;


/**
 *   选项，问题类型为选择题时才有意义
 */
@property (nonatomic, strong)NSArray<GSInvestigationOption*> *options;


/**
 *   参与这个问题的总人数
 */
@property (nonatomic, assign)NSUInteger totalSumOfUsers;


/**
 *   参与作答的所有用户,userID
 */
@property (nonatomic, strong)NSArray<NSNumber*> *users;


/**
 *   此题的分值
 */
@property (nonatomic, assign)NSUInteger score;






@end


/**
 *  一份问卷调查数据，通常一份问卷调查包含若干问题
 */
@interface GSInvestigation : NSObject


/**
 *  问卷调查ID， 主动创建时使用NSUUID随机生成
 */
@property (nonatomic, copy)NSString *ID;


/**
 *  发起问卷调查者的用户ID
 */
@property (nonatomic, assign)long long ownerID;


/**
 *  问卷调查主题
 */
@property (nonatomic, copy)NSString *theme;


/**
 *  该调查是否要求强制参与
 */
@property (nonatomic, assign)BOOL isForce;


/**
 *  调查是否发布
 */
@property (nonatomic, assign)BOOL isPublished;


/**
 *  此调查结果是否已经公布
 */
@property (nonatomic, assign)BOOL isResultPublished;


/**
 *  调查是否截止
 */
@property (nonatomic, assign)BOOL hasTerminated;


/**
 *  参与过的用户,userID
 */
@property (nonatomic, strong)NSArray<NSNumber*> *users;


/**
 *   问卷中的问题
 */
@property (nonatomic, strong)NSArray<GSInvestigationQuestion*>* questions;



/**
 *   这个调查问卷是否附带答案
 */
@property (nonatomic, assign)BOOL isHaveAnswer;
@property (nonatomic, strong) NSString* strRank;
@property (nonatomic, assign)int userCount;//总人数
@end


/**
 *  封装自己的问卷调查答案数据
 */
@interface GSInvestigationMyAnswer : NSObject

/**
 *  问题ID
 */
@property (nonatomic, copy)NSString *questionID;

/**
 *  选择的选项ID
 */
@property (nonatomic, copy)NSString *optionID;


/**
 *  问答题答案
 */
@property (nonatomic, copy)NSString *essayAnswer;

@end
