//
//  AelixBaseAdPosition.h
//  AelixSDK
//
//  Created by MS on 2021/10/12.
//

#import <Foundation/Foundation.h>
#import "AelixSupplierModel.h"
#import <UIKit/UIKit.h>

@class AelixSDKSupplier;
@protocol AelixAdapterDelegate;
@class AelixAdDataJsonBindingModel;

NS_ASSUME_NONNULL_BEGIN

@interface AelixBaseAdPosition : NSObject
@property (nonatomic, assign) NSInteger tag;// 标记并行渠道为了找到响应的adapter

@property (nonatomic, assign) NSInteger type;// 1 bidding or  2 waterfall

@property (nonatomic, assign) NSInteger price;// 价格 for waterfall

@property (nonatomic, strong) AelixAdDataJsonBindingModel *confiModel;

@property (nonatomic, weak) UIViewController *controller;

/// 内部竞价delegate
@property(nonatomic, weak) id<AelixAdapterDelegate> priceRuledelegate;

//@property (nonatomic, strong) AelixSDKSupplier *supplier;


- (instancetype)initWithSupplier:(AelixSDKSupplier *)supplier adspot:(id)adspot;

- (void)supplierStateLoad;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
 */
- (NSInteger)eCPM;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
 */
- (NSInteger)pubPrice;


- (void)loadAd;

- (void)showAd;

- (void)deallocAdapter;

- (AelixSDKSupplier *)getCurrentSupplier;

/// 信息流广告绑定点击事件图层
- (void)setContainer:(UIView *)containerView clickableViews:(NSArray *)clickableViews closableViews:(NSArray *)closableViews;

@end

NS_ASSUME_NONNULL_END
