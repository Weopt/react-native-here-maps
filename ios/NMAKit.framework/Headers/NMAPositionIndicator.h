/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
@class UIColor;


/**
 * Used to provide a visual indication of the user's current position.
 *
 * Each instance of `NMAMapView` automatically has a `NMAPositionIndicator` created
 * for it. The position indicator is hidden by default; it can be displayed by
 * change its visible property to YES.
 *
 * By default, the position indicator displays an `NMAMapMarker` showing a green
 * circle.
 *
 * The accuracy of the current position is indicated by a circle surrounding the
 * indicator object. The visibility of the accuracy indicator is controlled via
 * the `accuracyIndicatorVisible` property, and its color may be changed by setting
 * the `accuracyIndicatorColor`.
 *
 * @note The NMAPositionIndicator requires 'NMAPositioningManager' position updates
 * to function correctly, and will automatically start the positioning service
 * when required.
 */
@interface NMAPositionIndicator : NSObject

/**
 * Indicates whether the NMAPositionIndicator is visible.
 *
 * @note The getter is `isVisible`.
 *
 * @note Setting visible to YES will start NMAPositioningManager positioning
 * if it is not already active.
 */
@property (nonatomic, getter = isVisible) BOOL visible;

/**
 * Indicates whether the NMAPositionIndicator accuracy indicator
 * (the surrounding circle) is visible.
 *
 * @note The getter is isAccuracyIndicatorVisible.
 */
@property (nonatomic, getter = isAccuracyIndicatorVisible) BOOL accuracyIndicatorVisible;

/**
 * The color of the accuracy indicator circle.
 */
@property (nonnull, nonatomic) UIColor *accuracyIndicatorColor;

@end
