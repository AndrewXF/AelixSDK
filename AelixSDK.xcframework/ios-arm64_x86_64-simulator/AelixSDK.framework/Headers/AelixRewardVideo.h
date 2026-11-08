//
//  AelixRewardVideo.h
//  AelixSDKExample
//
//  Created by xiefei on 2020/4/7.
//  Copyright © 2020 Mercury. All rights reserved.
//

#import "AelixBaseAdapter.h"
#import "AelixError.h"

#import <UIKit/UIKit.h>

#import "AelixConfig.h"

#import "AelixRewardVideoDelegate.h"

@interface AelixRewardVideo : AelixBaseAdapter
/// 广告方法回调代理
@property (nonatomic, weak) id<AelixRewardVideoDelegate> delegate;

/// 展示的controller, 如果不传默认使用keyWindow.rootVC
/// @param placeMentId 广告位id
/// @param viewController viewController
- (nonnull instancetype)initWithPlaceMentId:(NSString *_Nonnull)placeMentId
                              viewController:( UIViewController * _Nonnull)viewController;


@end
