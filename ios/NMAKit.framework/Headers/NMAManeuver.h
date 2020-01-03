/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMARoutingMode.h"

@class NMAGeoCoordinates;
@class NMAGeoBoundingBox;
@class NMASignpost;
@class NMARouteElement;

/**
 * Defines types of actions for a `NMAManeuver`.
 */
typedef NS_ENUM(NSInteger, NMAManeuverAction) {
    /** An undefined action. */
    NMAManeuverActionUndefined = 0,             // 0
    /** An indication there is no action associated with the maneuver. */
    NMAManeuverActionNone,                      // 1
    /** An action that indicates the end of a route. */
    NMAManeuverActionEnd,                       // 2
    /** An action that indicates a stopover. */
    NMAManeuverActionStopover,                  // 3
    /** An action that indicates a junction. */
    NMAManeuverActionJunction,                  // 4
    /** An action that indicates a roundabout. */
    NMAManeuverActionRoundabout,                // 5
    /** An action that indicates a u-turn. */
    NMAManeuverActionUTurn,                     // 6
    /** An action that indicates entering a highway from the right. */
    NMAManeuverActionEnterHighwayFromRight,     // 7
    /** An action that indicates entering a highway from the left. */
    NMAManeuverActionEnterHighwayFromLeft,      // 8
    /** An action that indicates entering a highway. */
    NMAManeuverActionEnterHighway,              // 9
    /** An action that indicates leaving a highway. */
    NMAManeuverActionLeaveHighway,              // 10
    /** An action that indicates changing from one highway to another. */
    NMAManeuverActionChangeHighway,             // 11
    /** An action that indicates continuing along a highway. */
    NMAManeuverActionContinueHighway,           // 12
    /** An action that indicates boarding a ferry. */
    NMAManeuverActionFerry,                     // 13
    /** An action that indicates passing a junction. */
    NMAManeuverActionPassJunction,              // 14

    /** An invalid action. */
    NMAManeuverActionInvalid = -1
};


/**
 * Defines types of turns for a `NMAManeuver`.
 */
typedef NS_ENUM(NSUInteger, NMAManeuverTurn) {
    /** An undefined turn. */
    NMAManeuverTurnUndefined = 0,               // 0
    /** Indicates that no turn is necessary. */
    NMAManeuverTurnNone,                        // 1
    /** A turn that indicates keeping to the middle when a road forks. */
    NMAManeuverTurnKeepMiddle,                  // 2
    /** A turn that indicates keeping to the right when a road forks. */
    NMAManeuverTurnKeepRight,                   // 3
    /** A turn that indicates making a light right turn. */
    NMAManeuverTurnLightRight,                  // 4
    /** A turn that indicates making a normal right turn. */
    NMAManeuverTurnQuiteRight,                  // 5
    /** A turn that indicates making a heavy right turn. */
    NMAManeuverTurnHeavyRight,                  // 6
    /** A turn that indicates keeping to the left when a road forks. */
    NMAManeuverTurnKeepLeft,                    // 7
    /** A turn that indicates making a light left turn. */
    NMAManeuverTurnLightLeft,                   // 8
    /** A turn that indicates making a normal left turn. */
    NMAManeuverTurnQuiteLeft,                   // 9
    /** A turn that indicates making a heavy left turn. */
    NMAManeuverTurnHeavyLeft,                   // 10
    /** A turn that indicates a u-turn, turning around. */
    NMAManeuverTurnReturn,                      // 11
    /** A turn that indicates taking the first exit of a roundabout. */
    NMAManeuverTurnRoundabout1,                 // 12
    /** A turn that indicates taking the second exit of a roundabout. */
    NMAManeuverTurnRoundabout2,                 // 13
    /** A turn that indicates taking the third exit of a roundabout. */
    NMAManeuverTurnRoundabout3,                 // 14
    /** A turn that indicates taking the fourth exit of a roundabout. */
    NMAManeuverTurnRoundabout4,                 // 15
    /** A turn that indicates taking the fifth exit of a roundabout. */
    NMAManeuverTurnRoundabout5,                 // 16
    /** A turn that indicates taking the sixth exit of a roundabout. */
    NMAManeuverTurnRoundabout6,                 // 17
    /** A turn that indicates taking the seventh exit of a roundabout. */
    NMAManeuverTurnRoundabout7,                 // 18
    /** A turn that indicates taking the eighth exit of a roundabout. */
    NMAManeuverTurnRoundabout8,                 // 19
    /** A turn that indicates taking the ninth exit of a roundabout. */
    NMAManeuverTurnRoundabout9,                 // 20
    /** A turn that indicates taking the tenth exit of a roundabout. */
    NMAManeuverTurnRoundabout10,                // 21
    /** A turn that indicates taking the eleventh exit of a roundabout. */
    NMAManeuverTurnRoundabout11,                // 22
    /** A turn that indicates taking the twelfth exit of a roundabout. */
    NMAManeuverTurnRoundabout12                 // 23
};


