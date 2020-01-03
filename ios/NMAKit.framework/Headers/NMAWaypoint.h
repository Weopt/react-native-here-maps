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
 * Waypoints define a route's stopovers, including its start point it's
 * destination point and any points in between.
 *
 * Each waypoint represents a position along an `NMARoute`, this includes:
 *
 * - The original (input) coordinates specified as part of a search request
 *
 * or
 *
 * - The adjusted coordinates used to calculate the route. For example, the routing
 * engine may adjust the input coordinates so that they fall upon a road. The process of
 * adjusting the coordinates is known as map matching.
 *
 * @note A waypoint can represent the result of map matching.
 */
@interface NMAWaypoint : NSObject

/**
 * The `NMAGeoCoordinates` representing the original position of the
 * `NMAWaypoint` - typically the coordinates passed into a routing request.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *originalPosition;

/**
 * The `NMAGeoCoordinates` representing the mapped position of the
 * `NMAWaypoint` - the coordinates adjusted by the routing request.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *mappedPosition;

@end

NS_ASSUME_NONNULL_END
