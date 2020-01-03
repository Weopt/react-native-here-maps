/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
@class NMAMapContainer;

/**
 * Defines types of `NMAMapObject` objects that an application can add to
 * a map.
 */
typedef NS_ENUM(NSUInteger, NMAMapObjectType) {
    /** A map marker. */
    NMAMapObjectTypeMarker,
    /** A polygon. */
    NMAMapObjectTypePolygon,
    /** A polyline. */
    NMAMapObjectTypePolyline,
    /** A route. */
    NMAMapObjectTypeRoute,
    /** A map container to hold other map objects. */
    NMAMapObjectTypeContainer,
    /** A circle. */
    NMAMapObjectTypeCircle,
    /** A reserved object. */
    NMAMapObjectTypeReserved,
    /** An unknown object. */
    NMAMapObjectTypeUnknown
};

/**
 * Represents a base class for all visible objects shown on a map.
 *
 * This class serves as a generalization (or base) for several more specified map object types,
 * bundling their common properties.
 * Objects implementing this interface can be grouped within a `NMAMapContainer` by way of
 * the `-[NMAMapContainer addMapObject:]` method.
 *
 * @note This class serves as a base class to other map object types and should not be instantiated directly.
 */
@interface NMAMapObject : NSObject

/**
 * The `NSUInteger` z-index (stacking order) for the `NMAMapObject` within its
 * containing `NMAMapContainer`, or within the `NMAMapView` if the object was added to
 * `NMAMapView` directly.
 *
 * Must be in the range `NMAMapObjectMinimumZIndex`..`NMAMapObjectMaximumZIndex`. The
 * property will be clamped to this range if invalid values are specified.
 *
 * @note Objects with the highest value are placed at the top of the stacking order.
 */
@property (nonatomic) NSUInteger zIndex;

/**
 * Indicates whether the visibility of the `NMAMapObject` on the map is enabled.
 * Whether the `NMAMapObject` is actually visible depends on whether the visible
 * mask is set for the desired zoom level.
 *
 * @note The getter is `isVisible`.
 *
 * @note This property is independent but takes priority over the per-zoom level
 * settings. For example,
 * you can call
 * \code
 * [setVisible:YES fromZoomLevel:0 toZoomLevel:6]
 * \endcode
 * and then set `visible` to NO, and the
 * object will not appear on the map. Setting `visible` to YES will then cause
 * the object to be visible in zoom levels 0 to 6.
 */
@property (nonatomic, getter = isVisible) BOOL visible;

/**
 * The map object's type.
 */
@property (nonatomic, readonly) NMAMapObjectType type;

/**
 * The map object's container. This will be nil if the map object does not belong
 * to a container or was added to an `NMAMapView` directly.
 */
@property (nullable, nonatomic, readonly, weak) NMAMapContainer *parent;

/**
 * Returns the unique ID value of the `NMAMapObject`.
 *
 * @note This value will be consistent for the lifetime of the object.
 *
 * @return The unique ID
 */
- (NSUInteger)uniqueId;

/**
 * Determines whether the map object is set to visible at the specified zoom level
 * when the map object's visible property is set to YES.
 *
 * @param zoomLevel for checking whether the map object is visible. Will be clamped to
 *        the range `NMAMapViewMinimumZoomLevel`..`NMAMapViewMaximumZoomLevel`. This
 *        is rounded off to the nearest integer. e.g. 14.1 means [14..15)
 */
- (BOOL)isVisibleAtZoomLevel:(float)zoomLevel
NS_SWIFT_NAME(isVisible(atZoomLevel:));

/**
 * Sets the visibility of the map object at a specific zoom level.
 *
 * This method can only be used after the `NMAMapObject` has been added to the
 * map. By default, the visibility for all zoom levels are set to YES.
 *
 * @param visible indicates whether the map object should be visible.
 * @param zoomLevel for applying the specified visibility. Will be clamped to
 *        the range `NMAMapViewMinimumZoomLevel`..`NMAMapViewMaximumZoomLevel`. This
 *        is rounded off to the nearest integer. e.g. 14.1 means [14..15)
 *
 * @note This will take effect if/when the map object's `.visibile` property is set YES.
 */
- (void)setVisibility:(BOOL)visible atZoomLevel:(float)zoomLevel
NS_SWIFT_NAME(setVisibility(_:atZoomLevel:));

/**
 * Sets the visibility of the map object for a range of zoom levels.
 *
 * This method can only be used after the `NMAMapObject` has been added to the
 * map. By default, the map object is visible at all zoom levels. Each zoom level
 * retains its own visibility state.
 *
 * If you make the following calls:
 *
 * \code
 * #1. visible property is set to YES
 *     |111111111111111111111|
 * #2. setVisible:NO fromZoomLevel:10 toZoomLevel:16
 *                10    16
 *               |0000000|
 * #3. setVisible:YES fromZoomLevel:5 toZoomLevel:13
 *           5       13
 *          |111111111|
 * #4. setVisible:NO atZoomLevel:20
 * \endcode
 *
 * The result is a map object that is invisible at zoom levels 14-16 and 20 and
 * visible at the others.
 *
 * \code
 *           5        14 17 20
 *     |111111111111110001110|
 * \endcode
 *
 * @param visible indicates whether the map object should be visible.
 * @param fromZoomLevel clamped to range `NMAMapViewMinimumZoomLevel`..`NMAMapViewMaximumZoomLevel`Ø,
 * rounded off to the nearest integer.
 * @param toZoomLevel clamped to range `NMAMapViewMinimumZoomLevel`..`NMAMapViewMaximumZoomLevel`,
 * rounded off to the nearest integer.
 *
 * @note This will take effect if/when the map object's `visibile` property is set YES.
 */
- (void)setVisibility:(BOOL)visible fromZoomLevel:(float)fromZoomLevel toZoomLevel:(float)toZoomLevel
NS_SWIFT_NAME(setVisibility(_:fromZoomLevel:toZoomLevel:));

@end
