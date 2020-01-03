/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * This class stores signpost information along the Route.
 */
@interface NMASignpost : NSObject

/**
 *  The exit text of the signpost.
 */
@property (nullable, nonatomic, readonly) NSString *exitText;

@end
