//
//  AelixFullScreenVideoDelegate.h
//  AelixSDKDev
//
//  Created by xiefei on 2020/4/13.
//  Copyright © 2020 bayescom. All rights reserved.
//

#ifndef AelixFullScreenVideoDelegate_h
#define AelixFullScreenVideoDelegate_h
#import "AelixBaseDelegate.h"
@protocol AelixFullScreenVideoDelegate <AelixBaseDelegate>
@optional
/// 视频播放完成
- (void)aelixFullScreenVideoOnAdPlayFinish;


@end

#endif
