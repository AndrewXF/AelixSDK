//
//  AelixInterstitial.h
//  AelixSDKExample
//
//  Created by xiefei on 2020/4/7.
//  Copyright © 2020 Mercury. All rights reserved.
//

#import "AelixBaseAdapter.h"
#import "AelixInterstitialDelegate.h"
#import "AelixError.h"

#import <UIKit/UIKit.h>


@interface AelixInterstitial : AelixBaseAdapter
/// 广告方法回调代理
@property (nonatomic, weak) id<AelixInterstitialDelegate> delegate;

/// 展示的controller, 如果不传默认使用keyWindow.rootVC
/// @param placeMentId 广告位id
/// @param viewController viewController
- (nonnull instancetype)initWithPlaceMentId:(NSString *_Nonnull)placeMentId
                 viewController:(UIViewController * _Nonnull)viewController;

/// 在展示时传入viewController，优先使用此方法传入的VC
/// @param viewController 用于展示广告的根视图控制器
- (void)showAdFromRootViewController:(UIViewController * _Nonnull)viewController;

// 新增方法，便于开发者手动移除
- (void)removeAdView;

@end

