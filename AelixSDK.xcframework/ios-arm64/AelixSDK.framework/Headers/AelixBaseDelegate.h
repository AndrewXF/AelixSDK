//
//  AelixBaseDelegate.h
//  Pods
//
//  Created by MS on 2020/12/9.
//

#ifndef AelixBaseDelegate_h
#define AelixBaseDelegate_h
#import "AelixCommonDelegate.h"

// 策略相关的代理
@protocol AelixBaseDelegate <AelixCommonDelegate>

@optional

/// 广告曝光成功
- (void)aelixSDKExposured;

/// 广告点击回调
- (void)aelixSDKClicked;

/// 广告数据请求成功后调用
- (void)aelixUnifiedViewDidLoad;

/// 广告数据请求失败
- (void)aelixUnifiedViewDidLoadFailed;

/// 广告关闭的回调
- (void)aelixSDKDidClose;

@end

#endif /* AelixBaseDelegate_h */
