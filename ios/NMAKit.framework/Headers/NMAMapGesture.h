/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@class NMAMapView;

/**
 * The types of gesture that can be performed on an NMAMapView.
 */
typedef NS_OPTIONS(NSInteger, NMAMapGestureType) {
    /** A double tap. */
    NMAMapGestureTypeDoubleTap      = 1 << 0,
    /** A long press. */
    NMAMapGestureTypeLongPress      = 1 << 1,
    /** A pan. */
    NMAMapGestureTypePan            = 1 << 2,
    /** A pinch. */
    NMAMapGestureTypePinch          = 1 << 3,
    /** A tap. */
    NMAMapGestureTypeTap            = 1 << 5,
    /** A two-finger tap. */
    NMAMapGestureTypeTwoFingerTap   = 1 << 7,
    /** All geture types. */
    NMAMapGestureTypeAll            = 0xFF
};

/**
 * Delegate protocol for map gesture handling.
 *
 * This protocol should be implemented by any class which acts as the gesture delegate for a map view
 * or any map subview which needs to receive gestures from the map view.
 *
 * The `NMAMapView` may optionally be provided with a gesture delegate, set via the gestureDelegate
 * property. This delegate can be used to receive events about gestures.
 *
 * @note Methods of this protocol will be called on the main queue.
 */
@protocol NMAMapGestureDelegate<NSObject>

@optional



/**
 * Delegate callback for an NMAMapView tap gesture.
 *
 * @param mapView The `NMAMapView` on which the gesture occurred.
 * @param location The screen location in points at which the gesture occurred.
 */
- (void)mapView:(nonnull NMAMapView *)mapView didReceiveTapAtLocation:(CGPoint)location
NS_SWIFT_NAME(mapViewDidReceiveTap(_:at:));

/**
 * Delegate callback for an `NMAMapView` double-tap gesture.
 *
 * @param mapView The `NMAMapView` on which the gesture occurred.
 * @param location The screen location in points at which the gesture occurred.
 */
- (void)mapView:(nonnull NMAMapView *)mapView didReceiveDoubleTapAtLocation:(CGPoint)location
NS_SWIFT_NAME(mapViewDidReceiveDoubleTap(_:at:));

/**
 * Delegate callback for an `NMAMapView` two finger-tap gesture.
 *
 * @param mapView The `NMAMapView` on which the gesture occurred.
 * @param location The screen location in points at which the gesture occurred.
 */
- (void)mapView:(nonnull NMAMapView *)mapView didReceiveTwoFingerTapAtLocation:(CGPoint)location
NS_SWIFT_NAME(mapViewDidReceiveTwoFingerTap(_:at:));

/**
 * Delegate callback for an `NMAMapView` pan gesture.
 *
 * The translation of a pan gesture is reported as the distance covered by the gesture
 * since the last callback or since the beginning of the gesture. Note that this differs
 * from the behaviour of `UIPanGestureRecognizer`, which reports the total translation
 * since the beginning of the gesture.
 *
 * @param mapView The `NMAMapView` on which the gesture occurred.
 * @param translation The current translation of the pan gesture, in points.
 * @param location The screen location in points at which the gesture occurred.
 */
- (void)mapView:(nonnull NMAMapView *)mapView didReceivePan:(CGPoint)translation atLocation:(CGPoint)location
NS_SWIFT_NAME(mapViewDidReceivePan(_:translation:at:));

/**
 * Delegate callback for an NMAMapView pinch gesture.
 *
 * The current pinch change is measured as the relative distance change of the two touch
 * points since the last pinch callback or the beginning of the gesture. For example, if
 * the pinch value is 1.2, the two touches are 20% farther apart than they were at the time
 * of the last update. Note that this differs from the behaviour of `UIPinchGestureRecognizer`,
 * which reports the total pinch since the beginning of the gesture.
 *
 * @param mapView The `NMAMapView` on which the gesture occurred.
 * @param pinch The current relative pinch change of the gesture.
 * @param location The screen location in points at which the gesture occurred.
 */
- (void)mapView:(nonnull NMAMapView *)mapView didReceivePinch:(float)pinch atLocation:(CGPoint)location
NS_SWIFT_NAME(mapViewDidReceivePinch(_:pinch:at:));

/**
 * Delegate callback for an `NMAMapView` long press gesture.
 *
 * @param mapView The `NMAMapView` on which the gesture occurred.
 * @param location The screen location in points at which the gesture occurred.
 */
- (void)mapView:(nonnull NMAMapView *)mapView didReceiveLongPressAtLocation:(CGPoint)location
NS_SWIFT_NAME(mapViewDidReceiveLongPress(_:at:));

@end
