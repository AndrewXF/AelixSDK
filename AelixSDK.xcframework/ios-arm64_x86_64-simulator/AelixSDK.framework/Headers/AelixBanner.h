//
//  AelixBanner.h
//  AelixSDKExample
//
//  Created by xiefei on 2020/4/7.
//  Copyright © 2020 Mercury. All rights reserved.
//

#import "AelixBaseAdapter.h"
#import "AelixBannerDelegate.h"
#import <UIKit/UIKit.h>
#import "AelixError.h"

@protocol AelixBannerDelegate;

@interface AelixBanner : AelixBaseAdapter
/// 广告方法回调代理
@property (nonatomic, weak) id<AelixBannerDelegate> delegate;

@property(nonatomic, weak) UIView *adContainer;

@property(nonatomic, assign) int refreshInterval;

- (nonnull instancetype)initWithJsonDic:(nonnull NSDictionary *)jsonDic
                    adContainer:(nonnull UIView *)adContainer
                 viewController:(nonnull UIViewController *)viewController;

@end
