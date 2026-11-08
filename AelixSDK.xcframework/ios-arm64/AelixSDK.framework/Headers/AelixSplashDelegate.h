//
//  AelixSplashProtocol.h
//  AelixSDKExample
//
//  Created by xiefei on 2020/4/8.
//  Copyright © 2020 Mercury. All rights reserved.
//

#ifndef AelixSplashProtocol_h
#define AelixSplashProtocol_h
#import "AelixBaseDelegate.h"
@protocol AelixSplashDelegate <AelixBaseDelegate>
@optional
/// 广告点击跳过
- (void)aelixSplashOnAdSkipClicked;

/// 广告倒计时结束回调 -不同广告可能不回调，仅供参考
- (void)aelixSplashOnAdCountdownToZero;


@end

#endif 
