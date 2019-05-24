//
//  ARRtcpOption.h
//  RTCPEngine
//
//  Created by zjq on 2019/1/17.
//  Copyright © 2019 MaoZongWu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ARObjects.h"

NS_ASSUME_NONNULL_BEGIN

@interface ARRtcpOption : NSObject

/**
 使用默认配置生成一个 ARRtcpOption 对象
 
 @return 生成的 ARRtcpOption 对象
 */
+ (nonnull ARRtcpOption *)defaultOption;

/**
 视频配置项
 */
@property (nonatomic, strong) ARVideoConfig *videoConfig;

/**
 是否需要camera数据：默认为NO;
 说明：设置YES:将会有onRTCCaptureVideoPixelBuffer回调
 */
@property (nonatomic, assign) BOOL needCarmeraData;

@end

NS_ASSUME_NONNULL_END
