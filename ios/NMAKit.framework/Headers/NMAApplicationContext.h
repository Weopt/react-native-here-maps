/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoCoordinates;

NS_ASSUME_NONNULL_BEGIN

/**
 * Use this interface to set mandatory authentication crendentials.
 *
 * @note YOU MUST SET AUTHENTICATION CREDENTIALS in order to use the APIs
 * contained within this SDK. Some APIs may appear to work without valid
 * credentials but they may stop functioning in the near future when server side
 * configurations change, so please obtain and use valid credentials.
 */
@interface NMAApplicationContext : NSObject

/**
 * Sets the mandatory HERE Authentication Credentials.
 *
 * These credentials MUST be set in order to use the APIs in this SDK. It is
 * recommended to set the credentials in your application delegate, such as in
 * `[UIApplicationDelegate didFinishLaunchingWithOptions]`.
 */
+ (void)setAppId:(NSString *)appId appCode:(NSString *)appCode
NS_SWIFT_NAME(set(appId:appCode:));

/**
 * Returns the SDK version.
 * @return The SDK verion.
 */
+ (NSString *)sdkVersion;

/**
 * Sets initial map center with specified `NMAGeoCoordinates`.
 */
+ (void)setMapCenter:(nonnull NMAGeoCoordinates *)initialCenter;

@end

NS_ASSUME_NONNULL_END
