//  GSDocPage.h
//  RtSDK
//  Created by Gaojin Hsu on 3/19/15.
//  Copyright (c) 2015 Geensee. All rights reserved.
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
/**
 *   标注的类型
 */
typedef NS_ENUM(NSInteger, GSDocumentAnnoType){
    /**
     *  空标注
     */
    GSDocumentAnnoTypeNull = 0x00,
    
    /**
     *  点标注
     */
    GSDocumentAnnoTypePoint,
    
    /**
     *  自由笔标注
     */
    GSDocumentAnnoTypeFreePen,
    
    /**
     *  橡皮擦
     */
    GSDocumentAnnoTypeCleaner,
    
    /**
     *  文字标注
     */
    GSDocumentAnnoTypeText,
    
    /**
     *  圆标注
     */
    GSDocumentAnnoTypeCircle,
    
    /**
     *  矩形标注
     */
    GSDocumentAnnoTypeRect,
    
    /**
     *  直线标注
     */
    GSDocumentAnnoTypeLine,
    
    /**
     *  加强版直线标注
     */
    GSDocumentAnnoTypeLineEx,
    
    /**
     *  加强版点标注
     */
    GSDocumentAnnoTypePointEx,
    
    /**
     *  加强版自由笔标注
     */
    GSDocumentAnnoTypeFreePenEx,
};



/**
 *   文档的显示的类型
 */
typedef NS_ENUM(NSInteger, GSDocShowType){
    /**
     *  等高
     */
    GSDocEqualHighType = 0x01,
    /**
     *  等宽
     */
    GSDocEqualWidthType,
    
    /**
     *  全屏
     */
    GSDocEqualFullScreenType,
    
};




/**
 *   直线标注的类型
 */

typedef NS_ENUM(NSInteger, LineExAnnoType){
    /**
     *  普通实线型
     */
    LineExSolidAnnoType = 0x00,
    
    /**
     *  虚线标注
     */
    LineExDashAnnoType,
    
    /**
     *  箭头标注
     */
    LineExArrowAnnoType,
    
    
};





/**
 *   清除标注的类型
 */
typedef NS_ENUM(NSInteger, GSDocumentClearAnnoType){
    /**
     *  清除所有标注
     */
    GSDocumentAnnoClearAllType = 0x80,
    
    
    /**
     *  清除选中的标注
     */
    GSDocumentAnnoClearSelectAnnoType,
    
    /**
     * 上一步， 清除最后一个标注
     */
    GSDocumentAnnoClearLastAnnoType,
    
    
    /**
     * 下一步， 画下一个next一个标注
     */
    GSDocumentAnnoClearNextAnnoType,
    
};




/**
 *   显示点的类型
 */
typedef NS_ENUM(NSInteger, GSDocumentPointExAnnoType){
    /**
     *  十字型
     */
    GSDocumentAnnoPointExCross = 0x00,
    
    
    /**
     *  箭头
     */
    GSDocumentAnnoPointExArrow,
    
    
};






/**
 *  文档类，封装了文档的数据，一份文档可以包含若干文档页
 */
@interface GSDocument : NSObject

/**
 *  文档ID
 */
@property (assign, nonatomic)unsigned docID;

/**
 *  保存所有文档页对象的数组
 */
@property (strong, nonatomic)NSMutableDictionary *pages;


/**
 *  当前显示的文档页索引
 */
@property (assign, nonatomic)int currentPageIndex;

/**
 *  布尔值表示该文档是否存放在服务器上， YES表示是
 */
@property (assign, nonatomic)BOOL savedOnServer;

/**
 *  文档名称
 */
@property (strong, nonatomic)NSString *docName;


/**
 *  文档所属的用户ID
 */
@property (assign, nonatomic)long long ownerID;


/**
 *  文档的类型
 */
@property (assign, nonatomic)int docType;


@end


/**
 *  文档页类，封装了文档页数据
 */
@interface GSDocPage : NSObject


/**
 *  文档页ID
 */
@property (assign, nonatomic)unsigned pageID;


/**
 *  文档页数据
 */
@property (strong, nonatomic)NSData *pageData;


/**
 *  文档页的宽
 */
@property (assign, nonatomic)short pageWidth;


/**
 *  文档页的高
 */
