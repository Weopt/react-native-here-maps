/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class NMAGeoPosition;


/**
 * NMAPositioningManager Notifications */

/**
 * Indicates that the NMAPositioningManager currentPosition has changed.
 *
 * In order to receive this notification, register with `NSNotificationCenter` using this notification name and the
 * `[NMAPositioningManager sharedPositioningManager]` instance as the object (notification sender).
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAPositioningManagerDidUpdatePositionNotification;

/**
 * Indicates that the NMAPositioningManager currentPosition has been lost.
 *
 * In order to receive this notification, register with NSNotificationCenter using this notification name and the
 * `[NMAPositioningManager sharedPositioningManager]` instance as the object (notification sender).
 */
FOUNDATION_EXPORT NSString *const _Nonnull NMAPositioningManagerDidLosePositionNotification;

/**
 * Manages positioning services for the NMA SDK.
 *
 * This is a singleton class and thus should never be retained, released, or
 * instantiated. The singleton instance is accessed via the
 * sharedPositioningManager method.
 *
 * Use the `startPositioning` method to begin tracking position, and `stopPositioning`
 * to stop. By default, position data comes from `CLLocationManager`.
 *
 * Only one type of position is available from the positioning manager in Starter Edition:
 * the raw position. The raw position is simply passed straight through from
 * the positioning manager's data source. If the position is lost, 
 * a `NMAPositioningManagerDidLosePositionNotification` is sent.
 *
 * @note Certain other SDK features may require the use of the positioning manager;
 * if these features are accessed, the positioning manager will be enabled
 * automatically (for example, the `NMAPositionIndicator` of a `NMAMapView`).
 *
 * @note `NMAPositioningManager` requires valid authentication credentials to be set via
 * `NMAApplicationContext`. If valid credentials are not present the API may not
 * function correctly or may stop functioning correctly in the future when server
 * side configurations change.
 */
@interface NMAPositioningManager : NSObject

/**
 * Returns the `NMAPositioningManager` singleton instance.
 *
 * @note Use this method to obtain a `NMAPositioningManager` instance. Do not call
 * init directly.
 *
 * @return shared `NMAPositioningManager` instance
 */
+ (nonnull NMAPositioningManager *)sharedPositioningManager;

/**
 * Indicates whether the `NMAPositioningManager` is currently broadcasting
 * position updates.
 */
@property (nonatomic, readonly, getter = isActive) BOOL active;

/**
 * The latest unprocessed position.
 *
 * @note Will be nil if the latest update did not return a valid position.
 */
@property (nullable, nonatomic, readonly) NMAGeoPosition *rawPosition;

/**
 * The best estimate for the user's current position.
 *
 * The `currentPosition` will be equal to the `rawPosition` in the Starter Edition.
 *
 * @note Will be nil if the positioning manager is not active or does not
 * have a valid position.
 */
@property (nullable, nonatomic, readonly) NMAGeoPosition *currentPosition;

/**
 * Enables position broadcasting.
 *
 * @return YES if positioning was successfully started, NO if positioning
 * was already in progress or if positioning failed to start.
 */
- (BOOL)startPositioning;

/**
 * Disables position broadcasting.
 */
- (void)stopPositioning;

@end