/**
 * Defines types of icons for a `NMAManeuver`.
 *
 *  @note `NMAManeuverIcon` enum is simplified version of all valid `NMAManeuverAction`
 *        and `NMAManeuverTurn` combinations. It can be used to provide navigation
 *        directions, but for more detailed representation, use NMAManeuverAction
 *        in conjunction with NMAManeuverTurn.
 */
typedef NS_ENUM(NSUInteger, NMAManeuverIcon) {
    /** An undefined icon. */
    NMAManeuverIconUndefined = 0,           // 0
    /** An icon that indicates a straight heading. */
    NMAManeuverIconGoStraight,              // 1
    /** An icon that indicates a right u-turn. */
    NMAManeuverIconUTurnRight,              // 2
    /** An icon that indicates a left u-turn. */
    NMAManeuverIconUTurnLeft,               // 3
    /** An icon that indicates keeping to the right. */
    NMAManeuverIconKeepRight,               // 4
    /** An icon that indicates a light right turn. */
    NMAManeuverIconLightRight,              // 5
    /** An icon that indicates a normal right turn. */
    NMAManeuverIconQuiteRight,              // 6
    /** An icon that indicates a heavy right turn. */
    NMAManeuverIconHeavyRight,              // 7
    /** An icon that indicates keeping to the left. */
    NMAManeuverIconKeepMiddle,              // 8
    /** An icon that indicates keeping to the middle line */
    NMAManeuverIconKeepLeft,                // 9
    /** An icon that indicates a light left turn. */
    NMAManeuverIconLightLeft,               // 10
    /** An icon that indicates a normal left turn. */
    NMAManeuverIconQuiteLeft,               // 11
    /** An icon that indicates a heavy left turn. */
    NMAManeuverIconHeavyLeft,               // 12
    /** An icon that indicates entering a highway into the right lane. */
    NMAManeuverIconEnterHighwayRightLane,   // 13
    /** An icon that indicates entering a highway into the left lane. */
    NMAManeuverIconEnterHighwayLeftLane,    // 14
    /** An icon that indicates leaving a highway from the right lane. */
    NMAManeuverIconLeaveHighwayRightLane,   // 15
    /** An icon that indicates from the left lane. */
    NMAManeuverIconLeaveHighwayLeftLane,    // 16
    /** An icon that indicates keeping to the right. */
    NMAManeuverIconHighwayKeepRight,        // 17
    /** An icon that indicates keeping to the left. */
    NMAManeuverIconHighwayKeepLeft,         // 18
    /**
     * An icon that indicates using the first exit encountered while navigating a
     * roundabout in a counter-clockwise direction.
     */
    NMAManeuverIconRoundabout1,             // 19
    /**
     * An icon that indicates using the second exit encountered while navigating a
     * roundabout in a counter-clockwise direction.
     */
    NMAManeuverIconRoundabout2,             // 20
    /**
     * An icon that indicates using the third exit encountered while navigating a
     * roundabout in a counter-clockwise direction.
     */
    NMAManeuverIconRoundabout3,             // 21
    /**
     * An icon that indicates using the fourth exit encountered while navigating a
     * roundabout in a counter-clockwise direction.
     */
    NMAManeuverIconRoundabout4,             // 22
    /**
     * An icon that indicates using the fifth exit encountered while navigating a
     * roundabout in a counter-clockwise direction.
     */
    NMAManeuverIconRoundabout5,             // 23
    /**
     * An icon that indicates using the sixth exit encountered while navigating a
     * roundabout in a counter-clockwise direction.
     */
    NMAManeuverIconRoundabout6,             // 24
    /**
     * An icon that indicates using the seventh exit encountered while navigating a
     * roundabout in a counter-clockwise direction.
     */
    NMAManeuverIconRoundabout7,             // 25
    /**
     * An icon that indicates using the eighth exit encountered while navigating a
     * roundabout in a counter-clockwise direction.
     */
    NMAManeuverIconRoundabout8,             // 26
    /**
     * An icon that indicates using the ninth exit encountered while navigating a
     * roundabout in a counter-clockwise direction.
     */
    NMAManeuverIconRoundabout9,             // 27
    /**
     * An icon that indicates using the tenth exit encountered while navigating a
     * roundabout in a counter-clockwise direction.
     */
    NMAManeuverIconRoundabout10,            // 28
    /**
     * An icon that indicates using the eleventh exit encountered while navigating a
     * roundabout in a counter-clockwise direction.
     */
    NMAManeuverIconRoundabout11,            // 29
    /**
     * An icon that indicates using the twelfth exit encountered while navigating a
     * roundabout in a counter-clockwise direction.
     */
    NMAManeuverIconRoundabout12,            // 30
    /**
     * An icon that indicates using the first exit encountered while navigating a
     * roundabout in a counter-clockwise direction.
     */
    NMAManeuverIconRoundabout1LH,           // 31
    /**
     * An icon that indicates using the second exit encountered while navigating a
     * roundabout in a clockwise direction.
     */
    NMAManeuverIconRoundabout2LH,           // 32
    /**
     * An icon that indicates using the third exit encountered while navigating a
     * roundabout in a clockwise direction.
     */
    NMAManeuverIconRoundabout3LH,           // 33
    /**
     * An icon that indicates using the fourth exit encountered while navigating a
     * roundabout in a clockwise direction.
     */
    NMAManeuverIconRoundabout4LH,           // 34
    /**
     * An icon that indicates using the fifth exit encountered while navigating a
     * roundabout in a clockwise direction.
     */
    NMAManeuverIconRoundabout5LH,           // 35
    /**
     * An icon that indicates using the sixth exit encountered while navigating a
     * roundabout in a clockwise direction.
     */
    NMAManeuverIconRoundabout6LH,           // 36
    /**
     * An icon that indicates using the seventh exit encountered while navigating a
     * roundabout in a clockwise direction.
     */
    NMAManeuverIconRoundabout7LH,           // 37
    /**
     * An icon that indicates using the eighth exit encountered while navigating a
     * roundabout in a clockwise direction.
     */
    NMAManeuverIconRoundabout8LH,           // 38
    /**
     * An icon that indicates using the ninth exit encountered while navigating a
     * roundabout in a clockwise direction.
     */
    NMAManeuverIconRoundabout9LH,           // 39
    /**
     * An icon that indicates using the tenth exit encountered while navigating a
     * roundabout in a clockwise direction.
     */
    NMAManeuverIconRoundabout10LH,          // 40
    /**
     * An icon that indicates using the eleventh exit encountered while navigating a
     * roundabout in a clockwise direction.
     */
    NMAManeuverIconRoundabout11LH,          // 41
    /**
     * An icon that indicates using the twelfth exit encountered while navigating a
     * roundabout in a clockwise direction.
     */
    NMAManeuverIconRoundabout12LH,          // 42
    /**
     * An icon that indicates the start point (displayed when route navigation has not
     * yet begun).
     */
    NMAManeuverIconStart,                   // 43
    /** An icon that indicates the destination point. */
    NMAManeuverIconEnd,                     // 44
    /** An icon that indicates boarding a ferry. */
    NMAManeuverIconFerry,                   // 45
};

