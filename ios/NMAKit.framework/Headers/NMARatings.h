/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * Represents a summary of the user-supplied ratings for a NMAPlace.
 */
@interface NMARatings : NSObject

/**
 * The average rating for the NMAPlace.
 */
@property (nonatomic, readonly) double average;

/**
 * The number of individual votes that users provide for rating the
 * NMAPlace.
 */
@property (nonatomic, readonly) NSUInteger count;

@end