@property (assign, nonatomic)short pageHeight;


/**
 *  该文档页上的所有标注数据
 */
@property (strong, nonatomic)NSMutableDictionary *annos;

@property (strong, nonatomic)NSMutableArray *annosArray ;


@property (strong, nonatomic)NSData *aniCfg;


@end


/**
 *  文档标注的基类
 */
@interface GSAnnoBase : NSObject

/**
 *  标注类型
 *  @see GSDocumentAnnoType
 */
@property (assign, nonatomic)GSDocumentAnnoType type;


/**
 *  标注ID
 */
@property (assign, nonatomic)long long annoID;


/**
 *  标注所在文档页的ID
 */
@property (assign, nonatomic)unsigned pageID;


/**
 *  标注所在文档页所在的文档的ID
 */
@property (assign, nonatomic)unsigned docID;

@property (assign, nonatomic) long long ownerID;

@end


/**
 *  圆形标注
 */
@interface GSAnnoCircle : GSAnnoBase

/**
 *  线的粗细尺寸
 */
@property (assign, nonatomic)Byte lineSize;

/**
 *  线的颜色
 */
@property (strong, nonatomic)UIColor *lineColor;


/**
 *  圆标注所在的矩形区域
 */
@property (assign, nonatomic)CGRect rect;

@end


/**
 *  自由笔标注
 */
@interface GSAnnoFreePen : GSAnnoBase


/**
 *  自由笔所有的点数据
 */
@property (strong, nonatomic)NSMutableArray *points;


/**
 *  线的粗细尺寸
 */
@property (assign, nonatomic)Byte lineSize;


/**
 *  线的颜色
 */
@property (strong, nonatomic)UIColor *lineColor;

@property (assign, nonatomic)BOOL isHighlight;  //add tou ming




@end


/**
 *  加强版自由笔标注
 */
@interface GSAnnoFreePenEx : GSAnnoFreePen

/**
 *   表示当前的自由笔对象是开始点，过程中的点还是结束的点
 */
@property (assign, nonatomic) Byte stepType;


@property (assign, nonatomic)BOOL isHighlight;


@end


/**
 *  直线标注
 */
@interface GSAnnoLine : GSAnnoBase

/**
 *  线的粗细尺寸
 */
@property (assign, nonatomic)Byte lineSize;


/**
 *  线的颜色
 */
@property (strong, nonatomic)UIColor *lineColor;


/**
 *  起始点
 */
@property (assign, nonatomic)CGPoint startPoint;


/**
 *  结束点
 */
@property (assign, nonatomic)CGPoint endPoint;

@end


/**
 *  加强版直线标注
 */
@interface GSAnnoLineEx : GSAnnoLine

/**
 *  线的类型，箭头线，虚线和普通线
 */
@property (assign, nonatomic)Byte lineType;

@end

/**
 *  点标注
 */
@interface GSAnnoPoint : GSAnnoBase

/**
 *  点的坐标
 */
@property (assign, nonatomic)CGPoint point;

@end


/**
 *  加强版点标注
 */
@interface GSAnnoPointEx : GSAnnoPoint

/**
 *  点的类型，十字和箭头
 */
@property (assign, nonatomic)Byte pointType;

@end


/**
 *  矩形标注
 */
@interface GSAnnoRect : GSAnnoBase

/**
 *  线的粗心尺寸
 */
@property (assign, nonatomic)Byte lineSize;


/**
 *  线的颜色
 */
@property (strong, nonatomic)UIColor *lineColor;


/**
 *  矩形信息
 */
@property (assign, nonatomic)CGRect rect;

@end


/**
 *  文字标注
 */
@interface GSAnnoText : GSAnnoBase

/**
 *  文字颜色
 */
@property (strong, nonatomic)UIColor *textColor;


/**
 *  文字的字体大小
 */
@property (assign, nonatomic)Byte fontSize;


/**
 *  文本内容
 */
@property (strong, nonatomic)NSString *text;


/**
 *  文字位置起始点
 */
@property (assign, nonatomic)CGPoint point;
@end
/**
 *  橡皮擦标注
 */
@interface GSAnnoCleaner : GSAnnoBase

/**
 *  删除的标注ID
 */
@property (assign, nonatomic)long long removedAnnoID;
@end















