//
//  AelixMediationDataManager.h
//  AelixSDK
//
//  Created by xiefei10 on 2025/5/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol AelixNativeContainerProtocol;
@class AelixNativeExpressView;

@interface AelixMediationDataManager : NSObject

@property (nonatomic, strong) NSArray<AelixNativeExpressView *> *feedAdViews;

+ (instancetype)shareInstance;

/// 绑定点击事件图层
- (void)setContainer:(UIView *)containerView clickableViews:(NSArray *)clickableViews closableViews:(NSArray *)closableViews;

@end

NS_ASSUME_NONNULL_END