/**
 * Defines types of traffic directions, the side of the road on which one
 * must drive.
 */
typedef NS_ENUM(NSUInteger, NMAManeuverTrafficDirection) {
    /** Traffic flows on the left side of the road, as in the UK. */
    NMAManeuverTrafficDirectionLeft = 0,
    /** Traffic flows on the right side of the road, as in the USA. */
    NMAManeuverTrafficDirectionRight
};

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents a maneuver, which is the action required to leave one
 * street segment and enter the next in the linked chain of directions that
 * comprises a calculated `NMARoute`.
 */
@interface NMAManeuver : NSObject

/**
 * The `NMAGeoCoordinates` of the maneuver.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *coordinates;

/**
 * The `NMAManeuverAction` to take for the maneuver.
 *
 * @note If the action for the maneuver is undefined, attempts to read this
 * property will return `NMAManeuverActionUndefined`.
 */
@property (nonatomic, readonly) NMAManeuverAction action;

/**
 * The `NMAManeuverTurn` to take for the maneuver.
 *
 * @note If the turn for the maneuver is undefined, attempts to read this
 * property will return `NMAManeuverTurnUndefined`.
 */
@property (nonatomic, readonly) NMAManeuverTurn turn;

/**
 * The distance from the start of the route to the maneuver, in meters.
 */
