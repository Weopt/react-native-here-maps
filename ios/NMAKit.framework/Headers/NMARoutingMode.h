/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * Represents values describing different routing types.
 */
typedef NS_ENUM(NSUInteger, NMARoutingType) {
    /** Search for the shortest route, taking road conditions and restrictions into account (minimizes travel distance). */
    NMARoutingTypeShortest = 0,
    /** Search for the fastest route, taking road conditions and restrictions into account (minimizes travel time). */
    NMARoutingTypeFastest = 1
};

/**
 * Represents values describing different transport modes, the mode of
 * transportation a person will be using to travel a route (e.g. a car).
 */
typedef NS_ENUM(NSUInteger, NMATransportMode) {
    /** A car is being used as the mode of transportation. */
    NMATransportModeCar = 0,
    /** Walking is being used as the mode of transportation. */
    NMATransportModePedestrian = 1,
};

/**
 * Represents values describing routing options that can be used to enforce
 * special conditions on a calculated route.
 */
typedef NS_OPTIONS(NSUInteger, NMARoutingOption) {
    /**
     * The routing engine will avoid links that are part of a boat ferry passage.
     */
    NMARoutingOptionAvoidBoatFerry          = 1 << 0,

    /**
     * The routing engine will avoid links that are part of a dirt road.
     */
    NMARoutingOptionAvoidDirtRoad           = 1 << 1,

    /**
     * The routing engine will avoid links that are part of a highway.
     *
     * @note Effective only when used with `NMATransportModeCar`.
     */
    NMARoutingOptionAvoidHighway            = 1 << 2,

    /**
     * The routing engine will avoid links that go through a park.
     *
     * @note Effective only when used with `NMATransportModePedestrian`.
     */
    NMARoutingOptionAvoidPark               = 1 << 3,

    /**
     * The routing engine will avoid links that are part of a toll road.
     *
     * @note Effective only when used with `NMATransportModeCar`.
     */
    NMARoutingOptionAvoidTollRoad           = 1 << 4,

    /**
     * The routing engine will avoid links that are part of a tunnel.
     *
     * @note Effective only when used with `NMATransportModeCar`.
     */
    NMARoutingOptionAvoidTunnel             = 1 << 5,

    /**
     * The routing engine will avoid links that are part of a motorail train or car shuttle train passage.
     */
    NMARoutingOptionAvoidCarShuttleTrain    = 1 << 6,

    /**
     * The routing engine will avoid HOV/Carpool roads.
     */
    NMARoutingOptionAvoidCarpool            = 1 << 7

};

/**
 * Represents a model of the parameters required for one route
 * calculation, encapsulating parameters such as:
 *
 * - The `NMARoutingType`
 *
 * - The `NMATransportMode`
 *
 * - `NMARoutingOption` (specify 0 for none)
 */
@interface NMARoutingMode : NSObject

/**
 * The `NMARoutingType` for the `NMARoutingMode`.
 *
 * @note The default value is `NMARoutingTypeShortest`.
 */
@property (nonatomic) NMARoutingType routingType;

/**
 * The `NMATransportMode` for the `NMARoutingMode`.
 *
 * @note The default value is `NMATransportModeCar`.
 */
@property (nonatomic) NMATransportMode transportMode;

/**
 * The OR-ed `NMARoutingOption` values for the `NMARoutingMode`.
 *
 * @note The default value is 0 (no options selected).
 */
@property (nonatomic) NSUInteger routingOptions;

/**
 * The desired departure time.
 */
@property (nonatomic, strong) NSDate *departureTime;

/**
 * The maximum number of alternative routes to calculate. The actual
 * number calculated may be less. The default value is 1.
 *
 * @note Only one result will be returned for routes with more than two waypoints.
 */
@property (nonatomic) NSUInteger resultLimit;

/**
 * Initializes a `NMARoutingMode` instance with default values.
 */
- (id)init;

/**
 * Initializes a `NMARoutingMode` instance with the specified routing
 * parameters.
 *
 * @param routingType - A routing type (see #NMARoutingType)
 * @param transportMode - A transport mode (see #NMATransportMode)
 * @param routingOptions - An OR-ed combination of routing options (see #NMARoutingOption).
 * @return The `NMARoutingMode` object, or nil if initialization failed
 */
- (id)initWithRoutingType:(NMARoutingType)routingType transportMode:(NMATransportMode)transportMode routingOptions:(NSUInteger)routingOptions;

@end
