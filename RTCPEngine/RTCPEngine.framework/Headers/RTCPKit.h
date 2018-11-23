//
//  RTCPKit.h
//  RTMeetEngine
//
//  Created by derek on 2017/6/9.
//  Copyright © 2017年 EricTao. All rights reserved.
//

#ifndef RTCPKit_h
#define RTCPKit_h

#import <Foundation/Foundation.h>
#import "RTCPKitDelegate.h"
#import <UIKit/UIKit.h>
#import "RTCPOption.h"

@interface RTCPKit : NSObject

/**
 初始化

 @param delegate RTCP相关回调代理
 @param option 配置信息
 @return RTCP工具
 */
- (instancetype)initWithDelegate:(id<RTCPKitDelegate>)delegate;

#pragma mark Common function
/**
 设置本地视频采集窗口
 
 @param render 视频显示对象
 说明：该方法用于本地视频采集。
 */
- (void)setLocalVideoCapturer:(UIView*)render withOption:(RTCPOption*)option;
/**
 设置本地显示模式
 
 @param eVideoRenderMode 显示模式
 说明：默认：AnyRTCVideoRenderScaleAspectFill，等比例填充视图模式
 */
- (void)updateLocalVideoRenderModel:(AnyRTCVideoRenderMode)eVideoRenderMode;

/**
 设置本地音频是否传输
 
 @param bEnable 打开或关闭本地音频
 说明：yes为传输音频,no为不传输音频，默认传输
 */
- (void)setLocalAudioEnable:(bool)bEnable;

/**
 设置本地视频是否传输
 
 @param bEnable 打开或关闭本地视频
 说明：yes为传输视频，no为不传输视频，默认视频传输
 */
- (void)setLocalVideoEnable:(bool)bEnable;

/**
 获取本地音频传输是否打开
 
 @return 音频传输与否
 */
- (BOOL)localAudioEnabled;

/**
 获取本地视频传输是否打开
 
 @return 视频传输与否
 */
- (BOOL)localVideoEnabled;
/**
 设置扬声器开关

 @param bOn 设置YES,打开扬声器，设置NO,关闭扬声器
 说明：默认打开扬声器
 */
- (void)setSpeakerOn:(bool)bOn;

/**
 切换前后摄像头
 说明:切换本地前后摄像头。
 */
- (void)switchCamera;

/**
 设置本地前置摄像头镜像是否打开
 
 @param bEnable YES为打开，NO为关闭
 @return 镜像成功与否
 */
- (BOOL)setFontCameraMirrorEnable:(BOOL)bEnable;

/**
 前置摄像头是否镜像

 @return 是否镜像：默认:YES
 */
- (BOOL)fontCameraMirror;

#pragma mark RTCP function for media
/**
 发布媒体

 @param nMediaType 0:视频 1:音频
 @param strAnyRTCId 该参数可以随意填写，但是不能为空,如果发布成功，SDK会给你分配一个频道ID
 */
- (void)publish:(int)nMediaType withAnyRtcId:(NSString*)strAnyRTCId;
/**
 *  取消发布媒体
 */
- (void)unPublish;

/**
 订阅视频

 @param strRtcpId 订阅视频的频道Id
 */
- (void)subscribe:(NSString*)strRtcpId;

/**
 取消订阅 媒体流

 @param strRtcpId 媒体频道Id
 */
- (void)unSubscribe:(NSString*)strRtcpId;

/**
 设置显示其他人的视频窗口
 
 @param strRtcpId RTCP服务生成的通道Id (用于标识通道，每次发布随机生成)；
 @param render 对方视频的窗口，本地设置；
 说明：该方法用于订阅成功通后，视频即将显示的回调中（onRTCOpenVideoRender）使用。
 */
- (void)setRTCVideoRender:(NSString*)strRtcpId andRender:(UIView*)render;

/**
 设置其他人显示模式
 
 @param eVideoRenderMode 显示模式
 说明：默认：AnyRTCVideoRenderScaleAspectFill，等比例填充视图模式
 */
- (void)updateRTCVideoRenderModel:(AnyRTCVideoRenderMode)eVideoRenderMode;

/**
 关闭离开
 */
- (void)close;


#pragma mark - 音视频流信息监测

/**
 设置音频检测
 
 @param bOn 是否开启音频检测
 说明：默认打开
 */
- (void)setAudioActiveCheck:(bool)bOn;

/**
 获取音频检测是否打开
 */
- (BOOL)audioActiveCheck;

/**
 设置视频网络状态是否打开
 
 @param bEnable YES:打开;NO:关闭
 说明:默认关闭
 */
- (void)setNetworkStatus:(BOOL)bEnable;

/**
 获取当前视频网络状态是否打开
 
 @return 获取网络视频状态
 */
- (BOOL)networkStatusEnabled;

@end

#endif  // RTCPKit_h