@property (nonatomic, readonly) NSUInteger distanceFromStart;

/**
 * The distance from the previous maneuver along the route to the
 * `NMAManeuver`, in meters.
 */
@property (nonatomic, readonly) NSUInteger distanceFromPreviousManeuver;

/**
 * The distance to the next maneuver along the route to the
 * `NMAManeuver`, in meters.
 */
@property (nonatomic, readonly) NSUInteger distanceToNextManeuver;

/**
 * The name of the road on which the `NMAManeuver` takes place,
 * nil if not available. If not available, it should be left blank.
 * It's erroneous to assume that that may be the same as prior maneuvers.
 *
 * @note  It is localized to the locale of the region.
 */
@property (nullable, nonatomic, readonly) NSString *roadName;

/**
 * The name of the road to which the `NMAManeuver` leads.
 * nil if not available. If not available, it should be left blank.
 * It's erroneous to assume that that may be the same as some maneuver
 * along the route.
 *
 * @note  It is localized to the locale of the region.
 */
@property (nullable, nonatomic, readonly) NSString *nextRoadName;

/**
 * The number of the road on which the `NMAManeuver` takes place, a short
 * label for the road, (e.g. 5 for the Interstate 5).
 *
 * @note If the road number for the maneuver is unknown, attempts to read
 * this property will return an empty `NSString`. nil if not available.
 * If not available, it should be left blank. It's erroneous to assume
 * that that may be the same as prior maneuvers.
 *
 * @note  It is localized to the locale of the region.
 */
@property (nullable, nonatomic, readonly) NSString *roadNumber;

/**
 * The number of the road to which the maneuver leads, a short
 * label for the road, (e.g. 5 for Interstate 5). nil if not available.
 * If not available, it should be left blank. It's erroneous to assume
 * that that may be the same as some maneuver along the route.
 *
 * @note  It is localized to the locale of the region.
 */
@property (nullable, nonatomic, readonly) NSString *nextRoadNumber;

/**
 * The `NMAManeuverIcon` for the `NMAManeuver`.
 *
 * @note If the icon type for the maneuver is undefined, attempts to read
 * this property will return `NMAManeuverIconUndefined`.
 */
@property (nonatomic, readonly) NMAManeuverIcon icon;

/**
 * The (estimated) time at which the maneuver starts in UTC.
 *
 * @note The departure time must be set in `NMARoutingMode` before routing.
 * nil if not available.
 */
@property (nullable, nonatomic, readonly) NSDate *startTime;

/**
 * The angle (from north) at the start of the maneuver, in degrees.
 *
 * @note Zero represents true-north, with increasing
 * values representing a clockwise progression of map orientation.
 */
@property (nonatomic, readonly) NSUInteger mapOrientation;

/**
 * Gets the transport mode for the maneuver. This might differ from
 * the transport mode used for route calculation. For example, in the case
 * where a route is calculated using public transport, the overall route is
 * a public transport route, but some individual maneuvers may be pedestrian
 * (e.g. walking to a bus stop, transfers which involve walking to a new
 * stop, etc.).
 */
@property (nonatomic, readonly) NMATransportMode transportMode;

/**
 * Gets the signpost information for this maneuver.
 *
 * @note nil if no signpost information for this maneuver.
 */
@property (nullable, nonatomic, readonly) NMASignpost *signpost;

/**
 * The list of NMARouteElement (or instances of classes derived from it) within the maneuver object.
 *
 * [
 * NMATransitManeuver is not available in all product
 * variants. This note should be in the dev guide.
 * ]
 *
 * Note that if this is a `NMATransitManeuver`, this will be an array of `NMATransitRouteElement` and the
 * number of transit route elements is the same as the number of stops along `NMATransitManeuver`;
 * otherwise, this is a list of `NMARoadElement`.
 */
@property (nonatomic, readonly) NSArray<__kindof NMARouteElement *> *routeElements;

@end

NS_ASSUME_NONNULL_END

