//
//  AelixNativeExpressProtocol.h
//  AelixSDKDev
//
//  Created by xiefei on 2020/4/9.
//  Copyright © 2020 bayescom. All rights reserved.
//

#ifndef AelixNativeExpressProtocol_h
#define AelixNativeExpressProtocol_h
#import "AelixCommonDelegate.h"
@class AelixNativeExpressView;
@protocol AelixNativeExpressDelegate <AelixCommonDelegate>
@optional
/// 广告数据拉取成功
- (void)aelixNativeExpressOnAdLoadSuccess:(nullable NSArray<AelixNativeExpressView *> *)views;

/// 广告曝光
- (void)aelixNativeExpressOnAdShow:(nullable AelixNativeExpressView *)adView;

/// 广告点击
- (void)aelixNativeExpressOnAdClicked:(nullable AelixNativeExpressView *)adView;

/// 广告渲染成功
- (void)aelixNativeExpressOnAdRenderSuccess:(nullable AelixNativeExpressView *)adView;

/// 广告渲染失败
- (void)aelixNativeExpressOnAdRenderFail:(nullable AelixNativeExpressView *)adView;

/// 广告被关闭 (注: 百度广告(百青藤), 不支持该回调, 若使用百青藤,则该回到功能请自行实现)
- (void)aelixNativeExpressOnAdClosed:(nullable AelixNativeExpressView *)adView;

@end

#endif
