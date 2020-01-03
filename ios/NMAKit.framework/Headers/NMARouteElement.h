/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMARoadElement;

/**
 * Defines types of route element.
 */
typedef NS_ENUM(NSInteger, NMARouteElementType) {
    /** Road Element */
    NMARouteElementRoad = 1,
    /** invalid  */
    NMARouteElementInvalid
};

/**
 *
 * Represents a generic container for an element of a route.
 */
@interface NMARouteElement : NSObject

/**
 * The route element type.
 */
@property (nonatomic, readonly) NMARouteElementType type;

/**
 * Road element of the route element.
 *
 * @note nil if type of the route element is not `NMARouteElementRoad`
 */
@property (nullable, nonatomic, readonly) NMARoadElement *roadElement;

@end
