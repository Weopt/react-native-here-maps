/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * Identifiers for detailed explanation of travel duration (`NMARoute::duration`) estimates relating
 * to a route.
 *
 * @note This is a bitwise enum. If none of the bit is set, `NMARouteDurationDetailAccurate` is assumed
 */
typedef NS_OPTIONS(NSUInteger, NMARouteDurationDetail) {
    /** The estimate is accurate. */
    NMARouteDurationDetailAccurate = 0,
    /** The route uses a road that is blocked. */
    NMARouteDurationDetailBlockedRoad = 1 << 0,
    /** The route uses a road with carpool restriction. */
    NMARouteDurationDetailCarPool = 1 << 1,
    /** The route uses a restricted turn. */
    NMARouteDurationDetailRestrictedTurn = 1 << 2
};

/**
 * Describes Time to Arrival details of a `NMARoute` or a subleg of a
 * `NMARoute`.
 */
@interface NMARouteTta : NSObject

/**
 * Duration in seconds. -1 if not available.
 */
@property (nonatomic, readonly) NSTimeInterval duration;

/*
 * Details of this estimated time to arrival. See `NMARouteDurationDetail`.
 */
@property (nonatomic, readonly) NMARouteDurationDetail details;

/**
 * Whether a blocked road is present.
 */
@property (nonatomic, readonly, getter = isBlocked) BOOL blocked;

@end
