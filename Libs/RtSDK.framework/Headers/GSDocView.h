//GSDocView.h
//Created by Gaojin Hsu on 3/23/15.
//Copyright (c) 2015 Geensee. All rights reserved.
#import <UIKit/UIKit.h>
#import "GSDocPage.h"
@class GSDocPageDrawingView;
@protocol GSDocViewDelegate <NSObject>
@optional
/**
 文档打开成功
 */
- (void)docViewOpenFinishSuccess:(GSDocPage*)page docID:(unsigned)docID;
/*
 可以撤销的步骤数backNum，可以还原的步骤数nextNum
 */
- (void)docViewStepBackNextEnable:(int)backNum  nextNum:(int)nextNum;
@end
/**
 *  用于显示文档的View
 */
@interface GSDocView : UIScrollView

@property (strong, nonatomic)GSDocPageDrawingView *pageDrawingView;
/**
 *  设置zoomEnabled值，打开和关闭缩放功能，设置为YES表示可以缩放
 */
@property (assign, nonatomic)BOOL zoomEnabled;


/**
 *  设置isVectorScale值，在打开缩放功能的情况下，使用这个这个变量进行缩放方式的选择，yes表示是矢量放大，no表示是一般放大，默认是yes矢量放大
 */
@property (assign, nonatomic)BOOL isVectorScale;

/**
 *  设置文档显示模式，YES为平铺模式，No为正常比例缩放模式
 */
@property (assign, nonatomic)BOOL fullMode;


/**
 *  设置文档文档的显示类型
 */
@property(assign,nonatomic)GSDocShowType  gSDocShowType; //文档的显示类型



/**
 *  TextureCount 如果超过的话，OpenFile返回false, TextureCount =0，不限制
 */
@property (assign, nonatomic)NSUInteger limitTextureCount;

/**
 *  初始化GSDocView对象
 *
 *  @param frame GSDocView对象的矩形区域
 *
 *  @return GSDocView对象
 */
- (id)initWithFrame:(CGRect)frame;



- (void)drawPage:(GSDocPage*)page  step:(int)step docID:(unsigned)docID;


//文档代理
@property (nonatomic, weak)id<GSDocViewDelegate> docDelegate;



@property(nonatomic,strong)GSDocPage* currentPage ;




/**
 *  绘制文档页
 *
 *  @param page 文档页对象
 *  @see GSDocPage
 */
- (void)drawPage:(GSDocPage*)page docID:(unsigned)docID;


/**
 *  在文档上绘制标注
 *
 *  @param anno 标注对象
 *  @param page 文档页对象
 *  @see GSAnnoBase
 *  @see GSDocPage
 */
- (void)drawAnno:(GSAnnoBase*)anno onPage:(GSDocPage*)page;


-(void)goToAnimationStep:(int)step;

/**
 *
 *退出的时候，在leave之前，清理一下文档资源，
 */
-(void)clearPageAndAnno;



/**
 设置背景颜色
 */
-(void)setGlkBackgroundColor:(int)red green:(int)green blue:(int)blue;





/*
 @return 获得当前的显示的截图
 */
-(UIImage*)getCurrentImageView;




/**
 *  重新打开文档，视频进行了全屏的切换
 */
- (void)docViewReOpenFile;


/**
 初始化渲染
 */
- (void)docViewInitRender;



/**
  释放渲染
 */
- (void)docViewFreeRender;


//获得当前打开的文档的总的动画步骤数
- (int)docViewGetCurrentDocAnnoStepCount;

//重置docView
-(void)reSetDocView;


/**
 *  是否是老师的角色,老师可以删所有的标注，学生只能删自己的 YES,是老师,No是学生只能删自己的
 */
@property (assign, nonatomic)BOOL isRoleTeacher;


/**
 *  绘制的时候是否需要显示笔,YES 需要显示，NO,不显示
 */
@property (assign, nonatomic)BOOL isNeedShowPen;


//addAnno
//设置线的颜色
-(void)setupDocAnnoColor:(UIColor*)annoColor;
//设置线框
-(void)setupDocAnnoLineSize:(Byte)LineSize;
//发布端开启标注模式 YES,发布端可以标注，否则不能标注，开启了标注模式，就不再响应放大缩小的功能
@property (assign, nonatomic)BOOL isAnnomationModeOpen;
//发布端开启标注模式的情况下， YES,可以删除选中的标注，否则不能删除
@property (assign, nonatomic)BOOL isCanEraserSelect;
//设置需要绘制那种标注线型
-(void)setupDocAnnoType:(GSDocumentAnnoType)annoType;
//设置线的类型
-(void)setupLineExAnnoType:(LineExAnnoType)lineType;
//设置清除标注的类型
-(void)setupClearAnnoType:(GSDocumentClearAnnoType)clearType;
//设置PointEx的显示类型
-(void)setupPointExType:(GSDocumentPointExAnnoType)pointExType;
@end
