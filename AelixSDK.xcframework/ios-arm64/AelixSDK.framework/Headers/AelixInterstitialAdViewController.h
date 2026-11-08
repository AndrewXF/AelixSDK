//
//  AelixInterstitialAdViewController.h
//  AelixSDK
//
//  Created by Aelix on 2026/8/16.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AelixInterstitialAdViewController : UIViewController

/// 广告展示完成回调，用于通知外部可以调用三方SDK的show方法
@property (nonatomic, copy, nullable) void(^adReadyBlock)(void);

/// 广告关闭回调，用于通知外部dismiss
@property (nonatomic, copy, nullable) void(^adCloseBlock)(void);

@end

NS_ASSUME_NONNULL_END
