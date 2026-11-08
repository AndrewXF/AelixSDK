//
//  AelixFullScreenVideo.h
//  AelixSDKDev
//
//  Created by xiefei on 2020/4/13.
//  Copyright © 2020 bayescom. All rights reserved.
//

#import "AelixBaseAdapter.h"
#import <UIKit/UIKit.h>
#import "AelixError.h"

@protocol AelixFullScreenVideoDelegate;

@interface AelixFullScreenVideo : AelixBaseAdapter
/// 广告方法回调代理
@property (nonatomic, weak) id<AelixFullScreenVideoDelegate> delegate;

- (nonnull instancetype)initWithJsonDic:(nonnull NSDictionary *)jsonDic
                 viewController:(nonnull UIViewController *)viewController;

@end

