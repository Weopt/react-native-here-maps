/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMAMapObject.h"


NS_ASSUME_NONNULL_BEGIN

/**
 * A container of `NMAMapObject` instances, containers can be added to a `NMAMapView`
 * instance.
 *
 * Applications can, as necessary, add or remove certain
 * types of `NMAMapObject` objects to or from a `NMAMapContainer` (refer to
 * `-addMapObject:` for details). A `NMAMapContainer` is also
 * useful for grouping together `NMAMapObject` objects to allow application operations
 * on entire groups of map objects without requiring an iterative approach to
 * inspecting or changing the state of each individual `NMAMapObject` (e.g. for changing
 * their visibility).
 *
 * You can use the `NMAMapObject.visible` property to control
 * whether the objects in the container are visible. If it's set to YES, then
 * the visibility settings of each map object in the container are used. But
 * unlike other map objects, `NMAMapContainer` does not support the use of
 * visibility masks, so you cannot set container visibility on a zoom level basis.
 *
 * @note The `zOrder` of an `NMAMapObject` instance in a container is relative only to other
 * `NMAMapObject` instances within the same container. Note that containers are derived
 * from `NMAMapObject` also have `zOrder`.
 */
@interface NMAMapContainer : NMAMapObject

/**
 * The `NSArray` of `NMAMapObject` objects within the `NMAMapContainer`.
 */
@property (nonatomic, readonly, copy) NSArray<__kindof NMAMapObject *> *mapObjects;

/**
 * Adds a `NMAMapObject` to the `NMAMapContainer`.
 *
 * Following `NMAMapObject` types can be added to a `NMAMapContainer`:
 *
 * - `NMAMapMarker`
 *
 * - `NMAMapCircle`
 *
 * - `NMAMapPolygon`
 *
 * - `NMAMapPolyline`
 *
 * @note Attempts to add an object twice to the same container will be ignored.
 *
 * @param aMapObject A `NMAMapObject` to be added to the `NMAMapContainer`.
 *
 * @return YES if the `NMAMapObject` was added successfully, NO otherwise.
 *
 * See also `-removeMapObject:`
 */
- (BOOL)addMapObject:(NMAMapObject *)aMapObject
NS_SWIFT_NAME(add(_:));

/**
 * Removes the specified `NMAMapObject` from the `NMAMapContainer`.
 *
 * @note If the specified `NMAMapObject` is not contained within the `NMAMapContainer`,
 * the container will be unchanged.
 *
 * @param aMapObject A `NMAMapObject` to remove from the `NMAMapContainer`.
 *
 * @return YES if the `NMAMapObject` was removed successfully, NO otherwise.
 *
 * See also `-removeAllMapObjects`
 */
- (BOOL)removeMapObject:(NMAMapObject *)aMapObject
NS_SWIFT_NAME(remove(_:));

/**
 * Removes all `NMAMapObject` objects from the `NMAMapContainer`.
 *
 * @return YES if all `NMAMapObject` objects were removed successfully, NO otherwise.
 */
- (BOOL)removeAllMapObjects
NS_SWIFT_NAME(removeAll());

@end

NS_ASSUME_NONNULL_END
