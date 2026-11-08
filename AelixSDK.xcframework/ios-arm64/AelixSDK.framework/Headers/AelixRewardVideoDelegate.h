//
//  AelixRewardVideoProtocol.h
//  AelixSDKDev
//
//  Created by xiefei on 2020/4/9.
//  Copyright © 2020 bayescom. All rights reserved.
//

#ifndef AelixRewardVideoProtocol_h
#define AelixRewardVideoProtocol_h
#import "AelixBaseDelegate.h"
@protocol AelixRewardVideoDelegate <AelixBaseDelegate>
@optional

/// 广告视频播放完成
- (void)aelixRewardVideoAdDidPlayFinish;

/// 广告到达激励时间
- (void)aelixRewardVideoAdDidRewardEffective;

@end

#endif
