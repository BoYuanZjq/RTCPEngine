//
//  RTCPKitDelegate.h
//  RTMeetEngine
//
//  Created by derek on 2017/6/9.
//  Copyright © 2017年 EricTao. All rights reserved.
//

#ifndef RTCPKitDelegate_h
#define RTCPKitDelegate_h
#import <UIKit/UIKit.h>

@protocol RTCPKitDelegate <NSObject>

@optional
/**
 发布媒体成功回调

 @param strRtcpId 通道Id
 */
- (void)onPublishOK:(NSString *)strRtcpId withLiveInfo:(NSString*)strLiveInfo;

/**
 发布媒体失败回调

 @param nCode 失败的code值
 */
- (void)onPublishFailed:(int)nCode;

/**
 订阅通道成功的回调

 @param strRtcpId 通道Id
 */
- (void)onSubscribeOK:(NSString*)strRtcpId;

/**
 订阅通道失败的回调

 @param strRtcpId 通道Id
 @param nCode 失败的code值
 */
- (void)onSubscribeFailed:(NSString*)strRtcpId intCode:(int)nCode;

/**
 订阅后视频即将显示的回调

 @param strRtcpId 通道Id
 */
- (void)onRTCOpenVideoRender:(NSString*)strRtcpId;

/**
 订阅的视频离开的回调

 @param strRtcpId 通道Id
 */
- (void)onRTCCloseVideoRender:(NSString*)strRtcpId;

#pragma mark - 视频第一针的回调
/**
 本地视频第一针

 @param videoView 本地视频
 @param size 视频窗口大小
 */
-(void)onRTCFirstLocalVideoFrame:(UIView*)videoView videoSize:(CGSize)size;

/**
 远程视频第一针
 
 @param videoView 本地视频
 @param size 视频窗口大小
 */
-(void)onRTCFirstRemoteVideoFrame:(UIView*)videoView videoSize:(CGSize)size;

#pragma mark - 视频大小变化回调
/**
 本地/远程窗口大小的回调

 @param videoView 视频窗口
 @param size 视频窗口大小
 */
- (void)onRTCVideoViewChanged:(UIView*)videoView didChangeVideoSize:(CGSize)size;

@end


#endif /* RTCPKitDelegate_h */
