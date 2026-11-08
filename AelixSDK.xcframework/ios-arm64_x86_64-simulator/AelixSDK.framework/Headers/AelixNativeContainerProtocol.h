//
//  AelixSplashProtocol.h
//  AelixSDKExample
//
//  Created by xiefei on 2020/4/8.
//  Copyright © 2020 Mercury. All rights reserved.
//

#ifndef AelixSplashProtocol_h
#define AelixSplashProtocol_h
#import <UIKit/UIKit.h>
@protocol AelixNativeContainerProtocol
@optional
/// 绑定点击事件图层
- (void)setContainer:(UIView *)containerView clickableViews:(NSArray *)clickableViews closableViews:(NSArray *)closableViews;

@end

#endif 
