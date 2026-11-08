//
//  AelixNativeExpress.h
//  AelixSDKDev
//
//  Created by xiefei on 2020/4/13.
//  Copyright © 2020 bayescom. All rights reserved.
//

#import "AelixBaseAdapter.h"
#import "AelixError.h"
#import <UIKit/UIKit.h>
#import "AelixNativeExpressDelegate.h"


@interface AelixNativeExpress : AelixBaseAdapter
/// 广告方法回调代理
@property (nonatomic, weak) id<AelixNativeExpressDelegate> delegate;
@property (nonatomic, assign) CGSize adSize;
/// 是否模版
@property (nonatomic, assign) BOOL isTemplate;

/// 构造函数
/// @param placeMentId 广告位id
/// @param viewController viewController
/// @param size 尺寸
- (nonnull instancetype)initWithPlaceMentId:(NSString *_Nonnull)placeMentId
                 viewController:(UIViewController * _Nonnull)viewController
                         adSize:(CGSize)size;

@end

