//
//  AelixMedationFeedAdModel.h
//  AelixSDK
//
//  Created by xiefei10 on 10/15/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class AelixMediationMaterialData;
@class AelixBaseAdPosition;
@protocol AelixNativeContainerProtocol;
@interface AelixMedationFeedAdModel : NSObject <AelixNativeContainerProtocol>

/// 是否是模板广告
@property (nonatomic, assign) BOOL isExpressAd;

/// 是否是视频广告
@property (nonatomic, assign) BOOL isVideoAd;

/// 信息流广告数据
@property (nonatomic, strong) AelixMediationMaterialData *feedAdMaterialData;

/// 扩展参数
@property (nonatomic, strong)NSDictionary *extraParams;

@property (nonatomic, strong) id feedAdModel;

// 媒体相关
@property (nonatomic, strong) id adRelate;

- (nonnull instancetype)initWithPosition:(nonnull AelixBaseAdPosition *)adPostion;

/// 绑定点击事件图层
- (void)setContainer:(UIView *)containerView clickableViews:(NSArray *)clickableViews closableViews:(NSArray *)closableViews;
@end

NS_ASSUME_NONNULL_END
